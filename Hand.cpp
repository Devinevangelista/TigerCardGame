#include "Hand.h"

Hand::Hand(){}; //default constructor initializes empty hand

// parameterized constructor deals N cards from deck and adds to hand
Hand::Hand(Deck deck, int N){
    for(int i = 0; i < N; i++){
        Card card = deck.drawCard();
        hand.emplace_back(card);
    }
}

//returns string of hand
std::string Hand::printHand(){
    std::stringstream holder;
    for (int i = 0; i < (int)hand.size(); i++){
        holder << "[" << i+1 << "]";
        holder << (hand[i].getColor() == Card::Color::purple ? "purple:" : "orange:"); // checks if color is purp or orange
        holder << hand[i].getRank() << " ";
    }
    return holder.str();
}

// removes and returns the card at the index in the hand
Card Hand::dealCard(int num) {
    Card card = hand[num-1];
    hand.erase(hand.begin() + num-1);
    return card;
}

// returns the current number of cards in the hand
int Hand::getHandSize() {
    return hand.size();
}