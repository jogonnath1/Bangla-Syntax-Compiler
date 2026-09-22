// =============================================================
//  বাংলা সিনট্যাক্স কম্পাইলার — lexer.cpp
//  শাব্দিক বিশ্লেষক — সম্পূর্ণ বাস্তবায়ন
//  CSE-4114 কম্পাইলার ডিজাইন সেশনাল
// =============================================================
#include "lexer.h"
#include <cctype>
#include <stdexcept>

// ------------------------------------------------------------------
// কীওয়ার্ড সারণী — উৎস শব্দ → টোকেনটাইপ
// ------------------------------------------------------------------
const std::unordered_map<std::string, TokenType> Lexer::KEYWORDS = {
    {"ধরি",    TokenType::DHORO},
    {"সংখ্যা",  TokenType::SANKHYA},
    {"দশমিক", TokenType::DOSHOMIK},
    {"যদি",     TokenType::JODI},
    {"নাহলে",   TokenType::NAHOLE},
    {"যতক্ষণ", TokenType::JOTOKHON},
    {"দেখাও",   TokenType::DEKHAO},
    {"শুরু",    TokenType::SHURU},
    {"শেষ",    TokenType::SHESH},
};

// ------------------------------------------------------------------
// UTF-8 সহায়ক ফাংশন
// ------------------------------------------------------------------
static bool isAlphaOrUTF8(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return std::isalpha(uc) || uc >= 128;
}

static bool isAlnumOrUTF8(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return std::isalnum(uc) || uc >= 128;
}

// ------------------------------------------------------------------
// বাংলা অঙ্ক সহায়ক ফাংশন
// বাংলা অঙ্ক ০-৯ = U+09E6–U+09EF = UTF-8: E0 A7 A6 – E0 A7 AF
// ------------------------------------------------------------------
static bool isBengaliDigitAt(const std::string& s, int p) {
    if (p + 2 >= (int)s.size()) return false;
    unsigned char b0 = (unsigned char)s[p];
    unsigned char b1 = (unsigned char)s[p + 1];
    unsigned char b2 = (unsigned char)s[p + 2];
    return b0 == 0xE0 && b1 == 0xA7 && b2 >= 0xA6 && b2 <= 0xAF;
}

static char bengaliDigitToAscii(const std::string& s, int p) {
    return '0' + ((unsigned char)s[p + 2] - 0xA6);
}

// ------------------------------------------------------------------
// কনস্ট্রাক্টর
// ------------------------------------------------------------------
Lexer::Lexer(const std::string& source, ErrorHandler& errHandler)
    : src(source), err(errHandler), pos(0), line(1), col(1) {}

// ------------------------------------------------------------------
// tokenize() — সম্পূর্ণ উৎস স্ক্যান করে সব টোকেন ফেরত দেয়
// ------------------------------------------------------------------
std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!isAtEnd()) {
        skipWhitespaceAndComments();
        if (isAtEnd()) break;
        tokens.push_back(nextToken());
    }
    tokens.emplace_back(TokenType::EOF_TOKEN, "", line, col);
    return tokens;
}

// ------------------------------------------------------------------
// সহায়ক ফাংশনসমূহ
// ------------------------------------------------------------------
char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return src[pos];
}

char Lexer::peekNext() const {
    if (pos + 1 >= (int)src.size()) return '\0';
    return src[pos + 1];
}

char Lexer::advance() {
    char c = src[pos++];
    if (c == '\n') { line++; col = 1; }
    else            { col++; }
    return c;
}

bool Lexer::isAtEnd() const {
    return pos >= (int)src.size();
}

bool Lexer::match(char expected) {
    if (isAtEnd() || src[pos] != expected) return false;
    advance();
    return true;
}

// ------------------------------------------------------------------
// skipWhitespaceAndComments — ফাঁকা স্থান ও মন্তব্য বাদ দেয়
// ------------------------------------------------------------------
void Lexer::skipWhitespaceAndComments() {
    while (!isAtEnd()) {
        char c = peek();
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            advance();
        } else if (c == '/' && peekNext() == '/') {
            // এক-লাইন মন্তব্য: লাইন শেষ পর্যন্ত বাদ দাও
            while (!isAtEnd() && peek() != '\n') advance();
        } else {
            break;
        }
    }
}

