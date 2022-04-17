#include "Integer.h"

void Integer::clearZero()
{
	for (int i = this->bigNum.size() - 1; i > 0; i--) {
		if (this->bigNum[i]) {
			break;
		}
		this->bigNum.pop_back();
	}
}

Integer::Integer()
{
	vector<int> newNum = { 0 };
	bigNum = newNum;
	negative = false;
}

Integer::Integer(const Integer& rhs)
{
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
}

Integer::Integer(const string& rhs)
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

Integer::Integer(const char* rhs)
{
	string temp = rhs;
	Integer newInt = temp;
	*this = newInt;
}

void Integer::factorial()
{
	return;
}

Integer& Integer::operator=(const Integer& rhs)
{
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	return *this;
}

Integer& Integer::operator=(const char* rhs)
{
	Integer newInt(rhs);
	this->bigNum = newInt.bigNum;
	this->negative = newInt.negative;
	return *this;
}

Integer& Integer::operator=(const string& rhs)
{
	Integer newInt(rhs);
	this->bigNum = newInt.bigNum;
	this->negative = newInt.negative;
	return *this;
}

Integer Integer::operator+(const Integer& rhs)
{
	Integer num1(*this), num2(rhs);
	if (num1.negative == num2.negative) {
		//補齊長度
		if (num1.bigNum.size() < num2.bigNum.size()) {
			num1 = rhs;
			num2 = *this;
		}
		int len = num1.bigNum.size() - num2.bigNum.size();
		for (int i = 0; i < len; i++) {
			num2.bigNum.push_back(0);
		}

		//加法
		int carry = 0, temp;
		len = num1.bigNum.size();
		for (int i = 0; i < len; i++) {
			temp = num1.bigNum[i] + num2.bigNum[i] + carry;
			if (temp > 9) {
				temp -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			num1.bigNum[i] = temp;
		}
		if (carry) {
			num1.bigNum.push_back(1);
		}
		num1.clearZero();
		return num1;
	}
	else
	{
		if (num1.negative == true) {
			num1.negative = false;
			return (num2 - num1);
		}
		else
		{
			num2.negative = false;
			return (num1 - num2);
		}
	}
}

Integer Integer::operator-(const Integer& rhs)
{
	Integer num1(*this), num2(rhs), result;
	if (this->negative == true && rhs.negative == true) {
		//-a--b
		num2.negative = false;
		num1.negative = false;
		return (num2 - num1);
	}
	else if (this->negative == true && rhs.negative == false) {
		//-a-b
		num1.negative = false;
		result = num1 + num2;
		result.negative = true;
		return result;
	}
	else if (this->negative == false && rhs.negative == true) {
		//a--b
		num2.negative = false;
		return (num1 + num2);
	}
	else
	{
		//a-b
		int borrow = 0;
		if (num1.bigNum.size() > num2.bigNum.size()) {
			for (int i = num1.bigNum.size() - num2.bigNum.size(); i > 0; i--) {
				num2.bigNum.push_back(0);
			}
		}
		else {
			for (int i = num2.bigNum.size() - num1.bigNum.size(); i > 0; i--) {
				num1.bigNum.push_back(0);
			}
		}
		int len = num1.bigNum.size();
		int temp;
		result.bigNum = num1.bigNum;
		for (int i = 0; i < len; i++) {
			temp = num1.bigNum[i] - num2.bigNum[i] - borrow;
			if (temp < 0) {
				temp += 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}
			result.bigNum[i] = temp;
		}
		if (borrow) {
			result = num1;
			num1 = num2;
			num2 = result;
			borrow = 0;
			for (int i = 0; i < len; i++) {
				temp = num1.bigNum[i] - num2.bigNum[i] - borrow;
				if (temp < 0) {
					temp += 10;
					borrow = 1;
				}
				else
				{
					borrow = 0;
				}
				result.bigNum[i] = temp;
			}
			result.negative = true;

		}
		return result;
	}
}

Integer Integer::operator*(const Integer& rhs)
{

	return Integer();
}

Integer Integer::operator/(const Integer& rhs)
{
	return Integer();
}

Integer Integer::operator^(const Integer& rhs)
{
	return Integer();
}

ostream& operator<<(ostream& os, const Integer& rhs)
{
	if (rhs.negative)
		os << "-";
	for (int i = rhs.bigNum.size() - 1; i >= 0; i--) {
		os << rhs.bigNum[i];
	}
	return os;
}

istream& operator>>(istream& is, Integer& rhs)
{
	string temp;
	is >> temp;
	rhs = temp;
	return is;
}

