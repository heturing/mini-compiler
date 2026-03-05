cmake_minimum_required(VERSION 4.0.3)
project(mini_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mc
  src/main.cpp
  src/driver/Driver.cpp
  src/lexer/Lexer.cpp
  src/parser/Parser.cpp
  src/diag/Diag.cpp
)

target_include_directories(mc PRIVATE src)
target_compile_options(mc PRIVATE -Wall -Wextra -Wpedantic)