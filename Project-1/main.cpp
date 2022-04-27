#include<vector>
#include<string>
#include <iostream>
#include "Number.h"
#include "Decimal.h"
#include "Integer.h"
#include <stack>
using namespace std;

typedef struct
{
	Number* num;
	bool isInt;
}NumBool;

typedef struct
{
	string name;
	Number* num;

}NumWithName;


vector<int> findd(char in) {
	vector<int> out;
	out.resize(2);//0數字1權重
	int time = 0;
	char opr[12] = { '(',')','=','=','+','-','*','/','^','^','!','!' };
	for (int i = 0; i < 12 + 1; i++) {


		if (i < 12) {
			if (in == opr[i]) {
				out.at(0) = i;

				break;
			}
		}
		else
		{
			out.at(0) = -1;
			out.at(1) = -1;
		}
		out.at(1) = i / 2;
	}
	return  out;

}
vector<string> Postfix(string in) {
	vector<int> number;
	vector<int> lastnumber;
	vector<string> out;
	stack<int> stack;
	bool wronginput = false;
	bool isnegetive = false;
	string opr[12] = { "(",")","=","=", "+", "-", "*", "/","^","^","!","!" };
	string temp;

	lastnumber.resize(2); lastnumber.at(0) = -1; lastnumber.at(1) = -1;

	int buf = -1;
	int time = 0;
	for (int i = 0; i < in.length(); i++) {
		number = findd(in[i]);
		isnegetive = lastnumber.at(0) != -1 && lastnumber.at(0) != 1 && number.at(0) == 5;



		if (number.at(0) != -1 && temp.size() != 0) {
			out.push_back(temp);
			temp.clear();
		}

		if (stack.size() == 0)
		{
			buf = -1;
		}


		if (number.at(0) == 0) {
			stack.push(number.at(0));
			buf = -1;
		}
		else if (isnegetive)//-
		{
			temp = temp + in[i];
			isnegetive = false;
		}
		else if (number.at(0) == 1) {

			time = stack.size();
			for (int j = 0; j < time; j++) {
				wronginput = true;
				if (stack.top() == 0) {
					wronginput = false;
					stack.pop();
					if (stack.size() != 0)buf = stack.top() / 2;
					break;
				}
				else
				{
					out.push_back(opr[stack.top()]);
					stack.pop();
					if (stack.size() != 0)buf = stack.top() / 2;
				}
			}
		}
		else if (number.at(0) == -1)
		{
			temp = temp + in[i];
		}
		else if (number.at(1) > buf)
		{
			stack.push(number.at(0));
			if (stack.size() != 0)buf = stack.top() / 2;
		}
		else if (number.at(1) <= buf)
		{
			time = stack.size();
			for (int k = 0; k < time; k++) {
				if (stack.size() != 0)buf = stack.top() / 2; else buf = -1;
				if (number.at(1) >= buf) {
					break;
				}
				else if (number.at(1) <= buf)
				{
					out.push_back(opr[stack.top()]);
					stack.pop();

				}
			}
			stack.push(number.at(0));
			if (stack.size() != 0)buf = stack.top() / 2;
		}
		lastnumber = number;
	}


	if (temp.size() != 0) {
		out.push_back(temp);
	}
	time = stack.size();
	for (int i = 0; i < time; i++)
	{
		if (stack.top() != 0) {
			out.push_back(opr[stack.top()]);
			stack.pop();
		}
	}


	return out;
}
void calculate(vector<NumWithName>& vars, vector<Number*>& numbers, string& input) {
	vector<string> postInput = Postfix(input);	//postInput: 中序轉後序後的資料
	cout << "postFix: ";
	for (int i = 0; i < postInput.size(); i++)
	{
		cout << postInput.at(i) << " ";
	}
	cout << endl;
	bool countNegative = false;	//奇數個負為true
	for (int i = 0; i < postInput.size(); i++) {
		if (postInput[i] == "+") {					//加法
			if (numbers.size() < 2)
				continue;
			//throw "輸入錯誤，缺少數值";
			Number* num1, * num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (*num1 + *num2);
			if (temp.isInteger()) {
				Integer* result = new Integer(temp);
				numbers.push_back(result);
			}
			else
			{
				Decimal* result = new Decimal(temp);
				numbers.push_back(result);
			}
			//delete num1, num2;
		}
		else if (postInput[i] == "-") {					//減法
			if (numbers.size() < 2) {					//bug: 1---5
				if (numbers.size() == 1) {
					if (!countNegative) {
						Number temp = "0", * num;
						num = numbers.at(numbers.size() - 1);
						numbers.erase(numbers.end() - 1);
						temp = temp - *num;
						if (temp.isInteger()) {
							Integer* result = new Integer(temp);
							numbers.push_back(result);
						}
						else
						{
							Decimal* result = new Decimal(temp);
							numbers.push_back(result);
						}
						//delete num;
					}
				}
				else {
					countNegative = !countNegative;
				}
			}
			else
			{
				Number* num1, * num2;
				num2 = numbers.at(numbers.size() - 1);
				numbers.erase(numbers.end() - 1);
				num1 = numbers.at(numbers.size() - 1);
				numbers.erase(numbers.end() - 1);

				Number temp = (*num1 - *num2);
				if (temp.isInteger()) {
					Integer* result = new Integer(temp);
					numbers.push_back(result);
				}
				else
				{
					Decimal* result = new Decimal(temp);
					numbers.push_back(result);
				}
				//delete num1, num2;
			}
		}
		else if (postInput[i] == "*") {					//乘法
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number* num1, * num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (*num1 * *num2);
			if (temp.isInteger()) {
				Integer* result = new Integer(temp);
				numbers.push_back(result);
			}
			else
			{
				Decimal* result = new Decimal(temp);
				numbers.push_back(result);
			}
			//delete num1, num2;
		}
		else if (postInput[i] == "/") {					//除法
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number* num1, * num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (*num1 / *num2);
			if (temp.isInteger()) {
				Integer* result = new Integer(temp);
				numbers.push_back(result);
			}
			else
			{
				Decimal* result = new Decimal(temp);
				numbers.push_back(result);
			}
			//delete num1, num2;
		}
		else if (postInput[i] == "^") {					//冪次
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number* num1, * num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (*num1 ^ *num2);
			if (temp.isInteger()) {
				Integer* result = new Integer(temp);
				numbers.push_back(result);
			}
			else
			{
				Decimal* result = new Decimal(temp);
				numbers.push_back(result);
			}
			//delete num1, num2;
		}
		else if (postInput[i] == "!") {					//階乘
			if (numbers.size() < 1)
				throw "輸入錯誤，缺少數值";
			Number* temp;
			temp = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			temp->factorial();
			if (temp->isInteger()) {
				Integer* result = new Integer(*temp);
				numbers.push_back(result);
			}
			else
			{
				Decimal* result = new Decimal(*temp);
				numbers.push_back(result);
			}
			//delete temp;
		}
		else if (postInput[i] == "=") {
			if (numbers.size() < 2)			//assign
				throw "輸入錯誤，缺少數值";
			Number* num1, * num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			if (num1->isInteger()) {	//是整數
				Integer* newNum = new Integer(*num2);
				*num1 = *newNum;
			}
			else
			{
				Decimal* newNum = new Decimal(*num2) ;
				*num1 = *newNum;
			}
			delete num2;
			//delete num1, num2;
		}
		else
		{
			bool isDigit = true;
			for (auto c : postInput[i]) {
				if ((c > '9' || c < '0') && c != '.' && c != '-' && c != '+') {
					isDigit = false;
					break;
				}
			}
			if (isDigit) {										//是數字還是變數
				if (postInput[i].find('.') == string::npos) {	//是整數
					Integer* intNum = new Integer(postInput[i]);
					if (countNegative) {
						Integer temp = "0";
						*intNum = temp - *intNum;
					}
					numbers.push_back(intNum);
				}
				else
				{
					Decimal* decNum = new Decimal(postInput[i]);
					if (countNegative) {
						Decimal temp = "0";
						*decNum = temp - *decNum;
					}
					numbers.push_back(decNum);
				}
			}
			else
			{
				bool findVar = false;
				for (const auto& var : vars) {
					if (postInput[i] == var.name) {
						numbers.push_back(var.num);
						findVar = true;
						break;
					}
				}
				if (!findVar) {
					throw "找不到變數";
				}
			}
		}
	}
}

