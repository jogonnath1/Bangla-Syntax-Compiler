# বাংলা সিনট্যাক্স কম্পাইলার (Bangla Syntax Compiler)

> A fully Bangla-language compiler built in C++17, developed as a university sessional project.
> The source language uses Bengali keywords, Bengali identifiers, and Bengali digits.
> Target output is Python.

---

## Course Information

| Field | Details |
|-------|---------|
| **Course** | CSE-4114 — Compiler Design and Construction Sessional |
| **University** | Leading University, Sylhet (LUS) |
| **Instructor** | Alian Ahmed Ferdous, Adjunct Lecturer |
| **Session** | 8th Semester |

---

## Team Members & Responsibilities

| Member | Role |
|--------|------|
| **Jogonnath Das Talukder** | Lexical Analyzer (Lexer) |
| **Ellen** | Semantic Analyzer |
| **Sami** | Code Generator |
| **Sayem** | Parser |

---

## Project Structure

```
Bangla Syntax Compiler/
├── Part 1/                        ← Basic compiler (variables, if-else, print)
│   ├── Jogonnath/
│   │   ├── src/                   ← C++ source files
│   │   │   ├── main.cpp
│   │   │   ├── lexer.cpp / lexer.h
│   │   │   ├── parser.cpp / parser.h
│   │   │   ├── semantic.cpp / semantic.h
│   │   │   ├── codegen.cpp / codegen.h
│   │   │   ├── ast.h
│   │   │   ├── token.h
│   │   │   ├── error.h
│   │   │   ├── bangla_utils.h     ← Bengali digit converter utility
│   │   │   ├── win_console.h/cpp  ← Auto-sets Bengali font in CMD
│   │   ├── build/
│   │   │   └── banglasyntax.exe
│   │   └── examples/              ← .bsc source programs (fully Bengali)
│   ├── Ellen/                     ← Same structure
│   ├── Sami/                      ← Same structure
│   └── Sayem/                     ← Same structure
│
└── Part 2/                        ← Extended compiler (adds যতক্ষণ while loop)
    ├── Jogonnath/
    ├── Ellen/
    ├── Sami/
    └── Sayem/
```

---

## The Bangla Programming Language

This compiler implements a custom programming language with fully Bengali syntax.

### Keywords

| Bengali Keyword | Meaning |
|----------------|---------|
| `ধরি` | declare variable |
| `সংখ্যা` | integer type |
| `দশমিক` | float type |
| `যদি` | if |
| `নাহলে` | else |
| `যতক্ষণ` | while (Part 2) |
| `দেখাও` | print |
| `শুরু` | begin block |
| `শেষ` | end block |

### Bengali Digit Support

The compiler accepts Bengali digits directly in source code:

| Bengali | English |
|---------|---------|
| `০` | 0 |
| `১` | 1 |
| `২` | 2 |
| `৩` | 3 |
| `৪` | 4 |
| `৫` | 5 |
| `৬` | 6 |
| `৭` | 7 |
| `৮` | 8 |
| `৯` | 9 |

Multi-digit: `১০`, `২৫`, `১০০` | Decimal: `৩.১৪`, `৫.৫`

### Example Programs

**Hello World**
```
দেখাও "স্বাগতম, বাংলা কম্পাইলার!";
```

**Arithmetic**
```
ধরি সংখ্যা ক = ১০;
ধরি সংখ্যা খ = ৫;
ধরি সংখ্যা ফল = ক + খ;
দেখাও "যোগফল:";
দেখাও ফল;
```

**If-Else**
```
ধরি সংখ্যা বয়স = ২০;
যদি (বয়স >= ১৮) শুরু
    দেখাও "প্রাপ্তবয়স্ক";
শেষ
নাহলে শুরু
    দেখাও "অপ্রাপ্তবয়স্ক";
শেষ
```

**While Loop (Part 2)**
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
Expected output: `৫৫`

**Factorial (Part 2)**
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
Expected output: `১২০`

---

