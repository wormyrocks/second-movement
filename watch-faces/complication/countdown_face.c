/*
 * MIT License
 *
 * Copyright (c) 2024 Joseph Bryant
 * Copyright (c) 2023 Konrad Rieck
 * Copyright (c) 2022 Wesley Ellis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "countdown_face.h"
#include "watch.h"
#include "watch_utility.h"

#define CD_SELECTIONS 3
#define DEFAULT_MINUTES 3
#define TAP_DETECTION_SECONDS 5

static bool quick_ticks_running;

static void abort_quick_ticks(countdown_state_t *state)
{
    if (quick_ticks_running)
    {
        quick_ticks_running = false;
        if (state->mode == cd_setting)
            movement_request_tick_frequency(4);
        else
            movement_request_tick_frequency(1);
    }
}

static void abort_tap_detection(countdown_state_t *state)
{
    state->tap_detection_ticks = 0;
    movement_disable_tap_detection_if_available();
}

static inline void store_countdown(countdown_state_t *state)
{
    /* Store set countdown time */
    state->set_hours = state->hours;
    state->set_minutes = state->minutes;
    state->set_seconds = state->seconds;
}

static inline void load_countdown(countdown_state_t *state)
{
    /* Load set countdown time */
    state->hours = state->set_hours;
    state->minutes = state->set_minutes;
    state->seconds = state->set_seconds;
}

static inline void button_beep()
{
    // play a beep as confirmation for a button press (if applicable)
    if (movement_button_should_sound())
        watch_buzzer_play_note_with_volume(BUZZER_NOTE_C7, 50, movement_button_volume());
}

static void schedule_countdown(countdown_state_t *state)
{

    // Calculate the new state->now_ts but don't update it until we've updated the target -
    // avoid possible race where the old target is compared to the new time and immediately triggers
    uint32_t new_now = watch_utility_date_time_to_unix_time(movement_get_utc_date_time(), movement_get_current_timezone_offset());
    state->target_ts = watch_utility_offset_timestamp(new_now, state->hours, state->minutes, state->seconds);
    state->now_ts = new_now;
    watch_date_time_t target_dt = watch_utility_date_time_from_unix_time(state->target_ts, movement_get_current_timezone_offset());
    movement_schedule_background_task_for_face(state->watch_face_index, target_dt);
}

static void auto_repeat(countdown_state_t *state)
{
    movement_play_alarm();
    load_countdown(state);
    schedule_countdown(state);
}

static void start(countdown_state_t *state)
{
    state->mode = cd_running;
    schedule_countdown(state);
}

static void draw(countdown_state_t *state, uint8_t subsecond)
{
    char buf[16];

    uint32_t delta;
    div_t result;

    switch (state->mode)
    {
    case cd_running:
        if (state->target_ts <= state->now_ts)
            delta = 0;
        else
            delta = state->target_ts - state->now_ts;
        result = div(delta, 60);
        state->seconds = result.rem;
        result = div(result.quot, 60);
        state->hours = result.quot;
        state->minutes = result.rem;
        sprintf(buf, "%2d%02d%02d", state->hours, state->minutes, state->seconds);
        break;
    case cd_reset:
    case cd_paused:
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        sprintf(buf, "%2d%02d%02d", state->hours, state->minutes, state->seconds);
        break;
    case cd_setting:
        sprintf(buf, "%2d%02d%02d", state->hours, state->minutes, state->seconds);
        if (!quick_ticks_running && subsecond % 2)
        {
            switch (state->selection)
            {
            case 0:
                buf[0] = buf[1] = ' ';
                break;
            case 1:
                buf[2] = buf[3] = ' ';
                break;
            case 2:
                buf[4] = buf[5] = ' ';
                break;
            default:
                break;
            }
        }
        break;
    }

    watch_display_text(WATCH_POSITION_BOTTOM, buf);

    if (state->tap_detection_ticks)
    {
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    }
    else
    {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    }
}