// ------------------------------------------------------------------
// nextToken — বর্তমান অবস্থান থেকে একটি টোকেন স্ক্যান করে ফেরত দেয়
// ------------------------------------------------------------------
Token Lexer::nextToken() {
    int startLine = line;
    int startCol  = col;
    char c = advance();

    // ── এক-অক্ষর টোকেন ───────────────────────────────────────────
    switch (c) {
        case '+': return {TokenType::PLUS,      "+", startLine, startCol};
        case '-': return {TokenType::MINUS,     "-", startLine, startCol};
        case '*': return {TokenType::STAR,      "*", startLine, startCol};
        case '/': return {TokenType::SLASH,     "/", startLine, startCol};
        case '(': return {TokenType::LPAREN,    "(", startLine, startCol};
        case ')': return {TokenType::RPAREN,    ")", startLine, startCol};
        case ';': return {TokenType::SEMICOLON, ";", startLine, startCol};

        // ── এক-বা-দুই অক্ষর টোকেন ───────────────────────────────
        case '=':
            if (match('=')) return {TokenType::EQ,     "==", startLine, startCol};
            return             {TokenType::ASSIGN,     "=",  startLine, startCol};
        case '!':
            if (match('=')) return {TokenType::NEQ,    "!=", startLine, startCol};
            err.lexicalError(startLine, startCol, "অপ্রত্যাশিত '!'; আপনি হয়তো '!=' বোঝাতে চাইছেন?");
            return {TokenType::UNKNOWN, "!", startLine, startCol};
        case '<':
            if (match('=')) return {TokenType::LEQ,    "<=", startLine, startCol};
            return             {TokenType::LT,         "<",  startLine, startCol};
        case '>':
            if (match('=')) return {TokenType::GEQ,    ">=", startLine, startCol};
            return             {TokenType::GT,         ">",  startLine, startCol};

        default: break;
    }

    // ── ASCII অঙ্ক ────────────────────────────────────────────────
    if (std::isdigit(c)) {
        pos--;
        if (c == '\n') { line--; col = startCol; }
        else            { col = startCol; }
        return scanNumber();
    }

    // ── বাংলা অঙ্ক (UTF-8: E0 A7 A6–AF) ─────────────────────────
    // c ইতিমধ্যে consume হয়েছে, তাই pos এখন দ্বিতীয় বাইটে
    {
        unsigned char uc = (unsigned char)c;
        if (uc == 0xE0 && pos + 1 < (int)src.size() &&
            (unsigned char)src[pos] == 0xA7 &&
            (unsigned char)src[pos + 1] >= 0xA6 &&
            (unsigned char)src[pos + 1] <= 0xAF) {
            // প্রথম বাইটটি ফিরিয়ে দাও
            pos--; col = startCol;
            return scanBengaliNumber();
        }
    }

    // ── স্ট্রিং লিটারেল ──────────────────────────────────────────
    if (c == '"') {
        pos--; col = startCol;
        return scanString();
    }

    // ── শনাক্তকারী / কীওয়ার্ড ────────────────────────────────────
    if (isAlphaOrUTF8(c) || c == '_') {
        pos--;
        col = startCol;
        return scanIdentifierOrKeyword();
    }

    // ── অজানা অক্ষর ───────────────────────────────────────────────
    std::string msg = "অজানা অক্ষর '";
    msg += c;
    msg += "'";
    err.lexicalError(startLine, startCol, msg);
    return {TokenType::UNKNOWN, std::string(1, c), startLine, startCol};
}