## Compiler Pipeline

```
.bsc Source File
      ↓
[Step 1] Lexical Analysis  ← Jogonnath
      ↓  Tokens
[Step 2] Syntax Analysis   ← Sayem
      ↓  AST
[Step 3] Semantic Analysis ← Ellen
      ↓  Validated AST
[Step 4] Code Generation   ← Sami
      ↓
.py Python Output
```

---

## Grammar (BNF)

```
program      → statement*
statement    → declaration | assignment | if_stmt | while_stmt | print_stmt
declaration  → 'ধরি' type identifier '=' expression ';'
type         → 'সংখ্যা' | 'দশমিক'
assignment   → identifier '=' expression ';'
if_stmt      → 'যদি' '(' expression ')' block [ 'নাহলে' block ]
while_stmt   → 'যতক্ষণ' '(' expression ')' block
print_stmt   → 'দেখাও' expression ';'
block        → 'শুরু' statement* 'শেষ'
expression   → comparison
comparison   → addition ( ( '==' | '!=' | '<' | '>' | '<=' | '>=' ) addition )*
addition     → multiplication ( ( '+' | '-' ) multiplication )*
multiplication → unary ( ( '*' | '/' ) unary )*
unary        → '-' unary | primary
primary      → integer | decimal | string | identifier | '(' expression ')'
integer      → [0-9]+ | [০-৯]+
decimal      → [0-9]+'.'[0-9]+ | [০-৯]+'.'[০-৯]+
identifier   → (Bengali Unicode letter | ASCII letter) (letter | digit)*
```

---

## How to Build

**Requirements:** g++ (MinGW), Python 3

```cmd
g++ -o build\banglasyntax.exe src\main.cpp src\win_console.cpp src\lexer.cpp src\parser.cpp src\semantic.cpp src\codegen.cpp -std=c++17 -I src\
```

---

## How to Run

```cmd
cd "Part2\Sayem"

REM Step 1: Compile .bsc → .py
build\banglasyntax.exe examples\factorial_test.bsc

REM Step 2: Run output
python examples\factorial_test.py
```

### All Available Examples (Part 2)

| File | Description |
|------|-------------|
| `hello.bsc` | Hello World |
| `math_test.bsc` | Arithmetic operations |
| `age_check.bsc` | If-else condition |
| `circle_area.bsc` | Decimal calculation |
| `swap.bsc` | Variable swap |
| `countdown.bsc` | While loop countdown |
| `factorial_test.bsc` | Factorial with while loop |
| `fibonacci_test.bsc` | Fibonacci sequence |
| `sum_loop.bsc` | Sum 1 to 10 |
| `type_error.bsc` | Type error detection demo |
| `undeclared_error.bsc` | Undeclared variable demo |

---

## Features

### Part 1 (Basic)
- Bengali keyword syntax
- Bengali & ASCII identifier support
- Bengali & ASCII digit literals
- Integer (`সংখ্যা`) and float (`দশমিক`) types
- Arithmetic: `+`, `-`, `*`, `/`
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
- If-Else (`যদি` / `নাহলে`)
- Print (`দেখাও`)
- Type checking (semantic analysis)
- Undeclared variable detection
- Bengali digit output (৫৫, ১২০, etc.)
- Auto SolaimanLipi font in CMD

### Part 2 (Extended — adds)
- While loop (`যতক্ষণ`)
- Variable declarations inside loop body
- All Part 1 features preserved

---

## Error Messages (Bengali)

```
BSC: শাব্দিক ভুল।       ← Lexical error
BSC: সিনট্যাক্স ভুল।   ← Syntax error
BSC: অর্থগত ভুল।        ← Semantic error
```

---

## Topics

`compiler` `bangla` `bengali` `cpp` `lexer` `parser` `semantic-analysis`
`code-generation` `compiler-design` `university-project` `bangla-programming` `cse-4114`

---

*CSE-4114 Compiler Design and Construction Sessional — Leading University, Sylhet*