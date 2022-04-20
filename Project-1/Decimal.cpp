#include "Decimal.h"



Decimal::Decimal() :Number()
{
}

Decimal::Decimal(const Number& rhs) : Number(rhs)
{
}

Decimal::Decimal(const Decimal& rhs) : Number(rhs)
{
}

Decimal::Decimal(const string& rhs) : Number(rhs)
{
}

Decimal::Decimal(const char* rhs) : Number(rhs)
{
}

Decimal& Decimal::operator=(const Decimal& rhs)
{
	this->Number::operator=(rhs);
	return *this;
}

Decimal& Decimal::operator=(const char* rhs)
{
	Decimal newDec(rhs);
	*this = newDec;
	return *this;
}

Decimal& Decimal::operator=(const string& rhs)
{
	Decimal newDec(rhs);
	*this = newDec;
	return *this;
}

Decimal Decimal::operator+(const Integer& rhs)
{
	Decimal newDec(this->Number::operator+(rhs));
	return newDec;
}

Decimal Decimal::operator-(const Integer& rhs)
{
	Decimal newDec(this->Number::operator-(rhs));
	return newDec;
}

Decimal Decimal::operator*(const Integer& rhs)
{
	Decimal newDec(this->Number::operator*(rhs));
	return newDec;
}

Decimal Decimal::operator/(const Integer& rhs)
{
	Decimal newDec(this->Number::operator/(rhs));
	return newDec;
}

Decimal Decimal::operator^(const Integer& rhs)
{
	Decimal newDec(this->Number::operator^(rhs));
	return newDec;
}

Decimal Decimal::operator+(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator+(rhs));
	return newDec;
}

Decimal Decimal::operator-(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator-(rhs));
	return newDec;
}

Decimal Decimal::operator*(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator*(rhs));
	return newDec;
}

Decimal Decimal::operator/(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator/(rhs));
	return newDec;
}

Decimal Decimal::operator^(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator^(rhs));
	return newDec;
}

ostream& operator<<(ostream& os, const Decimal& rhs)
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
	if (!rhs.point)
		os << '.';
	for (int i = rhs.point; i < 100; i++) {
		cout << '0';
	}
	return os;
}

istream& operator>>(istream& is, Decimal& rhs)
{
	string temp;
	is >> temp;
	rhs = temp;
	return is;
}
