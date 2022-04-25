#include "Integer.h"


void Integer::toInteger()
{
	if (this->point) {
		for (int i = point; i > 0; i--) {
			this->bigNum.erase(this->bigNum.begin());
			point--;
		}
	}
	this->isInt = true;
}

Integer::Integer():Number()
{
}

Integer::Integer(const Number& rhs) : Number(rhs)
{
}

Integer::Integer(const Integer& rhs):Number(rhs)
{
	this->toInteger();
}

Integer::Integer(const string& rhs):Number(rhs)
{
	this->toInteger();
}

Integer::Integer(const double& rhs):Number(rhs)
{
	this->toInteger();
}

Integer::Integer(const char* rhs):Number(rhs)
{
	this->toInteger();
}

Integer& Integer::operator=(const Integer& rhs)
{
	this->Number::operator=(rhs);
	this->toInteger();
	return *this;
}

Integer& Integer::operator=(const char* rhs)
{
	Integer newInt(rhs);
	*this = newInt;
	return *this;
}

Integer& Integer::operator=(const string& rhs)
{
	Integer newInt(rhs);
	*this = newInt;
	return *this;
}

Integer& Integer::operator=(const double& rhs)
{
	Integer newInt(rhs);
	*this = newInt;
	return *this;
}

Integer Integer::operator+(const Integer& rhs)
{
	Integer newInt(this->Number::operator+(rhs));
	return newInt;
}

Integer Integer::operator-(const Integer& rhs)
{
	Integer newInt(this->Number::operator-(rhs));
	return newInt;
}

Integer Integer::operator*(const Integer& rhs)
{
	Integer newInt(this->Number::operator*(rhs));
	return newInt;
}

Integer Integer::operator/(const Integer& rhs)
{
	Integer newInt(this->Number::operator/(rhs));
	return newInt;
}

Integer Integer::operator^(const Integer& rhs)
{
	Integer newInt(this->Number::operator^(rhs));
	return newInt;
}

void Integer::print(ostream& os) const
{
	if (this->negative && !this->isZero())
		os << "-";
	for (int i = this->bigNum.size() - 1; i >= 0; i--) {
		os << this->bigNum[i];
		if (this->point) {
			if (this->point == i)
				return ;
		}
	}
	return ;
}

ostream& operator<<(ostream& os, const Integer& rhs)
{
	if (rhs.negative && !rhs.isZero())
		os << "-";
	for (int i = rhs.bigNum.size() - 1; i >= 0; i--) {
		os << rhs.bigNum[i];
		if (rhs.point) {
			if (rhs.point == i)
				return os;
		}
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

