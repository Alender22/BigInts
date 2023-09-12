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

    while(numberString[0] == '0' && numberString != "0")
        numberString = numberString.substr(1, numberString.length() - 1);

    return numberString;
}

/*
    Purpose: Add two Int numbers together
    Parameters: an int number. Will add that value to its own
    Return: Does not change the value of the object itself, returns a new object with the specified value
*/
Int Int::addNumbers(Int a)
{
    const int * ap = a.getNumPointer();
    int bigLen = (ap[0] > number[0]) ? ap[0] : number[0], shortLen = (ap[0] > number[0]) ? ap[0] : number[0];
    const int * bigNum = (ap[0] > number[0]) ? ap : number;
    const int * smallNum = (ap[0] <= number[0]) ? ap : number;

    int * answer = new int[bigLen + 1];
    answer[0] = bigLen + 1;

    for(int i = 1; i < bigLen; i++)
    {
        answer[i] = bigNum[i];
    }

    int carryInt = 0;

    for(int i = 1; i < shortLen; i++)
    {
        answer[i] += smallNum[i];
        carryInt = answer[i] / BASE;
        answer[i] -= carryInt * BASE;
        answer[i + 1] += carryInt;
    }

    //TODO: free the last, unused integer.
    /*if(answer[answer[0] - 1] == 0)
    {
        delete (answer + answer[0] - 1);
        answer[0]--;
    }*/

    Int result;
    result.setNumber(answer);
    return result;
}

/*
    Purpose: subtract two Int numbers. Only works when subtractin smaller equal numbers.
    Parameters: The Int to subtract from the object
    Return: Differnce Int
*/
Int Int::subNumbers(Int a)
{
    const int * ap = a.getNumPointer();
    int bigLen = (ap[0] > number[0]) ? ap[0] : number[0], shortLen = (ap[0] > number[0]) ? ap[0] : number[0];
    const int * bigNum = (ap[0] > number[0]) ? ap : number;
    const int * smallNum = (ap[0] <= number[0]) ? ap : number;

    int * answer = new int[bigLen];
    answer[0] = bigLen;

    for(int i = 1; i < bigLen; i++)
    {
        answer[i] = bigNum[i];
    }

    int carryInt = 0;

    for(int i = 1; i < shortLen; i++)
    {
        answer[i] -= smallNum[i];
        carryInt = 1 - ((answer[i] + BASE) / BASE);
        answer[i] += carryInt * BASE;
        answer[i + 1] -= carryInt;
    }

    Int result;
    result.setNumber(answer);
    return result;
}

/*
    Purpose: multiply two Int numbers
    Parameters: Number to multiply by
    Return: the product of the two numbers
*/
Int Int::mulNumbers(Int a)
{
    int * numA = a.getNumPointer(); int * numB = number;
    int * answer     = new int[numA[0] + numB[0]];
    answer[0] = numA[0] + numB[0];

    int product, carry;

    for(int i = 1; i < numA[0]; i++)
    {
        for(int j = 1; j < numB[0]; j++)
        {
            product = numA[i] * numB[j] + answer[i + j - 1];
            carry = product / BASE;
            product -= BASE * carry;    

            answer[i + j - 1] = product;
            answer[i + j] += carry;
        }
    }

    Int result;
    result.setNumber(answer);
    return result;
}

/*
    Purpose: set the number pointer in an Int object to a given int *
    Parameters: the int * to set number to
    Return: none
*/
void Int::setNumber(int * toSet)
{
    if(number != nullptr)
        delete [] number;

    number = toSet;
}