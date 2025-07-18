/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  BACKLIT
};

#define QWERTY PDF(_QWERTY)
#define COLEMAK PDF(_COLEMAK)
#define DVORAK PDF(_DVORAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------.
 * |   `      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del         |
 * |----------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Tab      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp        |
 * |----------+------+------+------+------+-------------+------+------+------+------+-------------|
 * | Ctrl,Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "          |
 * |----------+------+------+------+------+------|------+------+------+------+------+-------------|
 * | Shift    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift,Enter |
 * |----------+------+------+------+------+------+------+------+------+------+------+-------------|
 * | Caps     | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Right       |
 * `----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV             ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB             ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  MT(MOD_LCTL,KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT            ,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT),
  KC_CAPS            ,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *     |   (  |   )  | Bksp    |
 * |------+------+------+------+------+-------------+------+------+------+------+------------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *     |   (  |   )  | Del     |
 * |------+------+------+------+------+-------------+------+------+------+------+------------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +     |   {  |   }  | |       |
 * |------+------+------+------+------+------|------+------+------+------+------+------------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO |    | End  | Home  | Next   |
 * |------+------+------+------+------+------+------+------+------+------+------+------------|
 * |      |      |      |      |      |             |      | Bright- | Vol- | Vol+ | Bright+ |
 * `-----------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN,  KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN,  KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS,    KC_LCBR, KC_RCBR,  KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS), KC_END, KC_HOME,   KC_MNXT,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID,    KC_VOLD, KC_VOLU,  KC_BRIU
),

/* Raise
 * ,-----------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8     |   9  |   0  | Bksp    |
 * |------+------+------+------+------+------+------+------+---------+------+------+---------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8     |   9  |   0  | Del     |
 * |------+------+------+------+------+-------------+------+---------+------+------+---------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =     |   [  |   ]  |  \      |
 * |------+------+------+------+------+------|------+------+---------+------+------+---------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO /    | Pg Dn| Pg Up| Play    |
 * |------+------+------+------+------+------+------+------+---------+------+------+---------|
 * |      |      |      |      |      |             |      | Bright- | Vol- | Vol+ | Bright+ |
 * `-----------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGDN, KC_PGUP, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU
),

/* Adjust (Lower + Raise + Esc)
 * ,------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12        |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del        |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |             |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      | ToggleMouse |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------|
 * |      |      |      |      |      |             |      |      |      |      |             |
 * `------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, TG(_MOUSE),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Mouse (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------------.
 * |         | Accel0 | Accel1 | Accel2 |       |      |      |       |          |          |          |          |
 * |---------+--------+--------+--------+-------+------+------+-------+----------+----------+----------+----------|
 * |         |        | MouseU |        |       |      |      |       |          |          |          |          |
 * |---------+--------+--------+--------+-------+-------------+-------+----------+----------+----------+----------|
 * |         | MouseL | MouseD | MouseR |       |      |      |       |          |          |          |          |
 * |---------+--------+--------+--------+-------+------|------+-------+----------+----------+----------+----------|
 * |         |        |        |        |       |      |      |       |          |          |          |          |
 * |---------+--------+--------+--------+-------+------+------+-------+----------+----------+----------+----------|
 * |         |        |        |        |       |    Click    |       | Wheel LT | Wheel DN | Wheel Up | Wheel RT |
 * `--------------------------------------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid(
  _______, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, MS_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, MS_BTN1, MS_BTN1, _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            gpio_write_pin_low(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            gpio_write_pin_high(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
