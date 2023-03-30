#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <iostream>

class Card{
    // declare enum data type first
    public:
        enum Color{purple, orange};
        friend std::ostream& operator<<(std::ostream& os, const Card& card);

    private:
        int rank = 0; 
        int value = 0;
        Color color = purple;
        
    public:
        Card() = default; // default constructor
        Card(int rank, Color color);
        
//getter functs

    int getRank() const;
    Color getColor() const; 
    int getValue() const;

// Other functs
    
    std::string printCard();
    
};
  
#endif