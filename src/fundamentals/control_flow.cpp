// =============================================================================
//  control_flow.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - if / else / nested if
//    - else-if ladder
//    - switch / case / default / fallthrough
//    - Ternary operator ?:   (cond ? if_true : if_false)
//    - for loop               - when iteration count is known
//    - while loop             - when iteration count is unknown
//    - do-while loop          - executes at least once (note the trailing ';')
//    - Infinite loops
//    - break / continue
// =============================================================================

#include <iostream>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::control_demo {

// -----------------------------------------------------------------------------
// 1. if / else / nested if
// -----------------------------------------------------------------------------
void demonstrate_if_else(int x) {
    fmt::print("\n--- if / else / nested ---\n");
    fmt::print("x = {}\n", x);

    if (x == 0) {
        fmt::print("  x is zero\n");
    } else if (x > 0) {
        if (x % 2 == 0) {
            fmt::print("  x is a positive EVEN number\n");
        } else {
            fmt::print("  x is a positive ODD number\n");
        }
    } else {
        fmt::print("  x is negative\n");
    }
}

// -----------------------------------------------------------------------------
// 2. else-if ladder (multiple mutually-exclusive branches)
// -----------------------------------------------------------------------------
const char* grade_letter(int score) {
    if      (score >= 90) return "A";
    else if (score >= 80) return "B";
    else if (score >= 70) return "C";
    else if (score >= 60) return "D";
    else                  return "F";
}

// -----------------------------------------------------------------------------
// 3. switch / case / default
// -----------------------------------------------------------------------------
//   Notes:
//     - case labels must be CONSTANT integral (or enum) expressions.
//     - Without break, execution "falls through" to the next case.
//     - 'default' runs when nothing else matched.
// -----------------------------------------------------------------------------
void demonstrate_switch(int day_of_week) {
    fmt::print("\n--- switch ---\n");
    fmt::print("day = {} -> ", day_of_week);

    switch (day_of_week) {
        case 1: fmt::print("Monday\n");    break;
        case 2: fmt::print("Tuesday\n");   break;
        case 3: fmt::print("Wednesday\n"); break;
        case 4: fmt::print("Thursday\n");  break;
        case 5: fmt::print("Friday\n");    break;
        case 6:
        case 7: fmt::print("Weekend!\n");  break;   // fallthrough is intentional here
        default: fmt::print("Invalid day\n");
    }
}

// -----------------------------------------------------------------------------
// 4. Ternary operator  cond ? a : b
// -----------------------------------------------------------------------------
//   - Returns a VALUE (so it can be used in expressions).
//   - Prefer it only for SHORT conditions; nested ternaries are hard to read.
// -----------------------------------------------------------------------------
int absolute_value(int x) {
    return x < 0 ? -x : x;
}

const char* parity_str(int x) {
    return (x % 2 == 0) ? "even" : "odd";
}

void demonstrate_ternary() {
    fmt::print("\n--- Ternary ---\n");
    fmt::print("|-5|  = {}\n", absolute_value(-5));
    fmt::print("|-5|  = {}\n", absolute_value(7));
    fmt::print("4 is  = {}\n", parity_str(4));
    fmt::print("7 is  = {}\n", parity_str(7));
}

// -----------------------------------------------------------------------------
// 5. for loop  -  "I know how many iterations I want"
// -----------------------------------------------------------------------------
void demonstrate_for() {
    fmt::print("\n--- for loop (known iterations) ---\n");

    // Classic:   for (init; condition; step) { body }
    for (int i = 0; i < 5; ++i) {
        fmt::print("i = {}\n", i);
    }

    // Range-based for over an array
    int arr[] = {10, 20, 30, 40, 50};
    fmt::print("arr elements: ");
    for (int v : arr) {
        fmt::print("{} ", v);
    }
    fmt::print("\n");

    // Nested for - multiplication table (1..3)
    fmt::print("Multiplication table 1..3:\n");
    for (int r = 1; r <= 3; ++r) {
        for (int c = 1; c <= 3; ++c) {
            fmt::print("{:4}", r * c);
        }
        fmt::print("\n");
    }

    // Infinite for loop (use break to exit)
    fmt::print("Counting with break:\n");
    for (int i = 0; ; ++i) {
        if (i >= 3) break;
        fmt::print("  i = {}\n", i);
    }
}

// -----------------------------------------------------------------------------
// 6. while loop  -  "I don't know how many iterations"
// -----------------------------------------------------------------------------
void demonstrate_while() {
    fmt::print("\n--- while loop (unknown iterations) ---\n");

    // Halve a number until it becomes 0
    int n = 64;
    int steps = 0;
    while (n > 0) {
        n /= 2;
        ++steps;
        fmt::print("  step {:2}: n = {}\n", steps, n);
    }

    // Infinite while loop example (commented out, would run forever)
    // while (true) { /* must have a break or return inside */ }
}

// -----------------------------------------------------------------------------
// 7. do-while loop  -  "execute at least once"
// -----------------------------------------------------------------------------
//   The body runs FIRST, then the condition is checked.
//   Don't forget the SEMICOLON after while(condition);  <-- easy to miss!
// -----------------------------------------------------------------------------
void demonstrate_do_while() {
    fmt::print("\n--- do-while (at least once) ---\n");

    int x = 0;
    do {
        fmt::print("  x = {}  (runs even if condition is false)\n", x);
        ++x;
    } while (x < 3);

    // The condition is false from the start, but the body still ran ONCE.
    int y = 100;
    do {
        fmt::print("  y = {}  (body ran once even though y < 5 is false)\n", y);
    } while (y < 5);
}

// -----------------------------------------------------------------------------
// 8. break / continue
// -----------------------------------------------------------------------------
//   break    - exit the innermost loop or switch immediately
//   continue - skip the rest of the current iteration, go to the next one
// -----------------------------------------------------------------------------
void demonstrate_break_continue() {
    fmt::print("\n--- break / continue ---\n");

    // continue: skip odd numbers
    fmt::print("Even numbers 0..9: ");
    for (int i = 0; i < 10; ++i) {
        if (i % 2 != 0) continue;  // skip odd
        fmt::print("{} ", i);
    }
    fmt::print("\n");

    // break: stop at first multiple of 7
    fmt::print("First multiple of 7 > 0: ");
    for (int i = 1; i < 100; ++i) {
        if (i % 7 == 0) {
            fmt::print("{}\n", i);
            break;
        }
    }
}

}  // namespace fundamentals::control_demo

void run_control_flow_demo() {
    using namespace fundamentals::control_demo;

    fmt::print("\n========== CONTROL FLOW ==========\n");

    demonstrate_if_else(0);
    demonstrate_if_else(7);
    demonstrate_if_else(-3);

    fmt::print("\n--- else-if ladder ---\n");
    for (int score : {95, 82, 73, 61, 50}) {
        fmt::print("score {:3} -> grade {}\n", score, grade_letter(score));
    }

    demonstrate_switch(1);
    demonstrate_switch(6);
    demonstrate_switch(8);

    demonstrate_ternary();

    demonstrate_for();
    demonstrate_while();
    demonstrate_do_while();
    demonstrate_break_continue();
}
