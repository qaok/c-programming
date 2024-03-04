#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value <= VALUE_ACE && c.value >= 2);
  assert(c.suit <= CLUBS && c.suit >= SPADES);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH:
    return  "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return  "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";
  }
}

char value_letter(card_t c) {
  switch(c.value) {
  case VALUE_ACE:
    return 'A';
  case VALUE_KING:
    return 'K';
  case VALUE_QUEEN:
    return 'Q';
  case VALUE_JACK:
    return 'J';
  case 10:
    return '0';
  default:
    return '0' + c.value;
  }
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  default:
    return 'c';
  }
}

void print_card(card_t c) {
  char cur1 = value_letter(c);
  char cur2 = suit_letter(c);
  printf("%c", cur1);
  printf("%c", cur2);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let) {
  case 'A':
    temp.value = VALUE_ACE;
    break;
  case 'K':
    temp.value = VALUE_KING;
    break;
  case 'Q':
    temp.value = VALUE_QUEEN;
    break;
  case 'J':
    temp.value = VALUE_JACK;
    break;
  case '0':
    temp.value = 10;
    break;
  default:
    temp.value = value_let - '0';
    break;
  }
  switch(suit_let) {
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if (c <= 12) {
    temp.value = c + 2;
    temp.suit = SPADES;
  }
  else if (c > 12 && c <= 25) {
    temp.value = c % 13 + 2;
    temp.suit = HEARTS;
  }
  else if (c > 25 && c <= 38) {
    temp.value = c % 13 + 2;
    temp.suit = DIAMONDS;
  }
  else {
    temp.value = c % 13 + 2;
    temp.suit = CLUBS;
  }
  assert_card_valid(temp);
  return temp;
}
