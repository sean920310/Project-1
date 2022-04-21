#include <iostream>
#include <string>
#include "Integer.h"
#include "Decimal.h"
#include "Number.h"
using namespace std;


int main()
{
	string input = "2";
	Number num2 = "1.5";
	Number num1(input);
	try
	{
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
		cout << "+: " << num1 + num2 << endl;
		cout << "-: " << num1 - num2 << endl;
		cout << "*: " << num1 * num2 << endl;
		cout << "/: " << num1 / num2 << endl;
		cout << "^: " << (num1 ^ num2) << endl;
	}
	catch (const char* c)
	{
		cout << c;
	}

}