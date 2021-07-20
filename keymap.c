/* Copyright 2015-2017 Jack Humbert
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
#include "audio.h"

enum {
	TD_GUI_MYCM,
	TD_COL_SEM
	
};

void dance_cln_finshed(qk_tap_dance_action_t *state, void *user_data) {
	if (state->count == 1) {
		register_code16(KC_COLN);
	} else {
		register_code(KC_SCLN);
	}
}

void dance_cln_reset(qk_tap_dance_state_t, *state, void *user_data) {
	if (state->count == 1) {
		unregister_code16(KC_COLN);
	} else {
		unregister_code(KC_SCLN);
	}
}
	
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_GUI_MYCM] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_MYCM),
	[TD_COL_SEM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finshed, dance_cln_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |Esc/` |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TT(3)|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Leader| GUI  | Alt  |MO(1) |    Space    |MO(2) | Left | Up   | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_preonic_1x2uC(
 KC_GESC,    KC_1,    KC_2,            KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_BSPC,
 KC_TAB,     KC_Q,    KC_W,            KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           KC_DEL, 
 TT(3),      KC_A,    KC_S,            KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_COL_SEM), KC_QUOT,
 KC_LSFT,    KC_Z,    KC_X,            KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,        KC_ENT,
 KC_LCTL,    KC_LEAD, TD(TD_GUI_MYCM), KC_LALT, MO(1),       KC_SPC,       MO(2),   KC_LEFT, KC_UP,   KC_DOWN,        KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |   F2 |  F3  |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Leader| GUI  | Alt  |MO(1) |    Space    |MO(2) | Left | Up   | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_preonic_1x2uC(
 KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
 KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,      KC_BSPC, 
 KC_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,   KC_QUOT, 
 KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,   KC_ENT, 
 KC_LCTL, KC_TRNS,  KC_LGUI,  KC_LALT,  KC_TRNS,       KC_SPC,        KC_TRNS,  KC_LEFT,  KC_UP,     KC_DOWN,   KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   +  |   (  |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Debug| reset|      |      |      |      |      |      |      |   =  |   [  |   ]  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Voice+|Mus on|mu off|mu mod|Aud on|      |      |      |      |   -  |   {  |   }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Voice-|rgb + |brite+|speed+|audoff|      |      |prtscr|      |   _  |  \   |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |rgbtog|rgb - |brite-|speed-|      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_preonic_1x2uC(
 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PLUS,   KC_LPRN,    KC_RPRN,
 DEBUG,    RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_EQL,    KC_LBRC,    KC_RBRC,
 MUV_IN,   MU_ON,    MU_OFF,   MU_MOD,   AU_ON,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PMNS,   KC_LCBR,    KC_RCBR,
 MUV_DE,   RGB_MOD,  RGB_VAI,  RGB_SPI,  AU_OFF,   KC_NO,    KC_NO,    KC_PSCR,  KC_NO,    KC_UNDS,   KC_BSLS,    KC_PIPE,
 RGB_TOG,  RGB_RMOD, RGB_VAD,  RGB_SPD,  KC_TRNS,       KC_NO,         KC_TRNS,  KC_MNXT,  KC_VOLU,   KC_VOLD,    KC_MPLY
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |NumLck|ck| num/ | num* | num- |  Ins | Home | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |      |      |      |      | num7 | num8 | num9 | num+ |  Del | End  | PgDn |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TO(0)|      |      |      |      | num4 | num5 | num6 | num, |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | RShft|      |      |      |      | num1 | num2 | num3 | num= |      |      | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RCtrl|  APP | RGUI | RAlt | Caps |     num0    | num. |      |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_preonic_1x2uC(
 KC_ESC,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS,    KC_INS,    KC_HOME,    KC_PGUP, 
 KC_TAB,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,    KC_DEL,    KC_END,     KC_PGDN, 
 TO(0),     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P4,      KC_P5,      KC_P6,      KC_PCMM,    KC_NO,     KC_NO,      KC_NO,
 KC_RSFT,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P1,      KC_P2,      KC_P3,      KC_PEQL,    KC_NO,     KC_NO,      KC_PENT,
 KC_RCTL,   KC_APP,   KC_RGUI,  KC_RALT,  KC_CAPS,        KC_P0,            KC_PDOT,    KC_LEFT,    KC_UP,      KC_DOWN,     KC_RGHT
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(ZELDA_PUZZLE);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);
#endif


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(2);
            } else {
                layer_off(2);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
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
    case MO(1):
    case MO(2):
	case TT(3):
      return false;
    default:
      return true;
  }
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

  void startup_user(){
      PLAY_SONG(tone_startup);
  }

  void shutdown_user(){
      PLAY_SONG(tone_goodbye);
      stop_all_notes();
  }

  void music_on_user(void){
      music_scale_user();
  }

  void music_scale_user(void){
      PLAY_SONG(music_scale);
  }

#endif
