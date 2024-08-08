#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

#define LAYER_MAIN   0
#define LAYER_ALT    1
#define LAYER_SHIFT  2
#define LAYER_SUPER  3
#define LAYER_MOUSE  4
#define LAYER_GAMING 5
#define LAYER_LANG   6
#define LAYER_POLISH 7

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MAC_MISSION_CONTROL,
  MAC_SPOTLIGHT,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAIN] = LAYOUT_ergodox_pretty(
    KC_DLR,          KC_LBRC,        KC_LCBR,        KC_RCBR,        KC_LPRN,        KC_AMPR,       KC_GRAVE,                                       KC_AT,          KC_KP_ASTERISK, KC_RPRN,        KC_KP_PLUS,     KC_RBRC,        KC_EXLM,        KC_HASH,
    KC_TAB,          KC_SCLN,        KC_COMMA,       KC_DOT,         KC_P,           KC_Y,          KC_EQUAL,                                       KC_BSLS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,
    KC_ESCAPE,       KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                          KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_KP_MINUS,
    MO(LAYER_SHIFT), KC_QUOTE,       KC_Q,           KC_J,           KC_K,           KC_X,          TD(DANCE_0),                                    TD(DANCE_1),    KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           MO(LAYER_SHIFT),
    KC_LEFT_CTRL,    KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_GUI,    MO(LAYER_ALT),                                                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_RIGHT_CTRL,
                                                                                                    KC_MEH,         TT(LAYER_ALT),           KC_HYPR,               LCTL(KC_UP),
                                                                                                                    TT(LAYER_SUPER),         TG(LAYER_MOUSE),
                                                                                    KC_SPACE,       KC_BSPC,        KC_LEFT_GUI,             TT(LAYER_GAMING),      KC_DELETE,      KC_ENTER
  ),

  [LAYER_ALT] = LAYOUT_ergodox_pretty(
    LALT(KC_1),      LALT(KC_2),     LALT(KC_3),     LALT(KC_4),     LALT(KC_5),     LALT(KC_6),     LALT(KC_7),                                     LALT(KC_8),     LALT(KC_9),     LALT(KC_0),     LALT(LSFT(KC_1)), LALT(LSFT(KC_2)), LALT(LSFT(KC_3)), LALT(LSFT(KC_4)),
    LALT(KC_TAB),    LALT(KC_SCLN),  LALT(KC_COMMA), LALT(KC_DOT),   LALT(KC_P),     LALT(KC_Y),     LALT(KC_EQUAL),                                 LALT(KC_BSLS),  LALT(KC_F),     LALT(KC_G),     LALT(KC_C),       LALT(KC_R),       LALT(KC_L),       LALT(KC_SLASH),
    LALT(KC_ESCAPE), LALT(KC_A),     LALT(KC_O),     LALT(KC_E),     LALT(KC_U),     LALT(KC_I),                                                                     LALT(KC_D),     LALT(KC_H),     LALT(KC_T),       LALT(KC_N),       LALT(KC_S),       LALT(KC_MINUS),
    KC_LEFT_SHIFT,   LALT(KC_QUOTE), LALT(KC_Q),     LALT(KC_J),     LALT(KC_K),     LALT(KC_X),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(KC_B),     LALT(KC_M),     LALT(KC_W),       LALT(KC_V),       LALT(KC_Z),       LALT(KC_RIGHT_SHIFT),
    KC_LEFT_GUI,     KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_TRANSPARENT,                                                                                                 LALT(KC_LEFT),  LALT(KC_DOWN),    LALT(KC_UP),      LALT(KC_RIGHT),   KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, MAC_MISSION_CONTROL,KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_ENTER)
  ),

  [LAYER_SHIFT] = LAYOUT_ergodox_pretty(
    KC_TILD,        KC_7,           KC_5,           KC_3,           KC_1,           KC_9,           KC_PERC,                                        KC_CIRC,        KC_0,           KC_2,           KC_4,           KC_6,           KC_8,           KC_BSPC,
    LSFT(KC_TAB),   KC_COLN,        KC_LABK,        KC_RABK,        LSFT(KC_P),     LSFT(KC_Y),     US_CIRC,                                        KC_PIPE,        LSFT(KC_F),     LSFT(KC_G),     LSFT(KC_C),     LSFT(KC_R),     LSFT(KC_L),     KC_QUES,
    KC_TRANSPARENT, LSFT(KC_A),     LSFT(KC_O),     LSFT(KC_E),     LSFT(KC_U),     LSFT(KC_I),                                                                     LSFT(KC_D),     LSFT(KC_H),     LSFT(KC_T),     LSFT(KC_N),     LSFT(KC_S),     KC_UNDS,
    KC_TRANSPARENT, KC_DQUO,        LSFT(KC_Q),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_X),     LM(LAYER_POLISH, MOD_LSFT),                                     LM(LAYER_LANG, MOD_LSFT), LSFT(KC_B),     LSFT(KC_M),     LSFT(KC_W),     LSFT(KC_V),     LSFT(KC_Z),     KC_TRANSPARENT,
    KC_TRANSPARENT, LSFT(KC_PC_UNDO),LSFT(KC_PC_CUT),LSFT(KC_PC_COPY),LSFT(KC_PC_PASTE),                                                                                                LSFT(KC_LEFT),  LSFT(KC_DOWN),  LSFT(KC_UP),    LSFT(KC_RIGHT), LSFT(KC_RIGHT_CTRL),
                                                                                                    LSFT(KC_ESCAPE),KC_TRANSPARENT, RSFT(KC_ESCAPE),KC_TRANSPARENT,
                                                                                                                    KC_LEFT_SHIFT,  KC_TRANSPARENT,
                                                                                    LSFT(KC_SPACE), LSFT(KC_BSPC),  KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_DELETE),LSFT(KC_ENTER)
  ),

  [LAYER_SUPER] = LAYOUT_ergodox_pretty(
    LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     LGUI(KC_0),     KC_KP_ASTERISK, KC_TRANSPARENT,
    LGUI(KC_TAB),   KC_TRANSPARENT, LGUI(KC_LEFT),  LGUI(KC_RIGHT), LGUI(KC_P),     LGUI(KC_Y),     KC_END,                                         KC_HOME,        LGUI(KC_F),     LGUI(KC_G),     LGUI(KC_C),     LGUI(KC_R),     LGUI(KC_L),     KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_A),     LGUI(KC_O),     LGUI(KC_E),     LGUI(KC_U),     LGUI(KC_I),                                                                     LGUI(KC_D),     LGUI(KC_H),     LGUI(KC_T),     LGUI(KC_N),     LGUI(KC_S),     KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_TRANSPARENT, LGUI(KC_Q),     LGUI(KC_J),     LGUI(KC_K),     LGUI(KC_X),     KC_PGDN,                                        KC_PAGE_UP,     LGUI(KC_B),     LGUI(KC_M),     LGUI(KC_W),     LGUI(KC_V),     LGUI(KC_Z),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    LGUI(KC_SPACE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_ENTER)
  ),

  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_BTN4,     KC_MS_WH_UP,    KC_MS_BTN5,     KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_MS_ACCEL1,   KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_ACCEL2,   KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_GAMING] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_LANG] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       US_SECT,        UK_DLR,         US_PND,         US_EURO,        US_CENT,        US_YEN,                                         UK_TILD,        UK_GRV,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    US_TILD,        KC_DQUO,        US_LDAQ,        US_RDAQ,        KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,                                        KC_NONUS_HASH,  KC_TRANSPARENT, KC_TRANSPARENT, US_CCED,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, US_SS,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_QUOTE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_POLISH] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PL_08,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, PL_09,          PL_04,          PL_07,          KC_TRANSPARENT, PL_06,                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PL_05,          PL_03,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PL_02,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PL_01,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_SPOTLIGHT:
      HCS(0x221);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

