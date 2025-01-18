#include <vector>
#include <iostream>
#include <sstream>

#include <gtest/gtest.h>

#include "6.2-1-pick.h"
#include "6.2-2-boggle.h"


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


TEST(BoggleTest, MainTest) {
    std::streambuf* origin_cout_buf = std::cout.rdbuf();

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    boggle::solve();

    std::ostringstream expected;

    EXPECT_EQ(expected.str(), output.str());
}
