
# 🐳 Docker Development Environment

`cpp-journey` provides a reproducible C++ development environment using Docker.

The goal is simple:

> **Clone the repository, open it in VS Code, enter the development container, and get the same toolchain every time.**

The container includes:

- GCC / G++
- Clang / Clang++
- CMake
- Ninja
- vcpkg
- GDB
- LLDB
- clangd
- VS Code C++ tooling

The project is designed to work with **VS Code Dev Containers**.

---

## 🧰 Toolchain

The development container provides the following tools:

| Tool                | Purpose                                    |
| ------------------- | ------------------------------------------ |
| GCC / G++           | GNU C/C++ compiler                         |
| Clang / Clang++     | LLVM C/C++ compiler                        |
| CMake               | Build configuration and project generation |
| Ninja               | Fast build system                          |
| vcpkg               | C++ dependency/package manager             |
| GDB                 | GNU debugger                               |
| LLDB                | LLVM debugger                              |
| clangd              | C++ language server                        |
| VS Code CMake Tools | CMake integration                          |
| VS Code C/C++       | C++ development and GDB integration        |
| CodeLLDB            | VS Code ↔ LLDB integration                 |

The project uses:

```text
CMake
  ↓
Ninja
  ↓
GCC / Clang
```

with:

```text
vcpkg
  ↓
Third-party dependencies
```

and:

```text
GDB / LLDB
  ↓
Debugging
```

---

## 🖥 Requirements

You need the following on your local machine.

### Required

#### Docker

Install Docker Desktop on:

- Windows
- macOS
- Linux

Docker is responsible for running the development environment.

You do **not** need to manually install GCC, Clang, CMake, Ninja, vcpkg, GDB, or LLDB on your host machine.

They are installed inside the container.

#### Visual Studio Code

Install VS Code:

https://code.visualstudio.com/

#### Dev Containers Extension

Install Microsoft's:

**Dev Containers**

Extension ID:

```
ms-vscode-remote.remote-containers
```

You can install it from the VS Code Extensions panel by searching:

```
Dev Containers
```

---

## 🚀 Quick Start

### 1. Clone the repository

Clone the repository:

```bash
git clone https://github.com/ShahJabir/cpp-journey.git
```

Enter the project:

```bash
cd cpp-journey
```

### 2. Open the project in VS Code

Run:

```bash
code .
```

Alternatively, open the `cpp-journey` folder manually in VS Code.

### 3. Reopen the project inside the container

VS Code should detect:

```
.devcontainer/devcontainer.json
```

You should see an option similar to:

```
Reopen in Container
```

Select it.

You can also use:

```
Ctrl + Shift + P
```

and run:

```
Dev Containers: Reopen in Container
```

VS Code will then build and start the development container.

---

## 🐳 Manual Docker Method

You can also start the container manually without VS Code.

From the project root:

```bash
docker compose up --build -d
```

Check that the container is running:

```bash
docker compose ps
```

You should see the `cpp-dev` service running.

Enter the container:

```bash
docker compose exec -it cpp-dev bash
```

You should now be inside the container.

Check:

```bash
pwd
```

Expected:

```
/workspace
```

---

## 🔍 Verify the Toolchain

After entering the container, verify the installed tools.

**GCC**

```bash
gcc --version
```

```bash
g++ --version
```

**Clang**

```bash
clang --version
```

```bash
clang++ --version
```

**CMake**

```bash
cmake --version
```

**Ninja**

```bash
ninja --version
```

**GDB**

```bash
gdb --version
```

**LLDB**

```bash
lldb --version
```

**vcpkg**

```bash
vcpkg version
```

**clangd**

```bash
clangd --version
```

You should have all of these available inside the container.

---

## 📦 vcpkg

This project uses **vcpkg manifest mode**.

The project's dependencies are declared in:

```
vcpkg.json
```

For example:

```json
{
    "name": "my-cpp-project",
    "version-string": "1.0.0",
    "dependencies": [
        "fmt"
    ]
}
```

