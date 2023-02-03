// Computing Methods in HEP 
// Spring 2023
// Exercise 2

// 1. Write a C++ program which takes a number as a command
// line input paramter and writes "Hello world <input number>"
// in standard output.

// Write a Makefile which compiles and links the program
// No linking required.

// Create a job script in ...

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    // I can't bother with type conversion etc now.
    // Could be done for example like:
    // https://stackoverflow.com/questions/2797813/how-to-convert-a-command-line-argument-to-int
    std::string inputNumber = "";
    argc == 2 ? inputNumber = argv[1] : inputNumber = "?";
    std::cout<<"Hello world "<<inputNumber<<std::endl;
    return EXIT_SUCCESS;
}