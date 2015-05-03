#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

#include "Cards.h"
#include "handeval.h"

const int Elements (7461);
int BinarySearch (long [], long, long);

int main () {

  int x;
  int deck (0);
  const int NumPlayers (4);
  const int FullHand (5);        // hand recognition tables current support only 5-card hands
  long PValue [NumPlayers];
  int PrimeValues [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
  char PlayerHand [NumPlayers];
  int PlayerIndex [NumPlayers];
  int TIndex;
  bool Winner [NumPlayers];
  bool Flush [NumPlayers];
  bool Sorted;
  int Chk;

  Card  Deck [52];
  Card  Hand [NumPlayers][FullHand];
  Card  Tmp  [NumPlayers][FullHand];

  srand (time (0));

  Shuffle (Deck);

  //Deal cards
  for (int hand = 0; hand < FullHand; hand++) {
    for (int player = 0; player < NumPlayers; player++) {
      Hand [player][hand] = Deck [deck];
      Tmp  [player][hand] = Deck [deck];
      deck++;
      }
    }

  //  DisplayDeck (Deck);
  //  cout << endl << endl;

  //Sort individual player hands
  for (int player = 0; player < NumPlayers; player++) {
    Chk = FullHand;
    do {
      Chk--;
      Sorted = true;
      for (int i = 0; i < Chk; i++) {
        if (Hand [player][i].V > Hand [player][i + 1].V) {
          Tmp [player][i] = Hand [player][i];
          Hand [player][i] = Hand [player][i + 1];
          Hand [player][i + 1] = Tmp [player][i];
          Sorted = false;
          }
          else;
        }
      } while (!Sorted);
    }

  /*Display each player's hand before processing for testing
  for (int player = 0; player < NumPlayers; player++) {
    cout << "Hand for Player #" << player + 1 << ": ";
    for (int hand = 0; hand < FullHand; hand++) {
      DisplayCard (Hand [player][hand]);
      }
      //cout << PValue [player];
      cout << endl;
    }
  */

  //Evaluate each player's hand
  for (int player = 0; player < NumPlayers; player++) {
    Winner [player] = false;
    PValue [player] = 1;
    for (int hand = 0; hand < FullHand; hand++)
      PValue [player] *= PrimeValues[Hand [player][hand].V];
    }

  //Flush check
  for (int player = 0; player < NumPlayers; player++) {
    Flush[player] = true;
    for (int card = 0; card < FullHand - 1; card++) {
      if (Hand [player][card].S != Hand [player][card + 1].S)
        Flush[player] = false;
      }
      if ((Flush[player]) == true)
        PValue[player]++;
    }


  //Post-evaluation processing
  for (int player = 0; player < NumPlayers; player++) {
    PlayerIndex [player] = BinarySearch (Products, PValue[player], Elements);
    //cout << "Index for Player #" << player + 1 << ": " << PlayerIndex [player] << endl;
    }

  //Sort players by rank
  Chk = NumPlayers;
  do {
    Chk--;
    Sorted = true;
    for (int player = 0; player < Chk; player++) {
    if (Rank[(PlayerIndex [player])] > Rank[(PlayerIndex [player + 1])]) {
      TIndex = PlayerIndex [player];
      PlayerIndex [player] = PlayerIndex [player + 1];
      PlayerIndex [player + 1] = TIndex;
      for (int card = 0; card < FullHand; card++) {
        Tmp [player][card] = Hand [player][card];
        Hand [player][card] = Hand [player + 1][card];
        Hand [player + 1][card] = Tmp [player][card];
        }
      Sorted = false;
      }
      else;
      }
    } while (!Sorted);


  //Evaluate each player's hand
  Winner [0] = true;
  for (int player = 1; player < NumPlayers; player++) {
    if (Rank[(PlayerIndex [player])] == Rank[(PlayerIndex [0])])
      Winner [player] = true;
    }


  //Display each player's hand
  cout << endl << "C++ Poker Hand Dealer and Evaluator" << endl;
  cout << endl;
  cout << "Player      Result           Cards            Hand" << endl;
  cout << "----------  --------------   --------------   -------------------------" << endl;
  for (int player = 0; player < NumPlayers; player++) {
    cout << "Player #" << player + 1 << ":  ";
      if (Winner [player])
        cout << "*** WINNER ***   ";
      else
        cout << "                 ";
    for (int hand = 0; hand < FullHand; hand++) {
      DisplayCard (Hand [player][hand]);
      }
      //cout << "  " << PValue [player];
      cout << "  " << FHands [(PlayerIndex [player])];
      //cout << "  \t" << Rank [(PlayerIndex [player])];
      cout << endl;
    }

  cout << endl << endl;

  return 0;

  }
