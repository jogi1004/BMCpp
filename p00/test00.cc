#include <avr/io.h>

#include <cstdint>
#include <initializer_list>

#include "../include/test.h"

namespace std {
    
    template<bool B, typename TrueType, typename FalseType>
    struct conditional {
        using type = FalseType;  
    };
    template<typename TrueType, typename FalseType>
    struct conditional<true, TrueType, FalseType> {
        using type = TrueType;  
    };
    template<bool B, typename TrueType, typename FalseType>
    using conditional_t = typename conditional<B, TrueType, FalseType>::type;    
    
    template<typename ItemType, size_t N>
    struct array {
        using item_type = ItemType;
        
        using size_type = std::conditional_t<(N < 256), 
                               uint8_t, 
                               std::conditional_t<(N < 65536), uint16_t, uint32_t>
                          >;
        
        size_type size() const {
            return N;
        }
        
        ItemType* begin() {
            return &data[0];
        }
        ItemType* end() {
            return &data[N - 1] + 1;
        }
        const ItemType* begin() const {
            return &data[0];
        }
        const ItemType* end() const {
            return &data[N - 1] + 1;
        }
        ItemType& operator[](const size_t index) {
            return data[index];
        }
        const ItemType& operator[](const size_t index) const {
            return data[index];
        }
        ItemType data[N];
    };
    
    template<typename T, size_t N>
    T* begin(std::array<T, N>& a) {
        return a.begin();
    }
    template<typename T, size_t N>
    T* end(std::array<T, N>& a) {
        return a.end();
    }
    template<typename T, size_t N>
    const T* begin(const std::array<T, N>& a) {
        return a.begin();
    }
    template<typename T, size_t N>
    const T* end(const std::array<T, N>& a) {
        return a.end();
    }
}

template<typename C> // Anforderung: C ist ein Container
auto g(const C& c) {
    typename C::item_type sum{0}; // enclosing type
    for(const auto& e : c) {
        sum += e;
    }
    return sum;
}
template<typename C> // Anforderung: C ist ein Container
auto g2(const C& c) {
    typename C::item_type sum{0}; // enclosing type
    for(typename C::size_type i = 0; i < c.size(); ++i) {
        sum += c[i];
    }
    return sum;
}

#if 0

struct ABC {};

template<typename... T>
struct List {};

template<typename T>
struct Front {
};

template<typename F, typename... T>
struct Front<List<F, T...>> {
    using type = F;  
};

template<typename T>
struct Back {
};
template<typename F, typename... T>
struct Back<List<F, T...>> {
    using type = Back<List<T...>>::type;  
};
template<typename F>
struct Back<List<F>> {
    using type = F;  
};


void f() {
    using list1 = List<ABC, int, double, uint8_t>;
    using first = Front<list1>::type;
}


template<typename T, int N>
struct Z {
};

struct A {
};

bool operator>(const A& a, const A& b) {
    return true;
}

template<typename T>
T max(const T a, const T b) {
    T tmp;

//    T::_;
    
    if (a > b) {
        return a;
    }
    return b;
}

template<>  
A max<A>(const A a, const A b) {
    return A{};
}

namespace {
    A a{};    
    A b{};    
}

template<typename C1, typename C2>
struct isSame {
    inline static constexpr bool value{false};
};

template<typename C>
struct isSame<C, C> {
    inline static constexpr bool value{true};
};


template<typename T>
struct makeUnsigned {
};
template<>
struct makeUnsigned<int> {
    using type = unsigned int;  
};


template<typename T1, typename T2>
void test(T1 a, T2 b) {
//    static_assert(isSame<T1, T2>::value);
    typename makeUnsigned<T1>::type x;
//    decltype(x)::_;
}

uint16_t sum2(uint8_t a, uint8_t b) {
    return a + b;
}

namespace detail {
    template<typename T>
    struct enclosingType {
    //    using type = void;  
    };
    template<>
    struct enclosingType<uint8_t> {
        using type = uint16_t;  
    };
    template<>
    struct enclosingType<int8_t> {
        using type = int16_t;  
    };
    template<>
    struct enclosingType<uint16_t> {
        using type = uint32_t;  
    };
    template<>
    struct enclosingType<int16_t> {
        using type = int32_t;  
    };
}
template<typename T>
using enclosingType = typename detail::enclosingType<T>::type;

namespace std {
    template<typename T>
    struct is_arithmetic {
        static inline constexpr bool value{false};  
    };
    template<>
    struct is_arithmetic<uint8_t> {
        static inline constexpr bool value{true};  
    };
    template<>
    struct is_arithmetic<int> {
        static inline constexpr bool value{true};  
    };
    
    // Variablen template
    template<typename T>
    static inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
}

template<typename... T>
struct allSame {
    using first = Front<List<T...>>::type;
    using back = Back<List<T...>>::type;
//    first::_;
    inline static constexpr bool value = (isSame<back, T>::value && ...);  
};


#define VERSION 2

#if (VERSION == 1)
template<typename F, typename... T> // Parameter-Pack
F sum(F first, T... tail) { // (T0 v0, T1 v1, T2 v2, ...) 
    if constexpr(sizeof...(tail) == 0) {
        return first;
    }
    else {
        return first + (tail + ...);
    }
}
#endif
#if (VERSION == 2)
template<typename F, typename... T> 
requires (std::is_arithmetic_v<F> && allSame<F, T...>::value && (sizeof...(T) < 255))
//requires (std::is_arithmetic_v<F> && (isSame<F,T>::value && ...) && (sizeof...(T) < 255))
auto sum(F first, T... tail) { 
//    static_assert(sizeof...(tail) < 256);
//    static_assert((isSame<F,T>::value && ...), "all types must be the same");
//    static_assert(std::is_arithmetic_v<F>);
    
    if constexpr(sizeof...(tail) == 0) {
        return first;
    }
    else {
        return enclosingType<F>{first} + sum(tail...);
    }
}
#endif
#if (VERSION == 3)
template<typename F> 
F sum(F first) { 
    return first;
}
template<typename F, typename... T> 
F sum(F first, T... tail) { 
    return first + sum(tail...);
}
#endif

uint8_t x1;
uint8_t x2;
uint8_t x3;
uint8_t x4;

#endif

std::array<uint8_t, 10> a;

int main() {
    return g(a);
    
    
//    makeUnsigned<int>::type x;
////    decltype(x)::_;
    
//    test(1, 1);
////    test(1, 1.0);
    
//    auto r1 = sum(1,2,3,4,5);
////    auto r3 = sum(A{}, 1);
////    auto r2 = sum(0, 1.0,2.0,3);
////    auto r4 = sum({x1, x2, x3, x4});
//    auto r5 = sum(x1, x2, x3, x4);

//    return r5;
    
//    return isSame<int, double>::value;    
    
////    decltype(r1)::_;
////    decltype(r2)::_;
    
////    return r1 + r3;
    
////    Z<int, 3> z1;
////    Z<int, 1> z2;
    
////    decltype(z1)::_;    
////    max(a, b);
////    max(1, 2);
}





//template<typename C>
//int sum(const C& c) {
//    return 0;
//}

//template<typename T>
//T sum(const std::initializer_list<T>& values) {
//    T result{};
//    for(const auto& v : values) {
//        result += v;
//    }
//    return result;
//}

