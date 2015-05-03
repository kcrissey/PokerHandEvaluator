#include <iostream>

using namespace std;

#include <memory.h>
#include <stdlib.h>

#include "Cards.h"

char * SuitNames [] = {"h", "d", "c", "s"};
char * ValueNames [] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };


void Shuffle (Card Deck []) {
  long  i;
  bool  Picked  [52];
  long  WhichCard;

  memset (Picked, false, 52 * sizeof (bool));
  for (i = 0; i < 52; i++) {
    while (Picked [WhichCard = rand () % 52]);
    Deck [i].S      = (Suits) ((WhichCard / 13));
    Deck [i].V      = (Values) (WhichCard % 13);
    Picked [WhichCard]  = true;
//    Display (Deck [i]);
    }
  }

  
void DisplayCard (const Card & C) {
	cout << ValueNames [C.V] << SuitNames [C.S] << " ";
}
	
void DisplayDeck (Card Deck []) {
  for (int i = 0; i < 52; i++) {
	  if (i % 4 == 0)
	    cout << endl;
	  DisplayCard(Deck[i]);
  }
} 