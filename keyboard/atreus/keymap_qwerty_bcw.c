#include "keymap_common.h"


/* https://github.com/tmk/tmk_core/blob/master/doc/keycode.txt */

/*
 *  Q        W    E     R     T            ||        Y       U     I       O      P
 *  A        S    D     F     G            ||        H       J     K       L      enter
 *  Z(shft)  X    C     V     B            ||        N       M     ,       .      '
 * esc       tab bksp shift space  ctrl    || gui    bkspc   fn    L3      SAVE   ;
 */
#define LAYER_0 KEYMAP( \
  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,       KC_P, \
  KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,   KC_K,    KC_L,       KC_ENT, \
  KC_FN5, KC_X,   KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,   KC_COMM, KC_DOT,     KC_QUOT, \
  KC_ESC, KC_TAB, KC_LALT, KC_LSFT, KC_SPC, KC_LGUI,    KC_LCTL, KC_BSPC, KC_FN0, KC_FN3,  GUI(KC_S),  KC_SCLN)


/*
 *  1   2   3      4      5           ||       6            7     8     9      0
 *  {   }   [      ]      -           ||       line start   left  up    right  line end
 *  (   )   /      \      =           ||       no           pgup  down  pgdn   `
 *  L2  no  no  shift   space  ctrl   || alt   bkspc        fn    L2    no     del
 */
#define LAYER_1 KEYMAP( \
  KC_1,           KC_2,           KC_3,     KC_4,      KC_5,                     KC_6,          KC_7,     KC_8,     KC_9,      KC_0, \
  SHIFT(KC_LBRC), SHIFT(KC_RBRC), KC_LBRC,  KC_RBRC,   KC_MINS,                  GUI(KC_LEFT),  KC_LEFT,  KC_UP,    KC_RIGHT,  GUI(KC_RIGHT),  \
  SHIFT(KC_9),    SHIFT(KC_0),    KC_SLASH, KC_BSLASH, KC_EQL,                   KC_NO,         KC_PGUP,  KC_DOWN,  KC_PGDN,   KC_GRAVE,  \
  KC_FN1,         KC_NO,          KC_NO,    KC_LSFT,   KC_SPC, KC_LGUI, KC_LCTL, KC_BSPC,       KC_FN0,   KC_FN1,   KC_NO,     KC_DEL)


/*
 * F2  F3   F4     F5     F6          ||      F7     F8    F9     F10    F11
 * F1  F2   no     no     no          ||      pgup   left  up     right  enter
 * no  cut  copy   paste  RESET       ||      pgdn   home  down   end    no
 * L0  no   super  shift  no     ctrl || alt  no     L0    no     no     no
 */
#define LAYER_2 KEYMAP( \
  KC_F3,  KC_F4,      KC_F5,      KC_F6,      KC_F7,                     KC_F8,    KC_F9,    KC_F10,  KC_F11, KC_F12,   \
  KC_F1,  KC_F2,      KC_NO,      KC_NO,      KC_NO,                     KC_PGUP,  KC_LEFT,  KC_UP,   KC_RIGHT, KC_ENT,   \
  KC_NO,  GUI(KC_X), GUI(KC_C), GUI(KC_V), KC_FN4,                    KC_PGDN,  KC_HOME,  KC_DOWN, KC_END, KC_NO,   \
  KC_FN2, KC_TAB,     KC_NO,    KC_LSFT,    KC_SPC, KC_LGUI,  KC_LCTL,   KC_BSPC,  KC_FN2,   KC_NO,   KC_NO, KC_NO)



/*
 * no  no  no     no     no       ||      no       7   8   9   no
 * no  no  no     no     no       ||      no       4   5   6   enter
 * no  no  no     no     no       ||      0        1   2   3   .
 * no  no  super  shift  no  ctrl || alt  comment  no  L3  run  /
 */
#define LAYER_3 KEYMAP( \
  KC_FN6,  KC_NO,  KC_NO,    KC_VOLD,  KC_VOLU,                  KC_NO,           KC_7,  KC_8,   KC_9,                KC_NO,   \
  KC_INSERT,   KC_NO,  KC_NO,    KC_NO,    KC_FN6,                    KC_NO,           KC_4,  KC_5,   KC_6,                KC_ENT,   \
  KC_NO,       KC_NO,  KC_NO,    KC_NO,    KC_NO,                    KC_0,            KC_1,  KC_2,   KC_3,                KC_DOT,   \
  KC_NO,       KC_NO,  KC_NO,  KC_LSFT,  KC_NO, KC_LGUI,  KC_LCTL,   GUI(KC_SLASH),  KC_NO, KC_FN3, KC_FN6, KC_SLASH)


/* blank layer */
/*
 * no  no  no     no     no       ||      no  no  no  no  no
 * no  no  no     no     no       ||      no  no  no  no  no
 * no  no  no     no     no       ||      no  no  no  no  no
 * no  no  super  shift  no  ctrl || alt  no  no  no  no  no
 */
/*
#define LAYER_N KEYMAP( \
  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   \
  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   \
  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   \
  KC_NO,  KC_NO,  KC_LGUI,  KC_LSFT,  KC_NO, KC_LCTL,  KC_LALT, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO)
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  LAYER_0,                     \
  /* 1: punctuation and numbers */
  LAYER_1,                                     \
  /* 2: fixed: arrows and function keys */
  LAYER_2,
  /* 3: momentary function keys */
  LAYER_3
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_LAYER_MOMENTARY(3),  // to layer 3 overlay
  [4] = ACTION_FUNCTION(BOOTLOADER),  // RESET to bootloader
  [5] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),  // Holding Z is SHIFT
  [6] = ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT | MOD_LCTL, KC_4)  // Mac Print Screen equivalent
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
