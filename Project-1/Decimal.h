#pragma once
#include<vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;

class Decimal
{
public:
	Decimal();//
	Decimal(string input);//
	Decimal(vector<int> NumV, int point);
	void Plus(Decimal& a);//
	void Time(Decimal& a);


	vector<int> Plus(vector<int> a, int point);
	vector<int> time(vector<int> in, int i);

	Decimal operator + (const Decimal& a);

	vector<int> fixe(vector<int> in, int gustplus);//
	void watch(vector<int> NumV);
	void watch();

	vector<int> changePoint(vector<int>, int i);
	vector<int> changePoint(int i);
	vector<int>killzero(vector<int> NumV);
	vector<int> NumV;
private:

	int sign;

	int point;

};


