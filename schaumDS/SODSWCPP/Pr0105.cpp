//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.5 on page 14
//  Simulates the game of Rock, Scissors, Paper

#include <cstdlib> // defines the rand() function
#include <iostream>
using namespace std;
enum Choice {PAPER, SCISSORS, ROCK};
enum Result {YOU, ME, TIE}; 

int main()
{ // each player makes a choice:
  Choice yours, mine;
  Result winner = YOU;
  string s;
  cout << "Choose either rock, scissors, or paper (R/S/P): ";
  cin >> s;
  switch (s[0])
  { case 'R': case 'r': yours = ROCK;      break;
    case 'S': case 's': yours = SCISSORS;  break;
    case 'P': case 'p': yours = PAPER;     break;
    default:  yours = ROCK;
  }  int n = rand();  // generates a random integer
  switch (n%3)
  { case 0: mine = PAPER;     cout << "I chose paper.\n";     break;
    case 1: mine = SCISSORS;  cout << "I chose scissors.\n";  break;
    case 2: mine = ROCK;      cout << "I chose rock.\n";
  }
  if (yours == mine) winner = TIE;
  if (yours == PAPER && mine == SCISSORS
    || yours == SCISSORS && mine == ROCK
    || yours == ROCK && mine == PAPER) winner = ME;
  switch (winner)
  { case YOU: cout << "You won!\n"; break;
    case  ME: cout << "I won.\n";   break;
    case TIE: cout << "We tied.\n";
  }
}
