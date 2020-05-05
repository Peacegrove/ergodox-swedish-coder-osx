/* Copyright 2017 Magnus Fredlundh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define ARRO 2 // Arrow keys
#define NUMB 3 // Number Pad keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  LOCK  |   !  |  "   |  #   |  #   |  %   | ESC  |           |  ALF |   &  |  /   |  (   |  )   |  =   |        |
 * |        |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           |      |   6  |  7 { |  8 [ |  9 ] |  0 } |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  | Back-  |
 * |        |      |      |      |      |      | TAB  |           |      |      |      |      |      |      | space  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCTRL |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  *   | RCTRL  |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |  '   |        |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * | Left   |   Z  |   X  |   C  |   V  |   B  | lock |           | lock |   N  |   M  |   ;  |   :  |  -   | RShift |
 * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |  _   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  |      |      | LALT | LGUI |                                       | RGUI | RALT |      |      |  L2  |
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SHIFT| LALT |       | RALT | SHIFT|
 *                                        | + ALT|      |       |      | + ALT|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space| Back-|------|       |------| Shift| ENTER|
 *                                 |      | space|      |       |      |      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    HYPR(KC_L),       KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_ESC,
    KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_TAB,
    KC_LCTRL,         KC_A,             KC_S,             KC_D,             KC_F,             KC_G,
    KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             TG(ARRO),
    MO(ARRO),         MAGIC_TOGGLE_NKRO,                  KC_NO,            KC_LALT,          KC_LGUI,
                                                                                                  KC_LALT, LSFT(KC_LALT),
                                                                                                                   KC_NO,
                                                                        LT(SYMB, KC_SPC), MT(MOD_LSFT, KC_BSPC), RGB_TOG,
    // right hand
    HYPR(KC_A),       KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             HYPR(KC_T),
    KC_NO,            KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_BSPC,
                      KC_H,             KC_J,             KC_K,             KC_L,             SE_ASTR,          KC_RCTRL,
    TG(ARRO),         KC_N,             KC_M,             KC_COMM,          KC_DOT,           SE_MINS,          KC_RSFT,
                                        KC_RGUI,          KC_RALT,          KC_NO,            KC_NO,            MO(ARRO),
    RSFT(KC_RALT), KC_RALT,
    KC_PGUP,
    KC_PGDN, KC_RSFT, LT(SYMB, KC_ENT)
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   ^  |      |   #  |   $  |   %  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   ~  |      |      |   +  |      |           |      |   !  |   <  |   >  |   '  |  Å   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   &  |      |      |      |   =  |------|           |------|   ?  |   {  |   }  |   Ö  |  Ä   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |     |       |   -  |      |           |      |   _  |   [  |   ]  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |   *  |                                       |   ´  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,          SE_CIRC,          KC_TRNS,          KC_TRNS,          LALT(KC_4),       KC_PERC,          KC_TRNS,
    KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,      KC_TRNS,      KC_GRAVE,          KC_TRNS,
    KC_TRNS,          SE_AMPR,          KC_TRNS,          KC_TRNS,          SE_PIPE,          LSFT(KC_GRAVE),
    KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          SE_MINS,          KC_SPC,
    KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
                                                                                                       KC_TRNS, KC_TRNS,
                                                                                                                KC_TRNS,
                                                                                              KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,
    KC_TRNS,          SE_QUES,          SE_LESS_MAC,      SE_GRTR_MAC,      SE_CIRC,          SE_AA,          KC_TRNS,
                      SE_PLUS,          SE_LCBR_MAC,      SE_RCBR_MAC,      SE_OSLH,          SE_AE,          KC_TRNS,
    KC_ENT,           SE_UNDS,          SE_LBRC,          SE_RBRC,          SE_TILD,          KC_TRNS,        KC_TRNS,
                                        KC_GRAVE,         SE_APOS,          KC_INT1,          KC_INT2,        KC_INT3,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LALT | SHIFT|      |      |      |------|           |------|      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           |  L2  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Lock |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[ARRO] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_LALT, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS,KC_TRNS,
       TG(ARRO),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 4: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ½    |   !  |  "   |  #   |  #   |  %   | LEFT |           | RIGHT|   &  |  /   |  (   |  )   |  =   |  ?     |
 * |   §    |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           |      |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Delete |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
 * | Lock   |      |      |      |      |      | Hyper|           | Meh  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Left   |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
 * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | '/L1 |  `   |AltShf| Left | Right|                                       |  Up  | Down |  ^   |  *   | ~L1  |
 *   |      |  '   |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | AltGr|Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back- |------|       |------|  Tab   |Enter |
 *                                 |      |space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[NUMB] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    SE_HALF,          KC_1,           KC_2,          KC_3,    KC_4,    KC_5,   KC_LEFT,
    KC_DELT,          KC_Q,           KC_W,          KC_E,    KC_R,    KC_T,   TG(SYMB),
    KC_BSPC,          KC_A,           KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSFT,          CTL_T(KC_Z),    KC_X,          KC_C,    KC_V,    KC_B,   ALL_T(KC_NO),
    LT(SYMB,SE_APOS), SE_ACUT,        LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                          ALT_T(KC_APP),  KC_LGUI,
                                                          KC_HOME,
                                           KC_SPC,KC_BSPC,KC_END,
    // right hand
         KC_RGHT,      KC_6,   KC_7,   KC_8,    KC_9,    KC_0,              SE_PLUS,
         TG(SYMB),     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,              SE_AA,
                       KC_H,   KC_J,   KC_K,    KC_L,    SE_OSLH,            GUI_T(SE_AE),
         MEH_T(KC_NO), KC_N,   KC_M,   KC_COMM, KC_DOT,  CTL_T(SE_MINS),    KC_RSFT,
                               KC_UP,  KC_DOWN, SE_CIRC, SE_ASTR,           KC_FN1,
         KC_TRNS,        CTL_T(KC_ESC),
         KC_PGUP,
         KC_PGDN,KC_TAB, KC_ENT
),

};
