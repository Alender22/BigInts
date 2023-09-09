#include "bigInt.h"

/*
    Purpose: Takes a string, and returns whether it represents a positive integer, including 0.
    Parameters: candidate string, numberString, to checkt
    Return: True if only digits are contained, false otherwise.
*/
bool Int::isPositiveIntString(string numberString)
{
    for(int i = 0; i < numberString.length(); i++)
            if(!isdigit(numberString[i]))
                return false;                   //If a non-digit character is found, it's not a number string

    return true;
}

/*
    Purpose: Take a string and convert it to an int * array.
    Parameters: numberString | The string to be converted.
    Return: none. When this function completes, the number member of the class will represent the value of the string
*/
void Int::readStringToNumber(string numberString)
{
    if(!isPositiveIntString(numberString))

    if(number != nullptr)
        delete [] number;    //Avoid a memory leak if number is already pointing to a number

    string segment = "";

    int strLen = numberString.length();                                           //Number of characters in number to convert
    int numCells = (strLen / CHARPERCELL) + 1;      //Number of cells needed to store the number
    if(strLen % CHARPERCELL)
        numCells++;               //If number of characters does not evenly divide into cells, add one more

    number = new int[numCells];        //Allocates the memory needed to store the number
    number[0] = numCells;              //Stores the size of the number in its firs integer.

    for(int i = 0, j = 0, currentCell = 1; i <= strLen; i++)
    {
        if(j % CHARPERCELL == 0 && j != 0 && segment != "")
        {
            int cellInput = stoi(segment);
            number[currentCell] = stoi(segment);         //Store number in dynamic int array. Left is least significant cell
            segment = numberString[strLen - (i + 1)];    //Store next character in segment
            currentCell++; j++;                          //Increment cell and character counts
        }
        else
        {
            segment = numberString[strLen - (i + 1)] + segment;  //Add another character to the end of numberString
            j++;                                                 //increment character count

            if(i == strLen - 1)
                number[currentCell] = stoi(segment);
        }
    }
}

/*
    Purpose: Read the int * array int a string
    Parameters: none
    Return: a string reresenting the value of number
*/
string Int::readNumberToString()
{
    string numberString = "";

    for(int i = 1; i < number[0]; i++)
        numberString = to_string(number[i]) + numberString;

    return numberString;
}