You normally do not need to manually install individual packages.

Run:

```bash
vcpkg install
```

vcpkg reads:

```
vcpkg.json
```

and installs the declared dependencies.

For example:

```
vcpkg.json
    │
    ├── fmt
    │
    └── other dependencies
```

---

## 🏗 CMake

This project uses CMake for project configuration.

The main configuration file is:

```
CMakeLists.txt
```

CMake does not directly perform all compilation itself.

The project uses:

```
CMake → Ninja → Compiler
```

For example:

```
CMake
  ↓
Ninja build files
  ↓
clang++
  ↓
Executable
```

---

## 🎛 CMake Presets

The project provides four CMake configurations:

```
gcc-debug
gcc-release
clang-debug
clang-release
```

List the available presets:

```bash
cmake --list-presets
```

### 🔨 GCC Debug

Configure:

```bash
cmake --preset gcc-debug
```

Build:

```bash
cmake --build --preset gcc-debug
```

The executable will be generated at:

```
build/gcc-debug/app
```

Run it:

```bash
./build/gcc-debug/app
```

This configuration uses:

```
GCC
  ↓
G++
  ↓
Ninja
  ↓
Debug build
```

### 🔨 GCC Release

Configure:

```bash
cmake --preset gcc-release
```

Build:

```bash
cmake --build --preset gcc-release
```

Run:

```bash
./build/gcc-release/app
```

### 🔨 Clang Debug

Configure:

```bash
cmake --preset clang-debug
```

Build:

```bash
cmake --build --preset clang-debug
```

Run:

```bash
./build/clang-debug/app
```

This configuration uses:

```
Clang
  ↓
Clang++
  ↓
Ninja
  ↓
Debug build
```

### 🔨 Clang Release

Configure:

```bash
cmake --preset clang-release
```

Build:

```bash
cmake --build --preset clang-release
```

Run:

```bash
./build/clang-release/app
```

---

## 🐞 Debugging

The project supports both:

```
GDB
LLDB
```

The VS Code debugging configuration is located at:

```
.vscode/launch.json
```

### GDB

GDB is the debugger associated with the GCC development workflow.

The typical relationship is:

```
G++
  ↓
Executable
```

To test GDB manually:

```bash
gdb ./build/gcc-debug/app
```

Inside GDB:

```
break main
run
next
```

To inspect a variable:

```
print variable_name
```

Exit:

```
quit
```

### LLDB

LLDB is the debugger from the LLVM project.

The typical workflow is:

```
Clang++
  ↓
Executable
  ↓
LLDB
```

To test LLDB manually:

```bash
lldb ./build/clang-debug/app
```

Inside LLDB:

```
breakpoint set --name main
run
next
```

Inspect variables:

```
frame variable
```

Exit:

```
quit
```

---

## 🖥 Debugging from VS Code

When using the Dev Container, the required VS Code extensions are automatically installed.

The project includes:

```
ms-vscode.cmake-tools
ms-vscode.cpptools
vadimcn.vscode-lldb
llvm-vs-code-extensions.vscode-clangd
```

### Debug Clang with LLDB

First build the Clang Debug configuration:

```bash
cmake --preset clang-debug
cmake --build --preset clang-debug
```

Then open:

```
Run and Debug
```

Select:

```
Debug Clang with LLDB
```

Press:

```
F5
```

VS Code will launch:

```
build/clang-debug/app
```

using LLDB.

---

## 🧠 Why are there multiple compilers?

This repository intentionally supports both GCC and Clang.

They are different compiler implementations that compile the same C++ language.

This makes it possible to experiment with:

```
GCC
vs
Clang
```

For example:

```
              C++ source
                  │
        ┌─────────┴─────────┐
        │                   │
       GCC                Clang
        │                   │
       g++               clang++
        │                   │
        ▼                   ▼
   gcc-debug           clang-debug
```

Using multiple compilers is useful for learning:

- compiler diagnostics
- language support
- warnings
- optimization
- generated code
- portability
- compiler-specific behavior

---

