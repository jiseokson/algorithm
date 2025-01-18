#include "5.2-1-binsearch.h"


/* a[i-1] < x <= a[i] 인 i 반환 (a[-1] = -inf, a[n] = inf 가정) */
int lower_bound_binsearch1(const std::vector<int>& a, int x)
{
    int lo = -1, hi = a.size();

    /* 
     * 아래 코드는 다음을 항상 보존한다. (1의 증명은 연습, 2의 증명은 자명)
     *   1. lo < hi
     *   2. a[lo] < x <= a[hi]
     * 
     * 반복문 종료되었다면 반복문 조건에 의해 lo + 1 >= hi 이고
     * 불변식 1. lo < hi 도 성립하므로 lo + 1 = hi 이다.
     * 
     * 불변식 2에 의해 a[lo] < x <= a[hi] 이고
     * a[hi - 1] < x <= a[hi] 이므로 hi는 최종적으로 찾고자 했던 답이다.
     */
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (a[mid] < x)
            lo = mid;
        else
            hi = mid;
    }

    return hi;
}


/* a[i-1] <= x < a[i] 인 i 반환 (a[-1] = -inf, a[n] = inf 가정) */
int upper_bound_binsearch1(const std::vector<int>& a, int x)
{
    int lo = -1, hi = a.size();

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (a[mid] > x)
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}


/* a[i-1] < x <= a[i] 인 i 반환 (a[-1] = -inf, a[n] = inf 가정) */
size_t lower_bound_binsearch2(const std::vector<int>& a, int x)
{
    size_t lo = 0, hi = a.size();

    while (lo < hi) {
        auto mid = (lo + hi) / 2;

        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }

    return lo;
}


/* a[i-1] <= x < a[i] 인 i 반환 (a[-1] = -inf, a[n] = inf 가정) */
size_t upper_bound_binsearch2(const std::vector<int>& a, int x)
{
    size_t lo = 0, hi = a.size();

    while (lo < hi) {
        auto mid = (lo + hi) / 2;

        if (a[mid] > x)
            hi = mid;
        else
            lo = mid + 1;
    }

    return hi;
}


// https://en.wikipedia.org/wiki/Binary_search

// 1. L <= R
// 2. A[L-1] < T <= A[R]
//
// while 종료 후 => L >= R과 불변식 1. L <= R 에 의해 L == R
// 불변식 2. A[L-1] < T <= A[R] 에 의해 A[L-1] < T <= A[L] (또는 A[R-1] < T <= A[R])
//
// function binary_search_leftmost(A, n, T):
//     L := 0
//     R := n
//     while L < R:
//         m := floor((L + R) / 2)
//         if A[m] < T:
//             L := m + 1
//         else:
//             R := m
//     return L


// *STL의 upper bound 구현은 *(it - 1) <= value < *it 인 it 반환 (아래의 알고리즘에서 R 반환하는 것과 동일한 결과)
// 1. L <= R
// 2. A[L-1] <= T < A[R]
//
// function binary_search_rightmost(A, n, T):
//     L := 0
//     R := n
//     while L < R:
//         m := floor((L + R) / 2)
//         if A[m] > T:
//             R := m
//         else:
//             L := m + 1
//     return R - 1