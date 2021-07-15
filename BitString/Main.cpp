#include"BitString.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	BitString b;
	BitString c = "111";

	BitString error = "4545";

	//b = "567";
	//cout << b;

	//cout << b[1];

	/*
	преобразования из 10 в 2 систему
	int a = 545;
	a = b.dec2bin(a);
	cout << "a = " << a << endl;;
	char buf[80];
	b = _itoa(a, buf, 2);*/

	b = "100"; 
	b.checkBit();
	c.checkBit();
	error.checkBit();

	cout << "BitString b = " << b;
	cout << "BitString c = " << c;

	cout << "BitString error = 4545 - " << error;
	cout << endl;
	error = b + c;

	cout << "error = b + c " << error;
	cout << endl;

	bool k = b == c;
	cout << "bool k = b == c: " << k << endl;

	k = b != c;
	cout << "bool k = b != c: " << k << endl;

	b += error;

	cout << "b += error: " << b;

	cout << endl;
	system("pause");
}