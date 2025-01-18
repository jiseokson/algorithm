#include <iostream>
#include <string>
#include <vector>


namespace boggle {


using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


int c;
vvi board = vvi(5);


#ifdef MAIN
int main()
#else
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


} // namespace boggle
