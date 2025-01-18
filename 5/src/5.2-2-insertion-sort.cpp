#include "5.2-2-insertion-sort.h"


using std::vector;


void insertion_sort(std::vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; --j)
            std::swap(a[j - 1], a[j]);
    }
}
