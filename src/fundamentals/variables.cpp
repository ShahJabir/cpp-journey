// =============================================================================
//  variables.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - Comments (//, /* */) and why they matter
//    - Syntax of a C++ statement
//    - "Word" vs "Keyword" (reserved words)
//    - Variables: declaration, definition, initialization
//    - Naming conventions, identifiers, literals
//    - Constants: const, constexpr
//    - Data types: fundamental (int, float, double, char, bool) + modifiers
//    - Garbage value: what an uninitialized variable contains
//    - sizeof operator: compile-time size in bytes
//    - Operators overview: unary/binary, arithmetic, relational,
//                          logical, assignment
// =============================================================================

#include <cstddef>      // std::size_t, std::byte
#include <cstdint>      // std::int32_t, std::uint16_t, ...
#include <iomanip>      // std::setw, std::setprecision
#include <iostream>
#include <limits>       // std::numeric_limits

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::variables_demo {

// -----------------------------------------------------------------------------
// 1. Comments
// -----------------------------------------------------------------------------
// Single-line comment:  // ...
// Multi-line comment:   /* ... */
//   Comments are stripped by the preprocessor before compilation.
//   They exist purely for humans.

// -----------------------------------------------------------------------------
// 2. "Word" vs "Keyword"
// -----------------------------------------------------------------------------
//   A "keyword" is a reserved word with a fixed meaning to the compiler
//   (int, if, while, return, const, ...).
//   An "identifier" is a name YOU invent for variables, functions, types.
//
//   Below: `student_count` and `average_score` are identifiers.
//          `int`, `double`, `const` are keywords.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// 3. Data types & Variables
// -----------------------------------------------------------------------------
//   Fundamental types we use most often:
//       bool, char, int, float, double, void
//
//   Modifiers: signed, unsigned, short, long, long long
//
//   Garbage value:
//       A variable declared but NOT initialized holds an indeterminate value
//       - whatever bit pattern happened to sit in memory.
//       Reading it is undefined behavior (UB).
// -----------------------------------------------------------------------------

void demonstrate_garbage_value() {
    int uninitialized;             // declared, NOT initialized -> garbage
    int initialized{};             // value-initialized to 0 (safe)
    int initialized_to_value{42};  // direct-list-initialization

    fmt::print("[garbage]  uninitialized = {}  (UB - just shown as example)\n",
               uninitialized);
    fmt::print("[zero]     initialized    = {}\n", initialized);
    fmt::print("[explicit] initialized_to_value = {}\n", initialized_to_value);

    // Best practice: always initialize your variables.
    uninitialized = 0;  // now safe
    fmt::print("[fixed]    uninitialized = {}\n", uninitialized);
}

// -----------------------------------------------------------------------------
// 4. Identifiers, Naming conventions, Literals
// -----------------------------------------------------------------------------
//   Identifiers:
//     - letters, digits, underscores
//     - must start with a letter or underscore (NOT a digit)
//     - case-sensitive
//     - cannot be a keyword
//
//   Common naming conventions in C++:
//     snake_case        -> variables, functions   (common in STL / modern C++)
//     PascalCase        -> types, classes
//     ALL_CAPS / kCamel -> macros / constants
//     kPrefix / mPrefix -> Google style for vars / members
//
//   Literals (the value itself, written in source code):
//     42        -> int literal
//     42L       -> long
//     42ULL     -> unsigned long long
//     3.14      -> double
//     3.14f     -> float
//     'A'       -> char
//     "Hello"   -> const char[6] (string literal)
//     true/false-> bool
// -----------------------------------------------------------------------------

void demonstrate_naming_and_literals() {
    int student_count = 25;                // snake_case variable
    double average_score = 87.5;           // double literal
    float  pi_approx   = 3.14159f;         // float literal (note the 'f')
    char   grade_letter = 'A';             // char literal
    bool   is_passing   = true;            // bool literal
    const char* greeting = "Hello, C++!";  // string literal

    fmt::print("student_count = {}\n", student_count);
    fmt::print("average_score = {}\n", average_score);
    fmt::print("pi_approx    = {:.5f}\n", pi_approx);
    fmt::print("grade_letter  = {}\n",   grade_letter);
    fmt::print("is_passing    = {}\n",   is_passing);
    fmt::print("greeting      = {}\n",   greeting);
}

// -----------------------------------------------------------------------------
// 5. Constants: const and constexpr
// -----------------------------------------------------------------------------
//   const     -> "I promise not to change this".  Can be runtime or compile-time.
//   constexpr -> "Evaluate this AT COMPILE TIME". A stronger guarantee.
//   #define   -> preprocessor macro (older style, generally avoided in modern C++).
// -----------------------------------------------------------------------------

constexpr double PI       = 3.141592653589793;   // compile-time constant
constexpr int    BUFFER   = 1024;

void demonstrate_constants() {
    const int max_attempts = 5;   // runtime const, can't change later

    fmt::print("PI            = {:.10f}\n", PI);
    fmt::print("BUFFER        = {}\n",    BUFFER);
    fmt::print("max_attempts  = {}\n",    max_attempts);

    // PI = 3.0;      // ERROR: read-only variable
    // max_attempts = 10;  // ERROR: read-only variable
}

// -----------------------------------------------------------------------------
// 6. sizeof operator
// -----------------------------------------------------------------------------
//   sizeof(type)        -> bytes the type occupies
//   sizeof(expression)  -> bytes the expression's type occupies
//   sizeof is a compile-time operator (returns std::size_t).
// -----------------------------------------------------------------------------

void demonstrate_sizeof() {
    fmt::print("---- sizeof (bytes) ----\n");
    fmt::print("sizeof(bool)        = {}\n", sizeof(bool));
    fmt::print("sizeof(char)        = {}\n", sizeof(char));
    fmt::print("sizeof(short)       = {}\n", sizeof(short));
    fmt::print("sizeof(int)         = {}\n", sizeof(int));
    fmt::print("sizeof(long)        = {}\n", sizeof(long));
    fmt::print("sizeof(long long)   = {}\n", sizeof(long long));
    fmt::print("sizeof(float)       = {}\n", sizeof(float));
    fmt::print("sizeof(double)      = {}\n", sizeof(double));
    fmt::print("sizeof(long double) = {}\n", sizeof(long double));
    fmt::print("sizeof(void*)       = {}\n", sizeof(void*));
    fmt::print("sizeof(std::size_t) = {}\n", sizeof(std::size_t));

    // sizeof on an expression -> size of the expression's RESULT type
    int  x = 0;
    int& r = x;
    fmt::print("sizeof(x)  = {}\n", sizeof(x));   // size of int
    fmt::print("sizeof(r)  = {}\n", sizeof(r));   // size of reference (int)
}

// -----------------------------------------------------------------------------
// 7. Operators overview
// -----------------------------------------------------------------------------
//   Arithmetic:   +  -  *  /  %
//   Relational:   == !=  <  >  <=  >=
//   Logical:      &&  ||  !
//   Assignment:   =  +=  -=  *=  /=  %=
//   Unary:        +  -  !  ~  &  *  ++  --
//   Binary (most are binary - operators taking two operands).
// -----------------------------------------------------------------------------

void demonstrate_operators() {
    int a = 10, b = 3;

    // --- Arithmetic ---
    fmt::print("---- Arithmetic ----\n");
    fmt::print("a + b  = {}\n", a +  b);
    fmt::print("a - b  = {}\n", a -  b);
    fmt::print("a * b  = {}\n", a *  b);
    fmt::print("a / b  = {}\n", a /  b);   // integer division
    fmt::print("a %% b  = {}\n", a % b);   // remainder

    // --- Relational ---
    fmt::print("---- Relational ----\n");
    fmt::print("a == b : {}\n", a == b);
    fmt::print("a != b : {}\n", a != b);
    fmt::print("a >  b : {}\n", a >  b);
    fmt::print("a <= b : {}\n", a <= b);

    // --- Logical ---
    bool p = true, q = false;
    fmt::print("---- Logical ----\n");
    fmt::print("p && q : {}\n", p && q);
    fmt::print("p || q : {}\n", p || q);
    fmt::print("!p     : {}\n", !p);

    // --- Assignment (compound) ---
    fmt::print("---- Assignment (compound) ----\n");
    int x = 10;
    x += 5;  fmt::print("x += 5   -> x = {}\n", x);   // 15
    x -= 2;  fmt::print("x -= 2   -> x = {}\n", x);   // 13
    x *= 3;  fmt::print("x *= 3   -> x = {}\n", x);   // 39
    x /= 4;  fmt::print("x /= 4   -> x = {}\n", x);   // 9
    x %= 4;  fmt::print("x %%= 4   -> x = {}\n", x);   // 1

    // --- Unary ---
    fmt::print("---- Unary ----\n");
    int n = 5;
    fmt::print("n      = {}\n", n);
    fmt::print("+n     = {}\n", +n);
    fmt::print("-n     = {}\n", -n);
    fmt::print("n++    = {}\n", n++);  // post-increment: returns OLD value, then increments
    fmt::print("n now  = {}\n", n);
    fmt::print("++n    = {}\n", ++n);  // pre-increment: increments FIRST, then returns
    fmt::print("n--    = {}\n", n--);
    fmt::print("n now  = {}\n", n);
}

}  // namespace fundamentals::variables_demo

