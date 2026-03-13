# Lexer

This project is a C++ implementation of a lexer and parser for arithmetic expressions. It supports processing of integers, parentheses, addition and multiplication operations. The lexer tokenizes the input string, which is then passed onto the automaton for parsing and evaluation through a state machine. Error handling is included to manage invalid inputs and states gracefully.

## Building and Running
> The building process has been tested on Windows 11 with WSL 2 and Ubuntu 22.04 using g++ and make. Ensure you have these tools installed to build and run the project successfully.
To build the project, use the Makefile provided. Run the following command in the terminal:

```bash
make
```

After building, you can run the lexer and parser with:

```bash
./build/lexer.exe '<EXPRESSION>'
```

## Testing 
The tests for the program are in `tests/test_lexer.cpp`. You can run the tests using the following command from the `tests` directory:

```bash
make test
```
This will compile the test suite and execute it, providing feedback on the success or failure of each test case. Errors on the grammar are reported with specific messages indicating the nature of the error.