#pragma once

namespace etl {
    template<typename C>
    concept Container = requires(C c) {
        c.size();
        c.begin();
        c.end();
        c[0];
        typename C::item_type;
        typename C::size_type;
    };
    
    template<typename T>
    concept Unsigned = std::is_unsigned_v<T>;
    
    template<typename T>
    concept Signed = std::is_signed_v<T>;


    
}
