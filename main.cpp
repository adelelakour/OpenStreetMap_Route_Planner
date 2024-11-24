//
// Created by adelelakour on 24.11.24.
//

#include "A_star.h"



int main() {

    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFromFile("../files/board.txt");
    auto solution = Search(board, init, goal);
    PrintTheBoard(solution);
}