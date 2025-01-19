#include <vector>
#include <algorithm>
#include <random>

#include <gtest/gtest.h>

#include "4.1-1-majority.h"
#include "4.2-2-moving-avg.h"
#include "4.5-3-sort.h"
#include "4.6-4-maxsum.h"


using std::vector;
using std::swap;
using std::sort;

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


template<class T>
static vector<T> random_vector(size_t, int, int);


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


template<class T>
static vector<T> random_vector(size_t size, int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);

    vector<T> vec;
    for (int i = 0; i < size; ++i)
        vec.push_back(dis(gen));

    return vec;
}


TEST(Majority1Test, HandlesEmptyVector) {
    vector<int> nums;

    EXPECT_EQ(majority1(nums), -1);
}

TEST(Majority1Test, HandlesSingleElement) {
    vector<int> nums = {42};

    EXPECT_EQ(majority1(nums), 42);
}

TEST(Majority1Test, HandlesMajorityElement) {
    vector<int> nums = {3, 3, 4, 3, 5, 3};

    EXPECT_EQ(majority1(nums), 3);
}

TEST(Majority2Test, HandlesEmptyVector) {
    vector<int> nums;

    EXPECT_EQ(majority2(nums), -1);
}

TEST(Majority2Test, HandlesSingleElement) {
    vector<int> nums = {42};

    EXPECT_EQ(majority2(nums), 42);
}

TEST(Majority2Test, HandlesMajorityElement) {
    vector<int> nums = {3, 3, 4, 3, 5, 3};

    EXPECT_EQ(majority2(nums), 3);
}


TEST(MovingAvgTest1, HandlesNormalCase) {
    vector<double> input = {1.0, 2.0, 3.0, 4.0, 5.0};
    int window_size = 3;
    vector<double> result = moving_avg1(input, window_size);

    vector<double> expected = {2.0, 3.0, 4.0};
    
    for (size_t i = 0; i < result.size(); i++) {
        EXPECT_NEAR(result[i], expected[i], 1e-5);
    }
}

TEST(MovingAvgTest1, HandlesEdgeCase) {
    vector<double> input = {5.0};
    int window_size = 1;
    vector<double> result = moving_avg1(input, window_size);

    vector<double> expected = {5.0};
    EXPECT_EQ(result, expected);
}

TEST(MovingAvgTest1, HandlesEmptyVector) {
    vector<double> input = {};
    int window_size = 3;
    vector<double> result = moving_avg1(input, window_size);

    vector<double> expected = {};
    EXPECT_EQ(result, expected);
}


TEST(MovingAvgTest2, HandlesNormalCase) {
    vector<double> input = {1.0, 2.0, 3.0, 4.0, 5.0};
    int window_size = 3;
    vector<double> result = moving_avg2(input, window_size);

    vector<double> expected = {2.0, 3.0, 4.0};
    
    for (size_t i = 0; i < result.size(); i++) {
        EXPECT_NEAR(result[i], expected[i], 1e-5);
    }
}

TEST(MovingAvgTest2, HandlesEdgeCase) {
    vector<double> input = {5.0};
    int window_size = 1;
    vector<double> result = moving_avg2(input, window_size);

    vector<double> expected = {5.0};
    EXPECT_EQ(result, expected);
}

TEST(MovingAvgTest2, HandlesEmptyVector) {
    vector<double> input = {};
    int window_size = 3;
    vector<double> result = moving_avg2(input, window_size);

    vector<double> expected = {};
    EXPECT_EQ(result, expected);
}


TEST(SelectionSortTest, HandleNormalCase) {
    vector<int> input = random_vector<int>(100, 0, 100);

    vector<int> expected{input};
    sort(expected.begin(), expected.end());

    selection_sort(input);

    EXPECT_EQ(input, expected);
}

