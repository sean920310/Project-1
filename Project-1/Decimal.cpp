#include "Decimal.h"

Decimal::Decimal() :Number()
{
	this->isInt = false;
}

Decimal::Decimal(const Number& rhs) : Number(rhs)
{
	this->isInt = false;
	
}

Decimal::Decimal(const Decimal& rhs) : Number(rhs)
{
	this->isInt = false;

}

Decimal::Decimal(const string& rhs) : Number(rhs)
{
	this->isInt = false;

}

Decimal::Decimal(const double& rhs) :Number(rhs)
{
	this->isInt = false;
}

Decimal::Decimal(const char* rhs) : Number(rhs)
{
	this->isInt = false;
}

Decimal& Decimal::operator=(const Decimal& rhs)
{
	this->isInt = false;
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

Decimal& Decimal::operator=(const double& rhs)
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


Decimal operator+(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator+(rhs));

	return newDec;
}

Decimal operator-(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator-(rhs));

	return newDec;
}

Decimal operator*(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator*(rhs));

	return newDec;
}

Decimal operator/(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator/(rhs));

	return newDec;
}

Decimal operator^(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator^(rhs));
	return newDec;
}

void Decimal::print(ostream& os) const
{
	if (this->negative && !this->isZero())
		os << "-";
	Decimal molecular(this->fraction[0]), denominator(this->fraction[1]), output;
	output = molecular / denominator;
	//Decimal output;
	//output = *this;
	for (int i = output.bigNum.size() - 1; i >= 0; i--) {
		os << output.bigNum[i];
		if (output.point) {
			if (output.point == i)
				os << '.';
		}
	}
	if (!output.point)
		os << '.';
	for (int i = output.point; i < 100; i++) {
		os << '0';
	}
}

ostream& operator<<(ostream& os, const Decimal& rhs)
{
	if (rhs.negative && !rhs.isZero())
		os << "-";
	Decimal molecular(rhs.fraction[0]), denominator(rhs.fraction[1]), output;
	output = molecular / denominator;
	//Decimal output;
	//output = rhs;
	for (int i = output.bigNum.size() - 1; i >= 0; i--) {
		os << output.bigNum[i];
		if (output.point) {
			if (output.point == i)
				os << '.';
		}
	}
	if (!output.point)
		os << '.';
	for (int i = output.point; i < 100; i++) {
		os << '0';
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