## 📁 Build Directory

Build files are intentionally separated by compiler and configuration.

The structure is:

```
build/
│
├── gcc-debug/
│   └── app
│
├── gcc-release/
│   └── app
│
├── clang-debug/
│   └── app
│
└── clang-release/
    └── app
```

This prevents GCC and Clang configurations from interfering with each other.

Do not manually move files between these directories.

If you want to completely regenerate a configuration, you can remove its build directory.

For example:

```bash
rm -rf build/clang-debug
```

Then configure again:

```bash
cmake --preset clang-debug
```

---

## 🧹 Clean Build

To remove all generated build files:

```bash
rm -rf build
```

Then configure and build again:

```bash
cmake --preset clang-debug
cmake --build --preset clang-debug
```

---

## 🔄 Typical Development Workflow

Once everything is configured, your normal workflow is very small.

### Start the container

If using VS Code:

```
Reopen in Container
```

If using Docker manually:

```bash
docker compose up -d
```

### Install/update dependencies

When `vcpkg.json` changes:

```bash
vcpkg install
```

### Build

For Clang Debug:

```bash
cmake --preset clang-debug
cmake --build --preset clang-debug
```

For GCC Debug:

```bash
cmake --preset gcc-debug
cmake --build --preset gcc-debug
```

### Run

```bash
./build/clang-debug/app
```

or:

```bash
./build/gcc-debug/app
```

### Debug

Use VS Code:

```
Run and Debug
    ↓
Debug Clang with LLDB
    ↓
F5
```

---

## 🧪 Recommended Learning Workflow

Because `cpp-journey` is an internals-focused learning repository, don't treat the container as something you need to understand every time you write code.

The intended workflow is:

```
Write code
  ↓
Build with CMake
  ↓
Build using Ninja
  ↓
Run
  ↓
Break it intentionally
  ↓
Debug with GDB/LLDB
  ↓
Inspect compiler behavior
  ↓
Understand why it works
```

For example, compare the same program using:

```
GCC Debug
GCC Release
Clang Debug
Clang Release
```

This is particularly useful when studying:

- undefined behavior
- optimization
- compiler diagnostics
- templates
- memory
- generated code
- performance
- ABI behavior

---

## 🐳 Why Docker?

Without Docker, each developer may have a different environment:

```
Developer A
Windows
GCC 14
CMake 4.x

Developer B
Ubuntu
GCC 13
CMake 3.x

Developer C
macOS
Clang
different libraries
```

This can lead to:

> "It works on my machine."

Docker reduces this difference.

The project defines its development environment through:

```
.devcontainer/Dockerfile
docker-compose.yml
.devcontainer/devcontainer.json
```

The resulting environment contains the expected toolchain:

```
Ubuntu
├── GCC
├── Clang
├── CMake
├── Ninja
├── vcpkg
├── GDB
├── LLDB
└── clangd
```

---

## 🔒 Host vs Container

Your host machine only needs:

```
Docker
VS Code
Dev Containers extension
```

The C++ development tools live inside the container:

```
Host
│
├── Docker
└── VS Code
        │
        ▼
   Container
        │
        ├── GCC
        ├── Clang
        ├── CMake
        ├── Ninja
        ├── vcpkg
        ├── GDB
        ├── LLDB
        └── clangd
```

This means you do not need to separately configure all of these tools on your host machine.

---

## 🛠 Manual Docker Commands

Start:

```bash
docker compose up --build -d
```

Check:

```bash
docker compose ps
```

Enter:

```bash
docker compose exec -it cpp-dev bash
```

Stop:

```bash
docker compose down
```

Rebuild the development image:

```bash
docker compose build --no-cache
```

Start again:

```bash
docker compose up -d
```

---

## ⚠️ Troubleshooting

### CMake cannot find `fmt`

Make sure the dependency is declared in:

```
vcpkg.json
```

Then run:

```bash
vcpkg install
```

After that, remove the affected build directory:

```bash
rm -rf build/clang-debug
```

Configure again:

