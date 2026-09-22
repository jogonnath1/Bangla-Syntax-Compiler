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

**Bangla Syntax Compiler** is a custom programming language compiler built in **C++** that allows writing programs using **Bengali keywords**. Instead of English keywords like `if`, `while`, `print`, you write in Bengali: `যদি`, `যতক্ষণ`, `দেখাও`.

---

## 🎓 Course Information

| Field | Details |
|-------|---------|
| **Course** | CSE-4114 — Compiler Design and Construction Sessional |
| **University** | Leading University, Sylhet (LUS) |
| **Instructor** | Alian Ahmed Ferdous (Adjunct Lecturer) |
| **Session** | 8th Semester |

---

## 👥 Team Members

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
├── 📂 Part 1/                          ← Part 1: Basic Compiler
│   ├── 📂 Jogonnath/                   ← Lexer (শাব্দিক বিশ্লেষক)
│   │   ├── src/
│   │   │   ├── token.h                 ← Token definitions
│   │   │   ├── lexer.h / lexer.cpp     ← Lexer ★ (Jogonnath)
│   │   │   ├── ast.h                   ← AST node structures
│   │   │   ├── parser.h / parser.cpp   ← Parser (Sayem)
│   │   │   ├── semantic.h / semantic.cpp← Semantic Analyzer (Ellen)
│   │   │   ├── codegen.h / codegen.cpp ← Code Generator (Sami)
│   │   │   ├── error.h                 ← Error handling
│   │   │   ├── bangla_utils.h          ← Bengali digit converter
│   │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
│   │   │   └── main.cpp                ← Entry point
│   │   ├── build/
│   │   │   └── banglasyntax.exe        ← Compiled binary
│   │   ├── examples/
│   │   │   ├── hello.bsc               ← সহজ প্রিন্ট
│   │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
│   │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
│   │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
│   │   │   ├── swap.bsc                ← মান পরিবর্তন
│   │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
│   │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
│   │   └── README.md                   ← Lexer documentation
│   │
│   ├── 📂 Sayem/                       ← Parser (সিনট্যাক্স বিশ্লেষক)
│   │   ├── src/
│   │   │   ├── token.h                 ← Token definitions
│   │   │   ├── lexer.h / lexer.cpp     ← Lexer (Jogonnath)
│   │   │   ├── ast.h                   ← AST node structures
│   │   │   ├── parser.h / parser.cpp   ← Parser ★ (Sayem)
│   │   │   ├── semantic.h / semantic.cpp← Semantic Analyzer (Ellen)
│   │   │   ├── codegen.h / codegen.cpp ← Code Generator (Sami)
│   │   │   ├── error.h                 ← Error handling
│   │   │   ├── bangla_utils.h          ← Bengali digit converter
│   │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
│   │   │   └── main.cpp                ← Entry point
│   │   ├── build/
│   │   │   └── banglasyntax.exe        ← Compiled binary
│   │   ├── examples/
│   │   │   ├── hello.bsc               ← সহজ প্রিন্ট
│   │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
│   │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
│   │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
│   │   │   ├── swap.bsc                ← মান পরিবর্তন
│   │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
│   │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
│   │   └── README.md                   ← Parser documentation & BNF grammar
│   │
│   ├── 📂 Ellen/                       ← Semantic Analyzer (অর্থ বিশ্লেষক)
│   │   ├── src/
│   │   │   ├── token.h                 ← Token definitions
│   │   │   ├── lexer.h / lexer.cpp     ← Lexer (Jogonnath)
│   │   │   ├── ast.h                   ← AST node structures
│   │   │   ├── parser.h / parser.cpp   ← Parser (Sayem)
│   │   │   ├── semantic.h / semantic.cpp← Semantic Analyzer ★ (Ellen)
│   │   │   ├── codegen.h / codegen.cpp ← Code Generator (Sami)
│   │   │   ├── error.h                 ← Error handling
│   │   │   ├── bangla_utils.h          ← Bengali digit converter
│   │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
│   │   │   └── main.cpp                ← Entry point
│   │   ├── build/
│   │   │   └── banglasyntax.exe        ← Compiled binary
│   │   ├── examples/
│   │   │   ├── hello.bsc               ← সহজ প্রিন্ট
│   │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
│   │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
│   │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
│   │   │   ├── swap.bsc                ← মান পরিবর্তন
│   │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
│   │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
│   │   └── README.md                   ← Semantic Analyzer documentation
│   │
│   └── 📂 Sami/                        ← Code Generator (কোড তৈরিকারক)
│       ├── src/
│       │   ├── token.h                 ← Token definitions
│       │   ├── lexer.h / lexer.cpp     ← Lexer (Jogonnath)
│       │   ├── ast.h                   ← AST node structures
│       │   ├── parser.h / parser.cpp   ← Parser (Sayem)
│       │   ├── semantic.h / semantic.cpp← Semantic Analyzer (Ellen)
│       │   ├── codegen.h / codegen.cpp ← Code Generator ★ (Sami)
│       │   ├── error.h                 ← Error handling
│       │   ├── bangla_utils.h          ← Bengali digit converter
│       │   ├── win_console.h/.cpp      ← CMD Bengali font setup
│       │   └── main.cpp                ← Entry point
│       ├── build/
│       │   └── banglasyntax.exe        ← Compiled binary
│       ├── examples/
│       │   ├── hello.bsc               ← সহজ প্রিন্ট
│       │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
│       │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
│       │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
│       │   ├── swap.bsc                ← মান পরিবর্তন
│       │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
│       │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
│       └── README.md                   ← Code Generator documentation
│
└── 📂 Part 2/                          ← Part 2: Extended Compiler (যতক্ষণ While Loop)
    ├── 📂 Jogonnath/                   ← Extended Lexer (যতক্ষণ সমর্থন)
    │   ├── src/
    │   │   ├── token.h                 ← Token definitions (JOTOKHON keyword added)
    │   │   ├── lexer.h / lexer.cpp     ← Extended Lexer ★ (Jogonnath)
    │   │   ├── ast.h                   ← AST nodes (WhileNode added)
    │   │   ├── parser.h / parser.cpp   ← While-loop Parser (Sayem)
    │   │   ├── semantic.h / semantic.cpp← Loop-aware Semantic Analyzer (Ellen)
    │   │   ├── codegen.h / codegen.cpp ← Loop Code Generator (Sami)
    │   │   ├── error.h                 ← Error handling
    │   │   ├── bangla_utils.h          ← Bengali digit converter
    │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
    │   │   └── main.cpp                ← Entry point
    │   ├── build/
    │   │   └── banglasyntax.exe        ← Compiled binary
    │   ├── examples/
    │   │   ├── hello.bsc               ← সহজ প্রিন্ট
    │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
    │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
    │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
    │   │   ├── swap.bsc                ← মান পরিবর্তন
    │   │   ├── sum_loop.bsc            ← যোগফল লুপ (আউটপুট: ৫৫)
    │   │   ├── factorial_test.bsc      ← ফ্যাক্টরিয়াল লুপ (আউটপুট: ১২০)
    │   │   ├── fibonacci_test.bsc      ← ফিবোনাচি ধারা লুপ
    │   │   ├── countdown.bsc           ← উল্টো গণনা লুপ
    │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
    │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
    │   └── README.md                   ← Extended Lexer documentation
    │
    ├── 📂 Sayem/                       ← Extended Parser (যতক্ষণ লুপ পার্সিং)
    │   ├── src/
    │   │   ├── token.h                 ← Token definitions (JOTOKHON keyword added)
    │   │   ├── lexer.h / lexer.cpp     ← Extended Lexer (Jogonnath)
    │   │   ├── ast.h                   ← AST nodes (WhileNode added)
    │   │   ├── parser.h / parser.cpp   ← Extended Parser ★ (Sayem)
    │   │   ├── semantic.h / semantic.cpp← Loop-aware Semantic Analyzer (Ellen)
    │   │   ├── codegen.h / codegen.cpp ← Loop Code Generator (Sami)
    │   │   ├── error.h                 ← Error handling
    │   │   ├── bangla_utils.h          ← Bengali digit converter
    │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
    │   │   └── main.cpp                ← Entry point
    │   ├── build/
    │   │   └── banglasyntax.exe        ← Compiled binary
    │   ├── examples/
    │   │   ├── hello.bsc               ← সহজ প্রিন্ট
    │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
    │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
    │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
    │   │   ├── swap.bsc                ← মান পরিবর্তন
    │   │   ├── sum_loop.bsc            ← যোগফল লুপ (আউটপুট: ৫৫)
    │   │   ├── factorial_test.bsc      ← ফ্যাক্টরিয়াল লুপ (আউটপুট: ১২০)
    │   │   ├── fibonacci_test.bsc      ← ফিবোনাচি ধারা লুপ
    │   │   ├── countdown.bsc           ← উল্টো গণনা লুপ
    │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
    │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
    │   └── README.md                   ← Extended Parser documentation & BNF
    │
    ├── 📂 Ellen/                       ← Extended Semantic Analyzer
    │   ├── src/
    │   │   ├── token.h                 ← Token definitions (JOTOKHON keyword added)
    │   │   ├── lexer.h / lexer.cpp     ← Extended Lexer (Jogonnath)
    │   │   ├── ast.h                   ← AST nodes (WhileNode added)
    │   │   ├── parser.h / parser.cpp   ← Extended Parser (Sayem)
    │   │   ├── semantic.h / semantic.cpp← Extended Semantic Analyzer ★ (Ellen)
    │   │   ├── codegen.h / codegen.cpp ← Loop Code Generator (Sami)
    │   │   ├── error.h                 ← Error handling
    │   │   ├── bangla_utils.h          ← Bengali digit converter
    │   │   ├── win_console.h/.cpp      ← CMD Bengali font setup
    │   │   └── main.cpp                ← Entry point
    │   ├── build/
    │   │   └── banglasyntax.exe        ← Compiled binary
    │   ├── examples/
    │   │   ├── hello.bsc               ← সহজ প্রিন্ট
    │   │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
    │   │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
    │   │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
    │   │   ├── swap.bsc                ← মান পরিবর্তন
    │   │   ├── sum_loop.bsc            ← যোগফল লুপ (আউটপুট: ৫৫)
    │   │   ├── factorial_test.bsc      ← ফ্যাক্টরিয়াল লুপ (আউটপুট: ১২০)
    │   │   ├── fibonacci_test.bsc      ← ফিবোনাচি ধারা লুপ
    │   │   ├── countdown.bsc           ← উল্টো গণনা লুপ
    │   │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
    │   │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
    │   └── README.md                   ← Extended Semantic Analyzer documentation
    │
    └── 📂 Sami/                        ← Extended Code Generator
        ├── src/
        │   ├── token.h                 ← Token definitions (JOTOKHON keyword added)
        │   ├── lexer.h / lexer.cpp     ← Extended Lexer (Jogonnath)
        │   ├── ast.h                   ← AST nodes (WhileNode added)
        │   ├── parser.h / parser.cpp   ← Extended Parser (Sayem)
        │   ├── semantic.h / semantic.cpp← Extended Semantic Analyzer (Ellen)
        │   ├── codegen.h / codegen.cpp ← Extended Code Generator ★ (Sami)
        │   ├── error.h                 ← Error handling
        │   ├── bangla_utils.h          ← Bengali digit converter
        │   ├── win_console.h/.cpp      ← CMD Bengali font setup
        │   └── main.cpp                ← Entry point
        ├── build/
        │   └── banglasyntax.exe        ← Compiled binary
        ├── examples/
        │   ├── hello.bsc               ← সহজ প্রিন্ট
        │   ├── math_test.bsc           ← গণিতের হিসাব (আউটপুট: ২০)
        │   ├── age_check.bsc           ← যদি-নাহলে শর্ত
        │   ├── circle_area.bsc         ← বৃত্তের ক্ষেত্রফল (আউটপুট: ৯৫.০৩৩৪)
        │   ├── swap.bsc                ← মান পরিবর্তন
        │   ├── sum_loop.bsc            ← যোগফল লুপ (আউটপুট: ৫৫)
        │   ├── factorial_test.bsc      ← ফ্যাক্টরিয়াল লুপ (আউটপুট: ১২০)
        │   ├── fibonacci_test.bsc      ← ফিবোনাচি ধারা লুপ
        │   ├── countdown.bsc           ← উল্টো গণনা লুপ
        │   ├── type_error.bsc          ← ধরন ভুলের উদাহরণ
        │   └── undeclared_error.bsc    ← অঘোষিত চলকের উদাহরণ
        └── README.md                   ← Extended Code Generator documentation
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
| `IDENTIFIER` | `বয়স`, `যোগফল`, `গণক` |
| `INTEGER_LIT` | `১০`, `৫`, `১০০` |
| `FLOAT_LIT` | `৩.১৪`, `৫.৫` |
| `STRING_LIT` | `"হ্যালো বাংলা!"` |
| `OPERATOR` | `+`, `-`, `*`, `/`, `=`, `==`, `!=`, `>`, `<` |
| `SEMI` | `;` |

