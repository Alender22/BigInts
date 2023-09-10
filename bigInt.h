#ifndef BIGINT
#define BIGINT

#include <string>
#include <iostream>

using namespace std;

class Int
{
    private:
        const int CHARPERCELL = 1; //Set the number of characters that can be saved in each cell[integer variable]
        const int BASE = 10;       //Should make it dependant on variables....
        int * number = nullptr;

        bool isPositiveIntString(string numberString);

    public:
        void readStringToNumber(string numberString);
        string readNumberToString();

        int getLength() {return number[0];}
        int * getNumPointer() {return number;}

        void setNumber(int * toSet);

        Int addNumbers(Int a);
        Int subNumbers(Int a);
};

#endif