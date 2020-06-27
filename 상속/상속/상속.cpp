#include<iostream>
using namespace std;
class abstract
{
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x;this->y = y; }
	virtual bool operation() = 0;
};
class andgate :public abstract
{
public:
	virtual bool operation()
	{
		if (x == true && y == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class orgate :public abstract
{
public:
	virtual bool operation()
	{
		if (x == true || y == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class xorgate :public abstract
{
public:
	virtual bool operation()
	{
		if (x != y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main() {
	andgate andGate;
	orgate orGate;
	xorgate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}

