#include <iostream>
#include <string>
#include "bigInt.h"

using namespace std;

int main()
{
    int userIterations = 0;

    cout << "Enter sum test max: ";
    cin >> userIterations;
    cout << endl << endl;
    
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            Int a, b;
            a.readStringToNumber(to_string(i));
            b.readStringToNumber(to_string(j));

            Int result = a.addNumbers(b);
            if(result.readNumberToString() != to_string(i + j))
                cout << a.readNumberToString() << " + " << b.readNumberToString() << " = " << result.readNumberToString() << "  |  " << i + j << endl;
        }
    }

    return 0;
}