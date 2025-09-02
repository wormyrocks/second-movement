/*
 * MIT License
 *
 * Copyright (c) 2023 Jeremy O'Brien
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

#pragma once

#ifdef SIGNAL_TUNE_DEFAULT
int8_t signal_tune[] = {
    BUZZER_NOTE_C8, 5,
    BUZZER_NOTE_REST, 6,
    BUZZER_NOTE_C8, 5,
    0
};
#endif // SIGNAL_TUNE_DEFAULT

#ifdef SIGNAL_TUNE_ZELDA_SECRET
int8_t signal_tune[] = {
    BUZZER_NOTE_G5, 8,
    BUZZER_NOTE_F5SHARP_G5FLAT, 8,
    BUZZER_NOTE_D5SHARP_E5FLAT, 8,
    BUZZER_NOTE_A4, 8,
    BUZZER_NOTE_G4SHARP_A4FLAT, 8,
    BUZZER_NOTE_E5, 8,
    BUZZER_NOTE_G5SHARP_A5FLAT, 8,
    BUZZER_NOTE_C6, 20,
    0
};
#endif // SIGNAL_TUNE_ZELDA_SECRET

#ifdef SIGNAL_TUNE_MARIO_THEME
int8_t signal_tune[] = {
    BUZZER_NOTE_E6, 7,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_E6, 7,
    BUZZER_NOTE_REST, 10,
    BUZZER_NOTE_E6, 7,
    BUZZER_NOTE_REST, 11,
    BUZZER_NOTE_C6, 7,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_E6, 7,
    BUZZER_NOTE_REST, 10,
    BUZZER_NOTE_G6, 8,
    BUZZER_NOTE_REST, 30,
    BUZZER_NOTE_G5, 8,
    0
};
#endif // SIGNAL_TUNE_MARIO_THEME

#ifdef SIGNAL_TUNE_MGS_CODEC
int8_t signal_tune[] = {
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_REST, 6,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    BUZZER_NOTE_G5SHARP_A5FLAT, 1,
    BUZZER_NOTE_C6, 1,
    0
};
#endif // SIGNAL_TUNE_MGS_CODEC

#ifdef SIGNAL_TUNE_KIM_POSSIBLE
int8_t signal_tune[] = {
    BUZZER_NOTE_G7, 6,
    BUZZER_NOTE_G4, 2,
    BUZZER_NOTE_REST, 5,
    BUZZER_NOTE_G7, 6,
    BUZZER_NOTE_G4, 2,
    BUZZER_NOTE_REST, 5,
    BUZZER_NOTE_A7SHARP_B7FLAT, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G7, 6,
    BUZZER_NOTE_G4, 2,
    0
};
#endif // SIGNAL_TUNE_KIM_POSSIBLE

#ifdef SIGNAL_TUNE_POWER_RANGERS
int8_t signal_tune[] = {
    BUZZER_NOTE_D8, 6,
    BUZZER_NOTE_REST, 8,
    BUZZER_NOTE_D8, 6,
    BUZZER_NOTE_REST, 8,
    BUZZER_NOTE_C8, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D8, 6,
    BUZZER_NOTE_REST, 8,
    BUZZER_NOTE_F8, 6,
    BUZZER_NOTE_REST, 8,
    BUZZER_NOTE_D8, 6,
    0
};
#endif // SIGNAL_TUNE_POWER_RANGERS

#ifdef SIGNAL_TUNE_LAYLA
int8_t signal_tune[] = {
    BUZZER_NOTE_A6, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_C7, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_D7, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F7, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_D7, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_C7, 5,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_D7, 20,
    0
};
#endif // SIGNAL_TUNE_LAYLA

#ifdef SIGNAL_TUNE_HARRY_POTTER_SHORT
int8_t signal_tune[] = {
    BUZZER_NOTE_B5, 12,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_E6, 12,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G6, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6SHARP_G6FLAT, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_E6, 16,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_B6, 8,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_A6, 24,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6SHARP_G6FLAT, 24,
    0
};
#endif // SIGNAL_TUNE_HARRY_POTTER_SHORT

#ifdef SIGNAL_TUNE_HARRY_POTTER_LONG
int8_t signal_tune[] = {
    BUZZER_NOTE_B5, 12,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_E6, 12,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G6, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6SHARP_G6FLAT, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_E6, 16,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_B6, 8,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_A6, 24,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6SHARP_G6FLAT, 24,
    BUZZER_NOTE_REST, 1,

    BUZZER_NOTE_E6, 12,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G6, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6SHARP_G6FLAT, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_D6SHARP_E6FLAT, 16,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F6, 8,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_B5, 24,

    0
};
#endif // SIGNAL_TUNE_HARRY_POTTER_LONG

#ifdef SIGNAL_TUNE_JURASSIC_PARK
int8_t signal_tune[] = {
    BUZZER_NOTE_B5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_A5SHARP_B5FLAT, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_B5, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_F5SHARP_G5FLAT, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_E5, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_B5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_A5SHARP_B5FLAT, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_B5, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_F5SHARP_G5FLAT, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_E5, 13,
    0,
};
#endif // SIGNAL_TUNE_JURASSIC_PARK

#ifdef SIGNAL_TUNE_EVANGELION
int8_t signal_tune[] = {
    BUZZER_NOTE_C5, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_D5SHARP_E5FLAT, 13,
    BUZZER_NOTE_REST, 13,
    BUZZER_NOTE_F5, 13,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_D5SHARP_E5FLAT, 13,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_F5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_F5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_F5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_A5SHARP_B5FLAT, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_G5SHARP_A5FLAT, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_G5, 3,
    BUZZER_NOTE_REST, 3,
    BUZZER_NOTE_F5, 7,
    BUZZER_NOTE_REST, 7,
    BUZZER_NOTE_G5, 13,
    0,
};
#endif // SIGNAL_TUNE_EVANGELION

#ifdef SIGNAL_TUNE_NEVER_GONNA_GIVE_YOU_UP
#define never_gonna              \
    _root, _eighth_note,         \
        _root + 2, _eighth_note, \
        _root + 5, _eighth_note, \
        _root + 2, _eighth_note

#define give_you_up(X)                         \
    _root + X + 9, -1 + _dotted_quarter_s,     \
        _root + X + 9, -1 + _dotted_quarter_s, \
        _root + X + 7, 2 + _dotted_quarter

#define run_around_and                                   \
    _root + 5, 1 + _dotted_quarter,                      \
        _root + 7, 1 + _sixteenth_note + _eighth_note_s, \
        _root + 4, 2 + _quarter_note,                    \
        _root + 2, _quarter_note,                        \
        _root + 2, _sixteenth_note,                      \
        _root, _quarter_note

#define desert_you                      \
    _root + 7, _sixteenth_note,         \
        _root + 7, 1 + _quarter_note_s, \
        _root + 5, _sixteenth_note + 1 + _quarter_note_s + 3

#define let_you_down give_you_up(-2)
#define make_you_cry give_you_up(0)
#define say_goodbye                        \
    _root + 12, -1 + _dotted_quarter_s,    \
        _root + 4, -1 + _dotted_quarter_s, \
        _root + 5, 2 + _dotted_quarter

#define tell_a_lie_and_hurt_you run_around_and, desert_you

int8_t signal_tune[] = {
    never_gonna,
    give_you_up(0),
    never_gonna,
    let_you_down,
    never_gonna,
    run_around_and,
    desert_you,
    never_gonna,
    make_you_cry,
    never_gonna,
    say_goodbye,
    never_gonna,
    tell_a_lie_and_hurt_you,
    0};
#endif // NEVER_GONNA_GIVE_YOU_UP

#ifdef SIGNAL_TUNE_HAPPY_BIRTHDAY
#define _root BUZZER_NOTE_D4

#define happy(X) \
    _root+X, 3+_eighth_note_s, \
    _root+X, -3+_eighth_note,

#define birthday(X,Y) \
    _root+X, _quarter_note, \
    _root+Y, _quarter_note,

#define to_you(X,Y) \
    _root+X, _quarter_note, \
    _root+Y, _half_note,

#define birthdayy \
    _root+12, _quarter_note, \
    _root+9, _quarter_note,

#define dear_person \
    _root+5, _quarter_note, \
    _root+4, _quarter_note, \
    _root+2, _quarter_note,

#define and_many_more \
    BUZZER_NOTE_REST, _half_note-1, \
    _root, _half_note, \
    birthday(2,0) \
    _root+3, _eighth_note, \
    _root+2, _eighth_note, \
    _root+3, _eighth_note, \
    _root+2, _eighth_note, \
    _root+3, _eighth_note, \
    _root+2, _eighth_note, \
    _root+3, _eighth_note, \
    _root+2, _eighth_note, \
    _root+3, _quarter_note, \
    _root+3, _quarter_note,

int8_t signal_tune[] = {
    happy(0)
    birthday(2,0)
    to_you(5, 4)
    happy(0)
    birthday(2,0)
    to_you(7, 5)
    happy(0)
    birthdayy
    dear_person
    happy(10)
    birthday(9,5)
    to_you(7, 5)
    and_many_more
    0
};
#endif // HAPPY_BIRTHDAY

#ifdef SIGNAL_TUNE_SCHISM

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

int8_t signal_tune[] = {
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
#endif