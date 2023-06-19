#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<ctype.h>


  int StringLenght(char str[]);
  int StringLenght2(const char str[]);
char* to_upper(char str[]);
char* to_lower(char str[]);
char* shrink(char str[]);
 bool is_palindrome(const char str[]);
char* remove_symbol(char str[], char symbol);
 bool is_bin_number(const char str[]);
 int bin_to_dec(const char str[]);



int main()
{
	setlocale(LC_ALL, ""); //1

	//char str[] = {'H','e','l','l','o',' ','s','t','r','i','n','g','s','!', 0};
	//char str1[] = "Hello";
	//str1[1] = 'o';
	//std::cout << str1 << std::endl;

	//const char* str2 = "World!";
	//std::cout << str2 << std::endl;
	//==========================================================================

	const int SIZE = 256;
	char str[SIZE] = {};
	//char str[SIZE] = "    Хорошо      ЖИвет    НА     свете Винни      Пух";
	//char str[SIZE] = "Аргентина манит негра";;
	std::cout << "Enter your text (введите ваш текст): ";
	SetConsoleCP(1251); //2
	std::cin.getline(str, SIZE);
	SetConsoleCP(866);  //3
	std::cout << str << std::endl;

	std::cout << "String size: " << StringLenght2(str) << std::endl;
	std::cout << to_upper(str) << std::endl;
	std::cout << shrink(str) << std::endl;
	std::cout << to_lower(str) << std::endl;
	//std::cout << typeid(str).name() << std::endl;
	
	std::cout << "This string is " << (is_palindrome(str) ? "" : "not ") << "a palindrome. " << std::endl;
	
	std::cout << "------------------------------------" << std::endl;
	std::cout << str << std::endl;

	std::cout << "This string is " << (is_bin_number(str) ? "" : "not ") << "binary number ";

	std::cout << str << "(bin) = " << bin_to_dec(str) << "(dec);\n ";

}
  int StringLenght(char str[])
{
	int cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}
  int StringLenght2(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			/*if (str[i] >= 'a' && str[i] >= 'z')str[i] -= 32;
			if (str[i] >= 'а' && str[i] >= 'я')str[i] -= 32;
			if (str[i] == 'ё')str[i] -= 16;*/
		}
		str[i] = toupper(str[i]);
	}
	return str;
}
char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			/*if (str[i] >= 'a' && str[i] >= 'z')str[i] += 32;
			if (str[i] >= 'а' && str[i] >= 'я')str[i] += 32;
			if (str[i] == 'ё')str[i] += 16;*/
		}
		str[i] = tolower(str[i]);

	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++) str[j] = str[j + 1];
		}
	}
	while (str[0] == ' ')for (int i = 0; str[i]; i++)str[i] = str[i + 1];
	return str;
}
 bool is_palindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n/2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}
char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol) 
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
	}
	return str;
}
 bool is_bin_number(const char str[])
{
	 for (int i = 0; str[i]; i++)
	 {
		 if (str[i] != '0' && str[i] != '1') return false;
	 }
	 return true;
}
 int bin_to_dec(const char str[])
 {
	 if (!is_bin_number(str)) return 0;
	 int n = strlen(str);
	 int decimal = 0;
	 int weight = 1;  // discharge weighting factor
	 for (int i = n - 1; i >= 0; i--)
	 {
		 decimal += (str[i] - 48)*weight; // 48 - ascii code of "0"
		 weight *= 2;
	 }
	 return decimal;
 }