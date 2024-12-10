/*
For the player class
    1. Enter a name and give them a starting value for wisdom, strength and health
    as well as pride points, and age
    2. return those values. 
    3. Take the player to the different lands, and add points or take away points as they go along. 
    4. 

For the Board class
    1. Go through the tiles in the array with the max value as total_tiles. 
    2. Assign colors to each of the tiles. 
    3. Use the movePlayer functions and return the position of the player. 
        As well as the dice roll function to determine how many places to move. 

For the Tile class
    1. The tiles will go to different events where you can play the games and gain or lose points
    2. or you can land on another color where the player can choose to spend points to gain something. 
*/
#include "Board.h"
#include <fstream> 
// #include "player.h"
#include "Tile.h"
#include "player.h"
#include <iostream> 
using namespace std;

int main()
{
    Board b(2);
    b.displayBoard();

    Board b1;
    b1.characterOptions();

    //Board b2;
    //b2.spinWheel();

    
}