#include "Player.h"
#include <iostream>

Player::Player() {
    player_total_money = 0;
    bet_money = 0;
    wheel = Wheel();
    house_wins = 0;
    house_losses = 0;
    hard = HardWheel();
    
}

void Player::set_Bet_Money(int money) {
    bet_money = money;
}


void Player::setMoney(int amount) {
	player_total_money = amount;
}
int Player::getMoney() const {
	return player_total_money;
}

void Player::updateMoney(int amount) {
	player_total_money += amount;
}

int Player::spinWheel() {
	return wheel.spin();
}

int Player::ChallengingspinWheel() {
    hard.checkRangeAdjustment();
    return hard.spin();
}



void Player::wagerSame(int Player_value) {
    int house_value = wheel.spin();
    std::cout << "Player value: " << Player_value << ", House value: " << house_value << std::endl;
    if (house_value >= Player_value) {
        updateMoney(-bet_money);
        std::cout << "House wins! Player loses " << bet_money << "  $ money." << std::endl;
    }
    else {
        updateMoney(bet_money);
        std::cout << "Player wins! Player gains " << bet_money << " $ money." << std::endl;
    }
}

void Player::wagerDouble(int Player_value) {
    int house_value1 = wheel.spin();
    std::cout << "Player value: " << Player_value << ", House value 1: " << house_value1 << std::endl;
    if (house_value1 >= Player_value) {
        updateMoney(-2 * bet_money);
        std::cout << "House wins on first spin! Player loses " << 2 * bet_money << " $ money." << std::endl;
        return;
    }
    int house_value2 = wheel.spin();
    std::cout << "House value 2: " << house_value2 << std::endl;
    if (house_value2 >=Player_value) {
        updateMoney(-2 * bet_money);
        std::cout << "House wins on second spin! Player loses " << 2 * bet_money << " $ money." << std::endl;
    }
    else {
        updateMoney(2 * bet_money);
        std::cout << "Player wins! Player gains " << 2 * bet_money << " $ money." << std::endl;
    }
}

void Player::wagerHalf(int Player_value) {
    int house_value1 = wheel.spin();
    std::cout << "Player value: " << Player_value << ", House value 1: " << house_value1 << std::endl;

    if (house_value1 <= Player_value) {
        updateMoney(bet_money / 2);
        std::cout << "House loses on first spin! Player wins " << bet_money / 2 << " $ money." << std::endl;
        return;
    }

    int house_value2 = wheel.spin();
    std::cout << "House value 2: " << house_value2 << std::endl;

    if (house_value2 <= Player_value) {
        updateMoney(bet_money / 2);
        std::cout << "House loses on second spin! Player wins " << bet_money / 2 << " $ money." << std::endl;
    }
    else {
        updateMoney(-bet_money / 2);
        std::cout << "House wins both spins! Player loses " << bet_money / 2 << " $ money." << std::endl;
    }
}




void Player::wagerSameHard(int Player_value) {
    int house_value = hard.spin();
    std::cout << "Player value: " << Player_value << ", House value: " << house_value << std::endl;
    if (house_value >= Player_value) {
        hard.incrementWins();
        updateMoney(-bet_money);
        std::cout << "House wins! Player loses " << bet_money << " $ money." << std::endl;
    }
    else {
        hard.incrementLosses();
        updateMoney(bet_money);
        std::cout << "Player wins! Player gains " << bet_money << " $ money." << std::endl;

    }
    hard.checkRangeAdjustment();
}

void Player::wagerDoubleHard(int Player_value) {
    int house_value1 = hard.spin();
    std::cout << "Player value: " << Player_value << ", House value 1: " << house_value1 << std::endl;
    if (house_value1 >= Player_value) {
        hard.incrementWins();
        updateMoney(-2 * bet_money);
        std::cout << "House wins on first spin! Player loses " << 2 * bet_money << " $ money." << std::endl;
        hard.checkRangeAdjustment();
        return;
    }
    int house_value2 = hard.spin();
    std::cout << "House value 2: " << house_value2 << std::endl;
    if (house_value2 >= Player_value) {
        hard.incrementWins();
        updateMoney(-2 * bet_money);
        std::cout << "House wins on second spin! Player loses " << 2 * bet_money << " $ money." << std::endl;
    }
    else {
        hard.incrementLosses();
        updateMoney(2 * bet_money);
        std::cout << "Player wins! Player gains " << 2 * bet_money << " $ money." << std::endl;
    }
    hard.checkRangeAdjustment();

}


void Player::wagerHalfHard(int Player_value) {
    int house_value1 = hard.spin();
    std::cout << "Player value: " << Player_value << ", House value 1: " << house_value1 << std::endl;

    if (house_value1 <= Player_value) {
        hard.incrementLosses();
        updateMoney(bet_money / 2);
        std::cout << "House loses on first spin! Player wins " << bet_money / 2 << " $ money." << std::endl;
        hard.checkRangeAdjustment();
        return;
    }

    int house_value2 = hard.spin();
    std::cout << "House value 2: " << house_value2 << std::endl;

    if (house_value2 <= Player_value) {
        hard.incrementLosses();
        updateMoney(bet_money / 2);
        std::cout << "House loses on second spin! Player wins " << bet_money / 2 << " $ money." << std::endl;
    }
    else {
        hard.incrementWins();
        updateMoney(-bet_money / 2);
        std::cout << "House wins both spins! Player loses " << bet_money / 2 << " $ money." << std::endl;
    }

    hard.checkRangeAdjustment();
}



void Player::checkWheelRangeAndEndGame(bool& continue_playing) {
    if (hard.getMaxValue() == 1) {
        std::cout << "House has won and the wheel range has decreased to 0. You can't continue anymore." << std::endl;
        std::cout << "You leave this game with " << getMoney() << " $ money." << std::endl;
        continue_playing = false;
    }
}

HardWheel& Player::getHardWheel() {
    return hard;
}
