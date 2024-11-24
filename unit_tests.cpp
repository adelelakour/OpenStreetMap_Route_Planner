//
// Created by adelelakour on 24.11.24.
//

#include "gtest/gtest.h"
#include <vector>
#include "A_star.h"  // Include your main file header



TEST(heuristicTest, NegativeValues) {
    EXPECT_EQ(Compute_h(-2, -5, -4, 1), 8);
    EXPECT_EQ(Compute_h(-7, -3, 5, -2), 13);
}

TEST(heuristicTest, Zeros) {
    EXPECT_EQ(Compute_h(0, 0, 0, 0), 0);
}

TEST(Compare_Nodes, IfTrue) {
    EXPECT_TRUE(Compare({4,5,7,8}, {1,1,4,6} ));
}


TEST(Compare_Nodes, if_True) {

    vector<vector<State>> Fake_grid =
        {
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty}
        };

    EXPECT_TRUE(CheckCellValidity( 0,2, Fake_grid));
}

TEST(Compare_Nodes, if_False) {

    vector<vector<State>> Fake_grid =
        {
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty}
        };

    EXPECT_FALSE(CheckCellValidity( 0,3, Fake_grid));
}
