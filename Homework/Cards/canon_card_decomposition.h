#pragma once
#include <cassert>
#include "card_arrays.h"

int get_int_dignity_from_canon_card(int canon_card)
{
	return canon_card / 10;
}

char get_char_dignity_from_canon_card(int canon_card)
{
	return dignities[get_int_dignity_from_canon_card(canon_card) - 2];
}

int get_int_suit_from_canon_card(int canon_card)
{
	assert(canon_card % 10 >= 0 && canon_card % 10 <= 3);
	return canon_card % 10;
}

char get_char_suit_from_canon_card(int canon_card)
{
	//return suits[canon_card % 10];
	return suits[get_int_suit_from_canon_card(canon_card)];
}
