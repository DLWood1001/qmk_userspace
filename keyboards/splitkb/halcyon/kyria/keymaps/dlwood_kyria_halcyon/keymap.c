// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// #include "version.h"
#include <print.h>
//#include "rgblight.h"
// #include "stdlib.h"

// Layers - General
#define PRI_ 0
#define NUM_ 1
#define FUN_ 2
#define SYM_ 3
#define PAD_ 4
#define NAV_ 5
#define SYS_ 6
#define RGB_ 7
#define DBG_ 8

// Keycodes
enum custom_keycodes {
  KC_START = SAFE_RANGE,
  KC_RAISE,
  KC_LOWER,
  KC_ADJUST,
  KC_NUM_EXIT,
  KC_BS_DEL
};

// Shortcuts
#define SC_UNDO  LCTL(KC_Z)
#define SC_WLEFT RCTL(KC_LEFT)
#define SC_WDOWN RCTL(KC_DOWN)
#define SC_WUP   RCTL(KC_UP)
#define SC_WRGHT RCTL(KC_RGHT)
#define SC_PC_ALL RCTL(KC_A)

#define SC_MAC_UNDO RGUI(KC_Z)
#define SC_MAC_CUT RGUI(KC_X)
#define SC_MAC_COPY RGUI(KC_C)
#define SC_MAC_PASTE RGUI(KC_V)
#define SC_PC_UNDO RCTL(KC_Z)
#define SC_PC_CUT RCTL(KC_X)
#define SC_PC_COPY RCTL(KC_C)
#define SC_PC_PASTE RCTL(KC_V)

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};


// Note(Dan): Stop CLANG errors due to some issue with the way QMK generates these Layout macros
/* #ifndef LAYOUT_split_3x6_5_hlc */
/* #define LAYOUT_split_3x6_5_hlc(...) true */
/* #endif */


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [PRI_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______            _______ _______   _______  _______   _______   _______       _______    _______  _______   _______  _______  _______  _______               _______
     KC_TAB,  KC_Q,              KC_W,   KC_E,     KC_R,    KC_T,                                                 KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,                 KC_BSLS,
     KC_ESC,  KC_A,              KC_S,   KC_D,     KC_F,    KC_G,                                                 KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,              KC_QUOT,
     KC_LSFT, MT(MOD_LCTL,KC_Z), KC_X,   KC_C,     KC_V,    KC_B,     TT(RGB_), _______,      _______,   KC_CAPS, KC_N,     KC_M,    KC_COMM, KC_DOT,  MT(MOD_RCTL,KC_SLSH), KC_RSFT,
                                         KC_LGUI,  KC_LALT, TT(NUM_), KC_ENT,   KC_BS_DEL,    KC_BS_DEL, KC_SPC,  MO(NUM_), KC_RALT, TT(FUN_),
                                         _______,  _______, _______,  _______,  _______,      _______,   _______, _______,  _______, _______
  ),

  [NUM_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______    _______  _______   _______  _______  _______  _______  _______
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                        KC_CIRC,  KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
     KC_CIRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                           KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
     KC_MINS, KC_PAST, _______, _______, KC_LPRN, KC_LPRN, KC_LSFT, _______,                  _______,   _______, KC_RPRN,  KC_RPRN, KC_COMM, KC_DOT, KC_SLSH,  KC_PPLS,
                                _______, _______, _______, _______, _______,                  KC_BS_DEL, KC_SPC,  MO(NUM_), KC_RALT, TT(FUN_),
                                _______, _______, _______, _______, _______,                  _______,   _______, _______,  _______, _______
  ),

  [FUN_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______,
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
     _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______
  ),

  [SYM_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______  _______  _______  _______  _______
     _______, KC_TILD, _______, _______, _______, _______,                                                      KC_PPLS, KC_LBRC, KC_COLN, KC_RBRC, KC_PIPE, _______,
     _______, KC_GRV,  KC_LCBR, _______, KC_RCBR, _______,                                                      KC_QUOT, KC_LPRN, KC_DQUO, KC_RPRN, KC_BSLS, KC_EQL,
     _______, _______, KC_LABK, _______, KC_RABK, _______, _______, _______,                  _______, _______, KC_MINS, KC_LCBR, KC_UNDS, KC_RCBR, KC_TILD, KC_GRV,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______
  ),

  [PAD_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______
  ),

  [NAV_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______   _______   _______  _______   _______  _______
     _______, _______, _______, _______, _______, _______,                                                      SC_WLEFT, SC_WDOWN, SC_WUP,  SC_WRGHT, _______, _______,
     _______, _______, KC_LSFT, _______, _______, _______,                                                      KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  _______, _______,
     _______, KC_LCTL, _______, _______, _______, _______, _______, _______,                  _______, _______, KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   _______, _______,
                                _______, _______, _______, _______, _______,                  KC_LSFT, KC_LSFT, _______,  _______,  _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______,  _______,  _______
  ),

  [SYS_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______     _______     _______      _______    _______
     _______, _______, _______, _______, _______, _______,                                                      KC_SCRL, SC_PC_ALL,  _______,    _______,     _______,   _______,
     _______, _______, _______, _______, _______, _______,                                                      _______, SC_PC_UNDO, SC_PC_COPY, SC_PC_PASTE, SC_PC_CUT, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, KC_LGUI, KC_DEL,     _______,    _______,     _______,   _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______,    _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______,    _______
  ),

  [RGB_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______  _______  _______   _______  _______
     _______, _______, _______, _______, _______, _______,                                                      _______, RGB_HUI, RGB_HUD, _______,  _______, _______,
     _______, _______, _______, _______, _______, _______,                                                      RGB_MOD, RGB_VAI, RGB_VAD, RGB_RMOD, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, RGB_SAI, RGB_SAD, _______,  _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______
  ),

  [DBG_] = LAYOUT_split_3x6_5_hlc(
  // Left Hand                                                                                Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______                   _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
  debug_enable = true;
  debug_matrix = false;
  debug_keyboard = false;
}

