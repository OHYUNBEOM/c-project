#include<iostream>
using namespace std;
class circle
{
	int radius;
public:
	circle(int radius = 0) { this->radius = radius; }
	int getradius() { return radius; }
	void setradius(int radius) { this->radius = radius; }
	double getarea() { return 3.14 * radius * radius; }
};
class namedcircle :public circle
{
	string name;
public:
	namedcircle() {};
	namedcircle(int r, string name) :circle(r) { this->name = name; }
	string getname() { return name; }
	void setrname(int r, string name) { setradius(r);this->name = name; }
};
int main()
{
	namedcircle pizza[5];
	int radius = 0;
	string name;
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ">> ";
		cin >> radius >> name;
		pizza[i].setrname(radius, name);
	}
	double max = pizza[0].getarea();
	name = pizza[0].getname();
	for (int i = 1; i < 5; i++)
	{
		if (max < pizza[i].getarea())
		{
			max = pizza[i].getarea();
			name = pizza[i].getname();
		}
	}
	cout << "���� ������ ū ���ڴ� " << name << "�Դϴ�" << endl;
}