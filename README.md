# ⚙️ C++ Journey — A Systems-Level Learning Path

> **Not a tutorial dump. Not a "learn C++ in 30 days" course.**
> This repository is a **deep, internals-first journey into C++** — starting with Data Structures & Algorithms for competitive programming, then expanding into modern C++, tooling, systems programming, and applied domains like game development, cybersecurity, and networking.

If you are here to _"learn Qt"_ or _"learn a game engine"_, this repo is **not for you**.
If you want to **understand C++ from the language up — how it thinks, how it compiles, how it fails — and build contest-sharp fundamentals along the way**, welcome.

---

## 🎯 Purpose of This Repository

This repository exists to:

- Get **contest-ready fast** — DSA and STL fluency come first, before anything else
- Understand **modern C++ as it actually is today** (C++11 → C++23), not just "C with classes"
- Learn **industry-standard tooling** — build systems, package managers, compilers, linters
- Build **structured, real-world project layouts**, not single-file snippets
- Get comfortable with **debugging and compile-time computation** — sanitizers, `constexpr`, templates
- Integrate **third-party libraries** the way production codebases actually do
- Apply C++ in **game development, cybersecurity, and networking** once the fundamentals are solid

This is a **learning log + reference + code lab**.

---

## 🧠 Philosophy

```text
Contests reward speed of execution.
Systems work rewards depth of understanding.
This repo builds both, in that order.
```

Principles followed in this repo:

- ❌ No frameworks or engines without understanding what's underneath
- ❌ No copy-pasted contest templates without knowing why each line exists
- ✅ DSA and STL fluency first — everything else waits
- ✅ Every C++ standard learned deliberately, not accidentally absorbed
- ✅ Source, spec, and compiler-explorer curiosity over blog-post trust
- ✅ Understanding "why", not just "how"

---

## 🗺️ Learning Scope

This repository covers **far more than contest prep alone**:

- Data Structures & Algorithms — arrays, trees, graphs, DP, greedy, STL containers, fast I/O
- Modern C++ standards — C++11, C++14, C++20, C++23 (move semantics, smart pointers, concepts, ranges, coroutines, modules)
- Setup & industry-standard tooling — CMake, vcpkg/Conan, GCC/Clang/MSVC, linters, formatters
- Structured project architecture — real multi-file layouts, not single `.cpp` snippets
- Debugging & compile-time computation — GDB/LLDB, sanitizers, `constexpr`, templates, metaprogramming
- Third-party libraries & frameworks — dependency management, integrating external libs
- Game development — engines, graphics APIs, real-time systems
- Cybersecurity — memory-safety pitfalls, exploitation basics, secure coding
- Networking — sockets, protocols, low-level network programming

Think of this as:

> **Competitive Programming first, Systems Engineering after — through the lens of C++**

---

## 📍 Current Focus

```text
Phase 1 → Modern C++ Standards (C++11 → C++23)
Phase 2 → Tooling & Industry Standards
Phase 3 → Structured Projects
Phase 4 → Debugging & Compile-Time Computation
Phase 5 → Third-Party Libraries & Frameworks
Phase 6 → DSA for Competitive Programming
Phase 7 → Game Development
Phase 8 → Cybersecurity
Phase 9 → Networking
Phase 10 → Embedded
```

See [`LEARNING_LOG.md`](./LEARNING_LOG.md) for the running journal and [`RESOURCES.md`](./RESOURCES.md) for the curated reading list per phase.

---

## 📦 Core Rule: Depth Before Breadth

Every topic explored here follows the same progression:

1. **What is it?** — Conceptual foundation
2. **How does it work?** — Internal mechanics
3. **Why is it designed this way?** — Trade-offs and history
4. **Where does it break?** — Failure modes and edge cases
5. **How do I use it well?** — Practical, performance-aware application

External IDEs and GUIs are only discussed **conceptually** or for comparison — the compiler, the terminal, and the standard are the primary interface.

---

## 🧪 How to Use This Repository

### 1️⃣ Read

Each directory contains **Markdown notes** explaining concepts, internals, and trade-offs — not just "how to."

### 2️⃣ Code

Every concept is backed by small, runnable experiments — minimal examples, no boilerplate.

### 3️⃣ Break Things Intentionally

- Trigger undefined behavior on purpose and catch it with sanitizers
- Force a template instantiation error and read the diagnostic
- Compare compiled output across `-O0` and `-O3`
- TLE a naive solution, then fix it with the right data structure

Then understand **why it broke** and what the compiler or runtime was doing.

---

## 🚀 Who This Repo Is For

This repository is ideal for:

- Competitive programmers who also want to go beyond contests
- Backend/systems engineers who want **real depth**, not framework fluency
- Security engineers who need to understand memory-level attack surfaces
- Developers moving beyond "C with classes" into modern, idiomatic C++
- Anyone who wants to read STL and compiler documentation confidently

This repo is **not beginner-friendly** — and that is intentional.

---

## 📌 Expected Outcome

After completing this repository, you should be able to:

- Solve contest-level DSA problems fluently in C++ under time pressure
- Explain move semantics, smart pointers, and RAII with confidence
- Set up and configure a modern C++ project from scratch (CMake, package manager, CI)
- Debug memory issues with sanitizers and a real debugger, not `printf`
- Integrate third-party libraries into a structured project
- Apply C++ fundamentals to game dev, security, or networking projects

---

## ⚠️ Disclaimer

This repository is:

- Opinionated
- Internals-focused
- Performance-oriented

It prioritizes **understanding over speed** and **depth over comfort** — except in Phase 1, where contest speed is the explicit goal.

---

## 👤 Author

<p align="center">
<a href="https://shahjabir.com.bd">
<img src="https://img.shields.io/badge/Website-ShahJabir-black" alt="Website" /></a>
<a href="https://github.com/ShahJabir">
<img src="https://img.shields.io/badge/Github-ShahJabir-white" alt="Github" /></a>
<a href="https://www.facebook.com/sjtaqi">
<img src="https://img.shields.io/badge/Facebook-ShahJabir-blue" alt="Facebook" /></a>
<a href="https://x.com/TaqiJabir">
<img src="https://img.shields.io/badge/X-TaqiJabir-black" alt="Twitter" />
</a>
<a href="https://www.linkedin.com/in/shahjabir/">
<img src="https://img.shields.io/badge/Linkedin-shahjabirtaqi-blue" alt="Linkedin" /></a>
</p>

---

## 📄 License

This repository is licensed under the [MIT License](./LICENSE).
All notes, diagrams, and code are original work unless explicitly cited.

---

## 🏁 Final Words

```text
Most people use C++ to pass a contest or finish an assignment.
Very few understand the language underneath.
This repo is for the second group — after passing the contest.
```

Happy solving, and happy compiling 🚀
