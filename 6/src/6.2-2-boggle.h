#ifndef __6_2_2_BOGGLE_H__
#define __6_2_2_BOGGLE_H__


namespace boggle {

void solve();

}


constexpr auto BOGGLE_EX1_INPUT =
    "1\n"
    "URLPM\n"
    "XPRET\n"
    "GIAET\n"
    "XTNZY\n"
    "XOQRS\n"
    "6\n"
    "PRETTY\n"
    "GIRL\n"
    "REPEAT\n"
    "KARA\n"
    "PANDORA\n"
    "GIAZAPX\n";

constexpr auto BOGGLE_EX1_OUTPUT =
    "PRETTY YES\n"
    "GIRL YES\n"
    "REPEAT YES\n"
    "KARA NO\n"
    "PANDORA NO\n"
    "GIAZAPX YES\n";


#endif