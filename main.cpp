#include <iostream>
#include "analyseur.h"

int main(int argc, char* argv[]) {
   if (argc != 2) {
       cout << "Usage: " << argv[0] << " <expression>" << endl;
       return 1;
   }

   string expression = argv[1];
   cout << "Expression: " << expression << endl;
   int result = analyse(expression);
   cout << "Result: " << result << endl;
   return 0;
}

