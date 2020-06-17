#include <iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) 
{
	int cnt = 0, ch = sizeMinus;
	T* re = new T;
	for (int i = 0; i < sizeSrc; i++) 
	{
		for (int j = 0; j < sizeMinus; j++)
			if (src[i] != minus[j])
			{
				ch--;
			}
		if (ch == 0) 
		{
			re[cnt] = src[i];
			cnt++;
		}
		ch = sizeMinus;
	}
	retSize = cnt;
	return re;
}
int main() {
	int x[] = { 1, 5, 10, 3, 4 };
	int y[] = { 4, 6, 8, 7 };
	int size = 0;
	int* result = remove(x, 5, y, 4, size);
	for (int i = 0; i < size; i++)
	{
		cout << result[i] << ' ';
	}
	cout << endl;
}