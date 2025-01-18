#ifndef __6_2_2_BOGGLE_H__
#define __6_2_2_BOGGLE_H__


namespace BOGGLE {

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


constexpr auto BOGGLE_EX2_INPUT =
    "2\n"

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
    "GIAZAPX\n"

    "YYYYY\n"
    "YYYYY\n"
    "YYYYY\n"
    "YYYYY\n"
    "YYYYY\n"

    "2\n"
    "YYYYY\n"
    "GIRL\n";

constexpr auto BOGGLE_EX2_OUTPUT =
    "PRETTY YES\n"
    "GIRL YES\n"
    "REPEAT YES\n"
    "KARA NO\n"
    "PANDORA NO\n"
    "GIAZAPX YES\n"

    "YYYYY YES\n"
    "GIRL NO\n";


#endif