```bash
cmake --preset clang-debug
```

### `cmake --preset` cannot find a preset

Make sure you are in the project root:

```bash
pwd
```

Expected:

```
/workspace
```

Then:

```bash
ls CMakePresets.json
```

### The executable does not exist

Build the project first:

```bash
cmake --preset clang-debug
cmake --build --preset clang-debug
```

Then:

```bash
ls build/clang-debug/app
```

### VS Code cannot find LLDB

Verify inside the container:

```bash
lldb --version
```

Then make sure the CodeLLDB extension is installed:

```
vadimcn.vscode-lldb
```

If using the Dev Container, rebuild/reopen the container after changing `.devcontainer/devcontainer.json`.

### GDB cannot debug inside Docker

The Docker Compose configuration includes:

```yaml
cap_add:
  - SYS_PTRACE

security_opt:
  - seccomp:unconfined
```

These settings allow ptrace-based debugging inside the container.

If you modify the Compose configuration, recreate the container:

```bash
docker compose down
docker compose up --build -d
```

---

## 📌 Files Responsible for the Environment

| File                  | Responsibility                                   |
| --------------------- | ------------------------------------------------ |
| `Dockerfile`          | Defines the development image                    |
| `docker-compose.yml`  | Runs the development container                   |
| `devcontainer.json`   | Integrates the container with VS Code            |
| `CMakeLists.txt`      | Defines the C++ project                          |
| `CMakePresets.json`   | Defines GCC/Clang + Debug/Release configurations |
| `vcpkg.json`          | Declares C++ dependencies                        |
| `.vscode/launch.json` | Defines VS Code debugging                        |

Together:

```
Dockerfile
    │
    ▼
Development Image
    │
    ▼
docker-compose.yml
    │
    ▼
Running Container
    │
    ▼
devcontainer.json
    │
    ▼
VS Code
    │
    ├──────── CMake
    │             │
    │             ▼
    │           Ninja
    │             │
    │      ┌──────┴──────┐
    │      ▼             ▼
    │     GCC          Clang
    │      │             │
    │     GDB           LLDB
    │
    └──────── vcpkg
                  │
                  ▼
            Dependencies
```

---

## 🌎 Platform Independence

The repository is designed so that the C++ development environment is provided by Docker rather than the host operating system.

The same repository can therefore be used from:

```
Windows
macOS
Linux
```

provided Docker and VS Code Dev Containers are available.

---

## 💡 Important Note

Docker is provided for **development reproducibility**, not because C++ itself requires Docker.

You can still compile C++ directly on your host system.

The purpose of this environment is to make the tools and versions used by this repository predictable.

In particular, the container allows this repository to use:

```
GCC
Clang
CMake
Ninja
vcpkg
GDB
LLDB
```

without requiring every contributor to manually configure the entire toolchain.

---

## 🏁 Quick Reference

For most users, these are the only commands they need to remember.

**Start**

```bash
docker compose up --build -d
```

**Enter**

```bash
docker compose exec -it cpp-dev bash
```

**Install dependencies**

```bash
vcpkg install
```

**Clang Debug**

```bash
cmake --preset clang-debug
cmake --build --preset clang-debug
./build/clang-debug/app
```

**GCC Debug**

```bash
cmake --preset gcc-debug
cmake --build --preset gcc-debug
./build/gcc-debug/app
```

**Stop**

```bash
docker compose down
```

---

## 🚀 Recommended Path

If you are new to this repository, start with:

```
1. Clone repository
        ↓
2. Open in VS Code
        ↓
3. Reopen in Dev Container
        ↓
4. vcpkg install
        ↓
5. cmake --preset clang-debug
        ↓
6. cmake --build --preset clang-debug
        ↓
7. Run the executable
        ↓
8. Debug with LLDB
        ↓
9. Start exploring cpp-journey
```

The container handles the environment.

The actual purpose of `cpp-journey` remains what it has always been:

> **Understand C++ deeply enough that the tooling becomes an instrument for learning—not a black box standing between you and the language.**
