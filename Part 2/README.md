# বাংলা সিনট্যাক্স কম্পাইলার — পর্ব ২

> **Part 2 — যতক্ষণ (While Loop) সমর্থন সহ**
> CSE-4114 — Compiler Design and Construction Sessional
> শিক্ষক: Alian Ahmed Ferdous, Adjunct Lecturer

---

## পর্ব ২ এর নতুন বৈশিষ্ট্য

| বৈশিষ্ট্য | কীওয়ার্ড | উদাহরণ |
|-----------|----------|---------|
| যতক্ষণ লুপ | `যতক্ষণ` | `যতক্ষণ (গণক <= সীমা) শুরু ... শেষ` |
| যোগফল লুপ | `যতক্ষণ` | ১ থেকে ১০ পর্যন্ত যোগ → `৫৫` |
| ফ্যাক্টরিয়াল | `যতক্ষণ` | ৫! → `১২০` |
| ফিবোনাচি | `যতক্ষণ` | `০, ১, ১, ২, ৩, ৫, ...` |
| উল্টো গণনা | `যতক্ষণ` | `৫, ৪, ৩, ২, ১` |

---

## দলের সদস্য ও তাদের ফোল্ডার

| সদস্য | ফোল্ডার | দায়িত্ব | ধাপ |
|-------|---------|---------|------|
| জগন্নাথ | `Jogonnath/` | Extended Lexer — যতক্ষণ টোকেন | ধাপ ১ |
| সায়েম | `Sayem/` | Extended Parser — while_stmt পার্সিং | ধাপ ২ |
| এলেন | `Ellen/` | Extended Semantic — লুপ স্কোপ চেক | ধাপ ৩ |
| সামি | `Sami/` | Extended CodeGen — Python while লুপ | ধাপ ৪ |

---

## উদাহরণ প্রোগ্রাম

### যোগফল লুপ
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
cd Jogonnath
build\banglasyntax.exe examples\sum_loop.bsc
python examples\sum_loop.py
```

## উদাহরণ ফাইলসমূহ (পর্ব ২)

| ফাইল | বিবরণ |
|------|-------|
| `hello.bsc` | সহজ প্রিন্ট |
| `math_test.bsc` | গণিতের হিসাব |
| `age_check.bsc` | যদি-নাহলে শর্ত |
| `circle_area.bsc` | বৃত্তের ক্ষেত্রফল |
| `swap.bsc` | মান পরিবর্তন |
| `sum_loop.bsc` | ★ যোগফল লুপ |
| `factorial_test.bsc` | ★ ফ্যাক্টরিয়াল |
| `fibonacci_test.bsc` | ★ ফিবোনাচি ধারা |
| `countdown.bsc` | ★ উল্টো গণনা |
| `type_error.bsc` | ধরন ভুল |
| `undeclared_error.bsc` | অঘোষিত চলক |

---

## ফাইল কাঠামো

```
Part 2/
├── Jogonnath/    ← Extended Lexer (যতক্ষণ সমর্থন)
├── Sayem/        ← Extended Parser (while_stmt পার্সিং)
├── Ellen/        ← Extended Semantic Analyzer (লুপ স্কোপ)
└── Sami/         ← Extended Code Generator (Python while)
```

---

*বাংলা সিনট্যাক্স কম্পাইলার — CSE-4114 Sessional Project | Leading University, Sylhet*