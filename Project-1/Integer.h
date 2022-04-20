#pragma once
class Decimal;
#include "Number.h"
#include "Decimal.h"

class Integer: public Number
{
protected:
	void toInteger();
public:
	Integer();
	Integer(const Number& rhs);
	Integer(const Integer& rhs);
	Integer(const string& rhs);
	Integer(const char* rhs);

	Integer& operator=(const Integer& rhs);
	Integer& operator=(const char* rhs);
	Integer& operator=(const string& rhs);

	Integer operator+(const Integer& rhs);
	Integer operator-(const Integer& rhs);
	Integer operator*(const Integer& rhs);
	Integer operator/(const Integer& rhs);
	Integer operator^(const Integer& rhs);

	friend Decimal operator+(Integer lhs, Decimal rhs);
	friend Decimal operator-(Integer lhs, Decimal rhs);
	friend Decimal operator*(Integer lhs, Decimal rhs);
	friend Decimal operator/(Integer lhs, Decimal rhs);
	friend Decimal operator^(Integer lhs, Decimal rhs);

	
	friend ostream& operator<<(ostream& os, const Integer& rhs);
	friend istream& operator>>(istream& is, Integer& rhs);
};

