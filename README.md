# ⚙️ C++ Journey

> **A systems-oriented journey through C++ — from language fundamentals and modern C++ to tooling, memory, performance, and real-world domains.**

This repository documents my long-term journey of learning **C++ deeply**.

It is not a "learn C++ in 30 days" course, a collection of random code snippets, or a finished tutorial.

It is an evolving engineering workspace where I learn C++, experiment with the language and its ecosystem, build things, investigate how systems work underneath, and apply C++ to different domains.

---

## 🧭 Why This Repository Exists

I don't want to learn C++ only as a syntax.

I want to understand:

* how the language works
* how memory is managed
* how objects live and die
* how compilation and linking work
* how C++ programs are built and debugged
* how the Standard Library works
* how modern C++ improves upon older practices
* how performance is affected by design decisions
* how C++ is used in systems and specialized domains

The learning process therefore goes beyond:

```text
"Learn syntax → write small programs → finish tutorial"
```

Instead:

```text
Learn
  ↓
Understand
  ↓
Implement
  ↓
Experiment
  ↓
Break
  ↓
Debug
  ↓
Measure
  ↓
Build
  ↓
Reflect
  ↓
Repeat
```

---

# 🧩 What This Repository Covers

The repository is organized around several major areas of C++.

```text
                         C++
                         │
          ┌──────────────┼──────────────┐
          │              │              │
     Language         Tooling        Ecosystem
          │              │              │
          ↓              ↓              ↓
     Modern C++       CMake          STL
     Memory           Ninja          Libraries
     OOP              Docker         Packages
     Templates        Debuggers      ...
          │
          ↓
   ┌──────┼────────┬──────────┬────────────┐
   ↓      ↓        ↓          ↓            ↓
 Systems  Game    Network   Embedded   Cybersecurity
```

The exact scope will evolve as I continue learning.

---

# 📚 Learning Tracks

## 1. C++ Fundamentals

The foundation of the journey.

Topics include:

* Variables and types
* Operators
* Control flow
* Functions
* Arrays
* Strings
* Pointers
* References
* Structs
* Classes
* Object-oriented programming
* Constructors / destructors
* Inheritance
* Polymorphism
* Encapsulation
* Memory management
* Exceptions
* Namespaces
* Compilation model

The goal is not merely to know the syntax, but to understand the behavior behind it.

---

## 2. Modern C++

After establishing the fundamentals, the focus moves toward modern C++ practices.

Areas include:

* `auto`
* Range-based `for`
* Smart pointers
* RAII
* Move semantics
* Rvalue references
* Lambdas
* `constexpr`
* `consteval`
* `constinit`
* `std::optional`
* `std::variant`
* `std::string_view`
* Structured bindings
* Concepts
* Templates
* Generic programming
* Ranges
* `std::span`
* Modern concurrency
* Other features introduced across modern C++ standards

The goal is to understand **when and why** modern features should be used, rather than using new syntax simply because it exists.

---

# 🧰 C++ Toolchain

C++ is more than the language.

A significant part of this repository is learning the toolchain used to build, inspect, debug, and maintain C++ software.

The development environment includes tools such as:

* GCC
* Clang / LLVM
* CMake
* Ninja
* vcpkg
* GDB
* LLDB
* Docker
* Docker Compose
* VS Code
* Dev Containers
* clangd
* CMake Tools

The exact configuration is maintained in the repository.

---

## 🏗️ Build Systems

I am learning how C++ projects are actually built rather than relying exclusively on an IDE's "Build" button.

The repository explores:

* CMake
* CMake Presets
* Ninja
* compiler toolchains
* Debug / Release configurations
* dependency management
* reproducible builds

The objective is to understand the relationship between:

```text
Source Code
    ↓
Compiler
    ↓
Object Files
    ↓
Linker
    ↓
Executable
```

and how tools such as CMake and Ninja automate this process.

---

# 🐳 Reproducible Development Environment

The repository provides a containerized C++ development environment using Docker and VS Code Dev Containers.

The purpose is simple:

> **The development environment should be reproducible instead of being dependent on one specific machine.**

The environment is designed around tools such as:

```text
Ubuntu
├── GCC
├── Clang / LLVM
├── CMake
├── Ninja
├── vcpkg
├── GDB
├── LLDB
└── Git
```

This also allows me to experiment with different compilers and development workflows without polluting the host environment.

---

# 📦 C++ Standard Library / STL

The **Standard Template Library (STL)** is an important part of this repository.

STL is treated as part of learning C++ itself rather than being isolated into the separate Competitive Programming repository.

Areas include:

### Containers

* `std::vector`
* `std::array`
* `std::string`
* `std::deque`
* `std::list`
* `std::forward_list`
* `std::stack`
* `std::queue`
* `std::priority_queue`
* `std::set`
* `std::multiset`
* `std::map`
* `std::multimap`
* `std::unordered_set`
* `std::unordered_map`

