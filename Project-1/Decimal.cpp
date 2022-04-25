#include "Decimal.h"

Decimal::Decimal() :Number()
{
	this->isInt = false;
}

Decimal::Decimal(const Number& rhs) : Number(rhs)
{
	this->isInt = false;
	fraction.molecular = *this;
	fraction.negative = this->negative;
	fraction.molecular.absNum();
}

Decimal::Decimal(const Decimal& rhs) : Number(rhs)
{
	this->isInt = false;
	fraction.molecular = rhs.fraction.molecular;
	fraction.denominator = rhs.fraction.denominator;
	fraction.negative = rhs.fraction.negative;
	fraction.molecular.absNum();
}

Decimal::Decimal(const string& rhs) : Number(rhs)
{
	this->isInt = false;
	fraction.molecular = *this;
	fraction.negative = this->negative;
	fraction.molecular.absNum();
}

Decimal::Decimal(const double& rhs) :Number(rhs)
{
	this->isInt = false;
	fraction.molecular = *this;
	fraction.negative = this->negative;
	fraction.molecular.absNum();
}

Decimal::Decimal(const char* rhs) : Number(rhs)
{
	this->isInt = false;
	fraction.molecular = *this;
	fraction.negative = this->negative;
	fraction.molecular.absNum();
}

Decimal& Decimal::operator=(const Decimal& rhs)
{
	this->isInt = false;
	this->Number::operator=(rhs);
	this->fraction = rhs.fraction;
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
	Fraction newFra(rhs);
	newDec.fraction = this->fraction + newFra;
	return newDec;
}

Decimal Decimal::operator-(const Integer& rhs)
{
	Decimal newDec(this->Number::operator-(rhs));
	Fraction newFra(rhs);
	newDec.fraction = this->fraction - newFra;
	return newDec;
}

Decimal Decimal::operator*(const Integer& rhs)
{
	Decimal newDec(this->Number::operator*(rhs));
	Fraction newFra(rhs);
	newDec.fraction = this->fraction * newFra;
	return newDec;
}

Decimal Decimal::operator/(const Integer& rhs)
{
	Decimal newDec(this->Number::operator/(rhs));
	Fraction newFra(rhs);
	newDec.fraction = this->fraction / newFra;
	return newDec;
}

Decimal Decimal::operator^(const Integer& rhs)
{
	Decimal temp(this->fraction.molecular / this->fraction.denominator);
	temp.negative = temp.fraction.negative;
	Decimal newDec(temp.Number::operator^(rhs));
	return newDec;
}

Decimal Decimal::operator+(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator+(rhs));
	newDec.fraction = this->fraction + rhs.fraction;
	return newDec;
}

Decimal Decimal::operator-(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator-(rhs));
	newDec.fraction = this->fraction - rhs.fraction;
	return newDec;
}

Decimal Decimal::operator*(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator*(rhs));
	newDec.fraction = this->fraction * rhs.fraction;
	return newDec;
}

Decimal Decimal::operator/(const Decimal& rhs)
{
	Decimal newDec(this->Number::operator/(rhs));
	newDec.fraction = this->fraction / rhs.fraction;
	return newDec;
}

Decimal Decimal::operator^(const Decimal& rhs)
{
	Decimal temp(this->fraction.molecular / this->fraction.denominator);
	temp.negative = temp.fraction.negative;
	Decimal newDec(temp.Number::operator^(rhs));
	return newDec;
}


Decimal operator+(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator+(rhs));
	Fraction newFra(lhs);
	newDec.fraction = newFra + rhs.fraction;
	return newDec;
}

Decimal operator-(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator-(rhs));
	Fraction newFra(lhs);
	newDec.fraction = newFra - rhs.fraction;
	return newDec;
}

Decimal operator*(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator*(rhs));
	Fraction newFra(lhs);
	newDec.fraction = newFra * rhs.fraction;
	return newDec;
}

Decimal operator/(Integer lhs, Decimal rhs)
{
	Decimal newDec(lhs.Number::operator/(rhs));
	Fraction newFra(lhs);
	newDec.fraction = newFra / rhs.fraction;
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
	Decimal molecular(this->fraction.molecular), mol(this->fraction.denominator), output;
	//output = molecular / mol;
	output = *this;
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
	Decimal molecular(rhs.fraction.molecular), mol(rhs.fraction.denominator), output;
	output = molecular / mol;
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
