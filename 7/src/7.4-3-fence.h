#ifndef __7_4_3_FENCE_H__
#define __7_4_3_FENCE_H__


namespace FENCE {

void solve();

}


constexpr auto FENCE_EX1_INPUT =
"3\n"
"7\n"
"7 1 5 9 6 7 3\n"
"7\n"
"1 4 4 4 4 1 1\n"
"4\n"
"1 8 2 2\n";

constexpr auto FENCE_EX1_OUTPUT =
"20\n"
"16\n"
"8\n";


constexpr auto FENCE_EX2_INPUT =
"12\n"
"7\n"
"7 1 5 9 6 7 3\n"
"7\n"
"1 4 4 4 4 1 1\n"
"4\n"
"1 8 2 2\n"
"5\n"
"1 2 3 4 5\n"
"5\n"
"5 4 3 2 1\n"
"5\n"
"1 1 1 1 1\n"
"7\n"
"1 2 3 4 3 2 1\n"
"7\n"
"4 3 2 1 3 5 6\n"
"7\n"
"1 3 4 2 1 2 5\n"
"7\n"
"5 4 3 5 6 4 2\n"
"7\n"
"0 3 4 2 0 2 5\n"
"8\n"
"1 3 4 2 1 1 1 5\n";

constexpr auto FENCE_EX2_OUTPUT =
"20\n"
"16\n"
"8\n"
"9\n"
"9\n"
"5\n"
"10\n"
"10\n"
"7\n"
"18\n"
"6\n"
"8\n";


#endif
