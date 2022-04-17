#include <iostream>
#include <string>
#include "Integer.h"
using namespace std;


int main()
{
	string input = "-877";
	Integer num1 = "123", num2(input);
	num2 = num1 + num2;
	cout << num2 << endl << num1 << endl;
	cout << num2 + num2 << endl;
	cin >> num2 >> num1;
	cout << num2 << endl << num1 << endl;
}
