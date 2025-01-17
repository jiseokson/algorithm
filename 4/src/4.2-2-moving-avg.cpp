#include "4.2-2-moving-avg.h"


using std::vector;


/* O(N^2) */
vector<double> moving_avg1(const vector<double>& a, int m)
{
    vector<double> avgs;

    for (int i = m - 1; i < a.size(); ++i) {
        double avg = 0;
        for (int j = 0; j < m; ++j)
            avg += a[i - j];
        avg /= m;
        avgs.push_back(avg);
    }

    return avgs;
}


/* O(N) */
vector<double> moving_avg2(const vector<double>& a, int m)
{
    if (a.size() == 0)
        return vector<double>{};

    double partial_sum = 0.;
    for (int i = 0; i < m - 1; ++i)
        partial_sum += a[i];
    
    vector<double> avgs;
    for (int i = m - 1; i < a.size(); ++i) {
        partial_sum += a[i];
        avgs.push_back(partial_sum / m);
        partial_sum -= a[i - m + 1];
    }

    return avgs;
}
