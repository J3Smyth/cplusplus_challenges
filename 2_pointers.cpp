#include <iostream>
using namespace std;

int main(){

    int bookID = 555;
    int *ptr = &bookID;

    cout << *ptr << endl;

    bookID += 10;

    cout << *ptr << endl;

    *ptr = 550;

    cout << *ptr << endl << bookID << endl;





}