#pragma once

template <typename X>
struct Monoid_Min {
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }
    static constexpr X unit() noexcept { return infty<X>; }
    static constexpr bool commute = true;   // ?
};