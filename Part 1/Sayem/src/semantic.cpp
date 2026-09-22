#include "semantic.h"
#include <stdexcept>

SemanticAnalyzer::SemanticAnalyzer(ErrorHandler& e):err(e){}
const std::unordered_map<std::string,Symbol>& SemanticAnalyzer::getSymbolTable() const{return symbolTable;}

void SemanticAnalyzer::analyze(ProgramNode* p){
    for(auto& s:p->statements) analyzeStatement(s.get());
}
void SemanticAnalyzer::analyzeStatement(ASTNode* node){
    if(!node) return;
    if(auto* d=dynamic_cast<DeclarationNode*>(node)){analyzeDeclaration(d);return;}
    if(auto* a=dynamic_cast<AssignmentNode*>(node)){analyzeAssignment(a);return;}
    if(auto* i=dynamic_cast<IfNode*>(node)){analyzeIf(i);return;}
    if(auto* w=dynamic_cast<WhileNode*>(node)){analyzeWhile(w);return;}
    if(auto* p=dynamic_cast<PrintNode*>(node)){analyzePrint(p);return;}
    if(auto* b=dynamic_cast<BlockNode*>(node)){analyzeBlock(b);return;}
    err.semanticError(node->line,node->col,"অজানা AST নোড: "+node->nodeType());
}
void SemanticAnalyzer::analyzeBlock(BlockNode* n){
    for(auto& s:n->statements) analyzeStatement(s.get());
}
void SemanticAnalyzer::analyzeDeclaration(DeclarationNode* node){
    if(isDeclared(node->name)){err.semanticError(node->line,node->col,"চলক '"+node->name+"' আগেই ঘোষণা করা হয়েছে।"); return;}
    DataType t=DataType::UNKNOWN;
    if(node->initializer) t=analyzeExpr(node->initializer.get());
    if(node->type==DataType::SANKHYA && t==DataType::DOSHOMIK){
        err.semanticError(node->line,node->col,"ধরন অসংগত: 'দশমিক' মান 'সংখ্যা' চলক '"+node->name+"'-এ দেওয়া যাবে না।"); return;}
    declare(node->name,node->type,node->line,node->col);
}
void SemanticAnalyzer::analyzeAssignment(AssignmentNode* node){
    if(!isDeclared(node->name)){err.semanticError(node->line,node->col,"অস্বীকৃত চলক '"+node->name+"'"); return;}
    DataType vt=lookupType(node->name), et=analyzeExpr(node->value.get());
    if(vt==DataType::SANKHYA && et==DataType::DOSHOMIK)
        err.semanticError(node->line,node->col,"ধরন অসংগত: 'দশমিক' মান '"+node->name+"' চলকে দেওয়া যাবে না।");
}
void SemanticAnalyzer::analyzeIf(IfNode* n){
    analyzeExpr(n->condition.get());
    if(auto* b=dynamic_cast<BlockNode*>(n->thenBlock.get())) analyzeBlock(b);
    if(n->elseBlock) if(auto* b=dynamic_cast<BlockNode*>(n->elseBlock.get())) analyzeBlock(b);
}
void SemanticAnalyzer::analyzeWhile(WhileNode* n){
    analyzeExpr(n->condition.get());
    if(auto* b=dynamic_cast<BlockNode*>(n->body.get())) analyzeBlock(b);
}
void SemanticAnalyzer::analyzePrint(PrintNode* n){analyzeExpr(n->expr.get());}
DataType SemanticAnalyzer::analyzeExpr(ASTNode* node){
    if(!node) return DataType::UNKNOWN;
    if(dynamic_cast<IntLiteralNode*>(node))    return DataType::SANKHYA;
    if(dynamic_cast<FloatLiteralNode*>(node))  return DataType::DOSHOMIK;
    if(dynamic_cast<StringLiteralNode*>(node)) return DataType::BORNA;
    if(auto* n=dynamic_cast<IdentifierNode*>(node))  return analyzeIdentifier(n);
    if(auto* n=dynamic_cast<BinaryOpNode*>(node))    return analyzeBinaryOp(n);
    if(auto* n=dynamic_cast<UnaryMinusNode*>(node))  return analyzeUnaryMinus(n);
    err.semanticError(node->line,node->col,"অজানা ভাবপ্রকাশ: "+node->nodeType());
    return DataType::UNKNOWN;
}
DataType SemanticAnalyzer::analyzeIdentifier(IdentifierNode* n){
    if(!isDeclared(n->name)){err.semanticError(n->line,n->col,"অস্বীকৃত চলক '"+n->name+"'"); return DataType::UNKNOWN;}
    DataType t=lookupType(n->name); n->resolvedType=t; return t;
}
DataType SemanticAnalyzer::analyzeBinaryOp(BinaryOpNode* n){
    DataType l=analyzeExpr(n->left.get()), r=analyzeExpr(n->right.get());
    DataType res=(l==DataType::DOSHOMIK||r==DataType::DOSHOMIK)?DataType::DOSHOMIK:DataType::SANKHYA;
    if(n->op==TokenType::SLASH) res=DataType::DOSHOMIK;
    bool rel=(n->op==TokenType::EQ||n->op==TokenType::NEQ||n->op==TokenType::LT||
              n->op==TokenType::GT||n->op==TokenType::LEQ||n->op==TokenType::GEQ);
    if(rel) res=DataType::SANKHYA;
    n->resolvedType=res; return res;
}
DataType SemanticAnalyzer::analyzeUnaryMinus(UnaryMinusNode* n){
    DataType t=analyzeExpr(n->operand.get()); n->resolvedType=t; return t;
}
bool SemanticAnalyzer::isDeclared(const std::string& name) const{return symbolTable.find(name)!=symbolTable.end();}
void SemanticAnalyzer::declare(const std::string& n,DataType t,int l,int c){symbolTable[n]={n,t,l,c};}
DataType SemanticAnalyzer::lookupType(const std::string& n) const{
    auto it=symbolTable.find(n); return (it!=symbolTable.end())?it->second.type:DataType::UNKNOWN;}
