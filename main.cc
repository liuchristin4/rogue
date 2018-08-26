#include <iostream>
#include <sstream>
#include <utility>
#include "playerCharacter.h"
#include "AutoDisplay.h"
#include "floor.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "shade.h"


int main() {

    while (true) {
        // initialize our AutoDisplay, floor and 
        // a string stream to keep track of the player character actions
        std::unique_ptr<AutoDisplay> ad = std::make_unique<AutoDisplay>();
        Floor f; 
        std::stringstream out;

        // Displays the screen for player to choose race
        ad->printOptions(); 
        char raceChosen;

        //initializes our Player Character then sets it to the race chosen
        std::shared_ptr<PlayerCharacter> pc;

        while (true) { //will prompt the user to keep chosing until it inputs
                       //a valid race
            if (std::cin >> raceChosen) {
                out << "Player Character has spawned";
                if (raceChosen == 'd') {
                    pc = std::make_shared<Drow>();
                    break;
                } else if (raceChosen == 'v') {
                    pc = std::make_shared<Vampire>();
                    break;
                } else if (raceChosen == 'g') {
                    pc = std::make_shared<Goblin>();
                    break;
                } else if (raceChosen == 't') {
                    pc = std::make_shared<Troll>();
                    break;
                } else if (raceChosen == 's') {
                    pc = std::make_shared<Shade>();
                    break;
                } else {
                    std::cerr << "Invalid race, please choose a valid one"
                    << std::endl;
                }
            } else { //if no input -- default shade
                pc = std::make_shared<Shade>();
                break;
            }
        }

        f.init(*pc, out); // initializes the floor, spawns in it the player 
                          // character, stairs, potions, gold, and enemies
        bool freeze = false; //var accountable for when the Enemies are frozen
                             //(can't move) or not
        std::cout << f; // prints the floor to the display
        // display for the Player Character HP, Atk, Def, Gold after the floor
        ad->printStats(*pc, f.getLevel(), out); 


       
        std::string command;
        while (true) { //will prompt the user to input until it is a valid 
                       //command
            out.str(std::string()); //clears last action in the current game
            try{
                std::cin >> command;
                if (command == "u") { //command to use Potion
                    std::string dir;
                    std::cin >> dir;
                    f.usePotion(*pc, dir, out); 
                } else if (command == "a") { //command to attack Enemy
                    std::string dir;
                    std::cin >> dir;
                    f.attackEnemy(*pc, dir, out);
                } else if (command == "f") { //command to freeze enemies, make 
                                             //them stop moving
                    if (freeze){ 
                        freeze = false; 
                    } else{ 
                        freeze = true; 
                    }

                } else if (command == "r") { //command to restart the game 
                    break;
                } else if (command == "q") { //command to quit the game
                    break;
                } else { //
                    try {
                        f.movePC(*pc, command, out);
                    } catch (InvalidMove){
                        continue;
                    }
                }
                try {
                    if (!freeze) {f.moveEnemies(out);}
                } catch (InvalidMove){
                    continue;
                }

                // Checks if the PC is dead
                if (pc->getHP() == 0) {
                    std::cout << "Sorry you lost. Would you like to play again?"
                     << std::endl;
                    std::cout << "Press r to restart and q to quit" 
                    << std::endl;
                    std::string input;
                    std::cin >> input;
                    break;
                }


                std::cout << f;
                ad->printStats(*pc, f.getLevel(), out);
            } catch (InvalidMove){
                continue;
            }
        } 

        if (command == "q") {
            break;
        }


    }

}