// ------------------------------------------------------------------
// scanNumber — ASCII অঙ্ক দিয়ে সংখ্যা স্ক্যান করে
// ------------------------------------------------------------------
Token Lexer::scanNumber() {
    int startLine = line;
    int startCol  = col;
    std::string num;
    bool isFloat = false;

    while (!isAtEnd() && std::isdigit(peek())) {
        num += advance();
    }

    // দশমিক বিন্দু পরীক্ষা
    if (!isAtEnd() && peek() == '.' && std::isdigit(peekNext())) {
        isFloat = true;
        num += advance(); // '.' consume করো
        while (!isAtEnd() && std::isdigit(peek())) {
            num += advance();
        }
    }

    if (isFloat)
        return {TokenType::FLOAT_LIT, num, startLine, startCol};
    else
        return {TokenType::INTEGER_LIT, num, startLine, startCol};
}

// ------------------------------------------------------------------
// scanBengaliNumber — বাংলা অঙ্ক দিয়ে সংখ্যা স্ক্যান করে
// বাংলা অঙ্ককে ASCII-তে রূপান্তরিত করে সংরক্ষণ করে
// ------------------------------------------------------------------
Token Lexer::scanBengaliNumber() {
    int startLine = line;
    int startCol  = col;
    std::string num;
    bool isFloat = false;

    // বাংলা অঙ্ক পড়ো (প্রতিটি ৩ বাইট)
    while (!isAtEnd() && isBengaliDigitAt(src, pos)) {
        num += bengaliDigitToAscii(src, pos);
        advance(); advance(); advance(); // ৩ বাইট consume করো
    }

    // দশমিক বিন্দু পরীক্ষা (বাংলা বা ASCII অঙ্ক পরে)
    if (!isAtEnd() && peek() == '.') {
        bool nextIsBengali = isBengaliDigitAt(src, pos + 1);
        bool nextIsAscii   = (pos + 1 < (int)src.size()) && std::isdigit(src[pos + 1]);
        if (nextIsBengali || nextIsAscii) {
            isFloat = true;
            num += advance(); // '.' consume করো
            while (!isAtEnd() && (isBengaliDigitAt(src, pos) || std::isdigit(peek()))) {
                if (isBengaliDigitAt(src, pos)) {
                    num += bengaliDigitToAscii(src, pos);
                    advance(); advance(); advance();
                } else {
                    num += advance();
                }
            }
        }
    }

    if (isFloat)
        return {TokenType::FLOAT_LIT, num, startLine, startCol};
    else
        return {TokenType::INTEGER_LIT, num, startLine, startCol};
}

// ------------------------------------------------------------------
// scanIdentifierOrKeyword — শব্দ স্ক্যান করে শ্রেণীবদ্ধ করে
// ------------------------------------------------------------------
Token Lexer::scanIdentifierOrKeyword() {
    int startLine = line;
    int startCol  = col;
    std::string word;

    while (!isAtEnd() && (isAlnumOrUTF8(peek()) || peek() == '_')) {
        word += advance();
    }

    // কীওয়ার্ড সারণীতে খোঁজো
    auto it = KEYWORDS.find(word);
    if (it != KEYWORDS.end()) {
        return {it->second, word, startLine, startCol};
    }
    return {TokenType::IDENTIFIER, word, startLine, startCol};
}

// ------------------------------------------------------------------
// scanString — ডবল-কোটেড স্ট্রিং লিটারেল স্ক্যান করে
// ------------------------------------------------------------------
Token Lexer::scanString() {
    int startLine = line;
    int startCol  = col;
    advance(); // শুরুর '"' consume করো
    std::string str;
    while (!isAtEnd() && peek() != '"') {
        if (peek() == '\n') {
            err.lexicalError(startLine, startCol,
                "স্ট্রিং শেষ হয়নি: শেষ উদ্ধৃতি চিহ্ন নেই");
            return {TokenType::UNKNOWN, str, startLine, startCol};
        }
        str += advance();
    }
    if (isAtEnd()) {
        err.lexicalError(startLine, startCol,
            "স্ট্রিং শেষ হয়নি: শেষ উদ্ধৃতি চিহ্ন নেই");
        return {TokenType::UNKNOWN, str, startLine, startCol};
    }
    advance(); // শেষের '"' consume করো
    return {TokenType::STRING_LIT, str, startLine, startCol};
}
