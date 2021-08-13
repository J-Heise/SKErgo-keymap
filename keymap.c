//Written for Keyz.io SKErgo rev. 1

//Hold boot and+ press reset to enter bootloader mode//
//MCU: ATMEGA32A

#include QMK_KEYBOARD_H

enum custom_keycodes
{
	A_UMLAUT,
	U_UMLAUT,
	O_UMLAUT,
	DOUBLE_S,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
		case A_UMLAUT:
			if(record->event.pressed)
			{
				register_code(KC_RALT);
				register_code(KC_Q);
			}
		else
			{
				unregister_code(KC_RALT);
				unregister_code(KC_Q);
			}
		break;

		case U_UMLAUT:
			if(record->event.pressed)
			{
				register_code(KC_RALT);
				register_code(KC_Y);
			}
		else
			{
				unregister_code(KC_RALT);
				unregister_code(KC_Y);
			}
		break;

		case O_UMLAUT:
		if(record->event.pressed)
			{
				register_code(KC_RALT);
				register_code(KC_P);
			}
		else
			{
				unregister_code(KC_RALT);
				unregister_code(KC_P);
			}
		break;

		case DOUBLE_S:
		if(record->event.pressed)
			{
				register_code(KC_RALT);
				register_code(KC_S);
			}
		else
			{
				unregister_code(KC_RALT);
				unregister_code(KC_S);
			}
		break;
	}
return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
	//Default Layer
	[0] =	LAYOUT(
			KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSPC,

			KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,

			KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,

			KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_UP, KC_PGDN,
            
			KC_LCTL, KC_LGUI, KC_SPC, KC_LALT, KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_RGHT),

	//F1 Layer
	//Accessed through pressing MO(1)
	[1] =	LAYOUT(
			KC_SYSTEM_WAKE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 

			KC_TRNS, KC_TRNS, KC_TRNS, KC_MY_COMPUTER, KC_TRNS, KC_TRNS, KC_CALCULATOR, U_UMLAUT , KC_TRNS, O_UMLAUT, KC_MEDIA_PLAY_PAUSE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

			KC_TRNS, A_UMLAUT, DOUBLE_S, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,

			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_VOL_UP, KC_END,

			KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK),
};

