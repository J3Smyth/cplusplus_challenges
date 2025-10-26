#include <iostream>
#include <sstream> //for the stringstream concatinated output
using namespace std;

// POINTERS point to a variable's memory address,
// thus you can increment a ptr to iterate through an array
int ptrPrint();
string printIntArrayStr(int array[], int SIZE);
int ptrIteration();
int iMaxArrayElement(int *pi, int size);
int *piReverseArray(int *pi, int size);

//-----ptr logic functions
void swap(int &i, int &j);
void swap(int *i, int *j);

int main()
{
    ptrPrint();
    ptrIteration();
    // //----------------------------------
    int const size = 7;
    int *pi = new int[size]{30, 40, 50, 60, 70, 80, 90};
    cout << "Normal Array: " << printIntArrayStr(pi, size) << endl;
    cout << "Maximum Element in Array: " << iMaxArrayElement(pi, size) << endl;
    // //----------------------------------
    int *revPi = piReverseArray(pi, size);
    cout << "Reversed Array: " << printIntArrayStr(revPi, size) << endl;
    //-----------ptr logic functions
    int i = 5, j = 10;
    cout << "Original: " << i << " " << j << "\n";
    swap(i, j);
    cout << "*i, *j ptrs: " << i << " " << j << "\n";
    swap(&i, &j);
    cout << "&i, &j ptrs: " << i << " " << j << "\n";
}

int ptrPrint()
{
    int bookID = 555;
    int *ptr = &bookID;

    cout << *ptr << endl;

    bookID += 10;

    cout << *ptr << endl;

    *ptr = 550;

    cout << *ptr << endl
         << bookID << endl;
    return 0;
}

string printIntArrayStr(int array[], int SIZE)
{
    stringstream arrayStrs;
    arrayStrs << "[";
    for (int i = 0; i < SIZE; i++)
    {
        arrayStrs << array[i];
        if (i < SIZE - 1)
        {
            arrayStrs << ", ";
        }
    }
    arrayStrs << "]";
    string finalArrayStr = arrayStrs.str();
    return finalArrayStr;
}

int ptrIteration()
{
    const int SIZE = 6;
    int idList[SIZE] = {10, 12, 14, 16, 18, 20};
    int *end = idList + SIZE;

    cout << "Pointer Iteration\n--------------------\n"
         << "Array: " << printIntArrayStr(idList, SIZE) << endl;
    for (int *i = idList; i < end; i++)
    {
        cout << "__ " << *i << " __" << endl;
    }
    return 0;
}

int iMaxArrayElement(int *pi, int size)
// returns the value of the maximum element found in the int array pointed to by
// pi, of size elements.
{
    int maxElm = size - 1;
    return pi[maxElm];
}

int *piReverseArray(int *pi, int size)
// reverses the elements in the int array pointed to by pi, of size elements.
{
    int firstPos = 0;
    int lastPos = size - 1;
    for (int i = 0; i < (size / 2); i++)
    // going up to half size of array bc 2 position variables
    // at opposite ends coming to halfway point of word, meaning full word has been reversed.
    {
        int tempPos = pi[firstPos];
        pi[firstPos] = pi[lastPos];
        pi[lastPos] = tempPos;
        firstPos++;
        lastPos--;
    }
    return pi;
}

void swap(int &i, int &j)
//this function is easier as it simply calls by reference with '&'
{
    int temp = i;
    i = j;
    j = temp;
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}