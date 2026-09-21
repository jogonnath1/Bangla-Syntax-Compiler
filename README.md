<div align="center">

# 🇧🇩 বাংলা সিনট্যাক্স কম্পাইলার
### Bangla Syntax Compiler

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Course](https://img.shields.io/badge/Course-CSE--4114-green.svg)](https://github.com/jogonnath1/Bangla-Syntax-Compiler)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)](https://github.com/jogonnath1/Bangla-Syntax-Compiler)
[![University](https://img.shields.io/badge/University-LUS-orange.svg)](https://lus.ac.bd)

> A compiler that understands **Bengali (Bangla) keywords** — write code in your mother tongue!

</div>

---

## 📖 Project Overview

**Bangla Syntax Compiler** is a custom programming language compiler built in **C++** that allows writing programs using **Bengali keywords**. Instead of English keywords like `if`, `while`, `print`, you write `যদি`, `যতক্ষণ`, `দেখাও`.

This project is developed as a **group sessional project** for:

> 📚 **CSE-4114 — Compiler Design and Construction Sessional**
> 👨‍🏫 **Instructor:** Alian Ahmed Ferdous, Adjunct Lecturer
> 🏫 **Leading University, Sylhet (LUS)**

---

## 👥 Team Members & Responsibilities

| Member | Responsibility | Part 1 | Part 2 |
|--------|---------------|--------|--------|
| **Jogonnath Das Talukder** | Lexer (শাব্দিক বিশ্লেষক) | ✅ | ✅ |
| **Ellen** | Semantic Analyzer (অর্থ বিশ্লেষক) | ✅ | ✅ |
| **Sami** | Code Generator (কোড তৈরিকারক) | ✅ | ✅ |
| **Sayem** | Parser (সিনট্যাক্স বিশ্লেষক) | ✅ | ✅ |

---

## 🏗️ Compiler Pipeline

```
Source Code (.bsc)
       │
       ▼
┌─────────────┐
│    LEXER    │  ← Tokenizes Bengali source code (Jogonnath)
└──────┬──────┘
       │ Token Stream
       ▼
┌─────────────┐
│   PARSER    │  ← Builds Abstract Syntax Tree (Sayem)
└──────┬──────┘
       │ AST
       ▼
┌──────────────────┐
│ SEMANTIC ANALYZER│  ← Type checking, scope resolution (Ellen)
└──────┬───────────┘
       │ Validated AST
       ▼
┌──────────────┐
│ CODE GENERATOR│  ← Generates output/Python code (Sami)
└──────────────┘
```

---

## 📁 Repository Structure

```
Bangla-Syntax-Compiler/
├── 📂 Part 1/                        ← Part 1: Basic Compiler (Lexer + Parser + Semantic + CodeGen)
│   ├── 📂 Jogonnath/                 ← Lexer implementation
│   │   ├── src/
│   │   │   ├── token.h              ← Token definitions
│   │   │   ├── lexer.h / lexer.cpp  ← Lexer (Jogonnath)
│   │   │   ├── ast.h                ← AST node structures
│   │   │   ├── parser.h / parser.cpp← Parser (Sayem)
│   │   │   ├── semantic.h/.cpp      ← Semantic Analyzer (Ellen)
│   │   │   ├── codegen.h/.cpp       ← Code Generator (Sami)
│   │   │   ├── error.h              ← Error handling
│   │   │   └── main.cpp             ← Entry point
│   │   ├── build/
│   │   │   └── banglasyntax.exe    ← Compiled binary
│   │   ├── examples/
│   │   │   ├── hello.bsc
│   │   │   ├── math_test.bsc
│   │   │   ├── age_check.bsc
│   │   │   ├── circle_area.bsc
│   │   │   ├── swap.bsc
│   │   │   ├── type_error.bsc
│   │   │   └── undeclared_error.bsc
│   │   └── README.md
│   ├── 📂 Ellen/                     ← Ellen's contribution
│   ├── 📂 Sami/                      ← Sami's contribution
│   └── 📂 Sayem/                     ← Sayem's contribution
│
└── 📂 Part 2/                        ← Part 2: Extended Compiler (Loops + Advanced Features)
    ├── 📂 Jogonnath/                 ← Extended Lexer
    │   ├── src/ build/ examples/
    │   └── README.md
    ├── 📂 Ellen/
    ├── 📂 Sami/
    └── 📂 Sayem/
```

---

## 🔤 Bangla Keyword Reference

| Bengali Keyword | English Equivalent | Description |
|----------------|-------------------|-------------|
| `ধরি` | `let` / `var` | Variable declaration |
| `সংখ্যা` | `int` | Integer type |
| `দশমিক` | `float` | Float type |
| `দেখাও` | `print` | Print output |
| `যদি` | `if` | Conditional |
| `নাহলে` | `else` | Else branch |
| `যতক্ষণ` | `while` | While loop |
| `শুরু` | `{` | Block start |
| `শেষ` | `}` | Block end |

---

## 🔢 Token Types

| Token | Example |
|-------|---------|
| `KEYWORD` | `ধরি`, `যদি`, `দেখাও` |
| `TYPE` | `সংখ্যা`, `দশমিক` |
| `IDENTIFIER` | `বয়স`, `ফল`, `pi` |
| `INTEGER_LIT` | `10`, `5`, `100` |
| `FLOAT_LIT` | `3.14`, `5.5` |
| `STRING_LIT` | `"হ্যালো বাংলা!"` |
| `OPERATOR` | `+`, `-`, `*`, `/`, `=`, `==`, `!=`, `>`, `<` |
| `SEMI` | `;` |

---

## 💻 Code Examples

### Hello World
```
দেখাও "সারা বিশ্বের শ্রেষ্ঠ কম্পাইলার, ডগেশবাংলা!";
```

### Variable & Math
```
ধরি সংখ্যা a = 10;
ধরি সংখ্যা b = 5;
ধরি সংখ্যা c = 2;
ধরি সংখ্যা ফল = a + b * c;
দেখাও "গণনার ফল:";
দেখাও ফল;
```

### If-Else Condition
```
ধরি সংখ্যা বয়স = 16;
যদি (বয়স > 17) শুরু
    দেখাও "আপনি ভোট দিতে পারবেন!";
শেষ
নাহলে শুরু
    দেখাও "আপনি ভোটের বয়স হয়নি।";
শেষ
```

### While Loop (Part 2)
```
ধরি সংখ্যা n = 5;
ধরি সংখ্যা ফ্যাক্টরিয়াল = 1;
ধরি সংখ্যা i = 1;
যতক্ষণ (i <= n) শুরু
    ফ্যাক্টরিয়াল = ফ্যাক্টরিয়াল * i;
    i = i + 1;
শেষ
দেখাও "৫ এর ফ্যাক্টরিয়াল:";
দেখাও ফ্যাক্টরিয়াল;
```

### Fibonacci Sequence (Part 2)
```
ধরি সংখ্যা a = 0;
ধরি সংখ্যা b = 1;
ধরি সংখ্যা সীমা = 8;
ধরি সংখ্যা i = 0;
দেখাও "ফিবোনাচি ধারা:";
দেখাও a;
দেখাও b;
যতক্ষণ (i < সীমা) শুরু
    ধরি সংখ্যা tmp = a + b;
    a = b;
    b = tmp;
    দেখাও b;
    i = i + 1;
শেষ
```

---

## ▶️ How to Run

### Prerequisites
- Windows OS
- No installation needed — just the `.exe` file!

### Run a Program
```powershell
# Run a .bsc file
.\build\banglasyntax.exe examples\hello.bsc

# View token stream (debug mode)
.\build\banglasyntax.exe examples\math_test.bsc --tokens
```

### Example Output
```
====================================================
 বাংলা সিনট্যাক্স কম্পাইলার  --  পর্ব ১
 CSE-4114 | কম্পাইলার ডিজাইন সেশনাল
====================================================
 দলের সদস্য: জগন্নাথ (Jogonnath)
 দায়িত্ব  : ধাপ ১ -- শাব্দিক বিশ্লেষক (Lexer)
====================================================

কম্পাইলেশন সফল!
```

---

## 🛠️ Build from Source

```powershell
# Compile using g++
g++ -o build/banglasyntax.exe src/main.cpp src/lexer.cpp src/parser.cpp src/semantic.cpp src/codegen.cpp -std=c++17
```

---

## 📋 Example Files

| File | Description |
|------|-------------|
| `hello.bsc` | Simple print statement |
| `math_test.bsc` | Arithmetic operations |
| `age_check.bsc` | If-else condition |
| `circle_area.bsc` | Area calculation |
| `swap.bsc` | Variable swapping |
| `factorial_test.bsc` | Factorial using loop (Part 2) |
| `fibonacci_test.bsc` | Fibonacci series (Part 2) |
| `countdown.bsc` | Countdown loop (Part 2) |
| `sum_loop.bsc` | Sum using loop (Part 2) |
| `type_error.bsc` | Type mismatch error demo |
| `undeclared_error.bsc` | Undeclared variable error demo |

---

## 📌 Project Parts

| | Part 1 | Part 2 |
|---|--------|--------|
| **Lexer** | ✅ Basic tokenization | ✅ Extended with loop tokens |
| **Parser** | ✅ Basic AST | ✅ Loop & advanced parsing |
| **Semantic** | ✅ Type & scope check | ✅ Enhanced analysis |
| **Code Gen** | ✅ Basic output | ✅ Loop code generation |
| **Loops** | ❌ | ✅ `যতক্ষণ` (while) |
| **Examples** | 7 files | 11 files |

---

<div align="center">

**বাংলা সিনট্যাক্স কম্পাইলার** — CSE-4114 Sessional Project

*Leading University, Sylhet | Compiler Design and Construction*

Made with ❤️ by **Jogonnath**, **Ellen**, **Sami** & **Sayem**

</div>