#include <iostream>
#include <string>
#include <vector>


using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


int c;
vvi board = vvi(5);


#ifdef MAIN
int main()
#else
namespace boggle {
void solve()
#endif
{
    cin >> c;
    while (c--) {
        for (int i = 0; i < 5; ++i) {
            string row;
            cin >> row;
            for (char c: row)
                board[i].push_back(c);
        }
    }
}

#ifndef MAIN
} // namespace boggle
#endif