TEST(SelectionSortTest, HandleDuplicatedElements) {
    vector<int> input = {1, 4, 3, 2, 2, 1, 6, 5, 6, 7, 3, 2};

    vector<int> expected = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7};

    selection_sort(input);

    EXPECT_EQ(input, expected);
}

TEST(SelectionSortTest, HandleEmptyVector) {
    vector<int> input = {};

    vector<int> expected = {};

    selection_sort(input);

    EXPECT_EQ(input, expected);
}


TEST(InsertionSortTest, HandleNormalCase) {
    vector<int> input = random_vector<int>(100, 0, 100);

    vector<int> expected{input};
    sort(expected.begin(), expected.end());

    insertion_sort(input);

    EXPECT_EQ(input, expected);
}

TEST(InsertionSortTest, HandleDuplicatedElements) {
    vector<int> input = {1, 4, 3, 2, 2, 1, 6, 5, 6, 7, 3, 2};

    vector<int> expected = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7};

    insertion_sort(input);

    EXPECT_EQ(input, expected);
}

TEST(InsertionSortTest, HandleEmptyVector) {
    vector<int> input = {};

    vector<int> expected = {};

    selection_sort(input);

    EXPECT_EQ(input, expected);
}


TEST(InefficientMaxsumTest, HandleAllPositive) {
    vector<int> input = {1, 2, 3, 4, 5};
    int maxsum = inefficient_maxsum(input);

    int expected = 15;

    EXPECT_EQ(maxsum, expected);
}

TEST(InefficientMaxsumTest, HandleIncludeNegative) {
    vector<int> input = {1, 2, -7, 3, -2, 4, 5};
    int maxsum = inefficient_maxsum(input);

    int expected = 10;

    EXPECT_EQ(maxsum, expected);
}


TEST(BetterMaxsumTest, HandleAllPositive) {
    vector<int> input = {1, 2, 3, 4, 5};
    int maxsum = better_maxsum(input);

    int expected = 15;

    EXPECT_EQ(maxsum, expected);
}

TEST(BetterMaxsumTest, HandleIncludeNegative) {
    vector<int> input = {1, 2, -7, 3, -2, 4, 5};
    int maxsum = better_maxsum(input);

    int expected = 10;

    EXPECT_EQ(maxsum, expected);
}


TEST(FastMaxsumTest, HandleAllPositive) {
    vector<int> input = {1, 2, 3, 4, 5};
    int maxsum = fast_maxsum(input);

    int expected = 15;

    EXPECT_EQ(maxsum, expected);
}

TEST(FastMaxsumTest, HandleIncludeNegative) {
    vector<int> input = {1, 2, -7, 3, -2, 4, 5};
    int maxsum = fast_maxsum(input);

    int expected = 10;

    EXPECT_EQ(maxsum, expected);
}


TEST(FastestMaxsumTest, HandleAllPositive) {
    vector<int> input = {1, 2, 3, 4, 5};
    int maxsum = fastest_maxsum(input);

    int expected = 15;

    EXPECT_EQ(maxsum, expected);
}

TEST(FastestMaxsumTest, HandleIncludeNegative) {
    vector<int> input = {1, 2, -7, 3, -2, 4, 5};
    int maxsum = fastest_maxsum(input);

    int expected = 10;

    EXPECT_EQ(maxsum, expected);
}


TEST(InefficientMaxsumBench, N1000) {
    vector<int> input = random_vector<int>(1000, -500, 500);
    int maxsum = inefficient_maxsum(input);
}

TEST(InefficientMaxsumBench, N10000) {
    vector<int> input = random_vector<int>(10000, -5000, 5000);
    int maxsum = inefficient_maxsum(input);
}


TEST(BetterMaxsumBench, N1000) {
    vector<int> input = random_vector<int>(1000, -500, 500);
    int maxsum = better_maxsum(input);
}

TEST(BetterMaxsumBench, N10000) {
    vector<int> input = random_vector<int>(10000, -5000, 5000);
    int maxsum = better_maxsum(input);
}

