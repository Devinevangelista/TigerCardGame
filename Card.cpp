#include "Card.h"
#include <iostream>


//Card::Card(){};

Card::Card(int rank = 0, Color color = purple): rank(rank), color(color) // parameterized constructor
{   
    // Set value based on rank and color
    if (color == purple) {
        value = rank ;
    }
    else if (color == orange) {
        value = rank*2;
    }
}
//getter funct definitions
int Card::getRank() const {
    return rank;
}

Card::Color Card::getColor() const{
    return color;
}

int Card::getValue() const{
    return value;
}

std::string Card::printCard() {
    std::string color_str = ""; //str holder

    if (color == purple) {
        color_str = "purple:";
    }
    else {
        color_str = "orange:";
    }
    return color_str + std::to_string(rank); 
}

std::ostream& operator<<(std::ostream& os, const Card& card) // This is not needed and not called. 
{
    std::string color_str;
    if (card.color == Card::purple) {
        color_str = "purple";
    }
    else {
        color_str = "orange";
    }
    os << "Rank: " << card.rank << ", Color: " << color_str << ", Value: " << card.value;
    return os;
}
