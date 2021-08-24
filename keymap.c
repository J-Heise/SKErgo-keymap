/* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

//Written for Keyz.io SKErgo rev. 1

//Hold boot and press reset to enter bootloader mode.
//Custom layout assumes the PC is set to the English US International layout.
//MCU: ATMEGA32A

#include QMK_KEYBOARD_H

//SAFE_RANGE macro guarantees custom keycodes to be unique.
enum custom_keycodes
{
	DIACRITIC_A = SAFE_RANGE, 
	DIACRITIC_U,
	DIACRITIC_O,
	DOUBLE_S,
	EURO_CURRENCY_SIGN,
};

//Defines macros:
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
	//Macro for ä and Ä.
	case DIACRITIC_A:
		if(record->event.pressed)
			{
				//When keycode is pressed:
				register_code(KC_RALT);
				register_code(KC_Q);
			}
		else
			{
				//When keycode is released:
				unregister_code(KC_RALT);
				unregister_code(KC_Q);
			}
    return false;

	//Macro for ü and Ü.
    case DIACRITIC_U:
		if(record->event.pressed)
			{
				//When keycode is pressed:
				register_code(KC_RALT);
				register_code(KC_Y);
			}
		else
			{
				//When keycode is released:
				unregister_code(KC_RALT);
				unregister_code(KC_Y);
			}
    return false;

	//Macro for ö and Ö.
    case DIACRITIC_O:
		if(record->event.pressed)
			{
				//When keycode is pressed:
				register_code(KC_RALT);
				register_code(KC_P);
			}
		else
			{
				//When keycode is released:
				unregister_code(KC_RALT);
				unregister_code(KC_P);
			}
    return false;

	//Macro for ß.
    case DOUBLE_S:
		if(record->event.pressed)
			{
				//When keycode is pressed:
				register_code(KC_RALT);
				register_code(KC_S);
			}
		else
			{
				//When keycode is released:
				unregister_code(KC_RALT);
				unregister_code(KC_S);
			}
    return false;

	//Macro for €.
    case EURO_CURRENCY_SIGN:
		if(record->event.pressed)
			{
				//When keycode is pressed:
				register_code(KC_RALT);
				register_code(KC_5);
			}
		else
			{
				//When keycode is released:
				unregister_code(KC_RALT);
				unregister_code(KC_5);
			}
    return false;

    default: 
    return true;
  }
};

//Defines different keyboard layers:
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
	//Default Layer:
	[0] =	LAYOUT(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSPC,

		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,

		MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,

		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_UP, KC_PGDN,
		
		KC_LCTL, KC_LGUI, KC_SPC, KC_LALT, KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),

	//Second Layer (Accessed through pressing MO(1)):
	[1] =	LAYOUT(
		KC_SYSTEM_WAKE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 

		KC_TRNS, KC_TRNS, KC_TRNS, EURO_CURRENCY_SIGN, KC_TRNS, KC_TRNS, KC_CALCULATOR, DIACRITIC_U , KC_TRNS, DIACRITIC_O, KC_MEDIA_PLAY_PAUSE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

		KC_CAPS, DIACRITIC_A, DOUBLE_S, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,

		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_VOL_UP, KC_END,

		KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK),
};