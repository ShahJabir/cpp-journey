// =============================================================================
//  fundamentals/main.cpp
//  -----------------------------------------------------------------------------
//  This is the entry point for the "fundamentals" track of cpp-journey.
//
//  It runs each topic's demo in sequence:
//    1. Variables & data types
//    2. Input / output
//    3. Type conversion
//    4. Control flow
//    5. Functions
//    6. Scope & lifetime
//    7. Constants
//
//  Each topic lives in its own .cpp file.  This main.cpp only orchestrates
//  the calls and adds the topic banner.
// =============================================================================

#include <fmt/core.h>
#include <fmt/format.h>

// Forward declarations of each topic's runner
void run_variables_demo();
void run_input_output_demo();
void run_type_conversion_demo();
void run_control_flow_demo();
void run_functions_demo();
void run_scope_demo();
void run_constants_demo();

int main() {
    fmt::print("######################################################\n");
    fmt::print("#                                                    #\n");
    fmt::print("#            CPP-JOURNEY  ::  FUNDAMENTALS           #\n");
    fmt::print("#                                                    #\n");
    fmt::print("#  Variables - I/O - Conversions - Control - Funcs   #\n");
    fmt::print("#            Scope - Constants                       #\n");
    fmt::print("#                                                    #\n");
    fmt::print("######################################################\n");

    run_variables_demo();
    run_input_output_demo();
    run_type_conversion_demo();
    run_control_flow_demo();
    run_functions_demo();
    run_scope_demo();
    run_constants_demo();

    fmt::print("\n######################################################\n");
    fmt::print("#  Fundamentals demos finished.                       #\n");
    fmt::print("######################################################\n");
    return 0;
}
