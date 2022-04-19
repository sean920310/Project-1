#include "Number.h"

void Number::clearZero()
{
	for (int i = this->bigNum.size() - 1; i > point; i--) {
		if (this->bigNum[i])
			break;
		this->bigNum.pop_back();
	}
	while (point)
	{
		if (this->bigNum[0])
			break;
		this->bigNum.erase(this->bigNum.begin());
		this->point--;
	}
}

bool Number::isZero() const
{
	Number num(*this);
	num.clearZero();
	return (num.bigNum.size() == 1 && num.bigNum[1] == 0);
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
	this->clearZero();
	if (this->point) {
		throw "顶ぃΤ计";
		return;
	}

	if (this->bigNum.size() == 1 && (this->bigNum[0] == 1 || this->bigNum[0] == 2))
		return;
	else if (this->bigNum.size() == 1 && this->bigNum[0] == 0) {
		this->bigNum[0] = 1;
		return;
	}
	else {
		unsigned int num = 0, carry = 0, temp;
		for (int i = this->bigNum.size() - 1; i >= 0; i--) {
			num = num * 10 + this->bigNum[i];
		}

		for (unsigned int i = num - 1; i >= 2; i--) {
			for (int j = 0; j < this->bigNum.size(); j++) {
				temp = bigNum[j] * i + carry;
				bigNum[j] = temp % 10;
				carry = temp / 10;
			}
			while (carry)
			{
				bigNum.push_back(carry % 10);
				carry /= 10;
			}
		}
	}
	this->clearZero();
	return;
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

	vector<int> in1 = bigNum;
	vector<int> in2 = rhs.bigNum;
	vector<int> ans;

	int mosP = point;
	if (rhs.point > mosP) {
		mosP = rhs.point;
		for (int i = 0; i < abs(point - rhs.point); i++)
		{
			in1.insert(in1.begin(), 0);
		}
	}
	else
	{
		for (int i = 0; i < abs(point - rhs.point); i++)
		{
			in2.insert(in2.begin(), 0);
		}
	}
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
	Number co(rhs);



	co.bigNum = ans;
	co.point = mosP;

	vector<int> input(co.bigNum.size() + 1);
	int num, plus = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (i < co.bigNum.size()) {
			num = co.bigNum.at(i);
		}
		else
		{
			num = 0;
		}
		num = num + plus;
		if (i > co.bigNum.size() && plus == 0) {
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
	while (input.at(input.size() - 1 - time) == 0 && time > input.size())
	{
		time++;
	}
	bool sign = input.at(input.size() - 1 - time) > 0;
	co.negative = true;
	if (sign) {
		co.negative = false;
	}
	buf = 0;
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
		input.at(i) = abs(input.at(i));
	}

	co.bigNum = input;
	co.clearZero();

	return co;
}

Number Number::operator-(const Number& rhs)
{
	Number num1(*this); Number num2(rhs);
	num2.negative = (!num2.negative);
	Number abs = num1 + num2;



	return abs;
}

Number Number::operator*(const Number& rhs)
{
	Number num1(*this), num2(rhs), result;
	vector<int> tempNum(num1.bigNum.size() + num2.bigNum.size(), 0);
	result.bigNum = tempNum;
	result.negative = !(num1.negative == num2.negative);

	for (int i = 0; i < num1.bigNum.size(); i++) {
		for (int j = 0; j < num2.bigNum.size(); j++) {
			result.bigNum[i + j] += num1.bigNum[i] * num2.bigNum[j];
		}
	}
	int carry = 0;
	for (int i = 0; i < result.bigNum.size(); i++) {
		int temp = result.bigNum[i] + carry;
		result.bigNum[i] = temp % 10;
		carry = temp / 10;
	}

	result.point = num1.point + num2.point;
	result.clearZero();
	return result;
}

Number Number::operator/(const Number& rhs)
{
	Number num1(*this), num2(rhs), origin(rhs), result;
	result.negative = !(num1.negative == num2.negative);
	num1.clearZero();
	num2.clearZero();

	if (num2.isZero()) {
		result.bigNum = { 0 };
		throw "埃计ぃ0";
		return result;
	}
	else
	{
		num1.negative = false;
		num2.negative = false;
		origin.negative = false;

		int time = 0;
		if (num1 < num2) {
			while (num1 < num2 || num1 == num2)
			{
				num2.bigNum.push_back(0);
				num2.point++;				//埃10
				time--;
			}
			num2.bigNum.pop_back();
			num2.point--;					//10
			time++;
		}
		else {
			while (num1 > num2 || num2 == num1)
			{
				num2.bigNum.insert(num2.bigNum.begin(), 0);//10
				num2.point--;
				if (num2.point < 0)
					num2.point = 0;		//point 程0
				time++;
			}
			num2.bigNum.erase(num2.bigNum.begin());//埃10
			time--;
		}

		int count = 0;
		while (!num1.isZero() && count <= 100)
		{
			int n = 0;
			while (num1 > num2 || num2 == num1)
			{
				num1 = num1 - num2;
				n++;
			}
			Number temp;
			temp.negative = result.negative;
			temp.bigNum[0] = n;
			if (time >= 0) {
				for (int i = 0; i < time; i++) {
					temp.bigNum.insert(temp.bigNum.begin(), 0);
				}
			}
			else
			{
				for (int i = time; i < 0; i++) {
					temp.bigNum.push_back(0);
					temp.point++;
				}
			}
			result = result + temp;
			num2.bigNum.push_back(0);//埃10
			num2.point++;
			time--;
		}
	}

	result.clearZero();
	return result;
}

Number Number::operator^(const Number& rhs)
{
	return Number();
}

bool Number::operator==(const Number& rhs) const
{
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	return (num1.bigNum == num2.bigNum && num1.negative == num2.negative && num1.point == num2.point);
}

bool Number::operator<(const Number& rhs) const
{
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	if (this->negative != rhs.negative)
		return this->negative;							//オ娩琌璽计娩琌タ计
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point < num2.bigNum.size() - num2.point); //俱计ぃ
	else
	{
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
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	if (this->negative != rhs.negative)
		return !(this->negative);							//オ娩琌璽计娩琌タ计
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point > num2.bigNum.size() - num2.point); //俱计ぃ
	else
	{
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
	if (rhs.point) {

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