static void pause(countdown_state_t *state)
{
    state->mode = cd_paused;
    movement_cancel_background_task_for_face(state->watch_face_index);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

static void reset(countdown_state_t *state)
{
    state->mode = cd_reset;
    movement_cancel_background_task_for_face(state->watch_face_index);
    load_countdown(state);
}

static void ring(countdown_state_t *state)
{
    movement_play_alarm();
    reset(state);
}

static void times_up(countdown_state_t *state)
{
    if (state->repeat)
    {
        auto_repeat(state);
    }
    else
    {
        ring(state);
    }
}

static void settings_increment(countdown_state_t *state)
{
    switch (state->selection)
    {
    case 0:
        state->hours = (state->hours + 1) % 24;
        break;
    case 1:
        state->minutes = (state->minutes + 1) % 60;
        break;
    case 2:
        state->seconds = (state->seconds + 1) % 60;
        break;
    default:
        // should never happen
        break;
    }
    return;
}

#define _root BUZZER_NOTE_A4

#define a1 _root - 5
#define a2 _root + 7
#define b2 _root + 9
#define c3 _root + 10
#define d3 _root + 12
#define f3 _root + 15
#define e3 _root + 14
#define g3 _root + 17
#define a3 _root + 19

#define c4 _root + 22
#define d4 _root + 24
#define b3 _root + 21

#define f4 _root + 27
#define e4 _root + 26
#define d4 _root + 24
#define g4 _root + 29

#define _note 8
#define _chord(X,Y,R) X, 2, Y, 2, -2, (((R))/5-1)
#define _chord3(X,Y,Z,R) X, 1, Y, 1, Z, 1, -3, (((R))/6-1)
#define _beat BUZZER_NOTE_REST,(_note/6)
#define _rest(X) BUZZER_NOTE_REST,X
#define _volume(X) BUZZER_NOTE_SET_VOLUME,X
#define _note_s(N,B) ((N)-(B)),_rest(B)

#define _low_note _root, _note_s(4*_note,2)
#define _triplet _root, _note,c3, _note,d3, 2*_note
#define _octave_triplet _chord(_root, d4, _note)+1, \
    _chord(d4, c3, _note)+1, \
    d3,2*_note

int8_t happy_birthday[] = {
    _volume(5),
    BUZZER_NOTE_REST, 4,

    _triplet,

    f3, _note_s(4*_note,2),
    _low_note,

    e3, _note_s(4*_note,2),
    _low_note,

    _triplet,

    f3, _note_s(4*_note,2),
    _root, _note_s(4*_note,2),
    e3, _note_s(4*_note,2),
    _root, _note_s(4*_note,2),
    g3, _note_s(4*_note,2),
    _root, _note_s(4*_note,2),
    _volume(7),

    -27, 1,
    _volume(10),

    _triplet,

    _chord(f3, c4, 4*_note),
    _root,4*_note,

    _chord(e3, b3, _note*4),
    _chord(_root, a3, _note*4)-1,
    _rest(1),

    _triplet,

    _chord(f3, c4, _note*4),
    _root,4*_note,

    _chord(e3, b3, _note*4),
    _root,4*_note,
    _chord(_root,a3,_note*4),

    _chord(g3, d4, _note*4),
    _root,4*_note,

    _volume(12),

    _triplet,

    _chord3(f3, c4, f4, _note*4),
    _chord(_root, f4, _note*4),
    _volume(13),

    _chord3(e3, b3, e4, _note*4),
    _chord3(_root, a3, d4, _note*2),
    _root, _note*2+2,
    _volume(14),

    _octave_triplet,

    _chord3(f3, c4, f4, _note*4),
    _volume(10),
    _root,_note*4+2,
    _volume(15),

    _chord3(b3, e3, e4, _note*4),
    _volume(10),
    _root,_note*4+2,
    _volume(16),

    _chord3(g3, d4, g4, _note*4),
    _volume(10),
    _root,_note*4+2,
    _volume(17),

    _octave_triplet,

    _chord3(e3, c4, e4, _note*4),
    _root,_note*4,
    _chord3(d3, b3, d4, _note*2),
    _chord(d3, d4, _note*2)+1,
    _chord(_root, a3, _note*2),
    _root,_note*2+1,
    _octave_triplet,

    _chord3(e3, c4, e4, _note*4),
    _root,_note*4,
    _chord3(d3, b3, d4, _note*4),
    _root,_note*4,
    _chord3(c3, c4, d4, _note*4),
    _chord3(d4, d3, _root, _note*4),
    _triplet,
    
    _chord3(f3, c4, f4, _note*4),
    _root,_note*4,
    _chord3(e3, b3, e4, _note*2),
    _chord(e3, e4, _note*2),
    
    _chord(_root,a3, _note*2),
    _root,_note*2,
    
    _octave_triplet,
    
    _chord3(f3, c4, f4, _note*4),
    _root,_note*4,
    _chord3(e3, b3, e4, _note*4),
    _root,_note*4,
    _chord3(g3, d4, g4, _note*4),
    
    _triplet,
    _chord3(e3, c4, e4, _note*2),
    _chord(e3, c4, _note*2),
    
    _chord(d3, d4, _note*4),
    _chord3(d3, b3, e4, _note*2),
    _chord(d3, d4, _note*2),
    
    _chord3(_root,a3,d4, _note*4),

_triplet,
_chord3(e3, c4, e4, _note*4),
_low_note,
_chord3(d3, b3, d4, _note*2),
_chord(d3, d4, _note*2),
_chord(_root, a3, _note*2),
_root,_note*2,
_octave_triplet,
_chord3(e3, c4, e4, _note*4),
_low_note,
_chord3(d3, b3, d4, _note*4),
_chord(_root, c4, _note*4),
_chord3(c3, d4, f4, _note*4),
_chord3(_root, d3, e4, _note*4),
_chord(_root, e4, _note)+1,

0,


_chord(c3, e4, _note)+1,
_chord(d3, e4, _note*2),
// key change
_chord(c3, c4, _note*4),
_chord(a2, a3, _note*4),
_chord(b2, b3, _note*4),
_chord(a2, a3, _note*8),

_chord(a2,a3,_note)+1,
_chord(b2, b3, _note*2),
_chord(c3, c4, _note*4),
_chord(a2, a3, _note*4),
_chord(b2, b3, _note*4),
_chord(a2, a3, _note*4),
_chord(d3, d4, _note*4),
a2, _note_s(_note*4, 2),
_chord(a2, a3, _note)+1,
_chord(b2, b3, _note*2),


_chord(c3, c4, _note*4),
_chord (b2, b3, _note*4),
a3, _note_s(_note*2, 1),
a2, _note_s(_note*2, 1),
_chord(a2, a3, _note)+1,
_chord(b2, b3, _note*2),
_chord3(c3, c4, e4, _note*4),
0,





//     _chord(_root, d4, _note),
//     _chord(c3, d4, _note),
//     _chord(d3, d4, _note*2),
//     _chord(d3, d4, _note*2),
//     _chord(_root, a3, _note*4),
// _triplet,

    // _low_note,
    // _chord3(d3, b3, d4, _note*2),


    // f4,3,_root,1,-2,3,
    // f4, 10,
    // _chord3(e3, b3, e4, _note*4),

    // _chord(_root,d4,_note*4),
    // _chord(c3,d4,2),
    // d3,2*_note,



    0,
};

void countdown_face_setup(uint8_t watch_face_index, void **context_ptr)
{
    (void)watch_face_index;

    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(countdown_state_t));
        countdown_state_t *state = (countdown_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(countdown_state_t));
        state->minutes = DEFAULT_MINUTES;
        state->mode = cd_reset;
        state->watch_face_index = watch_face_index;
        store_countdown(state);
    }
}

