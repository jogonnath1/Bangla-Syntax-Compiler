// =============================================================
//  Bangla Syntax Compiler — token.h
//  Token type definitions and Token structure
//  CSE-4114 Compiler Design and Construction Sessional
// =============================================================
#pragma once
#include "bangla_utils.h"
#include <string>

// ------------------------------------------------------------------
// All token types recognized by the Bangla Syntax Compiler lexer
// ------------------------------------------------------------------
enum class TokenType {
    // ── Keywords ────────────────────────────────────────────────
    DHORO,       // dhoro    → variable declaration
    SANKHYA,     // sankhya  → integer type
    DOSHOMIK,    // doshomik → float type
    JODI,        // jodi     → if
    NAHOLE,      // nahole   → else
    JOTOKHON,    // jotokhon → while
    DEKHAO,      // dekhao   → print
    SHURU,       // shuru    → begin block  {
    SHESH,       // shesh    → end block    }

    // ── Literals ────────────────────────────────────────────────
    INTEGER_LIT,  // e.g.  42
    FLOAT_LIT,    // e.g.  3.14
    STRING_LIT,   // e.g.  "hello"

    // ── Identifier ──────────────────────────────────────────────
    IDENTIFIER,   // user-defined variable names

    // ── Arithmetic Operators ────────────────────────────────────
    PLUS,         // +
    MINUS,        // -
    STAR,         // *
    SLASH,        // /

    // ── Comparison / Relational Operators ───────────────────────
    ASSIGN,       // =
    EQ,           // ==
    NEQ,          // !=
    LT,           // <
    GT,           // >
    LEQ,          // <=
    GEQ,          // >=

    // ── Punctuation ─────────────────────────────────────────────
    LPAREN,       // (
    RPAREN,       // )
    SEMICOLON,    // ;

    // ── Special ─────────────────────────────────────────────────
    EOF_TOKEN,    // end of file
    UNKNOWN       // unrecognized character (triggers lexical error)
};

// ------------------------------------------------------------------
// Convert TokenType to human-readable string (for debugging/errors)
// ------------------------------------------------------------------
inline std::string tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::DHORO:       return "ধরি";
        case TokenType::SANKHYA:     return "সংখ্যা";
        case TokenType::DOSHOMIK:    return "দশমিক";
        case TokenType::JODI:        return "যদি";
        case TokenType::NAHOLE:      return "নাহলে";
        case TokenType::JOTOKHON:    return "যতক্ষণ";
        case TokenType::DEKHAO:      return "দেখাও";
        case TokenType::SHURU:       return "শুরু";
        case TokenType::SHESH:       return "শেষ";
        case TokenType::INTEGER_LIT: return "পূর্ণসংখ্যা";
        case TokenType::FLOAT_LIT:   return "দশমিকসংখ্যা";
        case TokenType::STRING_LIT:  return "বর্ণমালা";
        case TokenType::IDENTIFIER:  return "চলক";
        case TokenType::PLUS:        return "যোগ";
        case TokenType::MINUS:       return "বিয়োগ";
        case TokenType::STAR:        return "গুণ";
        case TokenType::SLASH:       return "ভাগ";
        case TokenType::ASSIGN:      return "নির্ধারণ";
        case TokenType::EQ:          return "সমান";
        case TokenType::NEQ:         return "অসমান";
        case TokenType::LT:          return "ছোট";
        case TokenType::GT:          return "বড়";
        case TokenType::LEQ:         return "ছোটবাসমান";
        case TokenType::GEQ:         return "বড়বাসমান";
        case TokenType::LPAREN:      return "বামবন্ধনী";
        case TokenType::RPAREN:      return "ডানবন্ধনী";
        case TokenType::SEMICOLON:   return "সেমিকোলন";
        case TokenType::EOF_TOKEN:   return "ফাইলশেষ";
        case TokenType::UNKNOWN:     return "অজানা";
        default:                     return "???";
    }
}

// ------------------------------------------------------------------
// Token — one unit of source text produced by the lexer
// ------------------------------------------------------------------
struct Token {
    TokenType   type;   // what kind of token this is
    std::string value;  // the raw source text
    int         line;   // 1-based source line number
    int         col;    // 1-based column number

    Token(TokenType t, std::string v, int l, int c)
        : type(t), value(std::move(v)), line(l), col(c) {}

    // Convenience: is this token a specific keyword/operator?
    bool is(TokenType t)        const { return type == t; }
    bool isNot(TokenType t)     const { return type != t; }
    bool isEOF()                const { return type == TokenType::EOF_TOKEN; }
    bool isLiteral()            const {
        return type == TokenType::INTEGER_LIT
            || type == TokenType::FLOAT_LIT;
    }
    bool isType()               const {
        return type == TokenType::SANKHYA
            || type == TokenType::DOSHOMIK;
    }
    bool isRelOp()              const {
        return type == TokenType::EQ   || type == TokenType::NEQ
            || type == TokenType::LT   || type == TokenType::GT
            || type == TokenType::LEQ  || type == TokenType::GEQ;
    }

    std::string toString() const {
        return "[" + tokenTypeToString(type) + " '" + value
             + "' লাইন:" + বাংলাসংখ্যা(line)
             + " কলাম:" + বাংলাসংখ্যা(col) + "]";
    }
};
