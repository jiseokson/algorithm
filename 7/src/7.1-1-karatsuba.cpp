#include <vector>


using std::vector;


static void normalize(vector<int>&);

static void add_to(vector<int>&, const vector<int>&, int k = 0);
static void sub_to(vector<int>&, const vector<int>&);


vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<int> result(a.size() + b.size() + 1, 0);

    for (auto i = 0; i < a.size(); ++i) {
        for (auto j = 0; j < b.size(); ++j) {
            result[i + j] += a[i] * b[j];
        }
    }

    normalize(result);

    return result;
}


vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    if (a.size() < b.size())
        return karatsuba(b, a);

    if (a.size() == 0 || b.size() == 0)
        return vector<int>{};

    if (a.size() < 50)
        return multiply(a, b);

    auto a_half = a.size() / 2;
    vector<int> a0{a.begin(), a.begin() + a_half};
    vector<int> a1{a.begin() + a_half, a.end()};

    auto b_half = std::min(a_half, b.size());
    vector<int> b0{b.begin(), b.begin() + b_half};
    vector<int> b1{b.begin() + b_half, b.end()};

    vector<int> z0 = karatsuba(a0, b0); // a0 * b0
    vector<int> z1 = karatsuba(a1, b1); // a1 * b1

    add_to(a0, a1); // (a0 + a1)
    add_to(b0, b1); // (b0 + b1)

    vector<int> z2 = karatsuba(a0, b0); // (a0 + a1) * (b0 + b1)
    sub_to(z2, z0);
    sub_to(z2, z1);

    vector<int> result;
    add_to(result, z0);             // result += a0 * b0
    add_to(result, z1, 2 * a_half); // result += (a1 * b1) * 10^2k
    add_to(result, z2, a_half);     // result += (a0 * b1 + a1 * b0) * 10^k

    return result;
}


static void normalize(vector<int>& a)
{
    a.push_back(0);

    for (auto i = 0; i + 1 < a.size(); ++i) {
        if (a[i] >= 0) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        } else {
            int borrow = (9 - a[i]) / 10;
            a[i + 1] -= borrow;
            a[i] += 10 * borrow;
        }
    }

    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}


// static void add_to(vector<int>& a, const vector<int>& b, int k /* = 0 */)
// {
//     vector<int> b_k(k, 0);
//     b_k.insert(b_k.end(), b.begin(), b.end());

//     auto common = std::min(a.size(), b_k.size());

//     for (auto i = 0; i < common; ++i) {
//         a[i] += b_k[i];
//     }

//     a.insert(a.end(), b_k.begin() + common, b_k.end());

//     normalize(a);
// }

static void add_to(vector<int>& a, const vector<int>& b, int k /* = 0 */)
{
    // i < a.size() && i - k < b.size()
    for (auto i = k; i < std::min(a.size(), b.size() + k); ++i) {
        a[i] += b[i - k];
    }

    if (a.size() < k) {
        a.insert(a.end(), k - a.size(), 0);
    }

    if (a.size() < k + b.size()) {
        a.insert(a.end(), b.begin() + (a.size() - k), b.end());
    }

    normalize(a);
}


static void sub_to(vector<int>& a, const vector<int>& b)
{
    for (auto i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }

    normalize(a);
}
