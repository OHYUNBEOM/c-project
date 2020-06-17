#include <iostream>
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb)
{
    T* rArray = new T[sizea + sizeb]; 
    for (int i = 0; i < sizea + sizeb; i++)
    {
        if (i < sizea)
        {
            rArray[i] = a[i];
        }
        else
        {
            rArray[i] = b[i - sizea];
        }
    }
    return rArray;
}

int main() {
    int x[] = { 1, 2, 3, 4, 5 };
    int y[] = { 6, 7, 8, 9 };
    int* a = concat(x, 5, y, 4);
    int asize = sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]);  
    for (int i = 0; i < asize; i++)
    {
        cout << a[i] << ' ';
    }
}