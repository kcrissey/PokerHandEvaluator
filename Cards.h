#ifndef CARDS_H
#define CARDS_H

enum Suits  {H, D, C, S};
enum Values  {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};


struct Card {
  Suits S;
  Values V;
  };

void DisplayCard (const Card &);
void DisplayDeck (Card []);
void Shuffle (Card []);


#endif