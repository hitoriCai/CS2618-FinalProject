//
// Created on 2023/11/27.
//

#ifndef FINALPROJECT_DEFINES_H
#define FINALPROJECT_DEFINES_H

#include <stdint.h> // NOLINT(*-deprecated-headers)

using ull_int = unsigned long long int;

using resistance_t = ull_int;
using voltage_t = double;

using pinID_t = uint8_t;



// A port contains 3 physical pins:
// 1. An analog pin, directly connected (no resistor) to the outside.
// 2. A digital pin, connected to the outside via a high-resistance resistor.
// 3. A digital pin, connected to the outside via a low-resistance resistor.
struct Port{
    pinID_t analogPin;
    pinID_t digitalPinHighR;
    pinID_t digitalPinLowR;

    constexpr Port(pinID_t analogPin, pinID_t digitalPinHighR, pinID_t digitalPinLowR) :
            analogPin(analogPin), digitalPinHighR(digitalPinHighR), digitalPinLowR(digitalPinLowR) {}

    // Set all pins to input mode.
    void clear() const {
        pinMode(analogPin, INPUT);
        pinMode(digitalPinHighR, INPUT);
        pinMode(digitalPinLowR, INPUT);
    }

};

using portID_t = uint8_t;

// implement std::move
template <typename T>
constexpr T&& move(T& arg) noexcept
{
    return static_cast<T&&>(arg);
}

// implement std::remove_reference
template <typename T>
struct remove_reference {
    using type = T;
};

// implement std::forward
template <typename T>
constexpr T&& forward(typename remove_reference<T>::type& arg) noexcept
{
    return static_cast<T&&>(arg);
}

#endif //FINALPROJECT_DEFINES_H
