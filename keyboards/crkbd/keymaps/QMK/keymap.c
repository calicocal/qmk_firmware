/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/select_word_previous.h"

enum custom_keycodes {
	SELWORD = SAFE_RANGE,
    SELWORDP,
    EMAIL1,
    EMAIL2,
    W_EMAIL,
    MOVE_WIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   CW_TOGG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    LGUI_T(KC_A),    LALT_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),    KC_G,                         KC_H,    RCTL_T(KC_J),    RSFT_T(KC_K),    RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_LEADER,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT(5,KC_DEL), KC_BACKSPACE,  LT(1,KC_TAB),     LT(3,KC_ENTER), LT(2,KC_SPACE), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LCTL(KC_C),    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                         KC_SLASH,    KC_7,    KC_8,    KC_9,    KC_MINUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL(KC_X), KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_SPACE,                      KC_KP_ASTERISK, KC_4,   KC_5,KC_6, KC_PLUS, KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_DEL, KC_1, KC_2, KC_3, KC_EQUAL, KC_ENTER,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_NO,  KC_TRNS,     KC_DOT, KC_0, KC_COMMA
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TILDE, KC_LCBR,   KC_AMPERSAND, KC_ASTERISK,  KC_LEFT_PAREN, KC_RCBR,                      KC_NO, EMAIL1, EMAIL2, W_EMAIL, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PIPE, KC_LBRC, KC_DOLLAR, KC_PERCENT, KC_CIRC, KC_RBRC,                      KC_SPACE,  KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BACKSLASH, KC_MINUS, KC_EXCLAIM, KC_AT, KC_HASH, KC_UNDS,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LEFT_PAREN, KC_BACKSPACE,  KC_RIGHT_PAREN,     KC_NO, KC_TRNS, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_MPLY, KC_F1, KC_F2, KC_F3, KC_F4, MOVE_WIN,                      KC_F13, RCS(KC_1), RCS(KC_2), RCS(KC_3), RCS(KC_4), RCS(KC_5),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,                      DM_PLY1, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, DM_REC1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,                      KC_F19, MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MEH(KC_F7), MEH(KC_F8),  LALT(KC_SPACE),     KC_TRNS, _______, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_NO, KC_Q, KC_W, KC_E, KC_R,                      KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LSFT, KC_A, KC_S, KC_D, KC_F,                      KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_LALT, KC_NO, KC_X, KC_B, KC_M,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(6), KC_SPACE,  KC_LCTL,     KC_ENT, KC_RSFT, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_INS, KC_PGUP, KC_UP, SELWORD, KC_HOME, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,                      KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_PGDN, KC_NO, SELWORDP, KC_END, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_NO,  KC_NO,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
 [6] = LAYOUT_split_3x6_3(KC_NO,KC_NO,KC_7,KC_8,KC_9,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_4,KC_5,KC_6,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_1,KC_2,KC_3,KC_NO,KC_NO,KC_TRANSPARENT,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRNS,KC_NO,KC_NO,KC_TRANSPARENT,KC_NO,KC_NO)
};

// Leader Stuff

void leader_start_user(void){
    // do something when the leader key is pressed
}

void leader_end_user(void){
    if (leader_sequence_two_keys(KC_S,KC_W)){
        tap_code16(LALT(KC_SPACE));
        SEND_STRING(SS_DELAY(250)"sw"SS_DELAY(250)SS_TAP(X_ENTER));
    } else if (leader_sequence_one_key(KC_T)){
        tap_code16(LALT(KC_SPACE));
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINUS:
        case RSFT(KC_MINUS):
        case KC_RSFT:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_select_word_previous(keycode, record, SELWORDP)) { return false; }
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

  // Your macros ...
    switch (keycode) {
        case EMAIL1:
            if (record->event.pressed){
                SEND_STRING("calicocal@gmail.com");
            }
            return false;
        case EMAIL2:
            if (record->event.pressed) {
                SEND_STRING("callin.ofarrell@gmail.com");
            }
            return false;
        case W_EMAIL:
            if (record->event.pressed){
                SEND_STRING("callin.ofarrell@dteenergy.com");
            }
            return false;
        case MOVE_WIN:
            if (record->event.pressed){
                tap_code16(LGUI(KC_LEFT));
            }
    }
  return true;
}