uint16_t layer_state_set_user(uint16_t state) {
    uint8_t layer = biton16(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case LAYER_MAIN:
        break;
      case LAYER_ALT:
        ergodox_right_led_2_on();
        break;
      case LAYER_SHIFT:
        ergodox_right_led_1_on();
        break;
      case LAYER_SUPER:
        ergodox_right_led_3_on();
        break;
      case LAYER_MOUSE:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case LAYER_GAMING:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case LAYER_LANG:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case LAYER_POLISH:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case LAYER_MAIN:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          // Bright Blue
          rgblight_sethsv_noeeprom(152,255, rgblight_config.val);
        }
        break;
      case LAYER_ALT:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          // Green
          rgblight_sethsv_noeeprom(74,255, rgblight_config.val);
        }
        break;
      case LAYER_SHIFT:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          // Yellow
          rgblight_sethsv_noeeprom(48, 53, rgblight_config.val);
        }
        break;
      case LAYER_SUPER:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(41,255, rgblight_config.val);
        }
        break;
      case LAYER_MOUSE:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(188,255, rgblight_config.val);
        }
        break;
      case LAYER_GAMING:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0, 100, rgblight_config.val);
        }
        break;
      case LAYER_LANG:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(131, 255, rgblight_config.val);
        }
        break;
      case LAYER_POLISH:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0, 245, rgblight_config.val);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PERC);
        tap_code16(KC_PERC);
        tap_code16(KC_PERC);
    }
    if(state->count > 3) {
        tap_code16(KC_PERC);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_PERC); break;
        case SINGLE_HOLD: layer_on(LAYER_POLISH); break;
        case DOUBLE_TAP: register_code16(KC_PERC); register_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PERC); register_code16(KC_PERC);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_PERC); break;
        case SINGLE_HOLD:
          layer_off(LAYER_POLISH);
        break;
        case DOUBLE_TAP: unregister_code16(KC_PERC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PERC); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_AMPR);
        tap_code16(KC_AMPR);
        tap_code16(KC_AMPR);
    }
    if(state->count > 3) {
        tap_code16(KC_AMPR);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_AMPR); break;
        case SINGLE_HOLD: layer_on(LAYER_LANG); break;
        case DOUBLE_TAP: register_code16(KC_AMPR); register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AMPR); register_code16(KC_AMPR);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_AMPR); break;
        case SINGLE_HOLD:
          layer_off(LAYER_LANG);
        break;
        case DOUBLE_TAP: unregister_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AMPR); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
