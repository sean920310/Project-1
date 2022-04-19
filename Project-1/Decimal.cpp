#include "Decimal.h"



Decimal::Decimal()
{
	NumV.clear();
	sign = 1;
	point = 0;
}

Decimal::Decimal(vector<int> NumV, int point) {
	this->NumV = NumV;
	this->point = point;
	sign = 1;

}


Decimal::Decimal(string in) {
	string input = in;
	string bufV;

	bool plus = true;

	sign = input.find('-');
	if (sign == -1) {
		plus = true;
		sign = 1;
	}
	else
	{
		input = input.erase(sign, sign + 1);
		plus = false;
		sign = -1;
	}

	point = input.find('.');


	if (point == -1) {
		bufV = input;
		point = 0;
	}
	else
	{
		bufV = input.substr(0, point) + input.substr(point + 1);
		input.erase(0, point + 1);
		point = input.size();
	}

	NumV.resize(bufV.size());

	for (int i = 0; i < bufV.length(); i++)
	{
		NumV.at(i) = (bufV[i] - '0') * sign;
	}
}

vector<int> Decimal::time(vector<int> in, int time) {
	vector<int> co = in;
	for (int i = 0; i < in.size(); i++)
	{

		co.at(i) = in.at(i) * time;
	}
	watch(co);
	return co;
}


void Decimal::Time(Decimal& a) {

	vector<int> in1 = NumV;
	vector<int> in2 = a.NumV;
	vector<int> buf = NumV;
	reverse(in1.begin(), in1.end());
	reverse(in2.begin(), in2.end());



	for (int i = 0; i < in2.size(); i++) {
		buf = time(in1, in2.at(i));
		int po = a.point;
		po = po - i + point;


		if (po >= 0) {

		}
		else
		{
			for (int j = 0; j < abs(po); j++)
			{
				buf.insert(buf.begin(), 0);
				po = 0;
			}
		}
		cout << i << endl;
		reverse(buf.begin(), buf.end());

		buf = Plus(buf, po);
		watch(buf);
	}

}



void Decimal::Plus(Decimal& a) {

	int mosP = point;
	if (a.point > mosP) {
		mosP = a.point;
	}
	vector<int> in1 = changePoint(mosP);
	vector<int> in2 = a.changePoint(mosP);
	vector<int> ans;

	reverse(in1.begin(), in1.end());
	reverse(in2.begin(), in2.end());

	int max = in1.size();
	if (in2.size() > in1.size()) {
		max = in2.size();
	}

	int x, y, buf = 0, sum = 0;

	ans.resize(max);

	for (int i = 0; i < max; i++) {

		if (i > in1.size() - 1)
		{
			x = 0;
		}
		else
		{
			x = in1.at(i);
		}
		if (i > in2.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.at(i);
		}

		sum = x + y + buf;
		buf = 0;
		if (sum == 0 && i == in1.size() - 1 && in1.size() == in2.size()) {
			break;
		}
		ans.at(i) = sum;


	}

	point = mosP;
	ans = fixe(ans, 1);
	NumV = ans;

}


vector<int>  Decimal::Plus(vector<int> a, int po) {

	int mosP = point;
	if (po > mosP) {
		mosP = po;
	}
	vector<int> in1 = changePoint(mosP);
	vector<int> in2 = changePoint(a, mosP);
	vector<int> ans;
	//watch(in2);
	reverse(in1.begin(), in1.end());
	reverse(in2.begin(), in2.end());

	int max = in1.size();
	if (in2.size() > in1.size()) {
		max = in2.size();
	}

	int x, y, buf = 0, sum = 0;

	ans.resize(max);

	for (int i = 0; i < max; i++) {

		if (i > in1.size() - 1)
		{
			x = 0;
		}
		else
		{
			x = in1.at(i);
		}
		if (i > in2.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.at(i);
		}

		sum = x + y + buf;
		buf = 0;
		if (sum == 0 && i == in1.size() - 1 && in1.size() == in2.size()) {
			break;
		}
		ans.at(i) = sum;


	}

	point = mosP;
	ans = fixe(ans, 1);
	return ans;

}





vector<int> Decimal::fixe(vector<int> in, int gustplus) {

	vector<int> input(in.size() + gustplus);

	int num, plus = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (i < in.size()) {
			num = in.at(i);
		}
		else
		{
			num = 0;
		}
		num = num + plus;
		if (i > in.size() && plus == 0) {
			break;
		}
		plus = 0;
		if (num > 9) {
			while (num > 9)
			{
				num = num - 10;
				plus = +1;
			}
		}
		else if (num < -9)
		{
			num = num + 10;
			plus = plus - 1;

		}
		input.at(i) = num;
	}

	int time = 0;
	while (input.at(input.size() - 1 - time) == 0)
	{
		time++;
	}

	//fixe +-
	bool sign = input.at(input.size() - 1 - time) > 0;
	if (sign) {
		Decimal::sign = 0;
	}

	int buf = 0;
	for (int i = 0; i < input.size(); i++) {
		input.at(i) = input.at(i) + buf;
		buf = 0;
		if (input.at(i) == 0) {

		}
		else if (input.at(i) > 0 != sign) {
			if (sign) {
				while (input.at(i) < 0)
				{
					input.at(i) = input.at(i) + 10;
					buf = -1;
				}
			}
			else
			{
				while (input.at(i) > 0)
				{
					input.at(i) = input.at(i) - 10;
					buf = 1;
				}
			}


		}

	}

	input = killzero(input);
	reverse(input.begin(), input.end());
	return input;

}

void Decimal::watch()
{
	if (sign == -1) {
		cout << "-";
	}
	for (int i = 0; i < NumV.size(); i++)
	{

		cout << abs(NumV.at(i));

		if (i == NumV.size() - 1 - point) {
			cout << ".";
		}

		if ((i + 1) % 10 == 0) {

		}

	}

}

vector<int> Decimal::changePoint(int i) {

	if (i > point) {

		vector<int> copy = NumV;
		copy.insert(copy.end(), i - point, 0);

		return copy;
	}
	return NumV;


}



vector<int> Decimal::changePoint(vector<int>asd, int i) {

	if (i > point) {

		vector<int> copy = asd;
		copy.insert(copy.begin(), i - point, 0);
		watch(copy);
		return copy;
	}
	return asd;


}


Decimal Decimal::operator+(const Decimal& a) {
	return a;
}


void Decimal::watch(vector<int> NumV)
{
	for (int i = 0; i < NumV.size(); i++)
	{
		cout << "" << NumV.at(i) << " ";
	}

}

vector<int> Decimal::killzero(vector<int> in)
{

	vector<int> co = in;
	for (int i = 0; i < in.size(); i++)
	{

		if (in.at(in.size() - i - 1) != 0) {
			break;
		}
		else
		{
			co.pop_back();
		}


		return co;
	}
}