int main() {
	vector<NumWithName> vars;
	string input;
	vector<Number*> numbers;
	cout << endl << "  大數計算機指令說明 : 可輸入任意不含空格之算式 ( '^'為次方運算、 '!'為階乘運算)" << endl << endl;;
	cout << "  變數宣告：   set(int / dec) 變數名稱   or   Set(int / dec) 變數名稱 = 運算式" << endl << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

	while (cin >> input)
	{
		try
		{
			numbers.clear();
			if (input == "set" || input == "Set") {
				NumWithName var;
				string type, val, dump;
				bool isInt = false;
				cin >> type;
				if (type == "Int" || type == "int" || type == "Integer" || type == "integer")
				{
					isInt = true;

				}
				else if (type == "Dec" || type == "dec" || type == "Decimal" || type == "decimal")
				{
					isInt = false;
				}
				else
				{
					getline(cin, dump);			//清除後面多餘的輸入
					cout << "錯誤的型態名稱" << endl;
					continue;
				}
				bool find = false;
				cin >> var.name;
				cin >> dump;
				cin >> val;
				calculate(vars, numbers, val);
				if (isInt) {
					Integer* newNum = new Integer(*numbers.back());
					var.num = newNum;
				}
				else {
					Decimal* newNum = new Decimal(*numbers.back());
					var.num = newNum;
				}
				for (auto& v : vars) {
					if (v.name == var.name) {
						delete v.num;
						v.num = var.num;
						find = true;
						break;
					}
				}
				if (!find)
					vars.push_back(var);
				numbers.clear();

			}
			else if (input == "assign" || input == "Assign") {

			}
			else											//純計算
			{
				//vector<string> postInput = Postfix(input);	//postInput: 中序轉後序後的資料
				//for (int i = 0; i < postInput.size(); i++)
				//{
				//	cout << postInput.at(i) << " ";
				//}
				//cout << endl;
				//bool countNegative = true;	//奇數個負為true
				//for (int i = 0; i < postInput.size(); i++) {
				//	if (postInput[i] == "+") {					//加法
				//		if (numbers.size() < 2)
				//			continue;
				//		//throw "輸入錯誤，缺少數值";
				//		Number* num1, * num2;
				//		num2 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		num1 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		Number temp = (*num1 + *num2);
				//		if (temp.isInteger()) {
				//			Integer* result = new Integer(temp);
				//			numbers.push_back(result);
				//		}
				//		else
				//		{
				//			Decimal* result = new Decimal(temp);
				//			numbers.push_back(result);
				//		}
				//		delete num1, num2;
				//	}
				//	else if (postInput[i] == "-") {					//減法
				//		if (numbers.size() < 2) {					//bug: 1---5
				//			if (numbers.size() == 1) {
				//				if (countNegative) {
				//					Number temp = "0", * num;
				//					num = numbers.at(numbers.size() - 1);
				//					numbers.erase(numbers.end() - 1);
				//					temp = temp - *num;
				//					if (temp.isInteger()) {
				//						Integer* result = new Integer(temp);
				//						numbers.push_back(result);
				//					}
				//					else
				//					{
				//						Decimal* result = new Decimal(temp);
				//						numbers.push_back(result);
				//					}
				//					delete num;
				//				}
				//			}
				//			else {
				//				countNegative = !countNegative;
				//			}
				//		}
				//		else
				//		{
				//			Number* num1, * num2;
				//			num2 = numbers.at(numbers.size() - 1);
				//			numbers.erase(numbers.end() - 1);
				//			num1 = numbers.at(numbers.size() - 1);
				//			numbers.erase(numbers.end() - 1);
				//			Number temp = (*num1 - *num2);
				//			if (temp.isInteger()) {
				//				Integer* result = new Integer(temp);
				//				numbers.push_back(result);
				//			}
				//			else
				//			{
				//				Decimal* result = new Decimal(temp);
				//				numbers.push_back(result);
				//			}
				//			delete num1, num2;
				//		}
				//	}
				//	else if (postInput[i] == "*") {					//乘法
				//		if (numbers.size() < 2)
				//			throw "輸入錯誤，缺少數值";
				//		Number* num1, * num2;
				//		num2 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		num1 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		Number temp = (*num1 * *num2);
				//		if (temp.isInteger()) {
				//			Integer* result = new Integer(temp);
				//			numbers.push_back(result);
				//		}
				//		else
				//		{
				//			Decimal* result = new Decimal(temp);
				//			numbers.push_back(result);
				//		}
				//		delete num1, num2;
				//	}
				//	else if (postInput[i] == "/") {					//除法
				//		if (numbers.size() < 2)
				//			throw "輸入錯誤，缺少數值";
				//		Number* num1, * num2;
				//		num2 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		num1 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		Number temp = (*num1 / *num2);
				//		if (temp.isInteger()) {
				//			Integer* result = new Integer(temp);
				//			numbers.push_back(result);
				//		}
				//		else
				//		{
				//			Decimal* result = new Decimal(temp);
				//			numbers.push_back(result);
				//		}
				//		delete num1, num2;
				//	}
				//	else if (postInput[i] == "^") {					//冪次
				//		if (numbers.size() < 2)
				//			throw "輸入錯誤，缺少數值";
				//		Number* num1, * num2;
				//		num2 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		num1 = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		Number temp = (*num1 ^ *num2);
				//		if (temp.isInteger()) {
				//			Integer* result = new Integer(temp);
				//			numbers.push_back(result);
				//		}
				//		else
				//		{
				//			Decimal* result = new Decimal(temp);
				//			numbers.push_back(result);
				//		}
				//		delete num1, num2;
				//	}
				//	else if (postInput[i] == "!") {					//階乘
				//		if (numbers.size() < 1)
				//			throw "輸入錯誤，缺少數值";
				//		Number* temp;
				//		temp = numbers.at(numbers.size() - 1);
				//		numbers.erase(numbers.end() - 1);
				//		temp->factorial();
				//		if (temp->isInteger()) {
				//			Integer* result = new Integer(*temp);
				//			numbers.push_back(result);
				//		}
				//		else
				//		{
				//			Decimal* result = new Decimal(*temp);
				//			numbers.push_back(result);
				//		}
				//		delete temp;
				//	}
				//	else
				//	{
				//		bool isDigit = true;
				//		for (auto c : postInput[i]) {
				//			if ((c > '9' || c < '0') && c != '.' && c != '-' && c != '+') {
				//				isDigit = false;
				//				break;
				//			}
				//		}
				//		if (isDigit) {										//是數字還是變數
				//			if (postInput[i].find('.') == string::npos) {	//是整數
				//				Integer* intNum = new Integer(postInput[i]);
				//				numbers.push_back(intNum);
				//			}
				//			else
				//			{
				//				Decimal* decNum = new Decimal(postInput[i]);
				//				numbers.push_back(decNum);
				//			}
				//		}
				//		else
				//		{
				//			bool findVar = false;
				//			for (const auto& var : vars) {
				//				if (postInput[i] == var.name) {
				//					numbers.push_back(var.num);
				//					findVar = true;
				//					break;
				//				}
				//			}
				//			if (!findVar) {
				//				throw "找不到變數";
				//			}
				//		}
				//	}
				//}
				calculate(vars, numbers, input);
				for (const auto& n : numbers) {
					cout << *(n) << endl;
				}
				numbers.clear();
			}
		}
		catch (const char* errorMessge)
		{
			numbers.clear();
			cout << errorMessge << endl;
		}
	}

}