---

## 💻 Code Examples

### Hello World
```
দেখাও "স্বাগতম, বাংলা কম্পাইলার!";
```
**Output:** `স্বাগতম, বাংলা কম্পাইলার!`

---

### Variable & Math
```
ধরি সংখ্যা প্রথম = ১০;
ধরি সংখ্যা দ্বিতীয় = ৫;
ধরি সংখ্যা তৃতীয় = ২;
ধরি সংখ্যা ফল = প্রথম + দ্বিতীয় * তৃতীয়;
দেখাও "গণনার ফল:";
দেখাও ফল;
```
**Output:** `গণনার ফল:` → `২০`

---

### If-Else Condition
```
ধরি সংখ্যা বয়স = ১৬;
যদি (বয়স > ১৭) শুরু
    দেখাও "আপনি ভোট দিতে পারবেন!";
শেষ
নাহলে শুরু
    দেখাও "আপনি ভোটের বয়স হয়নি।";
শেষ
```
**Output:** `আপনি ভোটের বয়স হয়নি।`

---

### Swap Variables
```
ধরি সংখ্যা প্রথম = ১০;
ধরি সংখ্যা দ্বিতীয় = ২৫;
ধরি সংখ্যা অস্থায়ী = প্রথম;
প্রথম = দ্বিতীয়;
দ্বিতীয় = অস্থায়ী;
দেখাও "পরিবর্তনের পরে প্রথম:";
দেখাও প্রথম;
দেখাও "পরিবর্তনের পরে দ্বিতীয়:";
দেখাও দ্বিতীয়;
```
**Output:** `২৫` then `১০`

