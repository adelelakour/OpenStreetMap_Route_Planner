//
// Created by adelelakour on 24.11.24.
//

#include "A_star.h"



vector<vector<State>> ReadBoardFromFile(string path) {
  ifstream File_INPUT (path);
  vector<vector<State>> board{};
  if (File_INPUT.is_open()) {
    string line;
    while (getline(File_INPUT, line)) {
      istringstream sline(line);
      int n;
      char c;
      vector<State> row;
      while (sline >> n >> c && c == ',') {
        if (n == 0) {
          row.push_back(State::kEmpty);
        } else {
          row.push_back(State::kObstacle);
        }
      }
      board.push_back(row);
    }
  }
  return board;
}



bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3];
  int f2 = b[2] + b[3];
  return f1 > f2;
}



void SortOpenList(vector<vector<int>>& v) {
  sort(v.begin(), v.end(), Compare);
}


int Compute_h(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}


bool CheckCellValidity(int x, int y, vector<vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}



void PushToOpenList(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}


void ExpandPcikedNode(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  int x = current[0];
  int y = current[1];
  int g = current[2];

  for (int i = 0; i < 4; i++) {
    int x2 = x + Directions[i][0];
    int y2 = y + Directions[i][1];

    if (CheckCellValidity(x2, y2, grid)) {
      int g2 = g + 1;
      int h2 = Compute_h(x2, y2, goal[0], goal[1]);
      PushToOpenList(x2, y2, g2, h2, openlist, grid);
    }
  }
}


vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {

  vector<vector<int>> open_list_ {};

  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Compute_h(x, y, goal[0],goal[1]);
  PushToOpenList(x, y, g, h, open_list_, grid);

  while (open_list_.size() > 0) {

    SortOpenList(open_list_);
    auto current = open_list_.back();
    open_list_.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    if (x == goal[0] && y == goal[1]) {
      grid[ init[0] ][ init[1] ] = State::kStart;
      grid[ goal[0] ][ goal[1] ] = State::kFinish;
      return grid;
    }

    ExpandPcikedNode(current, goal, open_list_, grid);
  }

  cout << "No possible path \n";

  return std::vector<vector<State>>{};

}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "  ⛰  ";
    case State::kPath: return "  🔻  ";
    case State::kStart: return "  S  ";
    case State::kFinish: return "  G  ";
    default: return "  0  ";
  }
}


void PrintTheBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


