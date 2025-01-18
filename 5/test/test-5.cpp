#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

#include "5.2-1-binsearch.h"
#include "5.2-2-insertion-sort.h"


using std::vector;
using std::lower_bound;
using std::upper_bound;
using std::distance;


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(LowerBoundBinSearch1Test, UniqueTarget) {
    vector<int> input = {1, 2, 3, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch1(input, target));
}

TEST(LowerBoundBinSearch1Test, MultipleTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch1(input, target));
}

TEST(LowerBoundBinSearch1Test, UpperNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 100;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch1(input, target));
}

TEST(LowerBoundBinSearch1Test, LowerNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = -7;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch1(input, target));
}

TEST(LowerBoundBinSearch1Test, MidNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 4;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch1(input, target));
}


TEST(UpperBoundBinSearch1Test, UniqueTarget) {
    vector<int> input = {1, 2, 3, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch1(input, target));
}

TEST(UpperBoundBinSearch1Test, MultipleTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch1(input, target));
}

TEST(UpperBoundBinSearch1Test, UpperNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 100;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch1(input, target));
}

TEST(UpperBoundBinSearch1Test, LowerNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = -7;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch1(input, target));
}

TEST(UpperBoundBinSearch1Test, MidNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 4;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch1(input, target));
}


TEST(LowerBoundBinSearch2Test, UniqueTarget) {
    vector<int> input = {1, 2, 3, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch2(input, target));
}

TEST(LowerBoundBinSearch2Test, MultipleTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch2(input, target));
}

TEST(LowerBoundBinSearch2Test, UpperNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 100;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch2(input, target));
}

TEST(LowerBoundBinSearch2Test, LowerNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = -7;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch2(input, target));
}

TEST(LowerBoundBinSearch2Test, MidNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 4;

    int expected = distance(
        input.begin(),
        lower_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, lower_bound_binsearch2(input, target));
}


TEST(UpperBoundBinSearch2Test, UniqueTarget) {
    vector<int> input = {1, 2, 3, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch2(input, target));
}

TEST(UpperBoundBinSearch2Test, MultipleTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 3;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch2(input, target));
}

TEST(UpperBoundBinSearch2Test, UpperNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 100;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch2(input, target));
}

TEST(UpperBoundBinSearch2Test, LowerNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = -7;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch2(input, target));
}

TEST(UpperBoundBinSearch2Test, MidNoneTarget) {
    vector<int> input = {1, 2, 2, 3, 3, 5, 5, 6, 7};
    int target = 4;

    int expected = distance(
        input.begin(),
        upper_bound(input.begin(), input.end(), target));

    EXPECT_EQ(expected, upper_bound_binsearch2(input, target));
}


TEST(InsertionSortTest, NormalCase) {
    vector<int> input = {5, 3, 1, 7, 6, 4, 9, 2};

    vector<int> expected{input};
    std::sort(expected.begin(), expected.end());

    insertion_sort(input);

    EXPECT_EQ(expected, input);
}
