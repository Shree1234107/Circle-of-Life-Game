#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "Tile.h"
// class Board
// {
// private:
// static const int _BOARD_SIZE = 52;
// Tile _tiles[2][_BOARD_SIZE];
// static const int _MAX_PLAYERS = 2;
// int _player_count;
// int _player_position[_MAX_PLAYERS];
// void displayTile(int player_index, int pos);
// void initializeTiles(int player_index);
// bool isPlayerOnTile(int player_index, int pos);
// public:
// Board();
// Board(int player_count);
// void displayTrack(int player_index);
// void initializeBoard();
// void displayBoard();
// bool movePlayer(int player_index);
// int getPlayerPosition(int player_index) const;
// };
class Board
{
private:
static const int _BOARD_SIZE = 52;
Tile _tiles[2][_BOARD_SIZE];
static const int _MAX_PLAYERS = 2;
int _player_count;
int _player_position[_MAX_PLAYERS];
//[5][0]
players players[_MAX_PLAYERS];
// void displayTile(int player_index, int pos);
// void initializeTiles(int player_index);
// bool isPlayerOnTile(int player_index, int pos);
public:
Board();
Board(int player_count);
void displayTile(int player_index, int pos);
void initializeTiles(int player_index);
bool isPlayerOnTile(int player_index, int pos, int boardindex);
void displayTrack(int player_index);
void initializeBoard();
void displayBoard();
bool movePlayer(int player_index);
int getPlayerPosition(int player_index) const;
char color; 
int boardnumber = 0;
void eventblue();
void eventpink();
void eventbrown();
void eventred();
void eventpurple();
void eventanothercolor();
void charactermenu();
void characterOptions();
void setpath();
void player1();
void player2();
void chooseAdvisor(int player_index, bool adv);
void chooseCharacter();
void spinWheel();
void mainmenu();
void quitGame();
int getTile();
void gameSetUp();
int getAdvisorChoice();
bool advisorOption();
void boardOption(int player_index);
void getgameend();
int gameend();
void setgameend();
void Game();
void reviewAdvisor(int player);
void checkPosition(int player);
void reviewCharacter(int player);
void checkProgress(int player);
void pathType();



};
#endif
