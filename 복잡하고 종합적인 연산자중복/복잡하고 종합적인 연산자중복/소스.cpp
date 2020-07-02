#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class mystring
{
	int mlen;
	char* mptr;
public:
	mystring();
	mystring(const char* str);
	mystring(mystring& ref);
	~mystring();
	friend ostream& operator <<(ostream& os, mystring& temp);
	mystring& operator=(const mystring& str);
	mystring operator+(mystring& str);
	mystring operator-(mystring& str);
};
ostream& operator<<(ostream& os, mystring& temp)
{
	for (int i = 0; i < temp.mlen + 1;i++)
	{
		os << temp.mptr[i];
	}
	return os;
}
mystring::mystring(mystring& ref)
{
	this->mlen = ref.mlen;
	this->mptr = new char[this->mlen + 1];
	strcpy(this->mptr, ref.mptr);
}
mystring& mystring::operator=(const mystring& str)
{
	this->mlen = str.mlen;
	this->mptr = new char[this->mlen + 1];
	for (int i = 0; i < this->mlen + 1; i++)
	{
		this->mptr[i] = str.mptr[i];
	}
	return*this;
}
mystring mystring::operator+(mystring& str)
{
	mystring tmp;
	delete[]tmp.mptr;
	tmp.mlen = this->mlen + str.mlen;
	tmp.mptr = new char[tmp.mlen + 1];
	for (int i = 0; i < tmp.mlen + 1; i++)
	{
		if (i < mlen)
		{
			tmp.mptr[i] = this->mptr[i];
		}
		else
		{
			tmp.mptr[i] = str.mptr[i - mlen];
		}
	}
	return tmp;
}
mystring mystring::operator-(mystring& str)
{
	mystring tmp;
	delete[]tmp.mptr;
	int len = 0, cnt = 0, idx = 0;
	char ch[10];
	for (int i = 0; i < this->mlen; i++)
	{
		for (int j = 0; j < str.mlen; j++)
		{
			if (this->mptr[i] == str.mptr[j])
			{
				ch[len] = this->mptr[i];
				len++;
			}
		}
	}
	for (int i = 0; i < this->mlen; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (this->mptr[i] == ch[j])
			{
				this->mptr[i] = 0;
				cnt++;
			}
		}
	}
	for (int i = 0; i < str.mlen; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str.mptr[i] == ch[j])
			{
				str.mptr[i] = 0;
				cnt++;
			}
		}
	}
	tmp.mlen = this->mlen + str.mlen - cnt;
	tmp.mptr = new char[tmp.mlen + 1];
	for (int i = 0; i < this->mlen; i++)
	{
		if (this->mptr[i] == 0)
		{
			continue;
		}
		else
		{
			tmp.mptr[idx] = this->mptr[i];
			idx++;
		}
	}
	for (int i = 0; i < str.mlen; i++)
	{
		if (str.mptr[i] == 0)
		{
			continue;
		}
		else
		{
			tmp.mptr[idx] = str.mptr[i];
			idx++;
		}
	}
	return tmp;
}
mystring::mystring()
{
	mlen = 1;
	mptr = new char[mlen];
	strcpy(mptr, "");
}
mystring::mystring(const char* str)
{
	mlen = strlen(str);
	mptr = new char[mlen + 1];
	strcpy(mptr, str);
}
mystring::~mystring()
{
	delete[]mptr;
	mlen = 0;
	mptr = NULL;
}
void main()
{
	mystring stra("Banana");
	mystring strb("Orange");
	mystring strc;
	mystring strd;
	mystring stre;

	cout << "strA=>" << stra << endl;
	cout << "strB=>" << strb << endl;

	stre = stra;
	cout << stre << endl;

	strc = stra + strb;
	cout << "strC=>" << strc << endl;

	strd = stra - strb;
	cout << "strD=>" << strd << endl;
}