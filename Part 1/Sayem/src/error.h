#pragma once
#include "bangla_utils.h"
#include <string>
#include <vector>
#include <iostream>

enum class ErrorSeverity { LEXICAL, SYNTAX, SEMANTIC };

struct CompilerError {
    ErrorSeverity severity;
    std::string   message;
    int line, col;
    CompilerError(ErrorSeverity s,std::string m,int l,int c)
        :severity(s),message(std::move(m)),line(l),col(c){}
    std::string toString() const {
        std::string tag;
        switch(severity){
            case ErrorSeverity::LEXICAL:  tag="[শাব্দিক ত্রুটি]";  break;
            case ErrorSeverity::SYNTAX:   tag="[সিনট্যাক্স ত্রুটি]"; break;
            case ErrorSeverity::SEMANTIC: tag="[অর্থগত ত্রুটি]";  break;
        }
        return tag+" লাইন "+বাংলাসংখ্যা(line)+", কলাম "+বাংলাসংখ্যা(col)+": "+message;
    }
};

class ErrorHandler {
public:
    std::vector<CompilerError> errors;
    bool hadError=false;
    void lexicalError(int l,int c,const std::string& m){
        errors.emplace_back(ErrorSeverity::LEXICAL,m,l,c); hadError=true;}
    void syntaxError(int l,int c,const std::string& m){
        errors.emplace_back(ErrorSeverity::SYNTAX,m,l,c); hadError=true;}
    void semanticError(int l,int c,const std::string& m){
        errors.emplace_back(ErrorSeverity::SEMANTIC,m,l,c); hadError=true;}
    void printAll() const {
        if(errors.empty()){std::cout<<"BSC: কোনো ত্রুটি নেই।\n"; return;}
        std::cerr<<"\n====== বাংলা সিনট্যাক্স কম্পাইলার ত্রুটিসমূহ ======\n";
        for(const auto& e:errors) std::cerr<<e.toString()<<"\n";
        std::cerr<<"==========================================\n";
        std::cerr<<"মোট ত্রুটি: "<<বাংলাসংখ্যা(errors.size())<<"\n\n";
    }
    bool hasErrors() const {return hadError;}
    void clear(){errors.clear(); hadError=false;}
};
