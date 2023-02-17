---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/range_add_query.test.cpp
    title: test/aoj/range_add_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/range_sum_query.test.cpp
    title: test/aoj/range_sum_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"basic.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define int long long\n#define i128 __int128\n#define endl \"\\n\"\n\
    #define all(v) (v).begin(), (v).end()\n#define len(v) unsigned(v.size())\n#define\
    \ popcountll(x) __builtin_popcountll(x)\n#define eb emplace_back\n#define stoi\
    \ stoll\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    // #define GEQB(v, x) distance((v).begin(), lower_bound(all(v), (x)))\n// #define\
    \ LEQB(v, x) distance((v).begin(), prev(upper_bound(all(v), (x))))\n// #define\
    \ GB(v, x) distance((v).begin(), upper_bound(all(v), (x)))\n// #define LB(v, x)\
    \ distance((v).begin(), prev(lower_bound(all(v), (x))))\n\n#define LB(v, x) distance((v).begin(),\
    \ lower_bound(all(v), (x)))\n#define UB(v, x) distance((v).begin(), upper_bound(all(v),\
    \ (x)))\n#define UNIQUE(v) \\\n    sort(all(v)), v.erase(unique(all(v)), v.end()),\
    \ v.shrink_to_fit()\n\ntemplate <class T>\nusing PQ = priority_queue<T>;\ntemplate\
    \ <class T>\nusing PQG = priority_queue<T, vector<T>, greater<T>>;\n\ntemplate\
    \ <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000'000'000'000;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<int>) * infty<int>;\ntemplate\
    \ <>\nconstexpr double infty<double> = infty<int>;\ntemplate <>\nconstexpr long\
    \ double infty<long double> = infty<int>;\n\nvoid YES(bool ok = 1) { cout << (ok\
    \ ? \"YES\" : \"NO\") << endl; }\nvoid NO(bool ok = 1) { YES(!ok); }\nvoid Yes(bool\
    \ ok = 1) { cout << (ok ? \"Yes\" : \"No\") << endl; }\nvoid No(bool ok = 1) {\
    \ Yes(!ok); }\nvoid yes(bool ok = 1) { cout << (ok ? \"yes\" : \"no\") << endl;\
    \ }\nvoid no(bool ok = 1) { yes(!ok); }\n\n#if not defined(Liucj_2022)\n#define\
    \ LOG(...)\n#endif // Liucj_2022\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define int long long\n\
    #define i128 __int128\n#define endl \"\\n\"\n#define all(v) (v).begin(), (v).end()\n\
    #define len(v) unsigned(v.size())\n#define popcountll(x) __builtin_popcountll(x)\n\
    #define eb emplace_back\n#define stoi stoll\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n// #define GEQB(v, x) distance((v).begin(),\
    \ lower_bound(all(v), (x)))\n// #define LEQB(v, x) distance((v).begin(), prev(upper_bound(all(v),\
    \ (x))))\n// #define GB(v, x) distance((v).begin(), upper_bound(all(v), (x)))\n\
    // #define LB(v, x) distance((v).begin(), prev(lower_bound(all(v), (x))))\n\n\
    #define LB(v, x) distance((v).begin(), lower_bound(all(v), (x)))\n#define UB(v,\
    \ x) distance((v).begin(), upper_bound(all(v), (x)))\n#define UNIQUE(v) \\\n \
    \   sort(all(v)), v.erase(unique(all(v)), v.end()), v.shrink_to_fit()\n\ntemplate\
    \ <class T>\nusing PQ = priority_queue<T>;\ntemplate <class T>\nusing PQG = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ i128 infty<i128> = i128(infty<int>) * infty<int>;\ntemplate <>\nconstexpr double\
    \ infty<double> = infty<int>;\ntemplate <>\nconstexpr long double infty<long double>\
    \ = infty<int>;\n\nvoid YES(bool ok = 1) { cout << (ok ? \"YES\" : \"NO\") <<\
    \ endl; }\nvoid NO(bool ok = 1) { YES(!ok); }\nvoid Yes(bool ok = 1) { cout <<\
    \ (ok ? \"Yes\" : \"No\") << endl; }\nvoid No(bool ok = 1) { Yes(!ok); }\nvoid\
    \ yes(bool ok = 1) { cout << (ok ? \"yes\" : \"no\") << endl; }\nvoid no(bool\
    \ ok = 1) { yes(!ok); }\n\n#if not defined(Liucj_2022)\n#define LOG(...)\n#endif\
    \ // Liucj_2022\n"
  dependsOn: []
  isVerificationFile: false
  path: basic.hpp
  requiredBy: []
  timestamp: '2023-02-17 15:05:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/range_sum_query.test.cpp
  - test/aoj/range_add_query.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
documentation_of: basic.hpp
layout: document
redirect_from:
- /library/basic.hpp
- /library/basic.hpp.html
title: basic.hpp
---
