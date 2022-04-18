#include <iostream>
#include <string>
#include "Integer.h"
using namespace std;


int main()
{
	string input = "333333333";
	Integer num1 = "0", num2(input);
	//num2 = num1 * num2;
	cout << (num2/num1) << endl;// << num1 << endl;
	
}
