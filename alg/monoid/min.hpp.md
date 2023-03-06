---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Min\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\n    static constexpr X unit() noexcept {\
    \ return infty<X>; }\n    static constexpr bool commute = true;   // ?\n};\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct Monoid_Min {\n    using value_type\
    \ = X;\n    static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\n    static constexpr X unit() noexcept { return infty<X>; }\n    static\
    \ constexpr bool commute = true;   // ?\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min.hpp
  requiredBy:
  - alg/acted_monoid/min_assign.hpp
  timestamp: '2023-02-17 15:05:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: alg/monoid/min.hpp
layout: document
redirect_from:
- /library/alg/monoid/min.hpp
- /library/alg/monoid/min.hpp.html
title: alg/monoid/min.hpp
---
