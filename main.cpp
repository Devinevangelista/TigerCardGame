#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {

      std::cout << "Welcome to TigerGame!\n";

    // 1. Create a deck of cards and shuffle it.
    Deck deck;
    deck.shuffle();
    
    // 2. Create two players, each one with 5 cards in their hand.
    Player human(deck, 5);
    Player computer(deck, 5);

    // Play five rounds
    for (int round = 1; round <= 5; ++round)
    {
        std::cout << "Round " << round << "\n-------\n";

        // Have computer deal a card from their hand
        Card computerCard = computer.hand.dealCard(1);
        std::cout << "The computer plays: " << computerCard.printCard() << "\n";

        // Show human their hand of cards so that they can make a selection
        std::cout << "Your hand: " << human.hand.printHand() << "\n";
        std::cout << "Which card do you want to play? ";
        int cardNum;
        std::cin >> cardNum;

        // Validate the user input
        while (cardNum < 1 || cardNum > human.hand.getHandSize())
        {
            std::cout << "Please select a valid card: ";
            std::cin >> cardNum;
        }

        // Have human deal their card
        Card humanCard = human.hand.dealCard(cardNum);
        std::cout << "You played: " << humanCard.printCard() << "\n";

        // Determine who won the round and update points accordingly
        if (humanCard.getValue() > computerCard.getValue())
        {
            std::cout << "You win!\n";
            human.score += humanCard.getValue() + computerCard.getValue(); // adds the sum of the cards played
        }
        else if (humanCard.getValue() < computerCard.getValue())
        {
            std::cout << "The computer wins!\n";
            computer.score += humanCard.getValue() + computerCard.getValue();
        }
        else
        {
            std::cout << "Tie!\n";
        }

        // Print results for current round
        std::cout << "Current scores:\n";
        std::cout << "Human: " << human.score << "\n";
        std::cout << "Computer: " << computer.score << "\n \n";
    }

    // Print final game results
    std::cout << "Final scores:\n";
    std::cout << "Human: " << human.score << "\n";
    std::cout << "Computer: " << computer.score << "\n";
  
  return 0;
}