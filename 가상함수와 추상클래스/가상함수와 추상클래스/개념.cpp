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
		cout << getsrcstring() << " 을" << getdeststring() << "(으)로 바꿉니다. 입력된 " << getsrcstring() << "은 " << src << "원입니다." << endl;
		cout << "반환결과 : " << re << getdeststring();
		return re;
	}
	string getsrcstring() { return "원"; }
	string getdeststring() { return "달러"; }
};
class wontoyen :public converter
{
public:
	wontoyen(double n) :converter(n) {}
	double convert(double src)
	{
		double re = src / ratio;
		cout << endl << getsrcstring() << "을" << getdeststring() << "(으)로 바꿉니다. 입력된 " << getsrcstring() << "은 " << src << "원입니다." << endl;
		cout << "반환결과 : " << re << getdeststring();
		return re;
	}
	string getsrcstring() { return "원"; }
	string getdeststring() { return "엔"; }
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