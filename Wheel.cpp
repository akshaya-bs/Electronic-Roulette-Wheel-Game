#include "Wheel.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Wheel::Wheel() {
    minValue = 1;
    maxValue = 10;
    std::srand(std::time(0));
}
Wheel::Wheel(int min, int max) {
    minValue = min;
    maxValue = max;
    std::srand(std::time(0));
}

int Wheel::spin() {
    ball_value = (std::rand() % (maxValue - minValue + 1)) + minValue; 
    return ball_value;
}
