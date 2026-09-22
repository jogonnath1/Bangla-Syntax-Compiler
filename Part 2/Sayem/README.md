# বাংলা সিনট্যাক্স কম্পাইলার — পর্ব ২ | সায়েম (Sayem)

> **CSE-4114 — Compiler Design and Construction Sessional**
> শিক্ষক: Alian Ahmed Ferdous, Adjunct Lecturer

---

## সদস্যের তথ্য

| বিষয় | বিবরণ |
|-------|--------|
| **নাম** | Sayem |
| **দায়িত্ব** | ধাপ ২ — সিনট্যাক্স বিশ্লেষক (Parser) |
| **পর্ব** | পর্ব ২ (যতক্ষণ লুপ সহ) |

---

## কাজের বিবরণ

পর্ব ২-তে Parser **`যতক্ষণ`** (while loop) স্টেটমেন্ট পার্সিং যোগ করেছে।

### পর্ব ২ ব্যাকরণ (BNF):
```
program      → statement*
statement    → declaration | assignment | if_stmt | while_stmt | print_stmt
declaration  → 'ধরি' type identifier '=' expression ';'
type         → 'সংখ্যা' | 'দশমিক'
if_stmt      → 'যদি' '(' expression ')' block ['নাহলে' block]
while_stmt   → 'যতক্ষণ' '(' expression ')' block
print_stmt   → 'দেখাও' expression ';'
block        → 'শুরু' statement* 'শেষ'
expression   → comparison (('+' | '-') comparison)*
comparison   → term (('==' | '!=' | '<' | '>' | '<=' | '>=') term)*
term         → unary (('*' | '/') unary)*
unary        → '-' unary | primary
primary      → integer | decimal | string | identifier | '(' expression ')'
```

---

## উদাহরণ প্রোগ্রাম

### ১ থেকে ১০ এর যোগফল
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
**আউটপুট:** `৫৫`

### ফ্যাক্টরিয়াল
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
**আউটপুট:** `১২০`

### উল্টো গণনা
```
ধরি সংখ্যা গণনা = ৫;
দেখাও "উল্টো গণনা:";

যতক্ষণ (গণনা > ০) শুরু
    দেখাও গণনা;
    গণনা = গণনা - ১;
শেষ

দেখাও "শেষ!";
```
**আউটপুট:** `৫, ৪, ৩, ২, ১, শেষ!`

---

## চালানোর নিয়ম

```cmd
cd "Part 2\Sayem"
build\banglasyntax.exe examples\sum_loop.bsc
python examples\sum_loop.py

build\banglasyntax.exe examples\factorial_test.bsc
python examples\factorial_test.py
```

---

## উদাহরণ ফাইলসমূহ (পর্ব ২)

| ফাইল | বিবরণ | আউটপুট |
|------|-------|--------|
| `hello.bsc` | সহজ প্রিন্ট | স্বাগতম! |
| `math_test.bsc` | গণিত ও অগ্রাধিকার | `২০` |
| `age_check.bsc` | যদি-নাহলে | আপনি ভোটের বয়স হয়নি। |
| `circle_area.bsc` | বৃত্তের ক্ষেত্রফল | `৯৫.০৩৩৪` |
| `swap.bsc` | মান পরিবর্তন | `২৫` তারপর `১০` |
| `sum_loop.bsc` | যোগফল লুপ ★ | `৫৫` |
| `factorial_test.bsc` | ফ্যাক্টরিয়াল ★ | `১২০` |
| `fibonacci_test.bsc` | ফিবোনাচি ★ | ধারা |
| `countdown.bsc` | উল্টো গণনা ★ | `৫,৪,৩,২,১` |
| `type_error.bsc` | ধরন ভুল | ত্রুটি |
| `undeclared_error.bsc` | অঘোষিত চলক | ত্রুটি |

---

## ফাইল কাঠামো

```
Part 2/Sayem/
├── src/
│   ├── lexer.h/.cpp      ← শাব্দিক বিশ্লেষক (জগন্নাথ)
│   ├── token.h           ← টোকেনের সংজ্ঞা
│   ├── ast.h             ← AST নোড (WhileNode সহ)
│   ├── parser.h/.cpp     ← সিনট্যাক্স বিশ্লেষক ★ (সায়েম)
│   ├── semantic.h/.cpp   ← অর্থ বিশ্লেষক (এলেন)
│   ├── codegen.h/.cpp    ← কোড তৈরিকারক (সামি)
│   ├── error.h           ← ত্রুটি ব্যবস্থাপনা
│   ├── bangla_utils.h    ← বাংলা সংখ্যা রূপান্তর
│   ├── win_console.h/.cpp← CMD বাংলা ফন্ট
│   └── main.cpp          ← মূল প্রোগ্রাম
├── build/
│   └── banglasyntax.exe
├── examples/
└── README.md
```

---

*বাংলা সিনট্যাক্স কম্পাইলার — CSE-4114 Sessional Project | Leading University, Sylhet*