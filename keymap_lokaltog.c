#include "bootloader.h"
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Layer 0 - Modified Programmer Dvorak
	//
	// Requires a custom xkb qwerty keymap with num keys remapped to symbols
	// ÅØÆÉ available with AltGr

	/*
	* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
	* │  $  ~  │  &  │  [  │  {  │  (  │  =  │ # ` │        │ L4  │  +  │  )  │  }  │  ]  │  *  │  !  %  │
	* ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
	* │ Tab    │ ; : │ , < │ . > │  P  │  Y  │     │        │     │  F  │  G  │  C  │  R  │  L  │  /  ?  │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │ LCtrl  │ A Å │ O Ø │ E Æ │ U É │  I  ├─────┤        ├─────┤  D  │  H  │  T  │  N  │  S  │  -  _  │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │ LShift │ " ' │  Q  │  J  │  K  │  X  │     │        │     │  B  │  M  │  W  │  V  │  Z  │  \  |  │
	* └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘        └─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
	*    │ L1  │ L2  │ L3  │AltGr│Supr │ ┌─────┬─────┐    ┌─────┬─────┐ │BkSp │ Del │ @ ^ │     │ L1  │
	*    └─────┴─────┴─────┴─────┴─────┘ │PgUp │PgDn │    │Home │End  │ └─────┴─────┴─────┴─────┴─────┘
	*                              ┌─────┼─────┼─────┤    ├─────┼─────┼─────┐
	*                              │Space│Meta │     │    │     │Esc  │ Ret │
	*                              │     │     ├─────┤    ├─────┤     │     │
	*                              │     │     │ F5  │    │     │     │     │
	*                              └─────┴─────┴─────┘    └─────┴─────┴─────┘
	*/
	KEYMAP(
		// Left hand
		GRV , 1   , 2   , 3   , 4   , 5   , EQL ,
		TAB , SCLN, COMM, DOT , P   , Y   , NO  ,
		LCTL, A   , O   , E   , U   , I   ,
		LSFT, QUOT, Q   , J   , K   , X   , NO  ,
		FN20, FN21, FN22, RALT, LGUI,
		
		      PGUP, PGDN,
		            NO  ,
		SPC , LALT, F5  ,
		
		// Right hand
		FN23, 6   , 7   , 8   , 9   , 0   , LBRC,
		NO  , F   , G   , C   , R   , L   , SLSH,
		      D   , H   , T   , N   , S   , MINS,
		NO  , B   , M   , W   , V   , Z   , BSLS,
		            BSPC, DEL , RBRC, NO  , FN20,
		
		HOME, END ,
		NO  ,
		NO  , ESC , ENT
	),

	// Layer 1 - Numpad / F keys / Misc
	/*
	* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
	* │ Teensy │ F1  │ F2  │ F3  │ F4  │ F5  │ F11 │        │ F12 │ F6  │ F7  │ F8  │ F9  │ F10 │ NumLk  │
	* ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │Prev │Play │Next │     │     │     │        │     │  /  │  1  │  2  │  3  │  -  │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │  ←  │  ↓  │  ↑  │  →  │     ├─────┤        ├─────┤  *  │  4  │  5  │  6  │  +  │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │     │     │     │     │     │     │        │     │     │  7  │  8  │  9  │ Ret │        │
	* └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘        └─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
	*    │     │     │     │     │     │ ┌─────┬─────┐    ┌─────┬─────┐ │  0  │  ,  │  .  │     │     │
	*    └─────┴─────┴─────┴─────┴─────┘ │     │     │    │     │     │ └─────┴─────┴─────┴─────┴─────┘
	*                              ┌─────┼─────┼─────┤    ├─────┼─────┼─────┐
	*                              │     │     │     │    │     │ 000 │ 00  │
	*                              │     │     ├─────┤    ├─────┤     │     │
	*                              │     │     │     │    │     │     │     │
	*                              └─────┴─────┴─────┘    └─────┴─────┴─────┘
	*/
	KEYMAP(
		// Left hand
		FN0 , F1  , F2  , F3  , F4  , F5  , F11 ,
		NO  , MPRV, MPLY, MNXT, NO  , NO  , NO  ,
		NO  , LEFT, DOWN, UP  , RGHT, NO  ,
		NO  , NO  , NO  , NO  , NO  , NO  , NO  ,
		TRNS, TRNS, TRNS, TRNS, TRNS,
		
		      TRNS, TRNS,
		            TRNS,
		TRNS, TRNS, TRNS,
		
		// Right hand
		F12 , F6  , F7  , F8  , F9  , F10 , NLCK,
		NO  , PSLS, P7  , P8  , P9  , PMNS, NO  ,
		      PAST, P4  , P5  , P6  , PPLS, NO  ,
		NO  , NO  , P1  , P2  , P3  , PENT, NO  ,
		            P0  , COMM, PDOT, TRNS, TRNS,
		
		NO  , NO  ,
		NO  ,
		NO  , FN30, FN31
	),

	// TODO Layer 2 - QWERTY/gaming
	/*
	* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
	* │        │  1  │  2  │  3  │  4  │  5  │     │        │     │  6  │  7  │  8  │  9  │  0  │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │  Q  │  W  │  E  │  R  │  T  │     │        │     │  Y  │  U  │  I  │  O  │  P  │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │  A  │  S  │  D  │  F  │  G  ├─────┤        ├─────┤  H  │  J  │  K  │  L  │     │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │  Z  │  X  │  C  │  V  │  B  │     │        │     │  N  │  M  │ , ; │ . : │ - _ │        │
	* └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘        └─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
	*    │     │     │     │     │     │ ┌─────┬─────┐    ┌─────┬─────┐ │     │     │     │     │     │
	*    └─────┴─────┴─────┴─────┴─────┘ │     │     │    │     │     │ └─────┴─────┴─────┴─────┴─────┘
	*                              ┌─────┼─────┼─────┤    ├─────┼─────┼─────┐
	*                              │ Spc │     │     │    │     │     │     │
	*                              │     │     ├─────┤    ├─────┤     │     │
	*                              │     │     │     │    │     │     │     │
	*                              └─────┴─────┴─────┘    └─────┴─────┴─────┘
	*/
	KEYMAP(
		// Left hand
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,
		
		      TRNS, TRNS,
		            TRNS,
		TRNS, TRNS, TRNS,
		
		// Right hand
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		            TRNS, TRNS, TRNS, TRNS, TRNS,
		
		TRNS, TRNS,
		TRNS,
		TRNS, TRNS, TRNS
	),

	// TODO Layer 3 - Macros
	/*
	* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
	* │        │     │     │     │     │     │     │        │     │     │     │     │     │     │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │     │     │     │     │     │     │        │     │     │     │     │     │     │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │     │     │     │     │     ├─────┤        ├─────┤     │     │     │     │     │        │
	* ├────────┼─────┼─────┼─────┼─────┼─────┤     │        │     ├─────┼─────┼─────┼─────┼─────┼────────┤
	* │        │     │     │     │     │     │     │        │     │     │     │     │     │     │        │
	* └──┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘        └─────┴─────┼─────┼─────┼─────┼─────┼─────┬──┘
	*    │     │     │     │     │     │ ┌─────┬─────┐    ┌─────┬─────┐ │     │     │     │     │     │
	*    └─────┴─────┴─────┴─────┴─────┘ │     │     │    │     │     │ └─────┴─────┴─────┴─────┴─────┘
	*                              ┌─────┼─────┼─────┤    ├─────┼─────┼─────┐
	*                              │     │     │     │    │     │     │     │
	*                              │     │     ├─────┤    ├─────┤     │     │
	*                              │     │     │     │    │     │     │     │
	*                              └─────┴─────┴─────┘    └─────┴─────┴─────┘
	*/
	KEYMAP(
		// Left hand
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,
		
		      TRNS, TRNS,
		            TRNS,
		TRNS, TRNS, TRNS,
		
		// Right hand
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		            TRNS, TRNS, TRNS, TRNS, TRNS,
		
		TRNS, TRNS,
		TRNS,
		TRNS, TRNS, TRNS
	),
};

enum function_id {
	F_TEENSY_KEY,
};

enum macro_id {
	M_DOUBLE_ZERO,
	M_TRIPLE_ZERO,
};

const action_t PROGMEM fn_actions[] = {
	[0]  = ACTION_FUNCTION(F_TEENSY_KEY),

	[10] = ACTION_MODS_ONESHOT(MOD_LSFT),

	[20] = ACTION_LAYER_MOMENTARY(1),
	[21] = ACTION_LAYER_SET(2, ON_PRESS),
	[22] = ACTION_LAYER_MOMENTARY(3),
	[23] = ACTION_LAYER_MOMENTARY(4),

	[30] = ACTION_MACRO(M_DOUBLE_ZERO),
	[31] = ACTION_MACRO(M_TRIPLE_ZERO),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	if (record->event.pressed) {
		switch (id) {
			case M_DOUBLE_ZERO: return MACRO(T(0), T(0), END);
			case M_TRIPLE_ZERO: return MACRO(T(0), T(0), T(0), END);
		}
	}
	return MACRO_NONE;
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	if (id == F_TEENSY_KEY) {
		clear_keyboard();
		_delay_ms(500);
		bootloader_jump(); // should not return
	}
}
