#include "Number.h"

void Number::clearZero()
{
}

bool Number::isZero() const
{
	return false;
}

void Number::pushLeft()
{
	bigNum.insert(bigNum.begin(), 0);
	point++;
}

void Number::pushRight()
{
	bigNum.push_back(0);
}

Number::Number()
{
	bigNum = { 0 };
	negative = false;
	point = 0;
}

Number::Number(const string& rhs)
{
	vector<int> newNum;
	bool hasOperator = false;
	for (auto c : rhs) {
		if (c > '9' || c < '0') {
			hasOperator = true;
			break;
		}
	}
	if (hasOperator) {
		string temp = rhs.substr(1);
		if (rhs[0] == '-') {
			bool hasOperator = false;
			for (auto c : temp) {
				if (c > '9' || c < '0') {
					hasOperator = true;
					break;
				}
			}
			if (hasOperator) {
				//todo calculate

			}
			else
			{
				for (int i = rhs.length() - 1; i >= 1; i--) {
					newNum.push_back(rhs[i] - '0');
				}
				this->negative = true;
			}
		}
	}
	else
	{
		for (int i = rhs.length() - 1; i >= 0; i--) {
			newNum.push_back(rhs[i] - '0');
		}
		this->negative = false;
	}
	this->bigNum = newNum;
}

Number::Number(const Number& rhs)
{
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	this->point = rhs.point;
}

void Number::factorial()
{
}

Number& Number::operator=(const Number& rhs)
{
	// TODO: 於此處插入 return 陳述式
}

Number Number::operator+(const Number& rhs)
{
	int mosP = point;
	if (rhs.point > mosP) {
		mosP = rhs.point;
	}

	vector<int> in1 = bigNum;
	vector<int> in2 = rhs.bigNum;
	vector<int> ans;

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
			if (negative) {

			}
		}
		if (i > in2.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.at(i);
			if (in2.negative) {

			}
		}

		sum = x + y + buf;
		buf = 0;
		if (sum == 0 && i == in1.size() - 1 && in1.size() == in2.size()) {
			break;
		}
		ans.at(i) = sum;


	}




	return Number();
}

Number Number::operator-(const Number& rhs)
{
	return Number();
}

Number Number::operator*(const Number& rhs)
{
	return Number();
}

Number Number::operator/(const Number& rhs)
{
	return Number();
}

Number Number::operator^(const Number& rhs)
{
	return Number();
}

bool Number::operator==(const Number& rhs) const
{
	return (this->bigNum == rhs.bigNum && this->negative == rhs.negative && this->point == rhs.point);
}

bool Number::operator<(const Number& rhs) const
{
	if (this->negative != rhs.negative)
		return this->negative;							//左邊是負數右邊是正數
	else if (this->bigNum.size() - this->point != rhs.bigNum.size() - rhs.point)
		return (this->bigNum.size() - this->point < rhs.bigNum.size() - rhs.point); //整數長度不同
	else
	{
		Number num1(*this), num2(rhs);
		if (num1.point > num2.point) {		//補齊小數點位數
			for (int i = num1.point - num2.point; i > 0; i--)
				num2.pushLeft();
		}
		else
		{
			for (int i = num2.point - num1.point; i > 0; i--)
				num1.pushLeft();
		}

		if (this->negative) {
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return !(num1.bigNum[i] < num2.bigNum[i]);
			}
		}
		else
		{
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return (num1.bigNum[i] < num2.bigNum[i]);
			}
		}
	}
	return false;
}

bool Number::operator>(const Number& rhs) const
{
	return false;
}

ostream& operator<<(ostream& os, const Number& rhs)
{
	// TODO: 於此處插入 return 陳述式
}

istream& operator>>(istream& is, Number& rhs)
{
	// TODO: 於此處插入 return 陳述式
}
