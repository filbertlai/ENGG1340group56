
#include "genfield.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define SPADE "\xE2\x99\xA0"

void expand(square ** map, int row, int col, int target, int player, int score[], int &total) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (map[i][j].owner == player) {
        map[i][j].heart = target;
        if (i - 1 >= 0) {
          if (map[i-1][j].heart == target && map[i-1][j].owner == 0) {
            map[i-1][j].owner = player;
            total += score[target];
          }
        }
        if (j - 1 >= 0) {
          if (map[i][j-1].heart == target && map[i][j-1].owner == 0) {
            map[i][j-1].owner = player;
            total += score[target];
          }
        }
        if (i + 1 < row) {
          if (map[i+1][j].heart == target && map[i+1][j].owner == 0) {
            map[i+1][j].owner = player;
            total += score[target];
          }
        }
        if (j + 1 < col) {
          if (map[i][j+1].heart == target && map[i][j+1].owner == 0) {
            map[i][j+1].owner = player;
            total += score[target];
          }
        }
      }
    }
  }
}

//this is for checking whether the input is valid
//output true if the input is not valid - not in the list of after_limit[]
//output false if the input is valid so as to stop the loop
bool notinlimit (string move, string * after_limit, int size){
    for (int i=0;i<size; i++){
        if (move == after_limit[i]){
            return false;
        }
    }
    return true;
}

string choice_of_player(string limit, string name, string last_move){
    string colour[6] = {"red","blue","green","yellow","cyan","white"};
    string * after_limit = new string [6];
    string move;
    int j = 0;
    for (int i=0; i<6;i++){
        if (colour[i]!=limit && colour[i]!=last_move){
          after_limit[j] = colour[i];
          j++;
        }
    }

    //show the colour the user can choose
    int array_size = 0;
    if(last_move==limit && last_move==""){
      array_size = 6;
    }else if(last_move==limit){
      array_size = 5;
    }else if (last_move!=limit && limit==""){
      array_size = 5;
    }else{
      array_size = 4;
    }

    cout << name << ", choose a colour ";
    for (int i=0; i<array_size;i++){
        cout << after_limit[i] << "/";
    }
    cout << ": ";
    cin >> move;
    while ( notinlimit (move,after_limit, array_size) ){
        cout << RED << "Invalid Input! Please input again: " << RESET;
        cin >> move;
    }
    delete [] after_limit;

    return move;
}

bool endgame(square ** map, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (map[i][j].owner == 0) {
        return false;
      }
    }
  }
  return true;
}

int countsquare(square ** map, int row, int col, int player) {
  int number = 0;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (map[i][j].owner == player) {
        number++;
      }
    }
  }
  return number;
}



