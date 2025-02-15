#include "HardWheel.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



HardWheel::HardWheel() {
    minValue = 1;
    maxValue = 10;
    house_wins = 0;
    house_losses = 0;
    consecutive_losses = 0;
    consecutive_wins = 0;
    std::srand(std::time(0)); 
}

void HardWheel::incrementWins() {
    house_wins++;
    this->consecutive_wins++;
    this->consecutive_losses = 0;  
}

void HardWheel::incrementLosses() {
    house_losses++;
    this->consecutive_losses++;
    this->consecutive_wins = 0; 
}

int HardWheel::getHouse_win() const {
    return house_wins;
}

int HardWheel::getHouse_loss()  const {
    return house_losses;
}

void HardWheel::checkRangeAdjustment() {
    if (this->consecutive_wins >= 2) {
        this->maxValue /= 2;
        this->consecutive_wins = 0;  
        std::cout << "House won consecutively two rounds. The Wheel range will decrease." << std::endl;
        std::cout << "Minimum Value is " << minValue << std::endl;
        std::cout << "Maximum Value is " << maxValue << std::endl;
    }
    else if (this->consecutive_losses >= 2) {
        this->maxValue *= 2;
        this->consecutive_losses = 0;  
        std::cout << "House lost consecutively two rounds. The Wheel range will increase." << std::endl;
        std::cout << "Minimum Value is " << minValue << std::endl;
        std::cout << "Maximum Value is " << maxValue << std::endl;

    }
}


int HardWheel::spin() {
    return (std::rand() % (this->maxValue - this->minValue + 1)) + this->minValue;
}

int HardWheel::getMaxValue() const {
    return maxValue;
}
