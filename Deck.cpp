#include "Deck.h"

//default constructor that implements 20 cards in the vector deck. 
Deck::Deck(){

    for(int i = 1; i <=10; i++){
        Card purple_card(i, Card::purple); // construct purple card and orange cards
        Card orange_card(i, Card::orange);
        deck.emplace_back(purple_card); // constructs object in place at the end of the vector
        deck.emplace_back(orange_card);
    }
}

void Deck::shuffle(){

    std::srand(std::time(nullptr)); // Seed the random number generator
    std::random_shuffle(deck.begin(), deck.end()); // Shuffle the deck
}

Card Deck::drawCard(){
    Card drawn_card = deck.front(); // Get first card in deck
    deck.erase(deck.begin()); // Remove first card from deck after drawn
    return drawn_card;
}

int Deck::getDeckSize(){
    return deck.size();
}



