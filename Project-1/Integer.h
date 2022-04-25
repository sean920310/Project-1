#pragma once
#include "Number.h"

class Decimal;

class Integer: public Number
{
protected:
	void toInteger();
public:
	Integer();
	Integer(const Number& rhs);
	Integer(const Integer& rhs);
	Integer(const string& rhs);
	Integer(const double& rhs);
	Integer(const char* rhs);

	Integer& operator=(const Integer& rhs);
	Integer& operator=(const char* rhs);
	Integer& operator=(const string& rhs);
	Integer& operator=(const double& rhs);

	Integer operator+(const Integer& rhs);
	Integer operator-(const Integer& rhs);
	Integer operator*(const Integer& rhs);
	Integer operator/(const Integer& rhs);
	Integer operator^(const Integer& rhs);

	virtual void print(ostream& os) const override;
	friend ostream& operator<<(ostream& os, const Integer& rhs);
	friend istream& operator>>(istream& is, Integer& rhs);
};

