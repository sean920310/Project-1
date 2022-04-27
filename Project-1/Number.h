#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Number
{
protected:
	vector<int> bigNum;
	bool negative = false;
	int point = 0;
	bool isInt = true;

	vector<string> fraction;	//0:だ 1:だダ

	void clearZero();		//盢俱计玡㎝计緇0睲埃
	bool isZero() const;	//琌0
	void pushLeft();		//计翴干0
	void pushRight();		//俱计玡干0

public:
	Number();
	Number(const string& rhs);
	Number(const Number& rhs);
	Number(const double& rhs);
	Number(const char* rhs);

	void factorial();

	Number& operator=(const Number& rhs);
	Number& operator=(const double& rhs);

	Number operator+(const Number& rhs);
	Number operator-(const Number& rhs);
	Number operator*(const Number& rhs);
	Number operator/(const Number& rhs);
	Number operator^(const Number& rhs);

	bool operator==(const Number& rhs) const;
	bool operator<(const Number& rhs) const;
	bool operator>(const Number& rhs) const;

	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Number& rhs);
	friend istream& operator>>(istream& is, Number& rhs);

	//だ计
	vector<string> fixFra();	//て虏程虏だ计
	Number absNum();
	bool isInteger();
	bool isNegative();
	string toString();
	vector<string> fraAdd(const Number& lhs, const Number& rhs);
	vector<string> fraSub(const Number& lhs, const Number& rhs);
	vector<string> fraMul(const Number& lhs, const Number& rhs);
	vector<string> fraDiv(const Number& lhs, const Number& rhs);
	vector<string> fraPow(const Number& lhs, const Number& rhs);
};

//typedef struct Fraction	//だ计
//{
//	Fraction& operator=(const Fraction& rhs)
//	{
//		this->molecular = rhs.molecular;
//		this->denominator = rhs.denominator;
//		this->negative = rhs.negative;
//		return *this;
//	}
//	Fraction operator+(const Fraction& rhs) {
//		Fraction fra1, fra2;
//		fra1 = *this;
//		fra2 = rhs;
//		if (fra1.negative == fra2.negative) {
//			fra1.molecular = fra1.molecular * fra2.denominator + fra1.denominator * fra2.molecular;
//			fra1.denominator = this->denominator * rhs.denominator;
//			//fra1.fix();
//			return fra1;
//		}
//		else {
//			if (fra1.negative) {
//				fra1.negative = false;
//				return (fra2 - fra1);
//			}
//			else {
//				fra2.negative = false;
//				return (fra1 - fra2);
//			}
//		}
//	}
//	Fraction operator-(const Fraction& rhs) {
//		Fraction fra1, fra2;
//		fra1 = *this;
//		fra2 = rhs;
//		if (fra1.negative == fra2.negative) {
//			fra1.molecular = fra1.molecular * fra2.denominator - fra1.denominator * fra2.molecular;
//			fra1.denominator = this->denominator * rhs.denominator;
//			if (fra1.molecular.isNegative()) {
//				fra1.molecular.absNum();
//				fra1.negative = true;
//			}
//			//fra1.fix();
//			return fra1;
//		}
//		else {
//			if (fra1.negative) {
//				fra1.negative = false;
//				fra1 = fra1 + fra2;
//				fra1.negative = true;
//				return fra1;
//			}
//			else {
//				fra2.negative = false;
//				return fra1 + fra2;
//			}
//		}
//	}
//	Fraction operator*(const Fraction& rhs) {
//		Fraction newFra;
//		newFra.molecular = this->molecular * rhs.molecular;
//		newFra.denominator = this->denominator * rhs.denominator;
//		newFra.negative = (this->negative ^ rhs.negative);
//		return newFra;
//	}
//	Fraction operator/(const Fraction& rhs) {
//		Fraction newFra;
//		newFra.molecular = this->molecular * rhs.denominator;
//		newFra.denominator = this->denominator * rhs.molecular;
//		newFra.negative = (this->negative ^ rhs.negative);
//		return newFra;
//	}
//	Fraction operator^(const Number& rhs) {
//		Fraction newFra;
//		newFra.molecular = this->molecular ^ rhs;
//		newFra.denominator = this->denominator ^ rhs;
//		newFra.negative = (this->negative);
//		return newFra;
//	}
//
//	Fraction() {
//		molecular = 0;
//		denominator = 1;
//		negative = false;
//	}
//	Fraction(Number num) {
//		molecular = num;
//		molecular.absNum();
//		denominator = 1;
//		negative = num.isNegative();
//	}
//	Fraction(const Fraction& rhs) {
//		this->molecular = rhs.molecular;
//		this->denominator = rhs.denominator;
//		this->negative = rhs.negative;
//	}
//
//	Number molecular; //だ
//	Number denominator;	//だダ
//
//	bool negative = false;
//
//}Fraction;