static bool bs_del_flag = false;

void update_tri_layer_d(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    /* uprintf("Adjust On.\n"); */
    layer_on(layer3);
  } else {
    /* uprintf("Adjust Off.\n"); */
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_RAISE:
      if (record->event.pressed) {
        uprintf("Raise On.\n");
        layer_on(NUM_);
      } else {
        uprintf("Raise Off.\n");
        layer_off(NUM_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_LOWER:
      if (record->event.pressed) {
        uprintf("Lower On.\n");
        layer_on(PAD_);
      } else {
        uprintf("Lower Off.\n");
        layer_off(PAD_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_ADJUST:
      if (record->event.pressed) {
        uprintf("Adjust On.\n");
        layer_on(FUN_);
      } else {
        uprintf("Adjust Off.\n");
        layer_off(FUN_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;
  }

  switch (keycode) {
    case KC_NUM_EXIT:
        layer_off(NUM_);
        return false;

    case KC_BS_DEL:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          unregister_code(KC_LSFT);
          register_code(KC_DEL);
          bs_del_flag = true;
        } else {
          register_code(KC_BSPC);
        }
      } else {
        if (bs_del_flag) {
          unregister_code(KC_DEL);
          register_code(KC_LSFT);
          bs_del_flag = false;
        } else {
          unregister_code(KC_BSPC);
        }
      }

      return false;
  }

  return true;
}

enum combos {
  CMB_DF,
  CMB_JK,
  CMB_DV,
  CMB_SF,
  CMB_SD,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
  [CMB_DF] = COMBO_ACTION(df_combo),
  [CMB_JK] = COMBO_ACTION(jk_combo),
  [CMB_DV] = COMBO_ACTION(dv_combo),
  [CMB_SF] = COMBO_ACTION(sf_combo),
  [CMB_SD] = COMBO_ACTION(sd_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  /* oled_write_P(PSTR("\n\n"), false); */
  switch(combo_index) {
    case CMB_DF:
    case CMB_JK:
      if (pressed) {
        /* uprintf("DF or JK pressed.\n"); */
        layer_on(SYM_);
      } else {
        /* uprintf("DF or JK unpressed.\n"); */
        layer_off(SYM_);
      }
    break;

    case CMB_DV:
      if (pressed) {
        /* uprintf("DV pressed.\n"); */
        layer_on(NAV_);
      } else {
        /* uprintf("DV unpressed.\n"); */
        layer_off(NAV_);
      }
    break;

    case CMB_SF:
      if (pressed) {
        /* uprintf("SF pressed.\n"); */
        layer_on(PAD_);
      } else {
        /* uprintf("SF unpressed.\n"); */
        layer_off(PAD_);
      }
    break;

    case CMB_SD:
      if (pressed) {
        /* uprintf("SD pressed.\n"); */
        layer_on(SYS_);
      } else {
        /* uprintf("SD unpressed.\n"); */
        layer_off(SYS_);
      }
    break;
    break;

    default:
    break;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL, KC_Z):
      return true;
    case MT(MOD_RCTL, KC_SLSH):
      return true;

    default:
      return false;
  }
}

/* bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case MT(MOD_LCTL, KC_Z): */
/*       return true; */
/*     case MT(MOD_RCTL, KC_SLSH): */
/*       return true; */

/*     default: */
/*       return false; */
/*   } */
/* } */