// -----------------------------------------------------------------------------
// Public entry point used by the fundamentals/main.cpp dispatcher
// -----------------------------------------------------------------------------
void run_variables_demo() {
    using namespace fundamentals::variables_demo;

    fmt::print("\n========== VARIABLES & DATA TYPES ==========\n");

    fmt::print("\n--- Garbage value vs initialized ---\n");
    demonstrate_garbage_value();

    fmt::print("\n--- Naming conventions & literals ---\n");
    demonstrate_naming_and_literals();

    fmt::print("\n--- Constants (const / constexpr) ---\n");
    demonstrate_constants();

    fmt::print("\n--- sizeof ---\n");
    demonstrate_sizeof();

    fmt::print("\n--- Operators ---\n");
    demonstrate_operators();

    fmt::print("\n--- Numeric limits ---\n");
    fmt::print("int min        = {}\n",
               std::numeric_limits<int>::min());
    fmt::print("int max        = {}\n",
               std::numeric_limits<int>::max());
    fmt::print("double min     = {}\n",
               std::numeric_limits<double>::min());
    fmt::print("double max     = {}\n",
               std::numeric_limits<double>::max());
    fmt::print("double epsilon = {}\n",
               std::numeric_limits<double>::epsilon());

    // Suppress iomanip / cstddef include warnings by using std::size_t explicitly
    std::size_t s = sizeof(int);
    fmt::print("std::size_t s  = {}\n", s);
}
