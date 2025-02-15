#pragma once
#ifndef Wheel_H
#define Wheel_H
#include <iostream>

class Wheel {
    private:
        int minValue;
        int maxValue;
        int ball_value;
    public:
        Wheel();
        Wheel(int, int);
        virtual int spin();
};

#endif