#include <iostream>
#include <string>


using namespace std;


static int c;
static string img;


static string reverse(int& index)
{
    string result(1, img[index]);
    ++index;

    if (img[index-1] == 'x') {
        string result1 = reverse(index);
        string result2 = reverse(index);
        string result3 = reverse(index);
        string result4 = reverse(index);
        result += result3 + result4 + result1 + result2;
    }

    return result;
}


#ifdef TEST_TARGET
namespace QUADTREE{
void solve()
#else
int main()
#endif
{
    cin >> c;

    while (c--) {
        cin >> img;
        int index = 0;
        cout << reverse(index) << endl;
    }
}


#ifdef TEST_TARGET
}
#endif