---

### Circle Area (Decimal)
```
ধরি দশমিক পাই = ৩.১৪১৬;
ধরি দশমিক ত্রিজ্যা = ৫.৫;
ধরি দশমিক ক্ষেত্রফল = পাই * ত্রিজ্যা * ত্রিজ্যা;
দেখাও "বৃত্তের ক্ষেত্রফল:";
দেখাও ক্ষেত্রফল;
```
**Output:** `বৃত্তের ক্ষেত্রফল:` → `৯৫.০৩৩৪`

---

### Sum 1 to 10 — While Loop (Part 2)
```
ধরি সংখ্যা সীমা = ১০;
ধরি সংখ্যা যোগফল = ০;
ধরি সংখ্যা গণক = ১;

যতক্ষণ (গণক <= সীমা) শুরু
    যোগফল = যোগফল + গণক;
    গণক = গণক + ১;
শেষ

দেখাও "১ থেকে ১০ এর যোগফল:";
দেখাও যোগফল;
```
**Output:** `১ থেকে ১০ এর যোগফল:` → `৫৫`

---

### Factorial — While Loop (Part 2)
```
ধরি সংখ্যা মান = ৫;
ধরি সংখ্যা ফ্যাক্টরিয়াল = ১;
ধরি সংখ্যা গণক = ১;

যতক্ষণ (গণক <= মান) শুরু
    ফ্যাক্টরিয়াল = ফ্যাক্টরিয়াল * গণক;
    গণক = গণক + ১;
শেষ

দেখাও "৫ এর ফ্যাক্টরিয়াল:";
দেখাও ফ্যাক্টরিয়াল;
```
**Output:** `৫ এর ফ্যাক্টরিয়াল:` → `১২০`

