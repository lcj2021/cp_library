#pragma once
#include "alg/monoid/min.hpp"
#include "alg/monoid/assign.hpp"

template <typename E, E none_val>
struct ActedMonoid_Min_Assign {
    using Monoid_X = Monoid_Min<E>;
    using Monoid_A = Monoid_Assign<E, none_val>;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static constexpr X act(X &x, A &a, const int &sz) {
        if (a == none_val) return x;
        return a;
    }
};