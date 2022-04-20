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

}