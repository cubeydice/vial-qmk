 /* Copyright 2021 Kyle McCreery
 * Copyright 2021 cubeydice
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

//Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
	EMOJI
};

//Define names for kaomoji and emoji
enum custom_keycodes {
    DISAPPROVAL = SAFE_RANGE,   //ಠ_ಠ
	FLIPTABLE,                  //(╯°□°)╯︵ ┻━┻
    TABLEBACK,                  //(┬─┬ノ( º _ ºノ)
    SHRUG,                      //¯\_(ツ)_/¯

    HAPPY,                      //◉‿◉
    HAPPYHAND,                  //ლ(╹◡╹ლ)
    FLOWERHAPPY,                //(◡‿◡✿)
    BYERUN,                     //ε=ε=ε=ε=┌(;￣◇￣)┘

    POOP,                       //💩
    DED,                        //💀
    CLOWN,                      //🤡

    DANCER,                     //💃
    HOT,                        //🥵
    JUDGE,                      //😗
    PARTY,                       //🥳


    TEAR,                       //🥲
    CUTECRY,                    //🥺
    ENABLER,                    //😳
    BTHOUGHT                    //😤

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                 KC_RBRACKET,  KC_LBRACKET, LCTL(KC_G), LCTL(LSFT(KC_H)),       //                  Send Forward        Send Backward       Group                   Show/Hide Selection
                 LCA(KC_K),  LSFT(KC_R), LCTL(KC_P), LSFT(KC_A),                //                  Component           Ruler               Pixel Preview           Auto Layout
                 KC_T,  LCTL(LSFT(KC_4)), LALT(KC_H), LALT(KC_D),              //                  Text                 Layout Grids        Distr. Center H         Align Right
        TG(2),  KC_P, KC_I, LALT(KC_W), LALT(KC_S),                             //Toggle Layer 2    Pen                 Pick Color          Align Top               Align Bottom
        KC_C,  KC_F, KC_L, LCA(KC_H), LALT(KC_A),                               //Comment           Frame               Line                Align H                 Align Left
        LCA(KC_3),  KC_V, KC_R, MO(1), MO(1),                                   //Team Library      Move                Rectangle           Fn                      Fn

                  _______, _______, _______

    ),

    [_FN1] = LAYOUT(
                 RGB_VAI,  RGB_VAD, LCTL(LSFT(KC_G)), _______,                  //                  Brightness+         Brightness-         Ungroup                 Show/Hide Selection
                 LCA(KC_B),  _______, _______, LSA(KC_A),                       //Paint Bucket      Detach Instance                                                 Undo Auto Layout
                 _______,  _______, LALT(KC_V), KC_RIGHT,                       //                                                          Distr. Center V         Right
        KC_MSEL,  LSFT(KC_P), _______, KC_UP, KC_DOWN,                          //Media Player      Pencil                                  Up                      Down
        RGB_MOD,  KC_S,  LSFT(KC_L), LCA(KC_V), KC_LEFT,                        //RGB Mode+         Slice Tool          Arrow               Align V                 Left
        RGB_TOG,  KC_K,  KC_O,   _______, _______,                              //RGB Toggle        Scale               Ellipse

                  _______, _______, _______

    ),

	[EMOJI] = LAYOUT(
                 DED, CLOWN, POOP,  KC_NO,                                      //💀                🤡                    💩
                 DISAPPROVAL,  BYERUN, PARTY, BTHOUGHT,                         //ಠ_ಠ              ε=ε=ε=ε=┌(;￣◇￣)┘     🥳
                 TABLEBACK,   FLOWERHAPPY, JUDGE, ENABLER,                      //(┬─┬ノ( º _ ºノ)  (◡‿◡✿)               😗               😳
        TO(0),  FLIPTABLE, HAPPYHAND, HOT, CUTECRY,                             //(╯°□°)╯︵ ┻━┻     ლ(╹◡╹ლ)              🥵                🥺
        KC_NO,  SHRUG, HAPPY, DANCER, TEAR,                                     //¯\_(ツ)_/¯        ◉‿◉                  💃                 🥲
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,

                  _______, _______, _______
    )
};

// Send kaomoji and emoji on key presses
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case DISAPPROVAL:
		if (record->event.pressed) {
			send_unicode_string("ಠ_ಠ");
		}
        return false;
		break;

		case FLIPTABLE:
		if (record->event.pressed) {
			send_unicode_string("(╯°□°)╯︵ ┻━┻");
		}
        return false;
		break;

		case TABLEBACK:
		if (record->event.pressed) {
			send_unicode_string("┬─┬ノ( º _ ºノ)");
		}
        return false;
		break;

		case HAPPY:
		if (record->event.pressed) {
			send_unicode_string("◉‿◉");
		}
        return false;
		break;

		case HAPPYHAND:
		if (record->event.pressed) {
			send_unicode_string("ლ(╹◡╹ლ)");
		}
        return false;
		break;

		case FLOWERHAPPY:
		if (record->event.pressed) {
			send_unicode_string("(◡‿◡✿)");
		}
        return false;
		break;

    	case SHRUG:
		if (record->event.pressed) {
			send_unicode_string("¯'\'_(ツ)_/¯");
		}
        return false;
		break;

		case BYERUN:
		if (record->event.pressed) {
			send_unicode_string("ε=ε=ε=ε=ε=ε=┌(;￣◇￣)┘");
		}
        return false;
		break;

		case POOP:
		if (record->event.pressed) {
			send_unicode_string("💩");
		}
        return false;
		break;

		case DED:
		if (record->event.pressed) {
			send_unicode_string("💀");
		}
        return false;
		break;

		case CLOWN:
		if (record->event.pressed) {
			send_unicode_string("🤡");
		}
        return false;
		break;

		case TEAR:
		if (record->event.pressed) {
			send_unicode_string("💃");
		}
        return false;
		break;

		case DANCER:
		if (record->event.pressed) {
			send_unicode_string("🥲");
		}
        return false;
		break;

		case PARTY:
		if (record->event.pressed) {
			send_unicode_string("🥳");
		}
        return false;
		break;

        case CUTECRY:
		if (record->event.pressed) {
			send_unicode_string("🥺");
		}
        return false;
		break;

		case HOT:
		if (record->event.pressed) {
			send_unicode_string("🥵");
		}
        return false;
		break;

		case ENABLER:
		if (record->event.pressed) {
			send_unicode_string("😗");
		}
        return false;
		break;

		case JUDGE:
		if (record->event.pressed) {
			send_unicode_string("😳");
		}
        return false;
		break;

        case BTHOUGHT:
		if (record->event.pressed) {
			send_unicode_string("😤");
		}
        return false;
		break;
    }
        return true;
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                register_code(KC_LCTRL);
                register_code(KC_Y);
                unregister_code(KC_LCTRL);
                unregister_code(KC_Y);
            } else {
                register_code(KC_LCTRL);
                register_code(KC_Z);
                unregister_code(KC_LCTRL);
                unregister_code(KC_Z);
            }
        break;
		case 1:
            if (clockwise) {
                register_code(KC_LCTRL);
                register_code(KC_RBRACKET);
                unregister_code(KC_LCTRL);
                unregister_code(KC_RBRACKET);
            } else {
                register_code(KC_LCTRL);
                register_code(KC_LBRACKET);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LBRACKET);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE

	static void render_logo(void) {     // Render butterfly
		static const char PROGMEM my_logo[] = {// 'butterfly', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xf2, 0x0e, 0x0e, 0x1c, 0x28, 0x28, 0xf0, 0xc0,
            0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x50, 0x38, 0x1c, 0x1c, 0x74,
            0x74, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0, 0xe0, 0x80,
            0x81, 0x83, 0xfe, 0xf8, 0xf8, 0xf8, 0xfe, 0x83, 0x81, 0x81, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xde,
            0x7e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x38, 0x1c, 0x1c, 0x0c,
            0x1c, 0x18, 0x18, 0x00, 0x00, 0x00, 0xff, 0xff, 0x38, 0x18, 0x0c, 0x1c, 0x1c, 0xf8, 0xf8, 0xc0,
            0x00, 0x00, 0x00, 0x00, 0x18, 0x9c, 0x8c, 0x8c, 0x8c, 0x98, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00,
            0xfc, 0xfc, 0x18, 0x18, 0x0c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x18, 0x08, 0x0c, 0x1c,
            0x3c, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x98, 0x8c, 0x8c, 0x8c, 0x9c, 0xf8, 0xf0, 0x00,
            0x00, 0x00, 0x00, 0xf0, 0xf8, 0x1c, 0x0c, 0x0c, 0x18, 0x38, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x79, 0xdf, 0xc0, 0x60, 0x30, 0x18,
            0x0c, 0x06, 0x03, 0x01, 0x00, 0x01, 0x03, 0x04, 0x08, 0x10, 0x60, 0xc1, 0xc1, 0xfb, 0xfb, 0x8d,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3c, 0x30, 0x30, 0x30,
            0x30, 0x38, 0x10, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f,
            0x00, 0x00, 0x00, 0x1f, 0x3f, 0x31, 0x31, 0x31, 0x31, 0x31, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00,
            0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x30, 0x30, 0x30,
            0x38, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x33, 0x31, 0x31, 0x31, 0x31, 0x3f, 0x3f, 0x00,
            0x00, 0x00, 0x00, 0x1f, 0x3f, 0x38, 0x30, 0x30, 0x30, 0x18, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x30, 0x18, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x19,
            0x30, 0x70, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        oled_write_raw_P(my_logo, sizeof(my_logo));
    }

    void oled_task_user(void) {
            render_logo();
    }

#endif
