#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    do {
        for (int i: vec)
            cout << i << ' ';
        cout << endl;
    } while(next_permutation(vec.begin(), vec.end()));
}
