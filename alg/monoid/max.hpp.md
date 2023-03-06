---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Max\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\n    static constexpr X unit() noexcept {\
    \ return -infty<X>; }\n    static constexpr bool commute = true;   // ?\n};\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct Monoid_Max {\n    using value_type\
    \ = X;\n    static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\n    static constexpr X unit() noexcept { return -infty<X>; }\n    static\
    \ constexpr bool commute = true;   // ?\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max.hpp
  requiredBy: []
  timestamp: '2023-03-06 16:29:36+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