---

### Fibonacci Sequence (Part 2)
```
ধরি সংখ্যা প্রথম = ০;
ধরি সংখ্যা দ্বিতীয় = ১;
ধরি সংখ্যা সীমা = ৮;
ধরি সংখ্যা গণক = ০;

দেখাও "ফিবোনাচি ধারা:";
দেখাও প্রথম;
দেখাও দ্বিতীয়;

যতক্ষণ (গণক < সীমা) শুরু
    ধরি সংখ্যা অস্থায়ী = প্রথম + দ্বিতীয়;
    প্রথম = দ্বিতীয়;
    দ্বিতীয় = অস্থায়ী;
    দেখাও দ্বিতীয়;
    গণক = গণক + ১;
শেষ
```
**Output:** `০, ১, ১, ২, ৩, ৫, ৮, ১৩, ২১, ৩৪`

---

### Countdown (Part 2)
```
ধরি সংখ্যা গণনা = ৫;
দেখাও "উল্টো গণনা:";

যতক্ষণ (গণনা > ০) শুরু
    দেখাও গণনা;
    গণনা = গণনা - ১;
শেষ

দেখাও "শেষ!";
```
**Output:** `৫, ৪, ৩, ২, ১, শেষ!`

---

## ▶️ How to Run

### Prerequisites
- Windows OS
- No installation needed — just the `.exe` file!

