#include<iostream>
#include<string>
using namespace std;
class book
{
	string str;
	int price;
	char* publishedDate;
public:
	book() {};
	~book() {};
	book(const char* title, int price, const char* pdate);
	void set(const char* title, int price, const char* pdate);
	void setpubishedDate();
	string getbookname();
	void setbookname(int position, string newtitle);
	void show();
};
book::book(const char* title, int price, const char* pdate)
{
	str = title;
	this->price = price;
	publishedDate = (char*)pdate;
}
void book::set(const char* title, int price, const char* pdate)
{
	str = title;
	this->price = price;
	publishedDate = (char*)pdate;
}
void book::setpubishedDate()
{
	int year, month, day;
	string publish = publishedDate;
	year = stoi(publish.substr(4, 4));
	month = stoi(publish.substr(0, 2));
	day = stoi(publish.substr(2, 2));
	cout << "출판년도 : " << year << "년 " << month << "월" << day << "일" << endl;
}
string book::getbookname()
{
	return str;
}
void book::setbookname(int position, string newtitle)
{
	str.replace(position, newtitle.size(), newtitle);
}
void book::show()
{
	cout << "책이름 : " << str << "\n책가격 : " << price << endl;
	setpubishedDate();
}
int replacebooktitle(book* books, int nbks, const char* oldtitle, const char* newtitle)
{
	string stoldtitle = oldtitle;
	string stnewtitle = newtitle;
	int pos, check = 0;
	for (int i = 0; i < nbks; i++)
	{
		string str = books[i].getbookname();
		if (pos = str.find(stoldtitle) != -1)
		{
			books[i].setbookname(pos - 1, stnewtitle);
			return i;
		}
	}
	return -1;
}
int main()
{
	book bookshelf[3] = { book("C#프로그래밍",20000,"09012016"),book("c++",25000,"09022018"),book() };
	bookshelf[2].set("java programming", 28000, "12052017");
	bookshelf[0].show();
	bookshelf[1].show();
	bookshelf[2].show();
	int n = 0;
	if ((n = replacebooktitle(bookshelf, 3, "c++", "C++ programming"))<0)
	{
		cout << "책이름이 없습니다." << endl;
	}
	else
	{
		bookshelf[n].show();
	}
}