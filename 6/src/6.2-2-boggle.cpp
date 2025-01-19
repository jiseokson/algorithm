#include <iostream>
#include <string>
#include <vector>


using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


int c, n;
vvi board;

int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool _boggle(const string& word, int now, int y, int x)
{
    if (now == word.size())
        return true;

    if (!(0 <= x && x < 5 && 0 <= y && y < 5))
        return false;

    if (word[now] != board[y][x])
        return false;

    for (int d = 0; d < 8; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (_boggle(word, now + 1, ny, nx))
            return true;
    }

    return false;
}

bool boggle(const string& word)
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (_boggle(word, 0, i, j))
                return true;
        }
    }
    return false;
}

#ifdef TEST_TARGET
namespace BOGGLE {
void solve()
#else
int main()
#endif
{
    cin >> c;
    while (c--) {
        board = vvi(5);
        for (int i = 0; i < 5; ++i) {
            string row;
            cin >> row;
            for (char c: row)
                board[i].push_back(c);
        }

        cin >> n;
        while (n--) {
            string word;
            cin >> word;

            std::cout << word << ' ' << (boggle(word) ? "YES" : "NO") << '\n';
        }
    }
}

#ifdef TEST_TARGET
} // namespace BOGGLE
#endif


// 오답 원인: 다음 케이스의 입력을 받아야 하는데 이전의 입력이 보드에 남아있었다.
//   vvi board = vvi(5); *

//   main () {
//       while (c--) {
//           ....
//       }
//   }

// 개선: 새로운 케이스의 실행을 시작할 때 이용하는 자원들을 꼼꼼히 초기화하자.
//   vvi board; *

//   main () {
//       while (c--) {
//           board = vvi(5); *
//           ....
//       }
//   }
