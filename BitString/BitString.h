#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<Windows.h>

using namespace std;

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "Да"; }
	std::string do_falsename() const { return "Нет"; }
};

class MyString
{
protected:

//private:
	char* str;
	int length;

public:

	// 1). конструктор без параметров;
	MyString() { str = nullptr, length = 0; }

	// 2). конструктор, принимающий в качестве параметра C-строку (заканчивается нулевым байтом);
	MyString(const char* str);

	// 3) конструктор копирования;
	MyString(const MyString& obj);

	// 4) оператор присваивания;
	MyString& operator =(const MyString& obj);

	// 5). получение длины строки;
	int countLenght();

	// 6) очистка строки (сделать строку пустой);
	void clearString();

	//void print() { cout << str; }


	// 7). деструктор
	~MyString();

	//8) конкатенация строк(перегрузить операторы + и += );
	MyString operator+(const MyString& obj);

	MyString& operator+=(const MyString& obj);

	//9) проверка на равенство(==) и на неравенство (!=).

	bool operator==(const MyString& obj);

	bool operator!=(const MyString& obj);

	char operator[](int index) const;

	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const MyString& obj);
};

inline MyString::MyString(const char* str)
{
	this->length = strlen(str);
	this->str = new char[length + 1];
	strcpy(this->str, str);
}

inline MyString::MyString(const MyString& obj)
{
	this->length = strlen(obj.str);
	this->str = new char[length + 1];
	strcpy(this->str, obj.str);
}

inline MyString& MyString::operator=(const MyString& obj)
{

	if (this->str != nullptr)
	{
		delete[]this->str;
	}

	this->length = strlen(obj.str);
	this->str = new char[length + 1];
	strcpy(this->str, obj.str);

	return *this;
}

inline int MyString::countLenght()
{
	//return strlen(this->str);
	return length;
}

inline void MyString::clearString()
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}

	this->str = nullptr;
	this->length = 0;
}

MyString::~MyString()
{
	//очищаем динамическую память выделенную под массив char *str
	delete[]this->str;
}

inline MyString MyString::operator+(const MyString& obj)
{
	MyString tmp;

	length = strlen(this->str) + strlen(obj.str);

	tmp.str = new char[length + 1];

	//int i = 0;

	//for (; i < strlen(this->str); i++)
	//{
	//	tmp.str[i] = this->str[i];
	//}

	//for (size_t j = 0; j < strlen(obj.str); j++, i++)
	//{
	//	tmp.str[i] = obj.str[j];
	//	
	//}

	//tmp.str[i] = '\0';

	tmp.str = strcpy(tmp.str, this->str);
	tmp.str = strcat(tmp.str, obj.str);

	return tmp;
}

inline MyString& MyString::operator+=(const MyString& obj)
{
	MyString tmp;

	length = strlen(this->str) + strlen(obj.str);

	tmp.str = new char[length + 1];
	tmp.str = strcpy(tmp.str, this->str);
	tmp.str = strcat(tmp.str, obj.str);

	this->clearString();

	length = strlen(tmp.str);

	this->str = new char[length + 1];

	strcpy(this->str, tmp.str);

	return *this;
}

inline bool MyString::operator==(const MyString& obj)
{
	if (this->length != obj.length)
		return false;

	return !strcmp(this->str, obj.str);
}

inline bool MyString::operator!=(const MyString& obj)
{
	//if (this->length != obj.length)
		//return true;

	//return strcmp(this->str, obj.str);

	return !(this->operator==(obj));
}

inline char MyString::operator[](int index) const
{
	return this->str[index];
}

ostream& operator<<(ostream& out, const MyString& obj)
{
	
	if (obj.length)
	{
		for (size_t i = 0; i < strlen(obj.str); i++)
		{
			out << obj.str[i];
		}

		out << endl;

		return out;
	}

	else
		cout << "Строка = nullptr";
}

class BitString : public MyString
{
public:

	BitString();
	BitString(const char *str);

	void checkBit();

	//изменение знака числа (перевод числа в дополнительный код);


	//8) сложение битовых строк(перегрузить операторы + и += );

	BitString operator+(const BitString& obj);

	//long long int dec2bin(int a); // ф-кция перевода числа из 10 в 2 систему

	~BitString();

private:

};

inline BitString::BitString()
{
	BitString::str = nullptr;
	BitString::length = 0;
}

inline BitString::BitString(const char* str)
{
	BitString::length = strlen(str);
	BitString::str = new char[length + 1];
	strcpy(BitString::str, str);	
}

