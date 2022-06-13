#include <iostream>

using namespace std;

class m_string {

	friend ostream& operator<<(ostream& os, const m_string& ms)
	{
		os << ms._Myptr;
		return os;
	}
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

	str2 = str2 + "ab";
	cout << str2 << " " << str2.size() << endl;

	cout << (str1 == "123") << endl;
	cout << (str1 == str2) << endl;

	return 0;
}
