#include <iostream>
#include "bigInt.h"

using namespace std;

int main()
{
    string userInput = "";
    Int test;

    cout << "Enter the number you want to save: ";
    cin >> userInput;

    test.readStringToNumber(userInput);

    cout << test.readNumberToString() << endl;

    return 0;
}