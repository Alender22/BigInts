#include "bigInt.h"

void Int::readStringToNumber(string numberString)
{
    string segment = "";

    int strLen = numberString.length();                                 //Number of characters in number to convert
    int numCells = (strLen / 2) + (strLen % CHARPERCELL) ? 1 : 2 ;      //Number of cells needed to store the number

    for(int i = 0, j = 0, currentCell = 1; i < strLen; i++)
    {
        if(j % CHARPERCELL == 0 && j != 0)
        {
            number[currentCell] = stoi(segment);
            segment = numberString[strLen - (i + 1)];
        }
        else
        {
            segment = numberString[strLen - (i + 1)] + segment;
        }
    }
}