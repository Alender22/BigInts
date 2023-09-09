#ifndef BIGINT
#define BIGINT

#include <string>
#include <iostream>

using namespace std;

class Int
{
    private:
        const int CHARPERCELL = 1; //Set the number of characters that can be saved in each cell[integer variable]
        int * number = nullptr;

    public:
        void readStringToNumber(string numberString);
        string readNumberToString();
};

#endif