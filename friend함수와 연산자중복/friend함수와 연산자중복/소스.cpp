#include<iostream>
using namespace std;
class circle
{
	int radius;
public:
	circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " ÀÎ ¿ø " << endl; }
	friend circle& operator++(circle& c);
	friend circle operator++(circle& c, int x);
};
circle& operator++(circle& c)
{
	c.radius++;
	return c;
}
circle operator++(circle& c, int x)
{
	circle test = c;
	c.radius++;
	return test;
}
int main()
{
	circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}