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

	m_string& operator=(const m_string& rhs)
	{
		if(_Myptr != nullptr)
			delete []_Myptr;

		_Mysize = rhs._Mysize;
		_Myptr = new char[_Mysize + 1];
		strcpy(_Myptr, rhs._Myptr);

		return *this;
	}

	m_string& operator=(const char* str)
	{
		delete []_Myptr;

		_Mysize = strlen(str);
		_Myptr = new char[_Mysize + 1];
		strcpy(_Myptr, str);

		return *this;
	}

	m_string operator+(const m_string& rhs)
	{
		m_string temp;
		temp._Mysize = _Mysize + rhs._Mysize;
		temp._Myptr = new char[temp._Mysize + 1];
		
		strcpy(temp._Myptr, _Myptr);
		strcat(temp._Myptr, rhs._Myptr);
				
		delete []_Myptr;
		_Myptr = nullptr;

		return temp;
	}

	friend ostream& operator<<(ostream& os, const m_string& ms)
	{
		os << ms._Myptr;
		return os;
	}

	unsigned int size(void) { return _Mysize; }
	unsigned int length(void) { return _Mysize; }

private:
	unsigned int _Mysize;
	char* _Myptr;
};


int main(void)
{
	m_string str1 = "123";
	cout << str1 << " " << str1.size() << endl;

	m_string str2 = str1;
	cout << str2 << " " << str2.size() << endl;

	str2 = "m_string";
	cout << str2 << " " << str2.size() << endl;

	str2 = str2 + str1;
	cout << str2 << " " << str2.size() << endl;

	return 0;
}
