#include "4.1-1-majority.h"


using std::vector;


/* O(N^2) */
int majority1(const vector<int>& a)
{
    int majority = -1, majority_count = 0;

    for (int i = 0; i < a.size(); ++i) {

        int count = 0;
        for (int j = 0; j < a.size(); ++j) {
            if (a[i] == a[j]) ++count;
        }

        if (count > majority_count) {
            majority_count = count;
            majority = a[i];
        }

    }

    return majority;
}


/* O(N) */
int majority2(const vector<int>& a)
{
    vector<int> count(101, 0);
    for (int i = 0; i < a.size(); ++i)
        ++count[i];

    int majority = -1, majority_count = 0;

    for (int i = 0; i <= 100; ++i) {
        if (count[i] > majority_count) {
            majority_count = count[i];
            majority = a[i];
        }
    }
    
    return majority;
}
