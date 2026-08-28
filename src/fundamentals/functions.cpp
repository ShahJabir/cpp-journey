// =============================================================================
//  functions.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - Function basics
//    - Function declaration  (prototype)   return_type name(args);
//    - Function definition                  return_type name(args) { body }
//    - Function calling                     name(args);
//    - Return type
//    - Call by value        - a COPY is made; caller is unaffected
//    - Call by reference    - caller's variable IS modified
//    - Default arguments    - MUST go from RIGHT to LEFT in the parameter list
//    - Function overloading - same name, different parameter list
// =============================================================================

#include <cstddef>
#include <string>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::funcs_demo {

// -----------------------------------------------------------------------------
// 1. Declaration vs Definition
// -----------------------------------------------------------------------------
//   Declaration (prototype) - tells the compiler the signature exists.
//   Definition              - provides the body.
//   You can call a function once it has been DECLARED, even if its
//   definition appears later in the file (or in another translation unit).
// -----------------------------------------------------------------------------
int add(int a, int b);   // <-- declaration (no body)

// -----------------------------------------------------------------------------
// 2. Call by VALUE
// -----------------------------------------------------------------------------
//   The parameter is a COPY.  Modifying it inside the function does NOT
//   change the caller's variable.
// -----------------------------------------------------------------------------
void try_to_double_by_value(int n) {
    n = n * 2;          // only the local copy changes
}

// -----------------------------------------------------------------------------
// 3. Call by REFERENCE
// -----------------------------------------------------------------------------
//   The parameter is an ALIAS for the caller's variable.
//   Use '&' between type and name:  int& ref
//   Modifying the reference DOES change the caller's variable.
// -----------------------------------------------------------------------------
void double_by_reference(int& n) {
    n = n * 2;          // the caller's variable changes
}

// -----------------------------------------------------------------------------
// 4. Call by const-reference (read-only, no copy)
// -----------------------------------------------------------------------------
//   Use when you want to avoid copying a large object but promise not to
//   modify it.
// -----------------------------------------------------------------------------
std::size_t length_of(const std::string& s) {
    return s.size();
}

// -----------------------------------------------------------------------------
// 5. Default arguments
// -----------------------------------------------------------------------------
//   RULE: default arguments must be specified from RIGHT to LEFT.
//         You can't skip a parameter.
// -----------------------------------------------------------------------------
double power(double base, int exponent = 2) {   // exponent defaults to 2
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) result *= base;
    return result;
}

// This would NOT compile:
//   double bad(double base = 1.0, int exponent) { ... }   // ERROR: gap

// -----------------------------------------------------------------------------
// 6. Function overloading
// -----------------------------------------------------------------------------
//   Same function name, different parameter list.
//   The compiler picks the right one based on the argument types at the call.
//   Return type alone is NOT enough to distinguish overloads.
// -----------------------------------------------------------------------------
int         scale(int x)              { return x * 2; }
double      scale(double x)           { return x * 2.0; }
std::string scale(const std::string& s){ return s + s; }

// -----------------------------------------------------------------------------
// 7. inline / constexpr helpers
// -----------------------------------------------------------------------------
//   'inline' suggests the compiler may expand the body at the call site (a
//   hint, not a command).  'constexpr' says it CAN be evaluated at compile
//   time when given constant-expression arguments.
// -----------------------------------------------------------------------------
inline int square(int x) { return x * x; }

constexpr int cube(int x) { return x * x * x; }

// -----------------------------------------------------------------------------
// 8. Function definition (matches the declaration above)
// -----------------------------------------------------------------------------
int add(int a, int b) {
    return a + b;
}

// -----------------------------------------------------------------------------
// Demo driver
// -----------------------------------------------------------------------------
void demonstrate_call_by_value_vs_reference() {
    fmt::print("\n--- Call by value vs reference ---\n");

    int x = 5;

    int copy = x;
    try_to_double_by_value(copy);
    fmt::print("after try_to_double_by_value( {} ) -> copy = {}, original x = {}\n",
               x, copy, x);

    double_by_reference(x);
    fmt::print("after double_by_reference  ( {} ) -> x = {}\n",
               5, x);
}

void demonstrate_default_arguments() {
    fmt::print("\n--- Default arguments ---\n");
    fmt::print("power(3.0)         = {}  (exponent defaulted to 2)\n", power(3.0));
    fmt::print("power(3.0, 4)      = {}\n", power(3.0, 4));
    fmt::print("power(2.0, 10)     = {}\n", power(2.0, 10));
}

void demonstrate_overloading() {
    fmt::print("\n--- Function overloading ---\n");
    fmt::print("scale(7)       = {}\n",   scale(7));
    fmt::print("scale(2.5)     = {}\n",   scale(2.5));
    fmt::print("scale(\"hi\")  = {}\n",   scale(std::string{"hi"}));
}

void demonstrate_constexpr_and_inline() {
    fmt::print("\n--- inline / constexpr ---\n");
    int s = square(9);
    int c = cube(3);          // computed at compile time
    fmt::print("square(9) = {}\n", s);
    fmt::print("cube(3)   = {}\n", c);

    // Used in a constant-expression context
    constexpr int c_at_compile_time = cube(5);
    static_assert(c_at_compile_time == 125, "cube(5) must be 125");
    fmt::print("constexpr cube(5) = {}\n", c_at_compile_time);
}

}  // namespace fundamentals::funcs_demo

void run_functions_demo() {
    using namespace fundamentals::funcs_demo;

    fmt::print("\n========== FUNCTIONS ==========\n");

    // Calling
    int sum = add(3, 4);
    fmt::print("add(3, 4) = {}\n", sum);
    fmt::print("length_of(\"hello\") = {}\n",
               length_of(std::string{"hello"}));

    demonstrate_call_by_value_vs_reference();
    demonstrate_default_arguments();
    demonstrate_overloading();
    demonstrate_constexpr_and_inline();
}
