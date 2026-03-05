# Mini Compiler

This is a toy compiler that compiles a toy language. I implement this while reading the bool [Engineering a Compiler](https://www.oreilly.com/library/view/engineering-a-compiler/9780080916613/).

## Build

Following the below instructions to build the mini-compiler. The executable is located in folder *build*.
```
cd <path-to-mini-compiler-source-root>
mkdir build
cmake -S . -B build
cmake --build build
```

## Language

The toy language for now only works with defining variables and computing the result of numeric expressions. I plan to extend the language to a simplified c++-style language in the future. Below is the language supported by the current implementation.

Statements:
* let x = Expr;
* print Expr;

Expressions:
* integers: e.g., 123
* identifiers: e.g., x
* binary: e.g., + - * /
* parentheses: e.g., (Expr)

Below is an example program. Running this program will output 7.
```
let x = 1 + 2 * 3;
print x;
```

### Grammer

```
Program     ->  Stmt* EOF
Stmt        ->  LetStmt
            |   PrintStmt
LetStmt     ->  "let" IDENT "=" Expr ";"
PrintStmt   ->  "print" Expr ";"
Expr        ->  Add
Add         ->  Mul (("+" | "-") Mul)*
Mul         ->  Unary (("*" | "/") Unary)*
Unary       ->  ("+" | "-") Unary
            |   Primary
Primary     ->  INT
            |   IDENT
            |   "(" Expr ")"
```

## Lexer
