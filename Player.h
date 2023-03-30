// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Deck.h"

class Player
{
    public:
        Hand hand;
        int score;
        //functions
        Player(){};
        Player(Deck deck, int N) : hand(deck, N), score(0) {};

};
  

#endif // PLAYER_H_
