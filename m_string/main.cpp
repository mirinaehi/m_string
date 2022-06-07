#include <iostream>
#include <string.h>
using namespace std;

class m_string {
public:
	m_string() {}

	m_string(const m_string& rhs)
	{

	}

	m_string(const char* str)
	{
		int len = strlen(str) + 1;
		_Myptr = new char[len];
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
	m_string str = "123";
	cout << str;
	return 0;
}
