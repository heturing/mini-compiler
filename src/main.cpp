#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer/lexer.h"



int main(int argc, char **argv){
    
    // test file path
    std::ifstream ifs(argv[1]);
    std::ostringstream oss;
    oss << ifs.rdbuf();
    const std::string prog = oss.str();

    Lexer lexer(prog);
    while(true){
        Token t = lexer.next();
        std::cout << t << "\n";

        if(!t){
            break;
        }
    }

}