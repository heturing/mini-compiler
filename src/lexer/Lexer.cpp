#include <iostream>
#include "lexer/lexer.h"

const std::string to_string(TokenKind kind){
    switch(kind){
        case TokenKind::Eof:
            return "EOF";
        case TokenKind::Identifier:
            return "IDENTIFIER";
        case TokenKind::Integer:
            return "INTEGER";
        case TokenKind::KWLet:
            return "KWLET";
        case TokenKind::KWPrint:
            return "KWPRINT";
        case TokenKind::Plus:
            return "PLUS";
        case TokenKind::Minus:
            return "MINUS";
        case TokenKind::Star:
            return "STAR";
        case TokenKind::Slash:
            return "SLASH";
        case TokenKind::Equal:
            return "EQUAL";
        case TokenKind::Semicolon:
            return "SEMICOLON";
        case TokenKind::LParan:
            return "LPARAN";
        case TokenKind::RParan:
            return "RPARAN";
        case TokenKind::Error:
            return "ERROR";
        default:
            return "ERROR";
    }
}

Lexer::Lexer(const std::string &prog) : prog_(prog), pos_(0), line_(0), col_(0){
    keywords.insert("let");
    keywords.insert("print");
}

void Lexer::advance(){
    ++pos_;

    // Since our toy language does not allow string. We can advance the line count when we see a \n.
    if(peek() == '\n'){
        advance();
        ++line_;
        col_ = 0;
    }
    else{
        ++col_;
    }
}

void Lexer::skipWhiteSpaces(){
    while(isWhiteSpace(peek())){
        advance();
    }
}

Token Lexer::lexAnIdentifier(){
    std::string lexeme;
    size_t startLine = line_;
    size_t startCol = col_;
    while(std::isalnum(peek())){
        lexeme += peek();
        advance();
    }

    if(isKeyword(lexeme)){
        if(lexeme == "let"){
            return Token(TokenKind::KWLet, lexeme, startLine, startCol);
        }
        else if(lexeme == "print"){
            return Token(TokenKind::KWPrint, lexeme, startLine, startCol);
        }
        else{
            std::cerr << "Unsupported keyword " << lexeme << "\n";
            std::terminate();
        }
    }
    else{
        return Token(TokenKind::Identifier, lexeme, startLine, startCol);
    }
}

Token Lexer::lexAnInteger(){
    // For now, we do not allow negative number.

    int number = 0;
    size_t startLine = line_;
    size_t startCol = col_;
    while(std::isdigit(peek())){
        number = number*10 + peek() - '0';
        advance();
    }

    return Token(TokenKind::Integer, std::to_string(number), startLine, startCol);

}

Token Lexer::next(){
    skipWhiteSpaces();

    if(isEof()){
        return Token(TokenKind::Eof, "", line_, col_);
    }

    char c = peek();

    if(isIdentifierStart(c)){
        return lexAnIdentifier();
    }

    if(isDigitStart(c)){
        return lexAnInteger();
    }

    int startLine = line_;
    int startCol = col_;
    switch(c){
        case '+':
            advance();
            return Token(TokenKind::Plus, "+", startLine, startCol);
        case '-':
            advance();
            return Token(TokenKind::Minus, "-", startLine, startCol);
        case '*':
            advance();
            return Token(TokenKind::Star, "*", startLine, startCol);
        case '/':
            advance();
            return Token(TokenKind::Slash, "/", startLine, startCol);
        case '(':
            advance();
            return Token(TokenKind::LParan, "(", startLine, startCol);
        case ')':
            advance();
            return Token(TokenKind::RParan, ")", startLine, startCol);
        case '=':
            advance();
            return Token(TokenKind::Equal, "=", startLine, startCol);
        case ';':
            advance();
            return Token(TokenKind::Semicolon, ";", startLine, startCol);
        default:
            std::cerr << "Unsupported lexeme " << c << "\n";
            std::terminate();
    }
}

std::ostream& operator<<(std::ostream &os, const Token &t){
    os << "Token(" << to_string(t.kind) << ", " << t.lexeme << ", " << t.line << ", " << t.col << ")";
    return os;
}