// =============================================================================
//  type_conversion.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - Implicit conversion  ("automatic", a.k.a. "coercion")
//         * promotions   (char/short -> int, float -> double)
//         * usual arithmetic conversions
//         * narrowing (potentially lossy) - flagged by compilers
//    - Explicit conversion
//         * C-style cast:        (int)3.14
//         * Function-style cast:  int(3.14)
//         * static_cast<T>(x)    <- the modern, recommended form
//    - Type casting pitfalls: sign loss, precision loss, overflow
// =============================================================================

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <typeinfo>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::conversion_demo {

// -----------------------------------------------------------------------------
// 1. Implicit (automatic) conversion
// -----------------------------------------------------------------------------
//   Done by the compiler without you asking.
//   Happens in:
//     - assignments           int x = 3.14;       // double -> int, truncates
//     - function arguments    void f(int); f(3.14);
//     - binary operators      'A' + 1;            // char promoted to int
//     - return statements     return 3.14;        // from double-returning fn
//
//   "Usual arithmetic conversions": when two different numeric types meet,
//   the "smaller" / "less precise" one is converted to the "larger" one
//   (e.g. int + double -> double).
// -----------------------------------------------------------------------------

void demonstrate_implicit_conversion() {
    fmt::print("\n--- Implicit conversion ---\n");

    // Integer promotions
    char  c = 'A';     // 'A' == 65
    int   promoted = c + 1;   // 'A' promoted to int, then +1 -> 66
    fmt::print("char 'A' + 1  = {}\n", promoted);

    // Usual arithmetic conversions: int + double -> double
    int    i = 7;
    double d = 2.5;
    auto   sum = i + d;   // 7 promoted to 7.0, result is double
    fmt::print("int + double  = {} (type: {})\n", sum, typeid(sum).name());

    // Implicit narrowing - the compiler usually warns
    int truncated = 3.99;           // 3.99 -> 3 (fraction discarded)
    fmt::print("int x = 3.99  -> x = {}\n", truncated);

    // Implicit overflow on narrowing
    long long big = 3000000000LL;
    int small = static_cast<int>(big);   // would overflow without a cast
    fmt::print("narrow long long -> int : big = {}, small = {}\n", big, small);

    // bool context: any non-zero numeric value converts to true
    int zero = 0, nonzero = -7;
    fmt::print("bool(0)       = {}\n", static_cast<bool>(zero));
    fmt::print("bool(-7)      = {}\n", static_cast<bool>(nonzero));
}

// -----------------------------------------------------------------------------
// 2. Explicit conversion
// -----------------------------------------------------------------------------
//   C-style cast:      (T) expression
//   Function-style:    T(expression)
//   Named casts (modern, preferred):
//     static_cast<T>(x)       - well-defined conversions between related types
//                              (numeric <-> numeric, void* <-> T*, base <-> derived up/down)
//     const_cast<T>(x)       - add/remove constness (use sparingly)
//     reinterpret_cast<T>(x) - low-level bit reinterpretation (dangerous)
//     dynamic_cast<T>(x)     - polymorphic downcast (requires RTTI)
//
//   Prefer static_cast for numeric conversions - it forces you to think.
// -----------------------------------------------------------------------------

void demonstrate_explicit_conversion() {
    fmt::print("\n--- Explicit conversion ---\n");

    double pi = 3.14159;

    // C-style
    int a = (int)pi;
    fmt::print("(int)pi           = {}\n", a);

    // Function-style
    int b = int(pi);
    fmt::print("int(pi)           = {}\n", b);

    // Modern preferred form
    int c = static_cast<int>(pi);
    fmt::print("static_cast<int>(pi) = {}\n", c);

    // Double -> int division vs int -> double division
    int x = 7, y = 2;
    double div1 = x / y;                              // integer division first
    double div2 = static_cast<double>(x) / y;         // promoted, true division
    fmt::print("7/2 (int math)     = {}\n", div1);
    fmt::print("static_cast<double>(7)/2 = {}\n", div2);

    // Char <-> int
    char letter = 'Z';
    int  code   = static_cast<int>(letter);          // 90
    char back   = static_cast<char>(code + 1);       // '['
    fmt::print("'Z' as int  = {}\n", code);
    fmt::print("91 as char  = {}\n", back);

    // Enum <-> int (also uses static_cast)
    enum class Color { Red = 0, Green = 1, Blue = 2 };
    Color col = Color::Green;
    int   raw = static_cast<int>(col);
    Color round_trip = static_cast<Color>(raw);
    fmt::print("Color::Green -> int -> Color : {} -> {} -> {}\n",
               static_cast<int>(Color::Red),
               raw,
               static_cast<int>(round_trip));
}

// -----------------------------------------------------------------------------
// 3. Traps and pitfalls
// -----------------------------------------------------------------------------
//   - Signed / unsigned mixing:  int  vs  unsigned int
//       The signed operand is converted to unsigned (wraparound for negatives).
//   - Floating <-> integer:      truncation + possible overflow
//   - Precision loss:            float (7 sig figs) vs double (15-17)
// -----------------------------------------------------------------------------

void demonstrate_pitfalls() {
    fmt::print("\n--- Conversion pitfalls ---\n");

    // Signed / unsigned surprise
    int  a = -1;
    unsigned b = 1;
    // a is converted to unsigned -> huge number, so a > b is true
    fmt::print("int(-1) > unsigned(1) ? -> {}\n", a > b);

    // Precision loss
    float  f = 3.14159265358979f;
    double d = 3.14159265358979;
    fmt::print("float  pi = {:.20f}\n", f);
    fmt::print("double pi = {:.20f}\n", d);

    // Overflow
    int big = std::numeric_limits<int>::max();
    fmt::print("int max        = {}\n", big);
    fmt::print("int max + 1    = {}  (undefined behavior technically)\n",
               big + 1);  // signed overflow is UB; in practice it wraps.

    // Safe cast: long long -> int with bounds checking
    long long huge = 100000;
    if (huge > std::numeric_limits<int>::max() ||
        huge < std::numeric_limits<int>::min()) {
        fmt::print("long long {} does not fit in int.\n", huge);
    } else {
        int safe = static_cast<int>(huge);
        fmt::print("safe cast long long -> int : {}\n", safe);
    }
}

}  // namespace fundamentals::conversion_demo

void run_type_conversion_demo() {
    using namespace fundamentals::conversion_demo;

    fmt::print("\n========== TYPE CONVERSION ==========\n");

    demonstrate_implicit_conversion();
    demonstrate_explicit_conversion();
    demonstrate_pitfalls();
}
