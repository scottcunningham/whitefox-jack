/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap_common.h"

#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|Del|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \|  |PgU|
     * |---------------------------------------------------------------|
     * | Fn0  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgD|
     * |---------------------------------------------------------------|
     * |  Shif  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|   Shift  |Up |
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Alt | Gui |      |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,BSPC, DEL, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGUP, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT,      PGDN,\
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     NO,  UP,\
        LCTL,LGUI,LALT,               SPC,           RALT,RGUI,NO,     LEFT,DOWN,RGHT \
    ),
    /* Layer 1: FN0 layer
     * ,---------------------------------------------------------------.
 F F * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Backspc|Hom|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \|  |PgU|
     * |---------------------------------------------------------------|
     * | Fn0  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgD|
     * |---------------------------------------------------------------|
     * |  Shif  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|   Shift  |Up |
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Alt | Gui |      |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP( \
        GRV,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10,   F11,F12, NO,BSPC, DEL, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGUP, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT,      PGDN,\
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     NO,  UP,\
        LCTL,LGUI,LALT,               SPC,           RALT,FN1,NO,     LEFT,DOWN,RGHT \
    ),
};

#define ACTION_LEDS_ALL 2

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_ALL:
      // toggle enter LED on press
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
      }
      break;
  }
}

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_FUNCTION(ACTION_LEDS_ALL),
};
