#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _CALC 1
#define _GAME 2
#define _HOTKEY 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CALC,
  GAME,
  HOTKEY,
  GESRADARON,
  GESRADAROFF,
  GESGAMEPLAY,
  GESLEVEL
};

#define KC_OTGR LT(_HOTKEY, KC_GRV)
#define KC_ALPA LALT_T(KC_PAST)
#define KC_CTPS LCTL_T(KC_BSLS)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GESRADARON:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("y/sm_rcon ge_allowradar 1" SS_TAP(X_ENTER));
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case GESRADAROFF:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("y/sm_rcon ge_allowradar 0" SS_TAP(X_ENTER));
        } else {
            // when keycode QMKURL is released
        }
        break;

    case GESGAMEPLAY:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("y/sm_rcon ge_gameplay");
        } else {
            // when keycode QMKURL is released
        }
        break;
    case GESLEVEL:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("y/sm_rcon changelevel");
        } else {
            // when keycode QMKURL is released
        }
        break;
    }
    return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	  KC_OTGR, KC_1,    KC_2,    KC_3,    KC_4,    KC_5     ,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG(_GAME),
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(_CALC),                         TG(_CALC),KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC  ,                         KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP, KC_PGDN  ,       KC_HOME, KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT  ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	  KC_LGUI, KC_EQL,  KC_MINS, KC_ALPA  ,    KC_CTPS  ,   KC_BSPC, KC_DEL   ,       KC_ENT,  KC_SPC,      KC_RALT  ,    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),
	[_CALC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5    ,                                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS  ,                         KC_TRNS, KC_CALC, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PAST  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS  ,                         KC_TRNS, KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PSLS  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS, KC_TRNS  ,       KC_TRNS, KC_TRNS, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_NO    ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS  ,   KC_TRNS, KC_TRNS  ,       KC_TRNS, KC_TRNS,     KC_P0    ,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
    [_GAME] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	  KC_TRNS , KC_1,    KC_2,    KC_3,    KC_4,    KC_5    ,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS ,                          KC_TRNS  ,KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC  ,                         KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP, KC_PGDN  ,       KC_HOME, KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT  ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	  KC_LCTL, KC_EQL,  KC_MINS, KC_ALPA  ,    KC_SPC   ,   KC_BSPC, KC_DEL   ,       KC_ENT,  KC_SPC,      KC_RALT  ,    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),
    [_HOTKEY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5     ,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    GESLEVEL,GESGAMEPLAY,GESRADARON,GESRADAROFF,KC_TRNS,                   KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC  ,                         KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_NO,   KC_NO    ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTRL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP, KC_PGDN  ,        KC_TRNS,KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SLEP  ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_EQL,  KC_MINS, KC_ALPA  ,    KC_SPACE ,   KC_BSPC, KC_DEL   ,       KC_TRNS, KC_TRNS,     KC_NO,        KC_NO,   KC_NO,   KC_NO,   RESET
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _CALC:
            oled_write_P(PSTR("Calc\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _HOTKEY:
            oled_write_P(PSTR("Hotkey\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
