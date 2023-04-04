#pragma once

#include "concept.h"

#include <algorithm>

namespace etl {
    template<size_t Offset = 0, Unsigned T, etl::Container C>
    requires (etl::maxNumberOfDigits_v<T> <= C::size())
    constexpr void to_chars(T value, C& container) {
        typename C::size_type p{0};
        do {
            container[Offset + p++] = static_cast<char>(value % 10 + '0');
            value /= 10;
        } while (value > T{0});
        std::reverse(begin(container) + Offset, begin(container) + Offset + p - 1);
    }
    
    template<Signed T, Container C>
    requires (etl::maxNumberOfDigits_v<T> <= C::size())
    constexpr void to_chars(T value, C& container) {
        if (value < 0) {
            const std::make_unsigned_t<T> nv = -value;
            container[0] = '-';
            to_chars<1>(nv, container);
        }
        else {
            const std::make_unsigned_t<T> nv = value;
            to_chars<0>(nv, container);
        }
    }
    
}
