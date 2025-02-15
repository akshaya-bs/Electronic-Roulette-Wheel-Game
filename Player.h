#pragma once
#ifndef Player_H
#define Player_H
#include <iostream>
#include <string>
#include "Wheel.h"
#include"HardWheel.h"

class Player
{
   private:
	   int player_total_money;
	   int bet_money;
	   int house_wins;
	   int house_losses;
	   Wheel wheel;
	   HardWheel hard;
public:
	Player();
	void set_Bet_Money(int);
	void setMoney(int);
	int getMoney() const ;
	void updateMoney(int);
	int spinWheel();
	void wagerSame(int Player_value);
	void wagerDouble(int Player_value);
	void wagerHalf(int Player_value );
	int ChallengingspinWheel();
	void wagerSameHard(int Player_value);
	void wagerDoubleHard(int Player_value);
	void wagerHalfHard(int Player_value);
	void checkWheelRangeAndEndGame(bool& continue_playing);
	HardWheel& getHardWheel();


};

#endif