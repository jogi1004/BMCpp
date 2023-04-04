#pragma once

#include <cstdint>
#include <type_traits>

namespace etl {
    namespace detail {
        template<typename T>
        struct enclosingType {};
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

    template<typename T>
    struct maxNumberOfDigits {};
    template<>
    struct maxNumberOfDigits<uint8_t> {
        static inline constexpr size_t value = 3;  
    };
    template<>
    struct maxNumberOfDigits<uint16_t> {
        static inline constexpr size_t value = 5;  
    };
    template<>
    struct maxNumberOfDigits<uint32_t> {
        static inline constexpr size_t value = 10;  
    };
    template<>
    struct maxNumberOfDigits<int8_t> {
        static inline constexpr size_t value = 4;  
    };
    template<>
    struct maxNumberOfDigits<int16_t> {
        static inline constexpr size_t value = 6;  
    };
    template<>
    struct maxNumberOfDigits<int32_t> {
        static inline constexpr size_t value = 11;  
    };
    
    template<typename T>
    static inline constexpr size_t maxNumberOfDigits_v = maxNumberOfDigits<T>::value;
    
}