inline void BitString::checkBit()
{
	if (this->length)
	{
		/*char* tmp = new char[length];
		strcpy(tmp, str);*/
		
		for (size_t i = 0; i < this->length; i++)
		{
			if (this->str[i] != '0' && this->str[i] != '1')
			{
				BitString::clearString();
				break;
			}				
		}
	}
}

//inline long long int BitString::dec2bin(int a)
//{
//	int bin = 0, k = 1;
//
//	while (a)
//	{
//		bin += (a % 2) * k;
//		k *= 10;
//		a /= 2;
//	}
//
//	return bin;
//}

inline BitString BitString::operator+(const BitString& obj)
{
	int dop = 0;

	char *buff = new char [length + obj.length];
	
	int i = 1;

	if (length > obj.length || length == obj.length)
	{
		for (; i < obj.length + 1; i++)
		{
			if (this->str[length - i] == '0' && obj.str[obj.length - i] == '0')
			{
				if (dop == 1)
				{
					buff[length - i] = '1';
					dop = 0;
				}
				else
				{
					buff[length - i] = '0';
				}
			}

			else if (this->str[length - i] == '0' && obj.str[obj.length - i] == '1' || this->str[length - i] == '1' && obj.str[obj.length - i] == '0')
			{
				if (dop == 1)
				{
					buff[length - i] = '0';
					dop = 1;
				}
				else
				{
					buff[length - i] = '1';
				}
			}

			else if (this->str[length - i] == '1' && obj.str[obj.length - i] == '1')
			{
				if (dop == 1)
				{
					buff[length - i] = '1';
				}
				else
				{
					buff[length - i] = '0';
					dop = 1;
				}
			}
		}

		for (; i < length + 1; i++)
		{
			if (this->str[length - i] == '0')
			{
				if (dop == 1)
				{
					buff[length - i] = '1';
					dop = 0;
				}
				else
				{
					buff[length - i] = '0';
				}
			}

			else if (this->str[length - i] == '1')
			{
				if (dop == 1)
				{
					buff[length - i] = '0';
				}
				else
				{
					buff[length - i] = '1';
					dop = 0;
				}
			}

		}

		if (dop == 1)
		{
			char* tmp = new char[i];
			buff[i - 1] = '\0';
			strcpy(tmp, buff);

			delete[]buff;

			buff = new char[i];

			buff[0] = '1';

			for (size_t j = 1; j < i; j++)
			{
				buff[j] = tmp[j - 1];
			}

			buff[i] = '\0';
		}

		else
			buff[i - 1] = '\0';
	}

	
	else
	{

		for (; i < length + 1; i++)
		{
			if (this->str[length - i] == '0' && obj.str[obj.length - i] == '0')
			{
				if (dop == 1)
				{
					buff[obj.length - i] = '1';
					dop = 0;
				}
				else
				{
					buff[obj.length - i] = '0';
				}
			}

			else if (this->str[length - i] == '0' && obj.str[obj.length - i] == '1' || this->str[length - i] == '1' && obj.str[obj.length - i] == '0')
			{
				if (dop == 1)
				{
					buff[obj.length - i] = '0';
					dop = 1;
				}
				else
				{
					buff[obj.length - i] = '1';
				}
			}

			else if (this->str[length - i] == '1' && obj.str[obj.length - i] == '1')
			{
				if (dop == 1)
				{
					buff[obj.length - i] = '1';
				}
				else
				{
					buff[obj.length - i] = '0';
					dop = 1;
				}
			}

		}

		for (; i < obj.length + 1; i++)
		{
			if (obj.str[obj.length - i] == '0')
			{
				if (dop == 1)
				{
					buff[obj.length - i] = '1';
					dop = 0;
				}
				else
				{
					buff[obj.length - i] = '0';
				}
			}

			else if (obj.str[obj.length - i] == '1')
			{
				if (dop == 1)
				{
					buff[obj.length - i] = '0';
				}
				else
				{
					buff[obj.length - i] = '1';
					dop = 0;
				}
			}
		}

		if (dop == 1)
		{
			char* tmp = new char[i];
			buff[i - 1] = '\0';
			strcpy(tmp, buff);

			delete[]buff;

			buff = new char[i];

			buff[0] = '1';

			for (size_t j = 1; j < i; j++)
			{
				buff[j] = tmp[j - 1];
			}

			buff[i] = '\0';
		}

		else
			buff[i - 1] = '\0';
	}

	return BitString(buff);
}

BitString::~BitString()
{
	BitString::clearString();
}