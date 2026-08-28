// =============================================================================
//  input_output.cpp
//  -----------------------------------------------------------------------------
//  Topics covered:
//    - cin, cout, cerr, clog
//    - getline() and cin.ignore()  (reading a line after >>)
//    - Reading a string AFTER an int (the classic leftover-newline bug)
//    - endl vs "\n"
//    - Escape sequences:  \n  \t  \\  \"  \'  \r  \b  \a  \0
//    - Stream formatting (setw, setprecision, boolalpha, hex/dec/oct)
// =============================================================================

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#include <fmt/core.h>
#include <fmt/format.h>

namespace fundamentals::io_demo {

// -----------------------------------------------------------------------------
// 1. The four standard streams
// -----------------------------------------------------------------------------
//   cout  - "character output" -> stdout (buffered)
//   cin   - "character input" -> stdin  (buffered)
//   cerr  - "character error" -> stderr (UNBUFFERED - flushed immediately)
//   clog  - "character log"   -> stderr (BUFFERED)
//
//   In this demo we use fmt::print for output, but cout is used to demonstrate
//   iostream-specific formatting flags.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// 2. endl vs "\n"
// -----------------------------------------------------------------------------
//   std::endl  -> writes '\n' AND flushes the stream (slow if used a lot)
//   "\n"       -> just the newline character, no flush (fast)
//
//   fmt::print defaults to "\n" and does NOT auto-flush, which is why it's
//   fast.  Use std::flush / fmt::print("...\n") explicitly when you need it.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// 3. Escape sequences
// -----------------------------------------------------------------------------
//   \n  newline
//   \t  horizontal tab
//   \\  backslash
//   \"  double quote
//   \'  single quote
//   \r  carriage return
//   \b  backspace
//   \a  alert (bell)
//   \0  null character
//   \xHH   hex byte
//   \OOO   octal byte
// -----------------------------------------------------------------------------

void demonstrate_escape_sequences() {
    fmt::print("\n--- Escape sequences ---\n");
    fmt::print("Line1\nLine2\n");
    fmt::print("Col1\tCol2\tCol3\n");
    fmt::print("Path: C:\\Users\\cpp\n");
    fmt::print("Quote: \"hello\"\n");
    fmt::print("Bell: \a (you may or may not hear it)\n");
    fmt::print("Hex byte: \x41 = 'A'\n");      // 0x41 == 'A'
    fmt::print("Octal byte: \101 = 'A'\n");     // 0o101 == 'A'
}

// -----------------------------------------------------------------------------
// 4. Stream formatting with iostream
// -----------------------------------------------------------------------------
//   setw(n)        - next field width
//   setprecision(n)- digits for floating-point
//   fixed / scientific / hexfloat / defaultfloat
//   boolalpha / noboolalpha - print true/false vs 1/0
//   hex / dec / oct - base for integers
//   left / right / internal - alignment
//   showbase / noshowbase   - show 0x prefix for hex
// -----------------------------------------------------------------------------

void demonstrate_iostream_formatting() {
    fmt::print("\n--- iostream formatting ---\n");

    double pi = 3.14159265358979;
    int    n  = 255;

    std::cout << "default       : pi = " << pi << '\n';
    std::cout << std::setprecision(4) << "setprecision : pi = " << pi << '\n';
    std::cout << std::fixed << std::setprecision(2) << "fixed 2dp   : pi = " << pi << '\n';
    std::cout << std::setprecision(6) << std::scientific << "scientific : pi = " << pi << '\n';

    // Reset to default float formatting
    std::cout << std::defaultfloat << std::setprecision(6);

    std::cout << std::boolalpha << "boolalpha   : " << (10 > 5) << '\n';
    std::cout << std::noboolalpha;

    std::cout << std::hex << std::showbase << "hex         : n = " << n << '\n';
    std::cout << std::oct << std::showbase << "oct         : n = " << n << '\n';
    std::cout << std::dec << std::noshowbase << "dec         : n = " << n << '\n';

    std::cout << std::setw(10) << std::right << "[" << 42 << "]\n";
    std::cout << std::setw(10) << std::left  << "[" << 42 << "]\n";
    std::cout << std::setfill('-') << std::setw(10) << std::right << "[" << 42 << "]\n";
    std::cout << std::setfill(' ');
}

// -----------------------------------------------------------------------------
// 5. Interactive parts (cin / getline / cin.ignore)
// -----------------------------------------------------------------------------
//   Reading a string AFTER an int is tricky:
//     std::cin >> x   leaves the newline in the input buffer.
//     std::getline(cin, s)  reads until '\n' - if there's a leftover '\n',
//                            it returns immediately with an empty string.
//
//   Fix:  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//   These functions USE std::cin directly (they don't take a stream argument).
//   In the dispatcher we will call them only when stdin is a TTY so the
//   automated run doesn't hang.
// -----------------------------------------------------------------------------

void interactive_demo() {
    using std::cin;
    using std::cout;

    cout << "\n--- Interactive I/O demo ---\n";

    int age = 0;
    cout << "Enter your age: ";
    cin >> age;

    // The newline we pressed after the number is STILL in cin's buffer.
    // Without ignore(), the next getline() would read an empty string.
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    cout << "Enter your full name: ";
    std::getline(cin, name);

    cout << "Hi " << name << ", you are " << age << " years old.\n";
}

}  // namespace fundamentals::io_demo

// -----------------------------------------------------------------------------
// Public entry point used by fundamentals/main.cpp
// -----------------------------------------------------------------------------
void run_input_output_demo() {
    using namespace fundamentals::io_demo;

    fmt::print("\n========== INPUT / OUTPUT ==========\n");

    demonstrate_escape_sequences();
    demonstrate_iostream_formatting();

    fmt::print("\n[note] interactive_demo() reads from stdin - call it from\n");
    fmt::print("       your own driver if you want to type into the program.\n");
}
