#include <iostream>
#include <string.h>
using namespace std;

class m_string {
public:
	m_string() {}

	m_string(const m_string& rhs) : _Mysize(rhs._Mysize)
	{
		_Myptr = new char[_Mysize + 1];
		strcpy(_Myptr, rhs._Myptr);
	}

	m_string(const char* str)
	{
		_Mysize = strlen(str);
		_Myptr = new char[_Mysize+1];
		strcpy(_Myptr, str);
	}

	friend ostream& operator<<(ostream& os, const m_string& ms)
	{
		os << ms._Myptr;
		return os;
	}

private:
	unsigned int _Mysize;
	char* _Myptr;
};


int main(void)
{
	m_string str1 = "123";
	m_string str2 = str1;
	cout << str2 << endl;
	return 0;
}
