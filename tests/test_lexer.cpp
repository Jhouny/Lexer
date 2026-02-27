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
    vector<TestCase> tests = {
        {"1+2", "3"},
        {"3*4", "12"},
        {"(1+2)*3", "9"},
        {"10+20*30", "610"},
        {"(10+20)*30", "900"},
        {"(1+)", "0"},
        // Add more test cases here
    };
    int passed = 0;
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
