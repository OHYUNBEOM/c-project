#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;
class storage
{
	int ndata;
	int* strg;
public:
	storage(int nsize);
	void showlist();
	void addndatas(int add);
	void substrg(storage s3);
};
storage::storage(int nsize)
{
	ndata = nsize;
	bool isa = true;
	int n = 0;                        
	strg = new int[ndata];
	cout << "자료" << ndata << "개 입력 :\n";
	for (int i = 0; i < ndata; i++)
	{
		cin >> n;
		for (int j = 0; j < i; j++)
		{
			if (strg[j] == n)
			{
				cout << "<중복>\n";
				isa = false;
				break;
			}
		}
		if (isa == true)
		{
			strg[i] = n;
		}
		else
		{
			isa = true;
			i--;
		}
	}
	cout << "입력완료 : ";
	for (int i = 0; i < ndata; i++)
	{
		cout << strg[i] << "  ";
	}
	cout << endl;
}
void storage::showlist()
{
	cout << ndata << " : ";
	for (int i = 0; i < ndata; i++)
	{
		cout << strg[i] << "  ";
	}
	cout << endl;
}
void storage::addndatas(int add)
{
	int addsize = ndata + add;
	int cndata = ndata;
	bool isa = true;
	int n1 = 0;
	int* temp = new int[addsize];
	for (int i = 0; i < ndata; i++)
	{
		temp[i] = strg[i];
	}
	cout << "자료" << add << "개 추가입력 : ";
	for (int i = 0; i < ndata; i++)
	{
		cout << strg[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < add; i++)
	{
		cin >> n1;
		for (int j = 0; j < addsize; j++)
		{
			if (temp[j] == n1)
			{
				cout << "<중복>\n";
				isa = false;
				break;
			}
		}
		if (isa == true)
		{
			temp[ndata] = n1;
			ndata++;
		}
		else
		{
			isa = true;
			i--;
		}
	}
	cout << "자료 ";
	for (int i = cndata; i < addsize; i++)
	{
		cout << temp[i] << "  ";
	}
	cout << "추가" << endl;
	strg = temp;
}
void storage::substrg(storage s3)
{
	int cnt1 = 0, cnt2 = 0;
	bool isa = false;
	int* temp = new int;
	for (int i = 0; i < ndata; i++)
	{
		for (int j = 0; j < s3.ndata; j++)
		{
			if (strg[i] == s3.strg[j])
			{
				cnt1++;
				isa = true;
				break;
			}
		}
		if (!isa)
		{
			temp[cnt2] = strg[i];
			cnt2++;
		}
		else
		{
			isa = false;
		}
	}
	strg = temp;
	ndata -= cnt1;
}
int main()
{
	storage s1(4);
	s1.showlist();

	storage s2(s1);
	s2.showlist();
	
	s2.addndatas(3);
	s2.showlist();

	storage s3(3);
	s3.showlist();
	s2.substrg(s3);
	s2.showlist();
}