### Run a Program
```cmd
cd "Part2\Sayem"

REM Compile .bsc → .py
build\banglasyntax.exe examples\factorial_test.bsc

REM Run output
python examples\factorial_test.py
```

### Debug Token Mode
```cmd
build\banglasyntax.exe examples\math_test.bsc --tokens
```

### Example Compiler Output
```
====================================================
 বাংলা সিনট্যাক্স কম্পাইলার  --  পর্ব ২
 CSE-4114 | কম্পাইলার ডিজাইন সেশনাল
====================================================
 দলের সদস্য: জগন্নাথ (Jogonnath)
 দায়িত্ব  : ধাপ ১ -- শাব্দিক বিশ্লেষক (Lexer)
====================================================

[ধাপ ১] শাব্দিক বিশ্লেষণ *** তোমার অংশ ***
  -> ৪৫ টি টোকেন পাওয়া গেছে।

[ধাপ ২] সিনট্যাক্স বিশ্লেষণ (Parsing)
  -> ৬ টি স্টেটমেন্ট সহ AST তৈরি।

[ধাপ ৩] অর্থ বিশ্লেষণ (Semantic Analysis)
  -> টাইপ চেকিং সফল। ৩ টি চলক।

[ধাপ ৪] Python কোড তৈরি (Code Generation)
  -> Python আউটপুট: examples\factorial_test.py

==================================================
 কম্পাইলেশন সফল! (জগন্নাথর অংশ সম্পন্ন)
==================================================
```

---

## 🛠️ Build from Source

```cmd
g++ -o build\banglasyntax.exe src\main.cpp src\win_console.cpp src\lexer.cpp src\parser.cpp src\semantic.cpp src\codegen.cpp -std=c++17 -I src\
```

---

## 📋 Example Files

| File | Description |
|------|-------------|
| `hello.bsc` | Simple print statement |
| `math_test.bsc` | Arithmetic operations |
| `age_check.bsc` | If-else condition |
| `circle_area.bsc` | Area calculation (decimal) |
| `swap.bsc` | Variable swapping |
| `factorial_test.bsc` | Factorial using loop (Part 2) |
| `fibonacci_test.bsc` | Fibonacci series (Part 2) |
| `countdown.bsc` | Countdown loop (Part 2) |
| `sum_loop.bsc` | Sum 1 to 10 (Part 2) |
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