### Algorithms

* sorting
* searching
* transformation
* counting
* min/max operations
* binary search
* numeric algorithms
* iterator-based algorithms

### Supporting Concepts

* Iterators
* Iterator categories
* Comparators
* Function objects
* Lambdas
* Allocators
* Container complexity
* Iterator invalidation

STL knowledge will also support other areas of my C++ journey.

---

# 🧠 Memory & Performance

One of the main goals of this journey is developing a better mental model of what C++ is doing underneath the abstraction.

Topics include:

* Stack vs heap
* Object lifetime
* Storage duration
* Pointers
* References
* Ownership
* RAII
* Smart pointers
* Dynamic allocation
* Copy semantics
* Move semantics
* Cache behavior
* Data locality
* Undefined behavior
* Performance measurement
* Compiler optimizations

The objective is to move from:

> "This code works."

toward:

> "I understand what this code causes the machine and runtime to do."

---

# 🧪 Experimentation

Not everything in this repository is intended to become a reusable project.

Some code exists specifically to answer questions.

For example:

```text
What happens if...?
Why does this compile?
Why does this produce undefined behavior?
How does the compiler transform this?
How expensive is this operation?
What happens to memory?
How does GCC differ from Clang?
```

These experiments are an intentional part of the learning process.

---

# 🌐 C++ Domains

One of the long-term goals of this repository is to explore the major areas where C++ is useful.

## 🎮 Game Development

Exploring C++ in areas such as:

* game loops
* graphics
* input systems
* physics
* ECS
* resource management
* engine architecture
* performance

---

## 🌐 Networking

Exploring:

* sockets
* TCP / UDP
* network protocols
* serialization
* asynchronous I/O
* client/server architecture
* network programming

---

## 🔌 Embedded Systems

Exploring C++ in resource-constrained environments.

Topics may include:

* microcontrollers
* hardware interfaces
* memory constraints
* interrupts
* peripherals
* real-time considerations
* embedded debugging

---

## 🔐 Cybersecurity

Exploring the relationship between C++ and low-level security concepts.

Potential areas include:

* memory vulnerabilities
* buffer overflows
* memory corruption
* binary analysis
* reverse engineering
* secure systems programming
* exploitation concepts in controlled environments

---

## 🖥️ Systems Programming

Exploring how C++ interacts with operating-system-level concepts.

Potential areas include:

* processes
* threads
* synchronization
* filesystems
* memory
* system calls
* concurrency
* low-level APIs

---

# 🗂️ Repository Structure

The repository structure will evolve as the journey grows.

The general organization is:

```text
cpp-journey/
│
├── fundamentals/
│
├── modern-cpp/
│
├── stl/
│
├── tooling/
│
├── experiments/
│
├── projects/
│
├── game-dev/
│
├── networking/
│
├── embedded/
│
├── cybersecurity/
│
├── systems/
│
├── .devcontainer/
│
├── CMakeLists.txt
├── CMakePresets.json
├── docker-compose.yml
└── README.md
```

> **Note:** The exact directory structure may change as the repository evolves. The repository itself is the source of truth.

---

# 🛠️ Development Environment

The recommended environment is:

**VS Code + Docker + Dev Containers**

The repository's development container is designed to provide a consistent C++ environment containing the required compilers, build systems, package manager, debuggers, and development tools.

### Core toolchain

| Tool           | Purpose                              |
| -------------- | ------------------------------------ |
| GCC            | GNU C++ compiler                     |
| Clang          | LLVM-based C++ compiler              |
| CMake          | Build configuration                  |
| Ninja          | Fast build system                    |
| vcpkg          | C++ dependency management            |
| GDB            | GNU debugger                         |
| LLDB           | LLVM debugger                        |
| Docker         | Container runtime                    |
| Dev Containers | Reproducible development environment |
| clangd         | C++ language server                  |
| VS Code        | Development environment              |

---

# 🚀 Getting Started

## Requirements

You can work with the repository either through the provided containerized environment or through a compatible native C++ environment.

### Recommended

* Git
* Docker
* Docker Compose
* VS Code
* Dev Containers extension

### Native development

A compatible environment should provide:

* C++ compiler
* CMake
* Ninja
* Git

---

## Using the Dev Container

Clone the repository:

```bash
git clone https://github.com/ShahJabir/cpp-journey.git
cd cpp-journey
```

Open the repository in VS Code:

```bash
code .
```

Then reopen the project inside the Dev Container.

The container provides the configured C++ toolchain and development utilities.

For the exact container configuration, see:

```text
.devcontainer/
docker-compose.yml
```

---

# 🔨 Building

This repository uses **CMake** as its primary build-system configuration and **Ninja** as a build backend where configured.

The exact configure/build commands should follow the available CMake presets in:

```text
CMakePresets.json
```

Typical CMake workflow:

```text
Configure
   ↓
Build
   ↓
Run
   ↓
Debug
```

