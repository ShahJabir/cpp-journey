// =============================================================================
//  constants.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - const
//         * "I promise not to modify this" - can be runtime or compile-time
//         * const applies to the type to its LEFT (or the first thing to its right)
//    - constexpr
//         * "Must be evaluable at compile time when given constant inputs"
//         * Stronger than const
//    - const vs #define
//         * #define is a preprocessor macro (no type, no scope, error-prone)
//         * const / constexpr respect scope, types, and debugging
//    - const with pointers (the classic "east const" rules)
//    - const member variables (preview - covered properly when we reach OOP)
// =============================================================================

#include <array>
#include <cstddef>
#include <string>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::constants_demo {

// -----------------------------------------------------------------------------
// const at namespace scope - internal linkage by default
// -----------------------------------------------------------------------------
const int    MAX_USERS      = 1000;
const double EARTH_GRAVITY  = 9.80665;

// -----------------------------------------------------------------------------
// constexpr - true compile-time constants
// -----------------------------------------------------------------------------
constexpr int    BUFFER_SIZE       = 1024;
constexpr double PI                = 3.141592653589793;
constexpr int    SECONDS_PER_MIN   = 60;
constexpr int    MINUTES_PER_HOUR  = 60;
constexpr int    SECONDS_PER_HOUR  = SECONDS_PER_MIN * MINUTES_PER_HOUR;

// -----------------------------------------------------------------------------
// constexpr functions - can be evaluated at compile time when given
// constant-expression arguments, otherwise behave like normal functions.
// -----------------------------------------------------------------------------
constexpr int square(int x) { return x * x; }
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// -----------------------------------------------------------------------------
// Pointers and const  (read the type RIGHT-to-LEFT)
//
//   int*       p        - pointer to int
//   const int* p        - pointer to const int       (the data is const, not the pointer)
//   int* const p        - const pointer to int       (the pointer itself is const)
//   const int* const p  - const pointer to const int (both are const)
// -----------------------------------------------------------------------------
void demonstrate_const_pointers() {
    fmt::print("\n--- const and pointers ---\n");

    int x = 10;
    int y = 20;

    int*       p1       = &x;     // pointer to int
    const int* p2       = &x;     // pointer to const int (can't write through it)
    int* const p3       = &x;     // const pointer to int (can't repoint)
    const int* const p4 = &x;     // const pointer to const int

    fmt::print("x = {}, y = {}\n", x, y);

    *p1 = 99;          fmt::print("*p1 = 99           -> x = {}\n", x);  // OK
    // *p2 = 99;        // ERROR: cannot modify through pointer-to-const
    // p1 = &y;         // OK: pointer itself is not const
    // p3 = &y;         // ERROR: p3 is const
    // *p3 = 99;        // OK: data isn't const
    // *p4 = 99;        // ERROR
    // p4 = &y;         // ERROR

    fmt::print("after p1 write: x = {}\n", x);
    (void)p2; (void)p3; (void)p4;
}

// -----------------------------------------------------------------------------
// Demonstrating compile-time evaluation of constexpr
// -----------------------------------------------------------------------------
void demonstrate_constexpr() {
    fmt::print("\n--- constexpr ---\n");

    constexpr int s = square(7);          // compile-time
    constexpr int f = factorial(5);       // compile-time
    static_assert(s == 49);
    static_assert(f == 120);

    fmt::print("constexpr square(7)    = {}\n", s);
    fmt::print("constexpr factorial(5) = {}\n", f);

    // constexpr used in array size
    constexpr std::size_t N = 16;
    std::array<int, N> buffer{};
    for (std::size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] = static_cast<int>(i * i);
    }

    fmt::print("buffer[0..{}]:", N);
    for (int v : buffer) fmt::print(" {}", v);
    fmt::print("\n");
}

// -----------------------------------------------------------------------------
// const vs #define  (and why we prefer const/constexpr)
// -----------------------------------------------------------------------------
//   #define PI_MACRO 3.14159     // preprocessor text substitution
//                                  // - no type checking
//                                  // - no scope (lives until #undef)
//                                  // - can cause surprising text replacement
//                                  // - not visible to the debugger by name
//
//   const/constexpr:
//                                  // - type-checked
//                                  // - respect scope
//                                  // - visible to debuggers
//                                  // - safe in modern C++
// -----------------------------------------------------------------------------
void demonstrate_const_vs_define() {
    fmt::print("\n--- const vs #define ---\n");
    fmt::print("MAX_USERS     = {}  (typed const)\n", MAX_USERS);
    fmt::print("EARTH_GRAVITY = {:.5f}\n", EARTH_GRAVITY);
    fmt::print("BUFFER_SIZE   = {}\n",   BUFFER_SIZE);
    fmt::print("PI            = {:.10f}\n", PI);
    fmt::print("SECONDS_PER_HOUR = {}\n", SECONDS_PER_HOUR);
}

// -----------------------------------------------------------------------------
// const with references
// -----------------------------------------------------------------------------
//   const T&   - reference to const T (no copy, can't modify the referent)
//   T&        - reference to T      (can modify the referent)
// -----------------------------------------------------------------------------
void print_length(const std::string& s) {
    fmt::print("\"{}\" has length {}\n", s, s.size());
}

void demonstrate_const_references() {
    fmt::print("\n--- const references ---\n");
    std::string greeting = "Hello, C++!";
    print_length(greeting);
    print_length(std::string{"temporary"});
}

}  // namespace fundamentals::constants_demo

void run_constants_demo() {
    using namespace fundamentals::constants_demo;

    fmt::print("\n========== CONSTANTS ==========\n");

    demonstrate_const_vs_define();
    demonstrate_constexpr();
    demonstrate_const_pointers();
    demonstrate_const_references();
}
