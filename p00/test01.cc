#include <avr/io.h>

#include <cstdint>
#include <initializer_list>
#include <type_traits>
#include <array>
#include <algorithm>

#include "../include/test.h"
#include "../include/meta.h"
#include "../include/type_traits.h"
#include "../include/concept.h"
#include "../include/algorithm.h"
 
template<etl::Container C> 
auto g(const C& c) {
    using enc_t = etl::enclosingType<typename C::item_type>;
    enc_t sum{0}; 
    for(const auto& e : c) {
        sum += e;
    }
    return sum;
}
template<typename C> 
requires etl::Container<C>
auto g2(const C& c) {
    using enc_t = etl::enclosingType<typename C::item_type>;
    enc_t sum{0}; 
    for(typename C::size_type i = 0; i < c.size(); ++i) {
        sum += c[i];
    }
    return sum;
}

#if 0

struct ABC {};

void f() {
    using list1 = Meta::List<ABC, int, double, uint8_t>;
    using first = Meta::front_t<list1>;
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

template<typename T1, typename T2>
void test(T1 a, T2 b) {
//    static_assert(isSame<T1, T2>::value);
    std::make_unsigned_t<T1> x;
//    decltype(x)::_;
}

uint16_t sum2(uint8_t a, uint8_t b) {
    return a + b;
}

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
requires (std::is_arithmetic_v<F> && Meta::allSame<F, T...>::value && (sizeof...(T) < 255))
auto sum(F first, T... tail) { 
    if constexpr(sizeof...(tail) == 0) {
        return first;
    }
    else {
        return etl::enclosingType<F>{first} + sum(tail...);
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

#include <math.h>
 
struct Sinus {
    static inline constexpr auto data = []{
        std::array<uint8_t, 10> data;
        for(uint8_t i = 0; auto& v : data) {
            v = 255 * (sin((i * 2 * 3.14) / data.size()) + 1) / 2;
            ++i;
        }
        return data;
    }();
};

int index;

constexpr int test(int i) {
    return 42 + i;
}

template<size_t N>
requires(N < 2)
struct Timer final {
    Timer() = delete;
    
    static void f() {
        d = 2;
    }

    static inline int d;    
};

using t1 = Timer<0>;
using t2 = Timer<1>;
//using t3 = Timer<2>;

static inline constexpr auto text = []{
    std::array<char, 10> data{};
    etl::to_chars(-42, data);
    return data;
}();

std::array<char, 3> r1;
std::array<char, 4> r2;
std::array<char, 5> r3;
std::array<char, 6> r4;

uint8_t v1;
int8_t v2;
uint8_t v3;
uint8_t v4;

int main() {
    etl::to_chars(v1, r1);     
    etl::to_chars(v2, r2);     
    etl::to_chars(v3, r3);     
    etl::to_chars(v4, r4);     
    
    
//    return text[index];
    
//    t1::f();
    
//    Timer<0> t1;
//    t1.f();
//    Timer<0> t11;
//    t11.f();
    
    
//    Timer<1> t2;
//    Timer<42> t3;
    
    return Sinus::data[index];
    
    
//    Sinus s1;
//    Sinus s2;
    
//    return s1.data[2] + s2.data[4];


    
    
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

