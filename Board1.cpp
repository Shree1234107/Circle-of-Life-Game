#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Board.h"
#include "player.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"
using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int sepcheck = 0;
    int counter = 0;
    int i = 0;
    int chars = 0;
    int extra = 0;
    if ((int)input_string.length() == 0)
    {
        return 0;
    }
    for (int j = 0; j < (int)input_string.length(); j++)
    {
        if (input_string[j] == separator)
        {
            sepcheck++;
        }
    }
    if (sepcheck == 0)
    {
        arr[i] = input_string;
        return 1;
    }
    for (int k = 0; k < (int)input_string.length() + 1; k++)
    {
        chars++;
        if (input_string[k] == separator || input_string[k] == '\0')
        {
            chars--;
            arr[counter] = input_string.substr(i, chars);
            i = k + 1;
            counter++;
            chars = 0;
            if (counter == ARR_SIZE)
            {
                for (int f = i; f < (int)input_string.length() + 1; f++)
                {
                    if (input_string[f] == separator || input_string[f] == '\0')
                    {
                        extra++;
                        f = input_string.length() + 2;
                    }
                }
                k = input_string.length() + 2;
            }
        }
    }

    if (extra == 1)
    {
        return -1;
    }
    else
    {
        return counter;
    }
}
void Board::initializeBoard()
{
    // Seed random number generator in your main function once

    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 -
                                                                       green_count))
        {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
            case 0:
                temp.color = 'B'; // Blue
                break;
            case 1:
                temp.color = 'P'; // Pink
                break;
            case 2:
                temp.color = 'N'; // Brown
                break;
            case 3:
                temp.color = 'R'; // Red
                break;
            case 4:
                temp.color = 'U'; // Purple
                break;
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}
Board::Board()
{
    _player_count = 1;
    // Initialize player position
    _player_position[0] = 0;
    // Initialize tiles
    // initializeTiles();
}
Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard();
}
bool Board::isPlayerOnTile(int player_index, int pos, int bc)
{
    if (_player_position[player_index] == pos && players[player_index].getboardc() == bc)
    {
        return true;
    }
    return false;
}
void Board::displayTile(int boardchoice, int pos)
{
    string space = " ";
    string color = "";
    int player = isPlayerOnTile(0, pos, boardchoice);
    int player2 = isPlayerOnTile(1, pos, boardchoice);
    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (_tiles[boardchoice][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[boardchoice][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[boardchoice][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[boardchoice][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[boardchoice][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[boardchoice][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[boardchoice][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[boardchoice][pos].color == 'Y')
    {
        color = GREY;
    }
    if (player == true && player2 == true)
    {
        cout << color << "|1&2|" << RESET;
    }
    else if (player == true && player2 == false)
    {
        cout << color << "|1|" << RESET;
    }
    else if (player == false && player2 == true)
    {
        cout << color << "|2|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}


void Board::characterOptions()
{
    // This is the code for each player to choose a character.
    string line;
    string _Name1;
    string _Name2;
    string player1char;
    string player2char;
    int numPlayers;

    ifstream characters("character.txt");
    if (!characters)
    {
        cout << "Error opening file" << endl;
    }
    while (getline(characters, line))
    {
        cout << line << endl;
    }
    cout << "How many players: Select 1 or 2: " << endl;
    cin >> numPlayers;

    cout << "Player 1: Enter your name:" << endl;
    cin >> _Name1;

    cout << "Player 2: Enter you name:" << endl;
    cin >> _Name2;

    cout << "Player 1: Enter you character name:" << endl;
    cin >> player1char;
    cout << "Player 1: You have selected: " << player1char << endl;

    cout << "Player 2: Enter your character name: " << endl;
    cin >> player2char;
    if (player2char == player1char)
    {
        cout << "That character has already been picked: Choose another character:" << endl;
        cin >> player2char;
    }
    else
    {
        cout << "Player 2: You have selected: " << player2char << endl;
    }
}

void Board::chooseAdvisor(int player_index, bool advisor)
{
    ifstream advisorlist("advisor.txt");
    string list;
    string info[2];
    string advisor[6] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};
    int choice;
    if (advisor == true)
    {
        cin >> choice;
    }
    while (choice == players[player_index].getAdvisorChoice())
    {
        cout << "Both players can not choose the same advisor: Pick again:" << endl;
        cin >> choice;
    }
    for (int i = 1; i < choice; i++)
    {
        getline(advisorlist, list);
        split(list, '-', info, 2);
        players[player_index].setAdvisor(info[0]);
    }
}

void Board::spinWheel()
{
    srand(time(0));
    // Board game;

    // Generates a random number between 1 and 6
    int randomNumber = (rand() % 6) + 1;

    // Output the random number
    cout << "Spin the wheel: " << randomNumber << endl;

    // for (int i = 0; i < randomNumber; i++)
    // {
    //     game.movePlayer(randomNumber);
    // }

    _player_position[0] = _player_position[0] += randomNumber;
}

void Board::boardOption(int player_index) // write this in board.h
{
    if (players[player_index].getboardc() == 0)
    {
        cout << "Player chose cub training" << endl;
        players[player_index].trainCub();   // in player.h and cpp trainCub has parameters can just change to static num change
        _tiles[0][0].advisorList();         // function in tile to read advisor list from txt file
        chooseAdvisor(player_index, false); // write function for choosing advisor depending on path
    }
    else if (players[player_index].getboardc() == 1)
    {
        cout << "Player chose Straight to Pride Lands" << endl;
        players[player_index].toPrideLands();
    }
}

void Board::pathType()
{

    int p1path;
    int p2path;

    cout << "Players have the option to choose between cub training and pride lands" << endl;
    cout << "Player 1: What path would you like to choose? Select 1 for cub training and 2 for pride lands"<< endl;
    cin >> p1path;
    if(p1path == 1)
    {
        cout << "Player 1: You have chosen cub training" << endl;
    }
    else
    {
        cout << "Player 1: You have chosen pride lands" << endl;
    }
    cout << "Player 2: What path would you like to choose? Select 1 for cub training and 2 for pride lands"<< endl;
    if(p2path == 1)
    {
        cout << "Player 1: You have chosen cub training" << endl;
    }
    else
    {
        cout << "Player 1: You have chosen pride lands" << endl;
    }
}


void Board::mainmenu()
{
    int option_player_one;
    int option_player_two;
    int player;

        do
        {
            if (getPlayerPosition(0) < 52)
            {
                cout << "(P1) Main Menu: Select an option to continue" << endl;
                cout << "1. Check Player Progress (1)" << endl; // per 100 points in stats add 1000 in total points
                cout << "2. Review Character (2)" << endl;
                cout << "3. Check Position (3)" << endl;
                cout << "4. Review your Advisor (4)" << endl;
                cout << "5. Move Forward (5)" << endl;
                cin >> option_player_one;
                cout << " " << endl;

                while (option_player_one <= 0 || option_player_one > 5)
                {
                    cout << "not valid option try again" << endl;
                    cout << " " << endl;
                    cout << "(P1) Main Menu: Select an option to continue" << endl;
                    cout << "1. Check Player Progress (1)" << endl;
                    cout << "2. Review Character (2)" << endl;
                    cout << "3. Check Position (3)" << endl;
                    cout << "4. Review your Advisor (4)" << endl;
                    cout << "5. Move Forward (5)" << endl;
                    cin >> option_player_one;
                    cout << " " << endl;
                }

                switch (option_player_one)
                {
                player = 1;
                case 1:
                    cout << "P1 chose option 1" << endl;
                    checkProgress(player);
                    break;

                case 2:
                    cout << "P1 chose option 2" << endl;
                    reviewCharacter(player);
                    break;

                case 3:
                    cout << "P1 chose option 3" << endl;
                    checkPosition(player);
                    break;

                case 4:
                    cout << "P1 chose option 4" << endl;
                    reviewAdvisor(player);
                    break;

                case 5:
                    cout << "P1 chose option 5" << endl;
                    move(player);
                    break;
                }
            }
            else
            {
                player = 2;
            }
        } while (player == 1);

        // add logic for when player 1 chooses something that doesnt let it be player 2 turn then it skips this
        do
        {
            if (getPlayerPosition(1) < 52)
            {
                cout << "(P2) Main Menu: Select an option to continue" << endl;
                cout << "1. Check Player Progress (1)" << endl; // per 100 points in stats add 1000 in total points
                cout << "2. Review Character (2)" << endl;
                cout << "3. Check Position (3)" << endl;
                cout << "4. Review your Advisor (4)" << endl;
                cout << "5. Move Forward (5)" << endl;
                cin >> option_player_two;
                cout << " " << endl;

                while (option_player_two == 0 || option_player_two > 5)
                {
                    cout << "not valid option try again" << endl;
                    cout << " " << endl;
                    cout << "(Player 2) Main Menu: Select an option to continue" << endl;
                    cout << "1. Check Player Progress (1)" << endl;
                    cout << "2. Review Character (2)" << endl;
                    cout << "3. Check Position (3)" << endl;
                    cout << "4. Review your Advisor (4)" << endl;
                    cout << "5. Move Forward (5)" << endl;
                    cin >> option_player_two;
                    cout << " " << endl;
                }

                switch (option_player_two)
                {
                player = 2;
                case 1:
                    cout << "Player 2 chose option 1" << endl;
                    checkProgress(player);
                    break;

                case 2:
                    cout << "Player 2 chose option 2" << endl;
                    reviewCharacter(player);
                    break;

                case 3:
                    cout << "Player 2 chose option 3" << endl;
                    checkPosition(player);
                    break;

                case 4:
                    cout << "P2 chose option 4" << endl;
                    reviewAdvisor(player);
                    break;

                case 5:
                    cout << "Player 2 chose option 5" << endl;
                    move(player);
                    break;
                }
            }
            else
            {
                player = 1;
            }
        } while (player == 2);

        

       // cout << "Thanks for playing!" << endl;
        // wait 5 seconds
        // std::this_thread::sleep_for(std::chrono::seconds(5));
       // exit(0);
} 

void Board::chooseAdvisor(int player_index, bool adv)
{
    ifstream advisorlist("advisor.txt");
    string list;
    string info[2];
    string advisors[6] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};
    int choice;
    if(adv == true)
    {
        cin >> choice;
        while(choice == players[player_index].getAdvisorChoice())
        {
            cout << "Both players can not choose the same advisor: Choose again" << endl;
            cin >> choice;
        }
        for(int i = 1;i<choice;i++)
        {
            getline(advisorlist,list);

        }
        getline(advisorlist,list);
        split(list, '-', info, 2);
        players[player_index].setAdvisor(info[0]);
        if(choice == 6)
    }
}

// bool Board::movePlayer(int player_index)
// {
// // Increment player position
// _player_position[player_index]++;
// if (_player_position[player_index] == _BOARD_SIZE - 1)
// {
// // Player reached last tile
// return true;
// }
// return false;
// }
// int Board::getPlayerPosition(int player_index) const
// {
// if (player_index >= 0 && player_index <= _player_count)
// {
// return _player_position[player_index];
// }
// return -1;
// }
