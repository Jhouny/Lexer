#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include "analyseur.h"

using namespace std;

struct TestCase {
    string expression;
    string expected_output;
};

string run_and_capture(const string& expr) {
    int res = analyse(expr);
    return to_string(res);
}

int main() {
    // Test structure: {expression, expected_output}
    vector<TestCase> tests = {
        {"1+2", "3"},
        {"3*4", "12"},
        {"(1+2)*3", "9"},
        {"10+20*30", "610"},
        {"(10+20)*30", "900"},
        {"(1+)", "-1"},
        // Error cases based on the LALR(1) table analysis
        {"+", "-1"},       // E0
        {"*", "-1"},       // E0
        {")", "-1"},       // E0
        {"", "-1"},        // E0
        //{"11", "-1"},     // E1 - can't test input valval because the lexer concatenates the numbers
        {"1(", "-1"},       // E1
        {"1)", "-1"},       // E1
        {"1(1)", "-1"},     // E1
        {"(+", "-1"},      // E2
        {"(*", "-1"},      // E2
        {"()", "-1"},      // E2
        {"(", "-1"},       // E2
        //{"1", "-1"},      // E3 - can't test input valval because the lexer concatenates the numbers
        //{"1(", "-1"},     // E3 - equivalent to E1
        //{"1(1)", "-1"},   // E3 - equivalent to E1
        {"1++", "-1"},     // E4
        {"1+*", "-1"},     // E4
        {"1+)", "-1"},     // E4
        {"1+", "-1"},      // E4
        {"1*+", "-1"},      // E5
        {"1**", "-1"},      // E5
        {"1*)", "-1"},      // E5
        {"1*", "-1"},       // E5
        //{"(11", "-1"},   // E6 - can't test input valval because the lexer concatenates the numbers
        {"(1(", "-1"},     // E6
        {"(1", "-1"},      // E6
        //{"(11", "-1"},   // E6 - can't test input valval because the lexer concatenates the numbers
        //{"1+11", "-1"},   // E7 - can't test input valval because the lexer concatenates the numbers
        {"1+1(", "-1"},     // E7
        //{"1+11", "-1"},   // E7 - can't test input valval because the lexer concatenates the numbers
        //{"1*11", "-1"},  // E8 - can't test input valval because the lexer concatenates the numbers
        {"1*1(", "-1"},    // E8
        //{"1*11", "-1"},  // E8 - can't test input valval because the lexer concatenates the numbers
        {"(1)1", "-1"},     // E9
        {"(1)(", "-1"},     // E9
        //{"(1)1", "-1"},   // E9 - can't test input valval because the lexer concatenates the numbers
    };
    long unsigned int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        string output = run_and_capture(tests[i].expression);
        if (output == tests[i].expected_output) {
            cout << "Test " << i+1 << " passed." << endl;
            ++passed;
        } else {
            cout << "Test " << i+1 << " failed. Expression: " << tests[i].expression << " -> Output was:\n" << output  << ", but expected: " << tests[i].expected_output << endl;
        }
    }
    cout << passed << "/" << tests.size() << " tests passed." << endl;
    return passed == tests.size() ? 0 : 1;
}
