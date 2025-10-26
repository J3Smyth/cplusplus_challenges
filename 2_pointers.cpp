#include <iostream>
#include <sstream> //for the stringstream concatinated output
using namespace std;

// POINTERS point to a variable's memory address,
// thus you can increment a ptr to iterate through an array
int ptrPrint();
int ptrIteration();
int iMaxArrayElement(int *pi, int size);
int iReverseArrayElement(int *pi, int size);

int main()
{
    // ptrPrint();
    ptrIteration();
    // iMaxArrayElement(int *pi, int 10);
    //*piReverseArray(int *pi, int 10);
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

string printIntArrayStr(int array[], int SIZE){
    stringstream arrayStrs;
    arrayStrs << "[";
    for(int i = 0; i<SIZE; i++){
        arrayStrs << array[i];
        if(i<SIZE-1){
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
    << "Array: " << printIntArrayStr(idList,SIZE) << endl;
    for (int *i = idList; i < end; i++)
    {
        cout << "__ " << *i << " __" << endl;
    }
    return 0;
}

int iMaxArrayElement(int *pi, int size)
{
    return 0;
}

int *piReverseArray(int *pi, int size)
{
    return 0;
}
