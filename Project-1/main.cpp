#include <iostream>
#include <string>
#include "Integer.h"
#include "Number.h"
using namespace std;


int main()
{
	string input = "0.1";
	Number num1 = "1.1", num2(input);
	try
	{
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
		cout << "+: " << num1 + num2 << endl;
		cout << "-: " << num1 - num2 << endl;
		cout << "*: " << num1 * num2 << endl;
		//cout << "/: " << num1 / num2 << endl;

	}
	catch (const char* c)
	{
		cout << c;
	}

	/*
	string input = "0.1";
		Number num1 = "10", num2(input);

		cout << "+: " << num1 + num2 << endl;

		string input = "9.9";
		Number num1 = "0.1", num2(input);

		cout << "+: " << num1 + num2 << endl;

		string input = "0.9";
		Number num1 = "0.1", num2(input);

		cout << "+: " << num1 + num2 << endl;

		string input = "2";
		Number num1 = "99", num2(input);
		cout << "+: " << num1 + num2 << endl;

		string input = "10.1";
		Number num1 = "10.1", num2(input);
		cout << "+: " << num1 + num2 << endl;
		*/

}