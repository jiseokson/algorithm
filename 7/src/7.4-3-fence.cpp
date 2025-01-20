#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

static int c;
static int n;

static vi fences;

static int maxarea(int lo, int hi)
{
    if (lo == hi)
        return fences[lo];

    if (lo + 1 == hi)
        return max(
            2 * min(fences[lo], fences[hi]),
            max(fences[lo], fences[hi]));

    int mid = (lo + hi) / 2;

    int res1 = maxarea(lo, mid - 1);
    int res2 = maxarea(mid, hi);
    int max_area = max(res1, res2);

    int l = mid - 1;
    int r = mid;

    int cur_height = min(fences[l], fences[r]);
    max_area = max(max_area, 2 * cur_height);

    while (lo < l && r < hi) {
        int l_height = min(cur_height, fences[l - 1]);
        int r_height = min(cur_height, fences[r + 1]);

        int l_area = l_height * (r - l + 2);
        int r_area = r_height * (r - l + 2);

        if (l_area > r_area) {
            --l;
            cur_height = l_height;
            max_area = max(max_area, l_area);
        } else {
            ++r;
            cur_height = r_height;
            max_area = max(max_area, r_area);
        }
    }

    for (; lo < l; --l) {
        cur_height = min(cur_height, fences[l - 1]);
        max_area = max(max_area, cur_height * (r - l + 2));
    }

    for (; r < hi; ++r) {
        cur_height = min(cur_height, fences[r + 1]);
        max_area = max(max_area, cur_height * (r - l + 2));
    }

    return max_area;
}

#ifdef TEST_TARGET
namespace FENCE {
void solve()
#else
int main()
#endif
{
    cin >> c;

    while (c--) {
        cin >> n;
        fences = vi(n);
        for (auto i = 0; i < n; ++i) {
            cin >> fences[i];
        }

        cout << maxarea(0, n - 1) << endl;
    }
}

#ifdef TEST_TARGET
}
#endif


// 오답 원인: <vector> 놓침


// 오답 원인:
// 원래 의도는 while 루프를 탈출하면 lo = l 또는 r = hi 중 하나가 참이 되도록 하여,
// 이후의 for 루프를 통해 lo 까지 도달하지 못한 l 또는 hi 까지 도달하지 못한 r 의 이동을 마무리하고자 함.

// 그러나 r = hi 조건에 의해 while 루프를 탈출했다 가정해 보자.
// 이 경우 첫 번째 for 루프는 l = lo - 1 로 종료된다.
// 문제는 r = hi 상태에서 두 번째 for 루프에 진입한다는 점이다. 이때 [lo - 1, r] 이라는 잘못된 범위를 사용한다.

//     while (lo < l && r < hi) {
//         ...
//     }

//     for (; lo < l; --l) {
//         int cur_height = min(cur_height, fences[l]);
//         max_area = max(max_area, cur_height * (r - l + 1));
//     }

//     for (; r < hi; ++r) {
//         int cur_height = min(cur_height, fences[r]);
//         max_area = max(max_area, cur_height * (r - l + 1));
//     }

// 개선:
//     while (lo < l && r < hi) {
//         ...
//     }

//     for (; lo < l; --l) {
//         int cur_height = min(cur_height, fences[l - 1]);
//         max_area = max(max_area, cur_height * (r - l + 2));
//     }

//     for (; r < hi; ++r) {
//         int cur_height = min(cur_height, fences[r + 1]);
//         max_area = max(max_area, cur_height * (r - l + 2));
//     }


// 오답 원인:
// 같은 이름으로 cur_height 다시 정의, 최소화되지 않은 문제
//     for (; r < hi; ++r) {
//         **int** cur_height = min(cur_height, fences[r + 1]);
//         max_area = max(max_area, cur_height * (r - l + 2));
//     }
