# SquareMat Project

## About

This project implements a C++ class called `SquareMat`, representing a square matrix of doubles.  
The class supports a wide variety of operations on matrices: addition, subtraction, multiplication, division, modulo, transpose, determinant calculation, comparisons, and more.

The project is designed without using STL containers, and memory management is done manually using dynamic arrays.

---

## Project Structure

- **SquareMat.hpp**  
  Defines the `SquareMat` class, its members, constructors, destructors, and operator overloads.

- **SquareMat.cpp**  
  Implements all the methods declared in the header file. Handles matrix operations and memory management.

- **main.cpp**  
  A demonstration file that creates matrices, performs operations, and displays the results.

- **tests.cpp**  
  Contains unit tests for all the features of `SquareMat`, written using the Doctest framework.  
  Tests cover normal functionality, edge cases, and exceptions.

- **Makefile**  
  Allows easy compilation and execution of the project, tests, and memory checking.

---

## Key Features

- Create square matrices of any positive size.
- Add, subtract, and multiply matrices.
- Multiply/divide matrices by scalars.
- Perform element-wise modulo operations.
- Calculate the transpose of a matrix.
- Calculate the determinant of a matrix (using Laplace expansion).
- Compare matrices based on the sum of their elements (`==`, `!=`, `<`, `>`, `<=`, `>=`).
- Support increment (`++`) and decrement (`--`) operators.
- Overloaded operators to enable clean and intuitive code.
- Full support for deep copy (copy constructor and assignment operator).
- Manual memory management (no STL vectors).

---

## How to Compile and Run

You can use the **Makefile** provided in the project.

### Available Commands:

| Command         | Description |
|-----------------|-------------|
| `make Main`     | Compile `main.cpp` and `SquareMat.cpp` to create `main_exec`. Run the demo of the project. |
| `make test`     | Compile `tests.cpp` and `SquareMat.cpp` to create `test_exec`. Run all unit tests. |
| `make valgrind` | Run the unit tests under Valgrind to detect memory leaks and memory errors. |
| `make clean`    | Delete all executables and temporary files to clean the project directory. |

---

## Usage Instructions

## 🖥️ Usage Instructions

### 1. Run the Main Demo
```bash
make Main
./main_exec
```

**Expected Output:**
- Matrices will be created and printed to the screen.
- Various operations will be demonstrated, including:
  - Addition (`A + B`)
  - Multiplication (`A * B`)
  - Transpose (`~A`)
  - Determinant calculation (`!A`)

---

### 2. Run the Unit Tests
```bash
make test
./test_exec
```

**Expected Output:**
- All unit tests will run automatically.
- If everything is implemented correctly, all tests should pass successfully.
- You will see a green success message from the Doctest framework indicating that all tests passed.

---

### 3. Check for Memory Leaks
```bash
make valgrind
```
Since I added "--log-file=valgrind-out.txt" to the makefile, to see the output we will use the command:
```bash
cat valgrind-out.txt
```

**Expected Output:**
- Valgrind will analyze the program's memory usage during the tests.
- At the end of the run, you should see the message:
  ```
  All heap blocks were freed -- no leaks are possible
  ```
- If any memory errors or leaks are detected, they will be reported.
- Fix any issues immediately before submitting the project!

---

### 4. Clean the Project
```bash
make clean
```

**Expected Output:**
- Deletes `main_exec`, `test_exec`, and any other generated files.
- Only source files (`.cpp`, `.hpp`) and documentation files (`README.md`, `Makefile`) will remain.
- This keeps your project directory clean and organized.

---




