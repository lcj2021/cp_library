---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/range_add_range_sum.hpp
    title: ds/range_add_range_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/range_add_query.test.cpp
    title: test/aoj/range_add_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/range_sum_query.test.cpp
    title: test/aoj/range_sum_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Add\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\n    static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n    static constexpr X power(const X &x, int n) noexcept { return\
    \ X(n) * x; }\n    static constexpr X unit() noexcept { return X(0); }\n    static\
    \ constexpr bool commute = true;   // ?\n};\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct Monoid_Add {\n    using value_type\
    \ = X;\n    static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\n    static constexpr X inverse(const X &x) noexcept { return -x; }\n\
    \    static constexpr X power(const X &x, int n) noexcept { return X(n) * x; }\n\
    \    static constexpr X unit() noexcept { return X(0); }\n    static constexpr\
    \ bool commute = true;   // ?\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add.hpp
  requiredBy:
  - ds/range_add_range_sum.hpp
  - ds/fenwicktree/fenwicktree.hpp
  timestamp: '2023-02-14 20:51:34+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/range_sum_query.test.cpp
  - test/aoj/range_add_query.test.cpp
documentation_of: alg/monoid/add.hpp
layout: document
redirect_from:
- /library/alg/monoid/add.hpp
- /library/alg/monoid/add.hpp.html
title: alg/monoid/add.hpp
---