int main() {
  cout << setfill('X');
  cout << setw(47) << "X" << endl;
  cout << "XXXXXXXXXX Welcome to Grab My Heart XXXXXXXXXXX" << endl;
  cout << "XX In this game, the rule is very easy..... XXX" << endl;
  cout << "XXXXX Just.....GRAB AS MUCH AS YOU CAN!!! XXXXX" << endl;

  while (true) {
    cout << setw(47) << "X" << endl;
    cout << SPADE << " 1.View the records." << endl;
    cout << SPADE << " 2.PLAY!!!" << endl;
    cout << SPADE << " 3.Quit Game" << endl;
    cout << "Please enter the command number (1/2/3): ";

    int cmd;
    cin >> cmd;

  // check whether the input is valid (only in the range of 1-3)
    while ((cmd != 1) && (cmd != 2) && (cmd != 3)) {
      cout << RED << "Invalid Input! Please input again: " << RESET;
      cin >> cmd;
    }
    char filename[] = "Game_Record.txt";

  // open the file of the gmae records
    if (cmd == 1) {
      ifstream fin;
      fin.open(filename);
      if (fin.fail()) {
        cout << "No game record. Play a game to enter record!" << endl;
      }
      else {
        cout << setw(47) << "X" << endl;
        cout << "Game Record" << endl;
        string name, wins;
        fin >> name >> wins;
        while (fin >> name >> wins) {
          cout << name << ": " << wins << " win" << endl;
        }
        fin.close();
      }
    }


    string player1, player2;

    // function for playing the game
    if (cmd == 2){

        //enter the player names
        cout << setw(47) << "X" << endl;
        cout << "X PLease enter the names of the two players!  X" << endl;
        cout << "Player 1: ";
        cin >> player1;
        cout << "Player 2: ";
        cin >> player2;
        cout << setw(47) << "X" << endl;
        cout << "HELLO " << player1 << " and " << player2 << "!" << endl;

        //choosing level
        cout << "PLease choose the level: " << endl;
        cout << SPADE << " Easy: 1" << endl;
        cout << SPADE <<" Moderate: 2" << endl;
        cout << SPADE <<" Difficult: 3" << endl;
        cout << "Indicate your choice(e.g.1): ";
        int choice = 0;
        cin >> choice;
        //check if the input is valid
        while ((choice != 1) && (choice != 2) && (choice != 3)) {
            cout << RED << "Invalid Input! Please input again: " << RESET;
            cin >> choice;
        }

        int score[6];
        for (int i = 0; i < 6; ++i) {
          score[i] = 1;
        }


      // if choice=1, no amendment is needed
        if(choice == 1){
            cout << "XXXXXXXXXXXXXXX LEVEL 1 - EASY XXXXXXXXXXXXXXXX" << endl;
        }

      // if choice=2, there is limitation in choosing the color
      // here is the description of the rule
        else if(choice == 2){
            cout << setw(47) << "X" << endl;
            cout << "XXXXXXXXXXXXX LEVEL 2 - MODERATE XXXXXXXXXXXXXX" << endl;
            cout << "XXXXXX In this level, you can limit your XXXXXX" << endl;
            cout << "XXXXXXXX opponent's choice on colour:) XXXXXXXX" << endl;
            cout << "You can choose red/blue/green/yellow/cyan/white" << endl;
        }

      // if choice =3, every colour is assigned with random scores
        else if (choice == 3){
            cout << setw(47) << "X" << endl;
            cout << "XXXXXXXXXXXX LEVEL 3 - DIFFICULT XXXXXXXXXXXXXX" << endl;
            cout << "XXXXXX In this level, different colours XXXXXXX" << endl;
            cout << "XXXXXXX are assigned with random scores XXXXXXX" << endl;
            cout << "XXXXXXXXXXXXX Your goal is to get XXXXXXXXXXXXX" << endl;
            cout << "XXXXXX a higher score than your opponent XXXXXX" << endl;
            srand(time(NULL));
            for (int i = 0; i < 6; ++i) {
              score[i] = rand() % 9 + 1;
            }
            cout << "Score of red hearts: " << score[0] << endl;
            cout << "Score of blue hearts: " << score[1] << endl;
            cout << "Score of green hearts: " << score[2] << endl;
            cout << "Score of yellow hearts: " << score[3] << endl;
            cout << "Score of cyan hearts: " << score[4] << endl;
            cout << "Score of white hearts: " << score[5] << endl;

        }

        //generating the map
        int row = 0;
        int col = 0;
        cout << "Let's customize the map!!" << endl;
        cout << "The number of row: ";
        cin >> row ;
        cout << "The number of column: ";
        cin >> col ;
        square ** map = new square* [row];
        for(int i = 0; i < row; ++i)
            map[i] = new square[col];
        randheart(map, row, col);

        // start playing
        cout << "Let's start playing!" << endl;
        cout << "- " << player1 << " will start at bottom-left corner " << endl;
        cout << "- " << player2 << " will start at top-right corner." << endl;
        map[row-1][0].owner = 1;
        map[0][col-1].owner = 2;
        printmap(map, row, col);
        cout << "Score of red hearts: " << score[0] << endl;
        cout << "Score of blue hearts: " << score[1] << endl;
        cout << "Score of green hearts: " << score[2] << endl;
        cout << "Score of yellow hearts: " << score[3] << endl;
        cout << "Score of cyan hearts: " << score[4] << endl;
        cout << "Score of white hearts: " << score[5] << endl;
        int playerscore[2];
        playerscore[0] = score[map[row-1][0].heart];
        playerscore[1] = score[map[0][col-1].heart];
        cout << "Score of " << player1 << ": " << playerscore[0] << endl;
        cout << "Score of " << player2 << ": " << playerscore[1] << endl;
        int round = 0;

// while till end game
        string last_move = "",limit = "",move ="";
        while (!endgame(map, row, col)) {
            string name, opponent;
            int turn, m;
            round++;
                if (round % 2 == 1){
                    name = player1;
                    opponent = player2;
                    turn = 1;
                }
                else {
                    name = player2;
                    opponent = player1;
                    turn = 2;
                }

        // if choice=2, there is limitation in choosing the color
            limit = "";
            if(choice == 2){
                cout << YELLOW << opponent << ", please indicate the colour that your want to limit your opponent to choose: " << RESET;
                cin >> limit;
                while ( (limit != "red") && (limit != "blue") && (limit != "green")&& (limit != "yellow")&& (limit != "cyan")&& (limit != "white") ){
                    cout << RED << "Invalid Input! Please input again: " << RESET;
                    cin >> limit;
                }
                cout << setw(47) << "X" << endl;
            }
            move = choice_of_player(limit, name, last_move);
            last_move = move;
            // else{
            //     cout << name << ", choose a colour (red, blue, green, yellow, cyan, white): ";
            //     cin >> move;
            //     while ( (move != "red") && (move != "blue") && (move != "green")&& (move != "yellow")&& (move != "cyan")&& (move != "white") ){
            //         cout << RED << "Invalid Input! Please input again: " << RESET;
            //         cin >> move;
            //     }
            // }
            if (move == "red")
                m = 0;
            else if (move == "blue")
                m = 1;
            else if (move == "green")
                m = 2;
            else if (move == "yellow")
                m = 3;
            else if (move == "cyan")
                m = 4;
            else if (move == "white")
                m = 5;
          expand(map, row, col, m, turn, score, playerscore[turn-1]);
          printmap(map, row, col);
          cout << "Score of red hearts: " << score[0] << endl;
          cout << "Score of blue hearts: " << score[1] << endl;
          cout << "Score of green hearts: " << score[2] << endl;
          cout << "Score of yellow hearts: " << score[3] << endl;
          cout << "Score of cyan hearts: " << score[4] << endl;
          cout << "Score of white hearts: " << score[5] << endl;
          cout << "Score of " << player1 << ": " << playerscore[0] << endl;
          cout << "Score of " << player2 << ": " << playerscore[1] << endl;
        }
        if (playerscore[0] == playerscore[1])
          cout << "DRAW!" << endl;
        else if (playerscore[0] > playerscore[1])
          cout << player1 << " WINS!" << endl;
        else if (playerscore[0] < playerscore[1])
          cout << player2 << " WINS!" << endl;

        ifstream fin;
        ofstream fout;
        fin.open(filename);
        if (fin.fail()) {
          fout.open(filename);
          fout << left;
          fout << setw(25) << "Player" << setw(5) << "Wins" << endl;
          if (playerscore[0] > playerscore[1]) {
            fout << setw(25) << player1 << setw(5) << "1" << endl;
            fout << setw(25) << player2 << setw(5) << "0" << endl;
          }
          else if (playerscore[0] < playerscore[1]) {
            fout << setw(25) << player1 << setw(5) << "0" << endl;
            fout << setw(25) << player2 << setw(5) << "1" << endl;
          }
          else if (playerscore[0] == playerscore[1]) {
            fout << setw(25) << player1 << setw(5) << "0" << endl;
            fout << setw(25) << player2 << setw(5) << "0" << endl;
          }
          fout.close();
        }
        else {
          string name, wins;
          int w;
          bool addplayer1 = false, addplayer2 = false;
          fout.open("temp.txt");
          fin >> name >> wins;
          fout << left;
          fout << setw(25) << name << setw(5) << wins << endl;
          while (fin >> name >> w) {
            if ((name != player1) && (name != player2)) {
              fout << setw(25) << name << setw(5) << w << endl;
            }
            else if (name == player1) {
              if (playerscore[0] > playerscore[1]) {
                w++;
                fout << setw(25) << name << setw(5) << w << endl;
                addplayer1 = true;
              }
              else {
                fout << setw(25) << name << setw(5) << w << endl;
                addplayer1 = true;
              }
            }
            else if (name == player2) {
              if (playerscore[0] < playerscore[1]) {
                w++;
                fout << setw(25) << name << setw(5) << w << endl;
                addplayer2 = true;
              }
              else {
                fout << setw(25) << name << setw(5) << w << endl;
                addplayer2 = true;
              }
            }
          }
          if (!addplayer1) {
            if (playerscore[0] > playerscore[1]) {
              fout << setw(25) << player1 << setw(5) << "1" << endl;
              addplayer1 = true;
            }
            else {
              fout << setw(25) << player1 << setw(5) << "0" << endl;
              addplayer1 = true;
            }
          }
          if (!addplayer2) {
            if (playerscore[0] < playerscore[1]) {
              fout << setw(25) << player2 << setw(5) << "1" << endl;
              addplayer2 = true;
            }
            else {
              fout << setw(25) << player2 << setw(5) << "0" << endl;
              addplayer2 = true;
            }
          }
          fout.close();
          fin.close();
          remove(filename);
          rename("temp.txt", filename);

        }
        char again;
        cout << "Play again (Y/N)? ";
        cin >> again;
        while ((again != 'Y') && (again != 'N')) {
          cout << "Invalid Input! Please input again: ";
          cin >> again;
        }
        if (again == 'N') {
          cout << "XXXXXXXXXXXX Bye! Hope you enjoy!! XXXXXXXXXXXX" << endl;
          break;
        }
    }

    if (cmd == 3) {
      cout << "XXXXXXXXXXXX Bye! Hope you enjoy!! XXXXXXXXXXXX" << endl;
      break;
    }
  }
  return 0;
}
