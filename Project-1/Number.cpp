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
	if (this->bigNum.size() == 1 && this->bigNum[0] == 0)
		this->negative = false;
}

bool Number::isZero() const
{
	Number num(*this);
	num.clearZero();
	return (num.bigNum.size() == 1 && num.bigNum[0] == 0);
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

//=====================================****constructor****==========================================

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

	for (auto c : rhs) { //判斷是否是算式
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

//=====================================****計算****==========================================

void Number::factorial()
{
	this->clearZero();
	if (this->point) {
		throw "階乘不能有小數";
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
	Number in1(*this); Number in2(rhs),Ans; 
	int dd;
	int mosP= in1.point;
	if (in2.point > mosP) {
		mosP = in2.point;
		dd = mosP - in1.point;
		for (int i = 0; i < dd;i++) {
			in1.pushLeft();	
		}
		in1.point = mosP;
	}
	else
	{
		dd = mosP - in2.point;
		for (int i = 0; i < dd; i++) {
			in2.pushLeft();
		}
		in2.point = mosP;
	}

	int max = in1.bigNum.size();
	if (in2.bigNum.size() > in1.bigNum.size()) {
		max = in2.bigNum.size();
	}

	int x, y, buf = 0, sum = 0;

	Ans.bigNum.resize(max);
	for (int i = 0; i < max; i++) {
		if (i > in1.bigNum.size() - 1)
		{
			x = 0;
		}
		else
		{
			x = in1.bigNum.at(i);
			if (in1.negative) {
				x = x * -1;
			}
		}
		if (i > in2.bigNum.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.bigNum.at(i);
			if (in2.negative) {
				y = y * -1;
			}
		}
		sum = x + y;
		Ans.bigNum.at(i) = sum;
	
	}
	//clea
	Ans.pushRight();

	sum = 0;
	for (int i = 0; i < Ans.bigNum.size(); i++)
	{
		sum = Ans.bigNum.at(i);
		sum = sum + buf;
		buf= 0;
		if (sum > 9) {
			while (sum > 9)
			{
				sum = sum - 10;
				buf = buf + 1;
			}
		}
		else if (sum < -9)
		{
			sum = sum + 10;
			buf = buf - 1;

		}
		
		Ans.bigNum.at(i) = sum;
	}


	int time = 0;
	for (int i = 0; i < Ans.bigNum.size(); i++)
	{
		time = Ans.bigNum.at(Ans.bigNum.size()-i-1);
		if (time !=0) {
		
			break;
		}
	}
	Ans.negative = time < 0;
	if(time !=0){

		buf = 0; 
		Ans.pushRight();

		for (int i = 0; i < Ans.bigNum.size(); i++) {
			Ans.bigNum.at(i) = Ans.bigNum.at(i) + buf;
			buf = 0;
			if (Ans.bigNum.at(i) == 0) {

			}
			else if (Ans.bigNum.at(i) > 0 != !Ans.negative) {
				if (!Ans.negative) {
					while (Ans.bigNum.at(i) < 0)
					{
						Ans.bigNum.at(i) = Ans.bigNum.at(i) + 10;
						buf = buf -1;
					}
				}
				else
				{
					while (Ans.bigNum.at(i) > 0)
					{
						Ans.bigNum.at(i) = Ans.bigNum.at(i) - 10;
						buf = buf + 1;
					}
				}

			}
			Ans.bigNum.at(i) = abs(Ans.bigNum.at(i));
		}
	
	}

	Ans.point = mosP;
	Ans.clearZero();
	return Ans;
}

Number Number::operator-(const Number& rhs)
{
	Number a(*this); Number b(rhs);
	b.negative = !b.negative;


	return a+b;
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
	Number num1(*this), num2(rhs), result;
	result.negative = !(num1.negative == num2.negative);		
	num1.clearZero();
	num2.clearZero();

	if (num2.isZero()) {
		result.bigNum = { 0 };
		throw "除數不能為0";
		return result;
	}
	else if (num1.isZero()) {
		result.bigNum = { 0 };
		return result;
	}

	else
	{
		num1.negative = false;
		num2.negative = false;

		int time = 0;
		if (num1 < num2) {
			while (num1 < num2 || num1 == num2)
			{
				num2.bigNum.push_back(0);
				num2.point++;				//除10
				time--;
			}
			num2.bigNum.pop_back();
			num2.point--;					//乘10
			time++;
		}
		else {
			while (num1 > num2 || num2 == num1)
			{
				num2.bigNum.insert(num2.bigNum.begin(), 0);//乘10
				time++;
			}
			num2.bigNum.erase(num2.bigNum.begin());//除10
			time--;
		}

		int count = point;
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
			num2.bigNum.push_back(0);//除10
			num2.point++;
			time--;
			count++;
		}
	}

	result.clearZero();
	return result;
}

Number Number::operator^(const Number& rhs)
{
	
	return Number();
}

//=====================================****判斷式****==========================================

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
		return this->negative;							//左邊是負數右邊是正數
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point < num2.bigNum.size() - num2.point); //整數長度不同
	else
	{
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
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	if (this->negative != rhs.negative)
		return !(this->negative);							//左邊是負數右邊是正數
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point > num2.bigNum.size() - num2.point); //整數長度不同
	else
	{
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

//=====================================****輸入輸出****==========================================

ostream& operator<<(ostream& os, const Number& rhs)
{
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




