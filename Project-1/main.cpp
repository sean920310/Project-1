#include <iostream>
#include <string>
#include "Integer.h"
#include "Number.h"
using namespace std;


int main()
{
	string input = "-99786785686706706767967679697976967.000203109230109052589859809809080983400980976097";
	Number num1 = "99786785686706706767967679697976967.0002031092301090525898598098090809834009809760977631897263871628947618275", num2(input);
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