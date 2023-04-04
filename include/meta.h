#pragma once

#include <type_traits>

namespace Meta {
    template<typename... T>
    struct List {};
    
    template<typename T>
    struct front {};
    
    template<typename F, typename... T>
    struct front<List<F, T...>> {
        using type = F;  
    };
    template<typename T>
    using front_t = typename front<T>::type;
    
    template<typename T>
    struct back {};
    template<typename F, typename... T>
    struct back<List<F, T...>> {
        using type = back<List<T...>>::type;  
    };
    template<typename F>
    struct back<List<F>> {
        using type = F;  
    };
    template<typename T>
    using back_t = typename back<T>::type;
    
    template<typename... T>
    struct allSame {
        using first = front_t<List<T...>>;
//        using back = back_t<List<T...>>;
        inline static constexpr bool value = (std::is_same_v<first, T> && ...);  
    };
    
    
}
