#include <iostream>
using namespace std;

template <class T>
T biggest(T a[], int size) {

	T max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max) max = a[i];
	}
	return max;
}

int main() {
	int a[] = { 1, 10, 100, 5, 4 };
	double b[] = { 2.1, 2.2, 2.3, 2.4, 2.5 };
	char c[] = { 'a', 'b', 'c', 'd', 'e' };

	cout << "int형 배열에서 가장 큰 값 : " << biggest(a, 5) << endl;
	cout << "double형 배열에서 가장 큰 값 : " << biggest(b, 5) << endl;
	cout << "char형 배열에서 가장 큰 값 : " << biggest(c, 5) << endl;
}