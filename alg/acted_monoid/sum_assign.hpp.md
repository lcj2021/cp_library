---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
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
    \ constexpr bool commute = true;   // ?\n};\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\ntemplate <typename X, X none_val>\nstruct Monoid_Assign {\n    using value_type\
    \ = X;\n    static X op(X x, X y) { return (y == none_val ? x : y); }\n    static\
    \ constexpr X unit() { return none_val; }\n    static constexpr bool commute =\
    \ false;\n};\n#line 3 \"alg/acted_monoid/sum_assign.hpp\"\n\ntemplate <typename\
    \ E, E none_val>\nstruct ActedMonoid_Sum_Assign {\n    using Monoid_X = Monoid_Add<E>;\n\
    \    using Monoid_A = Monoid_Assign<E, none_val>;\n    using X = typename Monoid_X::value_type;\n\
    \    using A = typename Monoid_A::value_type;\n    static constexpr X act(const\
    \ X &x, const A &a, const int &sz) {\n        if (a == Monoid_A::unit()) return\
    \ x;\n        return a * E(sz);\n    }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/assign.hpp\"\n\ntemplate\
    \ <typename E, E none_val>\nstruct ActedMonoid_Sum_Assign {\n    using Monoid_X\
    \ = Monoid_Add<E>;\n    using Monoid_A = Monoid_Assign<E, none_val>;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static constexpr X act(const X &x, const A &a, const int &sz) {\n       \
    \ if (a == Monoid_A::unit()) return x;\n        return a * E(sz);\n    }\n};"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_assign.hpp
  requiredBy: []
  timestamp: '2023-03-06 16:29:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
documentation_of: alg/acted_monoid/sum_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_assign.hpp
- /library/alg/acted_monoid/sum_assign.hpp.html
title: alg/acted_monoid/sum_assign.hpp
---
