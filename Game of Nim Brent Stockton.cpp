//
//  main.cpp
//  Project 2 - Game of Nim
//
//  Created by Brent Stockton on 3/15/18. XCODE
//  Copyright © 2018 Brent Stockton. All rights reserved.
//


#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    char playerMode = 'a';                         // Mode for "Easy" or "Hard"
    int numRocks = 0;                              // Total Stones in the Pile
    int playerStartTurn = 0;                       // Player Start Choice
    int cpuEasyStoneRemove = 0;                    // Computer Removes Stone "Easy"
    int cpuHardStoneRemove = 0;                    // Computer Removes Stone "Hard"
    int playerStoneRemove = 0;                     // Players amount of stones removed
    
    //Title " The Game of Nim "
    
    cout << setw(37) << setfill('*') << " The Game of Nim " << setw(20) << "" << endl;
    cout << endl;
    cout << endl;
    
    //Program starts by displaying an introduction of the game, including its rules.
    
    cout << "Rules of the game: " << endl;
    cout << "* Each player can remove 1, 2, or 3 stones from the pile." << endl;
    cout << "* The player who makes the last move loses." << endl;
    cout << endl;
    
    //Program asks the human player to choose between an easy mode and a hard mode.
    cout << "Choose mode: " << endl;
    
    //Loop for "Mode"
    while ((playerMode != 'e') && (playerMode != 'h')) {
        cout << "Easy Mode <e> of Hard Mode <h>: ";
        cin >> playerMode;
    }
    
    srand(time(0));
    
    playerStartTurn = rand() % 2;
    
    //Easy Mode Configuration
    
    if (playerMode == 'e') {
        cout << "You have chosen easy mode." << endl;
        cout << endl;
        numRocks = ((rand() % 12) + 10);
        cout << "The initial number of stones is " << numRocks << "." << endl;
        cout << "Now a roll of the die to determine who goes first..." << endl;;
       
        //Program chooses a player randomly to start the game.
        
        if (playerStartTurn == 0) {
            cout << "The computer plays first." << endl;
        }
        else {
            cout << "You play first." << endl;;
        }
        /* The computer will pick a random number of stones (1, 2, or 3) to
         remove while never allowing the number of stones left to be negative. */
        
        while (numRocks > 0) {
            if (playerStartTurn == 0) {
                cpuEasyStoneRemove = rand() % 3 + 1;
                while (cpuEasyStoneRemove > numRocks) {
                    cpuEasyStoneRemove = rand() % 3 + 1;
                }
                numRocks = numRocks - cpuEasyStoneRemove;
                cout << endl;
                cout << "The computer is choosing a move..." << endl;;
                
                cout << "The computer removed " << cpuEasyStoneRemove << " stone from the pile." << endl;
                cout << "The pile now has " << numRocks << " left." << endl;
                playerStartTurn = 1;
            }
            
            //The human player is allowed to remove 1, 2, or 3 stones but never more than the number of stones left.
            
            else if (playerStartTurn == 1) {
                cout << endl;
                cout << "It is your turn. Enter the number of stones you would like to remove: ";
                cin >> playerStoneRemove;
                
                //Warning about invalid inputs, allowing the user to reenter input when needed.
                
                while ((playerStoneRemove <= 0) || (playerStoneRemove > 3)) {
                    cout << playerStoneRemove << " is not a valid move. Enter either 1, 2, or 3 for the number of stones: ";
                    cin >> playerStoneRemove;
                }
                //number of stones taken by the player and the resulting number of stones in each turn.
                
                numRocks = numRocks - playerStoneRemove;
                cout << "You removed " << playerStoneRemove << " stones from the pile." << endl;
                cout << "The pile now has " << numRocks << " left." <<endl;
                playerStartTurn = 0;
            }
        }
    }
    //Hard Mode Configuration
    
    // Program chooses a player randomly to start the game.
    
    else if (playerMode == 'h') {
        cout << "You have chosen hard mode." << endl;
        cout << endl;
        numRocks = ((rand() % 11) + 9);
        cout << "The initial number of stones is " << numRocks << "." << endl;
        cout << endl;
        cout << "Now a roll of the die to determine who goes first..." << endl;
        if (playerStartTurn == 0) {
            cout << "The computer plays first." << endl;
        }
        else {
            cout << "You play first." << endl;
        }
        while (numRocks > 0) {
            
            // Computer Turn
            
            /*Number of stones is a multiple of four plus 1 (e.g. 1, 5, 9, etc.), the
             computer has no winning strategy and will simply remove one stone.*/
            
            if (playerStartTurn == 0) {
                if (numRocks % 4 == 1) {
                    cpuHardStoneRemove = 1;
                }
                
                //The computer will take enough stones to leave a multiple of four plus one.
                
                else {
                    cpuHardStoneRemove = (((numRocks % 4) + 7) % 4);
                }
                numRocks = numRocks - cpuHardStoneRemove;
                cout << endl;
                cout << "The computer is choosing a move..." << endl;
                
                cout << "The computer removed " << cpuHardStoneRemove << " stone from the pile." << endl;
                cout << "The pile now has " << numRocks << " left." << endl;
                playerStartTurn = 1;
            }
            //The human player is allowed to remove 1, 2, or 3 stones but never more than the number of stones left.
            
            else if (playerStartTurn == 1) {
                cout << endl;
                cout << "It is your turn. Enter the number of stones you would like to remove: ";
                cin >> playerStoneRemove;
                while ((playerStoneRemove <= 0) || (playerStoneRemove > 3) || (playerStoneRemove > numRocks)) {
                    cout << playerStoneRemove << " is not a valid move. Enter either 1, 2, or 3 for the number of stones: ";
                    cin >> playerStoneRemove;
                }
                numRocks = numRocks - playerStoneRemove;
                cout << "You removed " << playerStoneRemove << " stones from the pile." << endl;
                cout << "The pile now has " << numRocks << " left." << endl;
                playerStartTurn = 0;
            }
        }
    }
    
    // Game ending determining whether the human player wins or loses.
    
    if (playerStartTurn == 0) {
        cout << endl;
        cout << "Sorry, you lose the game :(" << endl;
        cout << endl;
        cout << setw(37) << setfill('*') << " Thank you for playing " << setw(20) << "" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    else if (playerStartTurn == 1) {
        cout << endl;
        cout << "Congratulations, you won! :)" << endl;
        cout << endl;
        cout << setw(37) << setfill('*') << " Thank you for playing " << setw(20) << "" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    return 0;
}
