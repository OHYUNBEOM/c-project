#include<iostream>
#include<string>
using namespace std;
class converter
{
protected:
	double ratio;
public:
	converter(double ratio) { this->ratio = ratio; }
	virtual double convert(double src) = 0;
	virtual string getsrcstring() = 0;
	virtual string getdeststring() = 0;
};
class wontodollar :public converter
{
public:
	wontodollar(double n) :converter(n) {}
	double convert(double src)
	{
		double re = src / ratio;
		cout << getsrcstring() << " ��" << getdeststring() << "(��)�� �ٲߴϴ�. �Էµ� " << getsrcstring() << "�� " << src << "���Դϴ�." << endl;
		cout << "��ȯ��� : " << re << getdeststring();
		return re;
	}
	string getsrcstring() { return "��"; }
	string getdeststring() { return "�޷�"; }
};
class wontoyen :public converter
{
public:
	wontoyen(double n) :converter(n) {}
	double convert(double src)
	{
		double re = src / ratio;
		cout << endl << getsrcstring() << "��" << getdeststring() << "(��)�� �ٲߴϴ�. �Էµ� " << getsrcstring() << "�� " << src << "���Դϴ�." << endl;
		cout << "��ȯ��� : " << re << getdeststring();
		return re;
	}
	string getsrcstring() { return "��"; }
	string getdeststring() { return "��"; }
};
int main()
{
	wontodollar wd(1130);
	converter* cv;
	cv = &wd;
	cv->convert(10000);
	wontoyen wy(100.6);
	cv = &wy;
	cv->convert(10000);
}