TEST(BetterMaxsumBench, N100000) {
    vector<int> input = random_vector<int>(100000, -50000, 50000);
    int maxsum = better_maxsum(input);
}


TEST(FastMaxsumBench, N1000) {
    vector<int> input = random_vector<int>(1000, -500, 500);
    int maxsum = fast_maxsum(input);
}

TEST(FastMaxsumBench, N10000) {
    vector<int> input = random_vector<int>(10000, -5000, 5000);
    int maxsum = fast_maxsum(input);
}

TEST(FastMaxsumBench, N100000) {
    vector<int> input = random_vector<int>(100000, -50000, 50000);
    int maxsum = fast_maxsum(input);
}

TEST(FastMaxsumBench, N1000000) {
    vector<int> input = random_vector<int>(1000000, -500000, 500000);
    int maxsum = fast_maxsum(input);
}


TEST(FastestMaxsumBench, N1000) {
    vector<int> input = random_vector<int>(1000, -500, 500);
    int maxsum = fastest_maxsum(input);
}

TEST(FastestMaxsumBench, N10000) {
    vector<int> input = random_vector<int>(10000, -5000, 5000);
    int maxsum = fastest_maxsum(input);
}

TEST(FastestMaxsumBench, N100000) {
    vector<int> input = random_vector<int>(100000, -50000, 50000);
    int maxsum = fastest_maxsum(input);
}

TEST(FastestMaxsumBench, N1000000) {
    vector<int> input = random_vector<int>(1000000, -500000, 500000);
    int maxsum = fastest_maxsum(input);
}


// [----------] 2 tests from InefficientMaxsumBench
// [ RUN      ] InefficientMaxsumBench.N1000
// [       OK ] InefficientMaxsumBench.N1000 (234 ms)
// [ RUN      ] InefficientMaxsumBench.N10000
// [       OK ] InefficientMaxsumBench.N10000 (224246 ms)
// [----------] 2 tests from InefficientMaxsumBench (224481 ms total)

// [----------] 3 tests from BetterMaxsumBench
// [ RUN      ] BetterMaxsumBench.N1000
// [       OK ] BetterMaxsumBench.N1000 (2 ms)
// [ RUN      ] BetterMaxsumBench.N10000
// [       OK ] BetterMaxsumBench.N10000 (203 ms)
// [ RUN      ] BetterMaxsumBench.N100000
// [       OK ] BetterMaxsumBench.N100000 (19953 ms)
// [----------] 3 tests from BetterMaxsumBench (20159 ms total)

// [----------] 4 tests from FastMaxsumBench
// [ RUN      ] FastMaxsumBench.N1000
// [       OK ] FastMaxsumBench.N1000 (0 ms)
// [ RUN      ] FastMaxsumBench.N10000
// [       OK ] FastMaxsumBench.N10000 (1 ms)
// [ RUN      ] FastMaxsumBench.N100000
// [       OK ] FastMaxsumBench.N100000 (18 ms)
// [ RUN      ] FastMaxsumBench.N1000000
// [       OK ] FastMaxsumBench.N1000000 (176 ms)
// [----------] 4 tests from FastMaxsumBench (197 ms total)

// [----------] 4 tests from FastestMaxsumBench
// [ RUN      ] FastestMaxsumBench.N1000
// [       OK ] FastestMaxsumBench.N1000 (0 ms)
// [ RUN      ] FastestMaxsumBench.N10000
// [       OK ] FastestMaxsumBench.N10000 (0 ms)
// [ RUN      ] FastestMaxsumBench.N100000
// [       OK ] FastestMaxsumBench.N100000 (8 ms)
// [ RUN      ] FastestMaxsumBench.N1000000
// [       OK ] FastestMaxsumBench.N1000000 (70 ms)
// [----------] 4 tests from FastestMaxsumBench (79 ms total)
