#pragma once
#ifndef HardWheel_H
#define HardWheel_H
#include "Wheel.h"

class HardWheel : public Wheel {
private:
    int minValue;
    int maxValue;
    int house_wins;
    int house_losses;
    int consecutive_wins; 
    int consecutive_losses;  
public:
    HardWheel();
    void incrementWins();
    void incrementLosses();
    void checkRangeAdjustment();
    int spin() override;
    int getHouse_win () const ;
    int getHouse_loss () const ;
    int getMaxValue() const; 

};

#endif

