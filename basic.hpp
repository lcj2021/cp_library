#include <bits/stdc++.h>

using namespace std;

#define int long long
#define i128 __int128
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define len(v) unsigned(v.size())
#define popcountll(x) __builtin_popcountll(x)
#define eb emplace_back
#define stoi stoll

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
// #define GEQB(v, x) distance((v).begin(), lower_bound(all(v), (x)))
// #define LEQB(v, x) distance((v).begin(), prev(upper_bound(all(v), (x))))
// #define GB(v, x) distance((v).begin(), upper_bound(all(v), (x)))
// #define LB(v, x) distance((v).begin(), prev(lower_bound(all(v), (x))))

#define LB(v, x) distance((v).begin(), lower_bound(all(v), (x)))
#define UB(v, x) distance((v).begin(), upper_bound(all(v), (x)))
#define UNIQUE(v) \
    sort(all(v)), v.erase(unique(all(v)), v.end()), v.shrink_to_fit()

template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, vector<T>, greater<T>>;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000'000'000'000;
template <>
constexpr i128 infty<i128> = i128(infty<int>) * infty<int>;
template <>
constexpr double infty<double> = infty<int>;
template <>
constexpr long double infty<long double> = infty<int>;

#if not defined(Liucj_2022)
#define LOG(...)
#endif // Liucj_2022
