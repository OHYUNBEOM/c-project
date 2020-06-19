#include<iostream>
#include<string>
using namespace std;

class Converter {
protected:
	double ratio;
public:
	Converter(double ratio) { this->ratio = ratio; }
	virtual double convert(double str) = 0;
	virtual string getSrcString() = 0;
	virtual string getDestString() = 0;

};

class WonToDollar : public Converter {
public:
	WonToDollar(double a) : Converter(a) { }
	double convert(double str) {
		cout << getSrcString() << "을 " << getDestString() << "(으)로 바꿉니다. 입력된 "
			<< getSrcString() << "은" << str << getDestString() << getSrcString() << "입니다.\n변환결과 : "
			<< (str / this->ratio) << getDestString() << "\n" << endl;
		return (str / this->ratio);
	}

	string getSrcString() {
		return "원";
	}
	string getDestString() {
		return "달러";
	}
};

class WonToYen : public Converter {
public:
	WonToYen(double a) : Converter(a) { }
	double convert(double str) {
		cout << getSrcString() << "을 " << getDestString() << "(으)로 바꿉니다. 입력된 "
			<< getSrcString() << "은" << str << getDestString() << getSrcString() << "입니다.\n변환결과 : "
			<< (str / this->ratio) << getDestString() << "\n" << endl;
		return (str / this->ratio);
	}

	string getSrcString() {
		return "원";
	}
	string getDestString() {
		return "엔";
	}

};

int main() {
	WonToDollar wd(1130);
	Converter* cv;
	cv = &wd;
	cv->convert(10000);
	WonToYen wy(100.6);
	cv = &wy;
	cv->convert(10000);
	return 0;
}