The repository intentionally keeps the build configuration explicit so that the development process is not tied to a single IDE.

---

# 🐛 Debugging

The development environment supports both:

* GDB
* LLDB

This allows experimentation with debugging from different toolchains.

Debugging is treated as part of learning C++, not simply as a way to fix broken programs.

I want to become comfortable investigating:

* segmentation faults
* memory errors
* undefined behavior
* incorrect program state
* performance issues
* compiler/runtime behavior

---

## 🐳 Development Environment

This repository provides a reproducible C++ development environment using Docker and VS Code Dev Containers.

The container includes:

- GCC / G++
- Clang / Clang++
- CMake
- Ninja
- vcpkg
- GDB
- LLDB
- clangd

You do not need to manually install the C++ toolchain on your host machine.

See [`DOCKER.md`](./DOCKER.md) for complete setup instructions, Docker commands, CMake presets, dependency management, and debugging instructions.

> **Recommended:** Use VS Code with the Dev Containers extension and reopen the repository inside the provided container.

---

# 📈 Learning Methodology

This repository follows an **implementation-first and experimentation-driven** approach.

Instead of:

```text
Tutorial
   ↓
Copy Code
   ↓
Move On
```

the preferred process is:

```text
Concept
   ↓
Mental Model
   ↓
Small Implementation
   ↓
Experiment
   ↓
Debug
   ↓
Measure
   ↓
Build Something
   ↓
Document
```

When something behaves unexpectedly, the goal is not simply to search for the answer.

First:

> **Try to understand why.**

---

# 🧭 Roadmap

The journey is intentionally not a rigid checklist.

The broad progression is:

```text
C++ Fundamentals
       ↓
Memory & Object Model
       ↓
OOP & Generic Programming
       ↓
Modern C++
       ↓
STL
       ↓
Toolchain
       ↓
Build Systems
       ↓
Debugging
       ↓
Performance
       ↓
Systems Programming
       ↓
Specialized Domains
```

The domain tracks can develop independently.

For example:

```text
             C++
              │
      ┌───────┼────────┐
      │       │        │
   Systems   Games   Networking
      │       │        │
   Embedded  Graphics  Protocols
      │
 Cybersecurity
```

This is a journey rather than a fixed curriculum.

---

# 🧪 Projects

The repository will gradually contain projects and experiments that apply concepts learned throughout the journey.

Projects are important because they force theoretical knowledge to interact with:

* architecture
* debugging
* performance
* tooling
* dependencies
* APIs
* operating systems
* real constraints

A topic is not considered fully understood simply because I can explain it.

> **I want to be able to use it.**

---

# 🎯 What This Repository Is — and Isn't

### This repository is:

* A long-term C++ learning journey
* A place for experiments
* A place to study modern C++
* A place to understand C++ tooling
* A place to build projects
* A place to explore systems-level concepts
* A record of technical progress

### This repository is not:

* A complete C++ textbook
* A "learn C++ in X days" course
* A competitive-programming solution archive
* A collection of copied tutorials
* A production C++ library
* A finished project

Competitive Programming is intentionally maintained separately so that it can have its own dedicated curriculum, problem archive, contest history, and progression.

---

# 🏆 Competitive Programming

Competitive Programming is **not part of this repository's primary scope anymore**.

My dedicated Competitive Programming journey is maintained separately.

This repository may still contain the C++ and STL knowledge that supports CP, but contest problems, algorithmic practice, ratings, and CP-specific progression belong in the dedicated repository.

---

# 📚 Resources

Some resources that support this journey:

### C++

* [cppreference](https://en.cppreference.com/)
* [ISO C++](https://isocpp.org/)

### Build Systems & Tooling

* [CMake](https://cmake.org/)
* [Ninja](https://ninja-build.org/)
* [LLVM](https://llvm.org/)
* [GCC](https://gcc.gnu.org/)
* [vcpkg](https://vcpkg.io/)

### Development Environment

* [Docker](https://www.docker.com/)
* [Visual Studio Code](https://code.visualstudio.com/)

Resources will be added when they become relevant to the current stage of the journey.

---

# 🔄 Status

**Active — Work in Progress**

This repository is intentionally unfinished.

New topics, experiments, projects, tools, and domains will be added as I progress.

The structure may change.

The code may change.

The understanding will change.

That's the point.

---

# 👤 About

I'm **Shah Jabir**, a developer interested in understanding software from both the high-level and low-level sides.

C++ is one of the languages I use to explore:

* programming language concepts
* systems
* performance
* tooling
* software architecture
* networking
* embedded systems
* game development
* cybersecurity

This repository is the public record of that journey.

---

## Related

**Competitive Programming**

A separate repository dedicated to algorithms, data structures, contest programming, and problem solving.

**C++ Journey**

You are here.

---

## 📜 License

See [`LICENSE`](LICENSE) for the license applicable to this repository.
