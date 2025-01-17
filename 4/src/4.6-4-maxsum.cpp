#include "4.6-4-maxsum.h"


using std::vector;


static const int MIN = std::numeric_limits<int>::min();


static int _fast_maxsum(const vector<int>& a, int lo, int hi);


/* O(n^3), 모든 구간을 조사하는 가장 무식한 알고리즘 */
int inefficient_maxsum(const std::vector<int>& a)
{
    int maxsum = MIN;

    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j < a.size(); ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k)
                sum += a[k];

            maxsum = std::max(sum, maxsum);
        }
    }

    return maxsum;
}


/* O(n^2), 모든 구간 조사, 중간 결과 sum에 저장하여 이용 */
int better_maxsum(const std::vector<int>& a)
{
    int maxsum = MIN;

    for (int i = 0; i < a.size(); ++i) {
        int sum = 0;
        for (int j = i; j < a.size(); ++j) {
            sum += a[j];
            maxsum = std::max(sum, maxsum);
        }
    }

    return maxsum;
}


/* O(nlog(n)), 분할 정복을 이용 */
int fast_maxsum(const std::vector<int>& a)
{
    return _fast_maxsum(a, 0, a.size() - 1);
}

static int _fast_maxsum(const vector<int>& a, int lo, int hi)
{
    if (lo == hi)
        return a[lo];

    int mid = (lo + hi) / 2;

    int left = MIN, right = MIN, sum = 0;
    for (int i = mid; i >= lo; --i) {
        sum += a[i];
        left = std::max(left, sum);
    }

    sum = 0;
    for (int j = mid + 1; j <= hi; ++j) {
        sum += a[j];
        right = std::max(right, sum);
    }

    int single = std::max(_fast_maxsum(a, lo, mid), _fast_maxsum(a, mid + 1, hi));

    return std::max(left + right, single);
}


/* O(n), iterative하게 구현한 DP 이용 */
int fastest_maxsum(const std::vector<int>& a)
{
    int partial_sum = 0, maxsum = MIN;
    for (int i = 0; i < a.size(); ++i) {
        partial_sum = std::max(partial_sum, 0) + a[i];
        maxsum = std::max(partial_sum, maxsum);
    }

    return maxsum;
}
