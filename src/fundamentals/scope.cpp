// =============================================================================
//  scope.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - Block scope     - inside { ... }
//    - Local vs global variables
//    - Variable lifetime basics (storage duration)
//    - Namespaces
//    - The "namespace std" rule (don't add `using namespace std;` in headers)
//    - Name hiding / shadowing
// =============================================================================

#include <string>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::scope_demo {

// -----------------------------------------------------------------------------
// Global variable (file scope) - visible to everything below it in this file
// -----------------------------------------------------------------------------
int global_counter = 0;

// -----------------------------------------------------------------------------
// Anonymous namespace - internal linkage.  Identifiers inside this block
// are visible ONLY inside this translation unit.  The modern replacement for
// C-style `static` at file scope.
// -----------------------------------------------------------------------------
namespace {
    int internal_only = 42;
}

// -----------------------------------------------------------------------------
// A small custom namespace
// -----------------------------------------------------------------------------
namespace math_utils {
    int square(int x) { return x * x; }
    int cube(int x)   { return x * x * x; }
}  // namespace math_utils

// -----------------------------------------------------------------------------
// Lifetime basics
// -----------------------------------------------------------------------------
//   'static' inside a function:
//     - Allocated once at program start.
//     - Keeps its value between calls.
//     - Initialized on the first call.
// -----------------------------------------------------------------------------
void increment_static_counter() {
    static int call_count = 0;   // initialized ONCE, on first call
    ++call_count;
    fmt::print("    increment_static_counter() called {} time(s)\n", call_count);
}

// -----------------------------------------------------------------------------
// Scope demo: block scope, shadowing, and lifetime
// -----------------------------------------------------------------------------
void demonstrate_block_scope() {
    fmt::print("\n--- Block scope / shadowing ---\n");

    int x = 10;          // outer 'x'
    fmt::print("outer x = {}\n", x);

    {
        int x = 99;      // inner 'x' SHADOWS the outer one within this block
        fmt::print("  inner x = {}  (shadows outer)\n", x);
        // The outer x is still alive but inaccessible by name here.
    }
    fmt::print("outer x again = {}  (unaffected)\n", x);
}

void demonstrate_global_vs_local() {
    fmt::print("\n--- Global vs local ---\n");

    int local_var = 1;
    fmt::print("global_counter = {}\n", global_counter);
    fmt::print("local_var      = {}\n", local_var);

    global_counter += 10;
    fmt::print("global_counter after += 10 = {}\n", global_counter);
}

void demonstrate_namespace() {
    fmt::print("\n--- Namespaces ---\n");

    // Fully qualified
    fmt::print("math_utils::square(5) = {}\n", math_utils::square(5));

    // Local 'using' directive - pulls names into the current scope
    using namespace math_utils;
    fmt::print("cube(3) [via using]    = {}\n", cube(3));

    // Namespace alias
    namespace mu = math_utils;
    fmt::print("mu::square(7)          = {}\n", mu::square(7));
}

void demonstrate_static_lifetime() {
    fmt::print("\n--- 'static' lifetime inside a function ---\n");
    increment_static_counter();
    increment_static_counter();
    increment_static_counter();
}

}  // namespace fundamentals::scope_demo

void run_scope_demo() {
    using namespace fundamentals::scope_demo;

    fmt::print("\n========== SCOPE & LIFETIME ==========\n");

    demonstrate_block_scope();
    demonstrate_global_vs_local();
    demonstrate_namespace();
    demonstrate_static_lifetime();

    // The namespaced internal value is reachable here (same TU)
    fmt::print("\ninternal_only (anonymous namespace) = {}\n",
               fundamentals::scope_demo::internal_only);
}
