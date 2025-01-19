#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

static int c;
static int h, w;
static vvi board;
static bool touched;

static int block[4][3][2] = {
    {
        {0, 0}, {0, 1}, {1, 0}
    },
    {
        {0, 0}, {0, 1}, {1, 1}
    },
    {
        {0, 0}, {1, 0}, {1, -1}
    },
    {
        {0, 0}, {1, 0}, {1, 1}
    },
};

static inline bool inrange(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

static bool isputable(int y, int x, int bid)
{
    int pos[3][2] = {
        {y + block[bid][0][0], x + block[bid][0][1]},
        {y + block[bid][1][0], x + block[bid][1][1]},
        {y + block[bid][2][0], x + block[bid][2][1]},
    };

    for (int i = 0; i < 3; ++i) {
        if (!inrange(pos[i][0], pos[i][1]))
            return false;

        if (board[pos[i][0]][pos[i][1]] != '.')
            return false;
    }

    return true;
}

static void put(int y, int x, int bid, char c)
{
    int pos[3][2] = {
        {y + block[bid][0][0], x + block[bid][0][1]},
        {y + block[bid][1][0], x + block[bid][1][1]},
        {y + block[bid][2][0], x + block[bid][2][1]},
    };

    for (int i = 0; i < 3; ++i) {
        board[pos[i][0]][pos[i][1]] = c;
    }
}

static int count(int y, int x)
{
    bool found = false;
    for (; y < h; ++y) {
        for (; x < w; ++x) {
            if (board[y][x] == '.') {
                found = true;
                break;
            }
        }
        if (found)
            break;
        x = 0;
    }

    if (y == h)
        return touched;

    int ret = 0;
    touched = true;

    for (int bid = 0; bid < 4; ++bid) {
        if (!isputable(y, x, bid))
            continue;

        put(y, x, bid, '#');

        ret += count(y, x);
        
        put(y, x, bid, '.');
    }

    return ret;
}

#ifdef TEST_TARGET
namespace BOARDCOVER {
void solve()
#else
int main()
#endif
{
    cin >> c;

    while (c--) {
        cin >> h >> w;

        board = vvi(h);
        touched = false;

        for (int i = 0; i < h; ++i) {
            string row;
            cin >> row;
            for (char c: row)
                board[i].push_back(c);
        }

        cout << count(0, 0) << endl;
    }
}

#ifdef TEST_TARGET
}
#endif


// 오답 원인: 
// 첫 번째 빈 칸을 찾는 코드, 무한루프 발생
// goto 문으로 인한 반복문의 초기화 시점이 뒤섞인 것으로 추정

// 입력:
// 1
// 2 2
// ##
// ##

// ...
//     for (; y < h; ++y) {
//         for (; x < w; ++x) {
//             if (board[y][x] == '.')
//                 goto done;
//         }
//         x = 0;
//     }

// done:
// ...

// 개선: goto 문 삭제 

// bool found = 0;
// for (; y < h; ++y) {
//     for (; x < w; ++x) {
//         if (board[y][x] == '.') {
//             found = true;
//             break;
//         }
//     }
//     if (found)
//         break;
//     x = 0;
// }