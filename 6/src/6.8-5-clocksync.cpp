#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

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

static int count(int button)
{
    if (button == 10) {
        return int(isdone());
    }

    int ret = 0;

    for (int i = 0; i < 4; ++i) {
        ret += count(button + 1);
        push(button);
    }

    return ret;
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

        cout << count(0) << endl;
    }
}

#ifdef TEST_TARGET
}
#endif
