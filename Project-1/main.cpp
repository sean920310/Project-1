#include <iostream>
#include <string>
#include "Integer.h"
#include "Number.h"
using namespace std;


int main()
{
	string input = "123456.123";
	Number num1 = "123456.01", num2(input);
	
	//num2 = num1 * num2;
	try
	{
		cout << (num2<num1) << endl;
		cout << num2 << endl;// << num1 << endl;

	}
	catch (const char* c)
	{
		cout << c;
	}
	
}
