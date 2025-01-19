#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

static constexpr auto MAX = 4 * 16;

static int c;
static vi clocks;
static vector<vi> buttons = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13},
};

static void push(int button)
{
    for (int clock: buttons[button]) {
        clocks[clock] = (clocks[clock] + 1) % 4;
    }
}

static void undo(int button)
{
    for (int clock: buttons[button]) {
        clocks[clock] = (clocks[clock] - 1 + 4) % 4;
    }
}

static bool isdone()
{
    for (int clock: clocks) {
        if (clock != 3)
            return false;
    }
    return true;
}

static int count(int button, int acc)
{
    if (button == 10) {
        if (isdone())
            return acc;
        return -1;
    }

    int ret = MAX;

    for (int i = 0; i < 4; ++i) {
        int temp = count(button + 1, acc);
        if (temp != -1) {
            ret = min(ret, temp);
        }
        push(button);
        ++acc;
    }

    return ret == MAX ? -1 : ret;
}

#ifdef TEST_TARGET
namespace CLOCKSYNC {
void solve()
#else
int main()
#endif
{
    cin >> c;

    while (c--) {
        clocks = vi();
        for (int i = 0; i < 16; ++i) {
            int time;
            cin >> time;
            clocks.push_back(time / 3 - 1);
        }

        cout << count(0, 0) << endl;
    }
}

#ifdef TEST_TARGET
}
#endif

// 오답 원인: 문제를 제대로 읽지 않음. *버튼을 누르는 전체 횟수*를 구해야 하지만, *정답이 가능한 경우의 수*를 세는 코드를 먼저 작성함.

// 오답 원인: 정답이 존재하지 않는 경우 최소화되지 않은 ret의 값인 MAX를 그대로 반환함.

//     int ret = MAX;

//     for (int i = 0; i < 4; ++i) {
//         int temp = count(button + 1, acc);
//         if (temp != -1) {
//             ret = min(ret, temp);
//         }
//         push(button);
//         ++acc;
//     }

//     return ret; ***

// 개선: 최소화가 발생했는지 확인 후 반환값 결정

//     int ret = MAX;

//     for (int i = 0; i < 4; ++i) {
//         int temp = count(button + 1, acc);
//         if (temp != -1) {
//             ret = min(ret, temp);
//         }
//         push(button);
//         ++acc;
//     }

//     return ret == MAX ? -1 : ret; ***