void countdown_face_activate(void *context)
{
    countdown_state_t *state = (countdown_state_t *)context;
    if (state->mode == cd_running)
    {
        watch_date_time_t now = movement_get_utc_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, movement_get_current_timezone_offset());
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    }
    watch_set_colon();
    if (state->repeat)
        watch_set_indicator(WATCH_INDICATOR_BELL);

    movement_request_tick_frequency(1);
    quick_ticks_running = true;
    if (state->mode != cd_running && movement_enable_tap_detection_if_available())
    {
        state->tap_detection_ticks = TAP_DETECTION_SECONDS;
        state->has_tapped_once = false;
    }
}

bool countdown_face_loop(movement_event_t event, void *context)
{
    countdown_state_t *state = (countdown_state_t *)context;

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        if (watch_sleep_animation_is_running())
            watch_stop_sleep_animation();
        watch_display_text_with_fallback(WATCH_POSITION_TOP, "TIMER", "CD");
        draw(state, event.subsecond);
    watch_buzzer_play_sequence(happy_birthday, NULL);
        break;
    case EVENT_TICK:
        if (quick_ticks_running)
        {
            if (HAL_GPIO_BTN_ALARM_read())
                settings_increment(state);
            else
                abort_quick_ticks(state);
        }

        state->seconds=(state->seconds+1);

        if (state->tap_detection_ticks > 0)
        {
            state->tap_detection_ticks--;
            if (state->tap_detection_ticks == 0)
                movement_disable_tap_detection_if_available();
        }

        draw(state, event.subsecond);
        break;
    case EVENT_MODE_BUTTON_UP:
        abort_quick_ticks(state);
        movement_move_to_next_face();
        break;
    case EVENT_LIGHT_BUTTON_UP:
        switch (state->mode)
        {
        case cd_running:
        case cd_reset:
            movement_illuminate_led();
            break;
        case cd_paused:
            reset(state);
            button_beep();
            break;
        case cd_setting:
            state->selection++;
            if (state->selection >= CD_SELECTIONS)
            {
                state->selection = 0;
                state->mode = cd_reset;
                store_countdown(state);
                movement_request_tick_frequency(1);
                button_beep();
            }
            break;
        }
        draw(state, event.subsecond);
        break;
    case EVENT_ALARM_BUTTON_UP:
        switch (state->mode)
        {
        case cd_running:
            pause(state);
            button_beep();
            break;
        case cd_reset:
        case cd_paused:
            // Only start the timer if we have a valid time.
            if (!(state->hours == 0 && state->minutes == 0 && state->seconds == 0))
            {
                abort_tap_detection(state);
                start(state);
                button_beep();
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            }
            break;
        case cd_setting:
            settings_increment(state);
            break;
        }
        draw(state, event.subsecond);
        break;
    case EVENT_ALARM_LONG_PRESS:
        switch (state->mode)
        {
        case cd_reset:
            // long press in reset mode enters settings
            abort_tap_detection(state);
            state->mode = cd_setting;
            movement_request_tick_frequency(4);
            button_beep();
            break;
        case cd_setting:
            // long press in settings mode starts quick ticks for adjusting the time
            quick_ticks_running = true;
            movement_request_tick_frequency(8);
            break;
        case cd_running:
        case cd_paused:
            // do nothing
            break;
        }
        break;
    case EVENT_LIGHT_LONG_PRESS:
        if (state->mode == cd_setting)
        {
            switch (state->selection)
            {
            case 0:
                state->hours = 0;
                // intentional fallthrough
            case 1:
                state->minutes = 0;
                // intentional fallthrough
            case 2:
                state->seconds = 0;
                break;
            }
        }
        else
        {
            // Toggle auto-repeat
            button_beep();
            state->repeat = !state->repeat;
            if (state->repeat)
                watch_set_indicator(WATCH_INDICATOR_BELL);
            else
                watch_clear_indicator(WATCH_INDICATOR_BELL);
        }
        break;
    case EVENT_ALARM_LONG_UP:
        abort_quick_ticks(state);
        break;
    case EVENT_BACKGROUND_TASK:
        times_up(state);
        break;
    case EVENT_TIMEOUT:
        if (state->mode == cd_setting)
        {
            state->selection = 0;
            state->mode = cd_reset;
            store_countdown(state);
            movement_request_tick_frequency(1);
        }
        if (state->mode != cd_running)
        {
            movement_move_to_face(0);
        }
        break;
    case EVENT_LOW_ENERGY_UPDATE:
        // we will only get this if the timer is stopped.
        if (watch_get_lcd_type() == WATCH_LCD_TYPE_CLASSIC)
        {
            // clear out the last two digits and replace them with the sleep mode indicator
            watch_display_text(WATCH_POSITION_SECONDS, "  ");
        }
        if (!watch_sleep_animation_is_running())
            watch_start_sleep_animation(1000);
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        // intentionally squelch the light default event; we only show the light when cd is running or reset
        break;
    case EVENT_SINGLE_TAP:
        if (state->has_tapped_once == false)
        {
            // on first tap, set the countdown to 1 minute
            state->has_tapped_once = true;
            state->hours = 0;
            state->minutes = 1;
            state->seconds = 0;
        }
        else
        {
            // on subsequent taps, increment the countdown by 1 minute, up to 59 taps
            state->minutes = state->minutes < 59 ? state->minutes + 1 : state->minutes;
        }
        // reset the tap detection timer
        state->tap_detection_ticks = TAP_DETECTION_SECONDS;
        draw(state, event.subsecond);
        break;
    default:
        movement_default_loop_handler(event);
        break;
    }

    return true;
}

void countdown_face_resign(void *context)
{
    countdown_state_t *state = (countdown_state_t *)context;
    if (state->mode == cd_setting)
    {
        state->selection = 0;
        state->mode = cd_reset;
        store_countdown(state);
    }
    

    // return accelerometer to the state it was in before
    abort_tap_detection(state);
}
