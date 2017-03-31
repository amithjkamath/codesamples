//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Maze.h
//  Interface for Maze class

#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <stack>    // defines the stack<T> class template
using namespace std;

class Maze
{   friend ostream& operator<<(ostream&, const Maze&);
  public:
    Maze(char*);
    int rows() const { return _rows; }
    int cols() const { return _cols; }
    stack<bool> solution() const;
  protected:
    int _rows, _cols;
    bool* _a;
};

#endif  // MAZE_H
