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
	int index;

	for (auto c : rhs) { //耞琌琌衡Α
		if ((c > '9' || c < '0') && c != '.' && c != '-') {
			hasOperator = true;
			break;
		}
	}

	index = rhs.find_last_of('-');
	if (index == -1) {
		this->negative = false;
	}
	else if (index == 0) {
		this->negative = true;
	}
	else
	{
		hasOperator = true;
	}

	index = rhs.find('.');
	if (index == -1) {
		this->point = 0;
	}
	else
	{
		if (!hasOperator)
			this->point = rhs.length() - index - 1;
	}

	if (hasOperator) {
		//todo calculate

	}
	else
	{
		int n;
		if (this->negative) {
			n = 1;
		}
		else
		{
			n = 0;
		}
		for (int i = rhs.length() - 1; i >= n; i--) {
			if (rhs[i] != '.')
				newNum.push_back(rhs[i] - '0');
		}
	}
	this->bigNum = newNum;
	this->clearZero();
}

Number::Number(const Number& rhs)
{
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	this->point = rhs.point;
}

Number::Number(const char* rhs)
{
	string temp = rhs;
	Number newNum = temp;
	*this = newNum;
}

void Number::factorial()
{
}

Number& Number::operator=(const Number& rhs)
{
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	this->point = rhs.point;
	return *this;
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
				x = in1.at(i) * -1;
			}
		}
		if (i > in2.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.at(i);
			if (rhs.negative) {
			y = in2.at(i) * -1;
			}
		}

		sum = x + y + buf;
		buf = 0;
		if (sum == 0 && i == in1.size() - 1 && in1.size() == in2.size()) {
			break;
		}
		ans.at(i) = sum;


	}

	//plus or not

	vector<int> input(ans.size() + 1);

	int num, plus = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (i < ans.size()) {
			num = ans.at(i);
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
		return this->negative;							//オ娩琌璽计娩琌タ计
	else if (this->bigNum.size() - this->point != rhs.bigNum.size() - rhs.point)
		return (this->bigNum.size() - this->point < rhs.bigNum.size() - rhs.point); //俱计ぃ
	else
	{
		Number num1(*this), num2(rhs);
		if (num1.point > num2.point) {		//干霍计翴计
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
	if (this->negative != rhs.negative)
		return !(this->negative);							//オ娩琌璽计娩琌タ计
	else if (this->bigNum.size() - this->point != rhs.bigNum.size() - rhs.point)
		return (this->bigNum.size() - this->point > rhs.bigNum.size() - rhs.point); //俱计ぃ
	else
	{
		Number num1(*this), num2(rhs);
		if (num1.point > num2.point) {		//干霍计翴计
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
					return !(num1.bigNum[i] > num2.bigNum[i]);
			}
		}
		else
		{
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return (num1.bigNum[i] > num2.bigNum[i]);
			}
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const Number& rhs)
{
	if (!rhs.bigNum.size()) {
		//error
		return os;
	}
	if (rhs.negative && !rhs.isZero())
		os << "-";
	for (int i = rhs.bigNum.size() - 1; i >= 0; i--) {
		os << rhs.bigNum[i];
		if (rhs.point) {
			if (rhs.point == i)
				os << '.';
		}
	}
	return os;
}

istream& operator>>(istream& is, Number& rhs)
{
	string temp;
	is >> temp;
	rhs = temp;
	return is;
}
