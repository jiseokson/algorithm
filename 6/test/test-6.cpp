#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <gtest/gtest.h>

#include "6.2-1-pick.h"
#include "6.2-2-boggle.h"
#include "6.3-3-picnic.h"
#include "6.5-4-boardcover.h"
#include "6.8-5-clocksync.h"


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(PickTest, NormalCase) {
    // 참고: std::cout -> std::streambuf -> write() -> 커널 버퍼 -> 물리적 출력

    // std::cout의 버퍼 백업
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    // 테스트 대상 함수의 출력 결과를 기록할 버퍼로 교체
    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    std::vector<int> vec1;
    pick(vec1, 10, 4);

    // 정상 출력 결과를 기록할 버퍼로 교체
    std::ostringstream expected;
    std::cout.rdbuf(expected.rdbuf());

    for (int i1 = 0; i1 < 10; ++i1)
        for (int i2 = i1 + 1; i2 < 10; ++i2)
            for (int i3 = i2 + 1; i3 < 10; ++i3)
                for (int i4 = i3 + 1; i4 < 10; ++i4)
                    std::cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << ' ' << std::endl;

    // 기존 std::cout 버퍼로 복원
    std::cout.rdbuf(origin_cout_buf);

    EXPECT_EQ(expected.str(), output.str());
}


TEST(BoggleTest, Ex1) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(BOGGLE_EX1_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    BOGGLE::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(BOGGLE_EX1_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}


TEST(BoggleTest, Ex2) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(BOGGLE_EX2_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    BOGGLE::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(BOGGLE_EX2_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}


TEST(PicnicTest, Ex1) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(PICNIC_EX1_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    PICNIC::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(PICNIC_EX1_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}


TEST(BoardcoverTest, Ex1) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(BOARDCOVER_EX1_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    BOARDCOVER::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(BOARDCOVER_EX1_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}


TEST(BoardcoverTest, Ex2) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(BOARDCOVER_EX2_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    BOARDCOVER::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(BOARDCOVER_EX2_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}


TEST(ClocksyncTest, Ex1) {
    std::streambuf* origin_cin_buf = std::cin.rdbuf();
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::istringstream input(CLOCKSYNC_EX1_INPUT); // exercise input
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    CLOCKSYNC::solve(); // exercise namespce

    std::cin.rdbuf(origin_cin_buf);
    std::cout.rdbuf(origin_cout_buf);

    std::istringstream expected_stream(CLOCKSYNC_EX1_OUTPUT); // exercise output
    std::istringstream output_stream(output.str());

    std::string expected_line;
    while (std::getline(expected_stream, expected_line)) {
        std::string output_line;
        ASSERT_TRUE(std::getline(output_stream, output_line))
            << "no output";

        EXPECT_TRUE(expected_line == output_line || expected_line + " " == output_line)
            << "  Actual:\n"
            << output_line + "\n"
            << "Expected:\n"
            << expected_line;
    }
}
