#pragma once
#include "Number.h"
#include "Integer.h"

class Integer;

class Decimal:public Number
{
public:
	Decimal();
	Decimal(const Number& rhs);
	Decimal(const Decimal& rhs);
	Decimal(const string& rhs);
	Decimal(const double& rhs);
	Decimal(const char* rhs);

	Decimal& operator=(const Decimal& rhs);
	Decimal& operator=(const char* rhs);
	Decimal& operator=(const string& rhs);
	Decimal& operator=(const double& rhs);
	
	Decimal operator+(const Integer& rhs);
	Decimal operator-(const Integer& rhs);
	Decimal operator*(const Integer& rhs);
	Decimal operator/(const Integer& rhs);
	Decimal operator^(const Integer& rhs);

	Decimal operator+(const Decimal& rhs);
	Decimal operator-(const Decimal& rhs);
	Decimal operator*(const Decimal& rhs);
	Decimal operator/(const Decimal& rhs);
	Decimal operator^(const Decimal& rhs);

	friend Decimal operator+(Integer lhs, Decimal rhs);
	friend Decimal operator-(Integer lhs, Decimal rhs);
	friend Decimal operator*(Integer lhs, Decimal rhs);
	friend Decimal operator/(Integer lhs, Decimal rhs);
	friend Decimal operator^(Integer lhs, Decimal rhs);

	virtual void print(ostream& os) const override;
	friend ostream& operator<<(ostream& os, const Decimal& rhs);
	friend istream& operator>>(istream& is, Decimal& rhs);
};


