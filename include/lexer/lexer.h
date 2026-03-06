#ifndef MINI_COMPILER_LEXER
#define MINI_COMPILER_LEXER

#include <string>
#include <cctype>
#include <unordered_set>



enum class TokenKind{
    Eof,
    Identifier,
    Integer,
    KWLet,
    KWPrint,
    Plus,
    Minus,
    Star,
    Slash,
    Equal,
    Semicolon,
    LParan,
    RParan,
    Error
};

const std::string to_string(TokenKind kind);

struct Token{
    TokenKind kind;
    std::string lexeme;
    int line;
    int col;

    Token(TokenKind kind, const std::string &lexeme, int line, int col) : 
        kind(kind), lexeme(lexeme), line(line), col(col) {}

    explicit operator bool() const{
        return kind != TokenKind::Eof; 
    }
};

class Lexer{

    public:
        Lexer(const std::string &prog);
        Token next();

    private:
        void skipWhiteSpaces();
        bool isWhiteSpace(const char &c){
            if(c == ' ' || c == '\n' || c == '\t' || c == '\r'){
                return true;
            }
            return false;
        }
        void checkPos(){
            if(pos_ > prog_.size()){
                std::cerr << "Lexer error. Try to scan pass the program.\n";
                std::cerr << pos_ << " " << prog_.size() << "\n";
                std::terminate();
            }
        }
        char peek(){
            checkPos();
            return prog_[pos_];
        }
        void advance();
        bool isEof(){
            if(pos_ == prog_.size()){
                return true;
            }
            return false;
        }
        bool isIdentifierStart(const char &c){
            return std::isalpha(c);
        }
        bool isDigitStart(const char &c){
            return std::isdigit(c);
        }


        Token lexAnIdentifier();
        bool isKeyword(const std::string s){
            return keywords.count(s);
        }
        Token lexAnInteger();

        

    private:
        const std::string prog_;
        size_t pos_; // current scan pos
        size_t line_; // current scan line number
        size_t col_; // current scan col number 
        std::unordered_set<std::string> keywords;

};

std::ostream& operator<<(std::ostream &os, const Token &t);


#endif