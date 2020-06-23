#include<iostream>
#include<string>
using namespace std;

class Point{
	int x, y;
public:
	Point(){ x = 1; y = 1; }
	~Point(){}
	int getX();
	int getY();
	void setXY(int x, int y);
};

void Point::setXY(int x, int y){ this->x = x; this->y = y; }
int Point::getX(){ return x; }
int Point::getY(){ return y;  }

//////////////////////////////////////////////////////////////////

class ColorPoint : public Point{
	string Color;
public:
	ColorPoint(){ Color = "BLACK"; this->setXY(0, 0); }
	ColorPoint(int x, int y){ Color = "BLACK"; this->setXY(x, y); }

	void show(){ cout << Color << "������ (" << this->getX() << "." << this->getY() << ")��ġ�� �� �Դϴ�." << endl; }
	void setPoint(int x, int y){ this->setXY(x, y); }
	void setColor(string s){ this->Color = s; }
};

int main(){
	Point point;
	cout << "Point ��ü�� �⺻ ��ǥ�� " << point.getX() << "." << point.getY() << " �Դϴ�." << endl;
	point.setXY(5, 5);
	cout << "����� Point ��ü�� �⺻ ��ǥ�� " << point.getX() << "." << point.getY() << " �Դϴ�." << endl;

	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

	return 0;
}