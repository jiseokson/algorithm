#include <vector>
#include <iostream>

#include "6.2-1-pick.h"


void pick(std::vector<int>& picked, int total, int to_pick)
{
    if (to_pick  == 0) {
        for (int i = 0; i < picked.size(); ++i)
            std::cout << picked[i] << ' ';
        std::cout << std::endl;
        return ;
    }

    // 다음으로 선택할 가장 작은 수
    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < total; ++next) {
        picked.push_back(next);
        pick(picked, total, to_pick - 1);
        picked.pop_back();
    }
}
