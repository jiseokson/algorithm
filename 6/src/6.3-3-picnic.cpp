#include <iostream>
#include <vector>


using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


static int c;
static int n, m;
static vvi isfriend;
static vi check;


static int count(int i)
{
    while (i < check.size() && check[i])
        ++i;

    if (i == check.size())
        return 1;

    int ret = 0;

    for (int j = i + 1; j < check.size(); ++j) {
        if (check[j])
            continue;

        if (!isfriend[i][j])
            continue;

        check[i] = check[j] = 1;

        ret += count(i);

        check[i] = check[j] = 0;
    }

    return ret;
}


#ifdef TEST_TARGET
namespace PICNIC {
void solve()
#else
int main()
#endif
{
    cin >> c;

    while (c--) {
        isfriend = vvi(10, vi(10, 0));

        cin >> n >> m;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            isfriend[a][b] = isfriend[b][a] = 1;
        }

        check = vi(n, 0);
        cout << count(0) << endl;
    }    
}


#ifdef TEST_TARGET
} // namespace PICNIC
#endif
