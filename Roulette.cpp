#include <iostream>
#include <string>
#include "Player.h"
#include "Wheel.h"
#include "HardWheel.h"

int main() {
    std::string choice;
    std::cout << "Welcome to the Roulette wheel-style game " << std::endl;
    std::cout << "Please enter if you would like to play the Challenging Version or the Normal Version" << std::endl;
    std::cin >> choice;

    if (choice == "Normal" || choice == "normal" || choice == "NORMAL") {
        Player player;
        int player_total_money;
        do {
            std::cout << "Enter the total amount of money you would like to start with (Minimum has to be 6 )" << std::endl;
            std::cin >> player_total_money;
        } while (player_total_money < 6);

        player.setMoney(player_total_money);

        bool continue_playing = true;

        while (continue_playing && player.getMoney() >= 6) {
            int bet_money;
            do {
                std::cout << "Enter the bet amount you would like to place (Between 6 and 20)" << std::endl;
                std::cin >> bet_money;
            } while (bet_money > player.getMoney() || bet_money < 6 || bet_money > 20  );
            player.set_Bet_Money(bet_money);

            int player_value = player.spinWheel();
            std::cout << "The ball has landed on " << player_value << " for the player" << std::endl;
            std::cout << "Choose if you would like to Double, Half or not change your wager by choosing " << std::endl;
            std::cout << " Type 1 if you would like to Double" << std::endl;
            std::cout << " Type 2 if you would like to Half" << std::endl;
            std::cout << " Type 3 if you would like to keep it same" << std::endl;

            int wager_choice;
            bool valid_choice = false;
            while (!valid_choice) {
                std::cin >> wager_choice;
                if (wager_choice == 1) {
                    player.wagerDouble(player_value);
                    valid_choice = true;
                }
                else if (wager_choice == 2) {
                    player.wagerHalf(player_value);
                    valid_choice = true;
                }
                else if (wager_choice == 3) {
                    player.wagerSame(player_value);
                    valid_choice = true;
                }
                else {
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                }
            }

            std::cout << "Player's total money: " << player.getMoney() << std::endl;

            if (player.getMoney() >= 6) {
                std::cout << "Would you like to continue playing or cash out? (Type 'continue' to keep playing or 'out' to end the game)" << std::endl;
                std::string play_choice;
                std::cin >> play_choice;
                if (play_choice == "out" || play_choice == "Out" || play_choice == "OUT") {
                    continue_playing = false;
                    std::cout << "Thanks for playing! You leave this game with " << player.getMoney() << " money." << std::endl;
                }
                else if (play_choice == "continue" || play_choice == "CONTINUE" || play_choice == "Continue") {
                    continue_playing = true;
                    std::cout << "You have chosen to continue playing this game" << std::endl;
                }
            }
            else {
                std::cout << "You don't have enough money to continue playing. Thanks for playing! You leave this game with " << player.getMoney() << " money." << std::endl;
                continue_playing = false;
            }


        }
    }
    else if (choice == "Challenging" || choice == "challenging" || choice == "CHALLENGING") {
        Player player;
        int player_total_money;
        do {
            std::cout << "Enter the total amount of money you would like to start with (Minimum has to be 6 )" << std::endl;
            std::cin >> player_total_money;
        } while (player_total_money < 6);

        player.setMoney(player_total_money);

        bool continue_playing = true;

        while (continue_playing && player.getMoney() >= 6) {
            int bet_money;
            do {
                std::cout << "Enter the bet amount you would like to place (Between 6 and 20)" << std::endl;
                std::cin >> bet_money;
            } while (bet_money > player.getMoney() || bet_money < 6 || bet_money > 20);
            player.set_Bet_Money(bet_money);

            int player_value = player.ChallengingspinWheel();
            std::cout << "The ball has landed on " << player_value << " for the player" << std::endl;
            std::cout << "Choose if you would like to Double, Half or not change your wager by choosing " << std::endl;
            std::cout << " Type 1 if you would like to Double" << std::endl;
            std::cout << " Type 2 if you would like to Half" << std::endl;
            std::cout << " Type 3 if you would like to keep it same" << std::endl;

            int wager_choice;
            bool valid_choice = false;
            while (!valid_choice) {
                std::cin >> wager_choice;
                if (wager_choice == 1) {
                    player.wagerDoubleHard(player_value);
                    valid_choice = true;
                }
                else if (wager_choice == 2) {
                    player.wagerHalfHard(player_value);
                    valid_choice = true;
                }
                else if (wager_choice == 3) {
                    player.wagerSameHard(player_value);
                    valid_choice = true;
                }
                else {
                    std::cout << "Invalid choice. Please choose again." << std::endl;
                }
            }
            std::cout << "Player's total money: $ " << player.getMoney() << std::endl;
            player.checkWheelRangeAndEndGame(continue_playing);
            if (!continue_playing) {
                break; 
            }


            if (player.getMoney() >= 6) {
                std::cout << "Would you like to continue playing or cash out? (Type 'continue' to keep playing or 'out' to end the game)" << std::endl;
                std::string play_choice;
                std::cin >> play_choice;
                std::cin.ignore();
                if (play_choice == "out" || play_choice == "Out" || play_choice == "OUT") {
                    continue_playing = false;
                    std::cout << "Thanks for playing! You leave this game with " << player.getMoney() << " $ money." << std::endl;
                }
                else if (play_choice == "continue" || play_choice == "CONTINUE" || play_choice == "Continue") {
                    continue_playing = true;
                    std::cout << "You have chosen to continue playing this game" << std::endl;
                }
            }
            else {
                std::cout << "You don't have enough money to continue playing. Thanks for playing! You leave this game with " << player.getMoney() << " $ money." << std::endl;
                continue_playing = false;
            }



        }

    }
    return 0;
    }
