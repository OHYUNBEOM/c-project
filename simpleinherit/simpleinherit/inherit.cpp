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
		cout << getSrcString() << "�� " << getDestString() << "(��)�� �ٲߴϴ�. �Էµ� "
			<< getSrcString() << "��" << str << getDestString() << getSrcString() << "�Դϴ�.\n��ȯ��� : "
			<< (str / this->ratio) << getDestString() << "\n" << endl;
		return (str / this->ratio);
	}

	string getSrcString() {
		return "��";
	}
	string getDestString() {
		return "�޷�";
	}
};

class WonToYen : public Converter {
public:
	WonToYen(double a) : Converter(a) { }
	double convert(double str) {
		cout << getSrcString() << "�� " << getDestString() << "(��)�� �ٲߴϴ�. �Էµ� "
			<< getSrcString() << "��" << str << getDestString() << getSrcString() << "�Դϴ�.\n��ȯ��� : "
			<< (str / this->ratio) << getDestString() << "\n" << endl;
		return (str / this->ratio);
	}

	string getSrcString() {
		return "��";
	}
	string getDestString() {
		return "��";
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