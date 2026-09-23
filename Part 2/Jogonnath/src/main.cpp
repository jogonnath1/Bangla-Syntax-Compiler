// =====================================================
//  বাংলা সিনট্যাক্স কম্পাইলার - জগন্নাথ (Lexer)
//  পর্ব ২ - যতক্ষণ লুপ
//  CSE-4114 Compiler Design and Construction Sessional
//  Leading University, Sylhet
// =====================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "win_console.h"

#include "bangla_utils.h"
#include "token.h"
#include "error.h"
#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include "codegen.h"

static std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "BSC: ফাইল খোলা যায়নি: " << path << "\n";
        std::exit(1);
    }
    std::ostringstream ss; ss << file.rdbuf(); return ss.str();
}
static void writeFile(const std::string& path, const std::string& c) {
    std::ofstream f(path);
    if (!f.is_open()) { std::cerr << "BSC: ফাইলে লেখা যায়নি: " << path << "\n"; std::exit(1); }
    f << c;
}
static std::string deriveOutput(const std::string& in) {
    size_t s=in.find_last_of("/\\"), d;
    std::string dir=(s==std::string::npos)?"":in.substr(0,s+1);
    std::string base=(s==std::string::npos)?in:in.substr(s+1);
    d=base.find_last_of('.');
    return dir+((d==std::string::npos)?base:base.substr(0,d))+".py";
}

int main(int argc, char* argv[]) {
    // UTF-8 এবং বাংলা ফন্ট সেট করো
    system("chcp 65001 > nul 2>&1");
    setBengaliFont();

    std::cout << "\n";
    std::cout << "  ====================================================\n";
    std::cout << "   বাংলা সিনট্যাক্স কম্পাইলার  --  পর্ব ২ (যতক্ষণ লুপ)\n";
    std::cout << "   CSE-4114 | কম্পাইলার ডিজাইন সেশনাল\n";
    std::cout << "  ====================================================\n";
    std::cout << "   দলের সদস্য: জগন্নাথ (Jogonnath)\n";
    std::cout << "   দায়িত্ব  : ধাপ ১ -- শাব্দিক বিশ্লেষক (Lexer)\n";
    std::cout << "  ====================================================\n\n";

    if (argc < 2) {
        std::cout << "ব্যবহার: " << argv[0] << " source.bsc [--tokens]\n";
        return 1;
    }
    std::string inputPath = argv[1];
    bool dumpTokens = (argc >= 3 && std::string(argv[2]) == "--tokens");
    ErrorHandler err;

    // ── ধাপ ১: শাব্দিক বিশ্লেষণ ─────────────────────────────────
    std::cout << "--------------------------------------------------\n";
    std::cout << "[ধাপ ১] শাব্দিক বিশ্লেষণ (Lexical Analysis) *** তোমার অংশ ***\n";
    std::cout << "        দায়িত্ব: জগন্নাথ (Lexer)\n";
    std::cout << "--------------------------------------------------\n";
    std::string source = readFile(inputPath);
    Lexer lexer(source, err);
    auto tokens = lexer.tokenize();
    if (dumpTokens) {
        std::cout << "\n--- টোকেন স্ট্রিম ---\n";
        for (const auto& t : tokens) std::cout << "  " << t.toString() << "\n";
        std::cout << "--------------------\n\n";
    }
    if (err.hasErrors()) { err.printAll(); std::cerr << "BSC: শাব্দিক ভুল।\n"; return 1; }
    std::cout << "  -> " << বাংলাসংখ্যা(tokens.size()) << " টি টোকেন পাওয়া গেছে।\n\n";

    // ── ধাপ ২: পার্সিং ───────────────────────────────────────────
    std::cout << "--------------------------------------------------\n";
    std::cout << "[ধাপ ২] সিনট্যাক্স বিশ্লেষণ (Parsing)\n";
    std::cout << "        দায়িত্ব: সায়েম (Parser)\n";
    std::cout << "--------------------------------------------------\n";
    Parser parser(std::move(tokens), err);
    auto program = parser.parse();
    if (err.hasErrors()) { err.printAll(); std::cerr << "BSC: সিনট্যাক্স ভুল।\n"; return 1; }
    std::cout << "  -> " << বাংলাসংখ্যা(program->statements.size()) << " টি স্টেটমেন্ট সহ AST তৈরি।\n\n";

    // ── ধাপ ৩: অর্থ বিশ্লেষণ ────────────────────────────────────
    std::cout << "--------------------------------------------------\n";
    std::cout << "[ধাপ ৩] অর্থ বিশ্লেষণ (Semantic Analysis)\n";
    std::cout << "        দায়িত্ব: এলেন (Semantic Analyzer)\n";
    std::cout << "--------------------------------------------------\n";
    SemanticAnalyzer semantic(err);
    semantic.analyze(program.get());
    if (err.hasErrors()) { err.printAll(); std::cerr << "BSC: অর্থগত ভুল।\n"; return 1; }
    std::cout << "  -> টাইপ চেকিং সফল। " << বাংলাসংখ্যা(semantic.getSymbolTable().size()) << " টি চলক।\n\n";

    // ── ধাপ ৪: কোড তৈরি ─────────────────────────────────────────
    std::cout << "--------------------------------------------------\n";
    std::cout << "[ধাপ ৪] Python কোড তৈরি (Code Generation)\n";
    std::cout << "        দায়িত্ব: সামি (Code Generator)\n";
    std::cout << "--------------------------------------------------\n";
    CodeGenerator codegen(err);
    std::string pyCode = codegen.generate(program.get());
    if (err.hasErrors()) { err.printAll(); std::cerr << "BSC: কোড তৈরিতে ভুল।\n"; return 1; }
    std::string out = deriveOutput(inputPath);
    writeFile(out, pyCode);
    std::cout << "  -> Python আউটপুট: " << out << "\n\n";

    std::cout << "==================================================\n";
    std::cout << " কম্পাইলেশন সফল! (জগন্নাথর অংশ সম্পন্ন)\n";
    std::cout << " প্রোগ্রাম চালান: python " << out << "\n";
    std::cout << "==================================================\n\n";
    return 0;
}
