---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_assign.hpp
    title: alg/acted_monoid/sum_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/assign.hpp\"\n\ntemplate <typename X, X none_val>\n\
    struct Monoid_Assign {\n    using value_type = X;\n    static X op(X x, X y) {\
    \ return (y == none_val ? x : y); }\n    static constexpr X unit() { return none_val;\
    \ }\n    static constexpr bool commute = false;\n};\n"
  code: "#pragma once\n\ntemplate <typename X, X none_val>\nstruct Monoid_Assign {\n\
    \    using value_type = X;\n    static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\n    static constexpr X unit() { return none_val; }\n    static\
    \ constexpr bool commute = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/sum_assign.hpp
  - alg/acted_monoid/min_assign.hpp
  timestamp: '2023-03-06 16:29:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
