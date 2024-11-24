//
// Created by adelelakour on 24.11.24.
//

#pragma once

#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

enum class State {
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
  };

const int Directions[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool Compare(const vector<int> a, const vector<int> b);

void SortOpenList(vector<vector<int>>& v);

int Compute_h(int x1, int y1, int x2, int y2);

bool CheckCellValidity(int x, int y, vector<vector<State>> &grid);

void PushToOpenList(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid);

void ExpandPcikedNode(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid);

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);

string CellString(State cell);

void PrintTheBoard(const vector<vector<State>> board);

vector<vector<State>> ReadBoardFromFile(string path);

