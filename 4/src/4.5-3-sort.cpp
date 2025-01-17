#include "4.5-3-sort.h"


using std::vector;
using std::swap;


void selection_sort(vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i) {
        int min_index = i;
        for (int j = i; j < a.size(); ++j) {
            if (a[j] < a[min_index])
                min_index = j;
        }
        swap(a[i], a[min_index]);
    }
}


void insertion_sort(vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; --j)
            swap(a[j - 1], a[j]);
    }
}
