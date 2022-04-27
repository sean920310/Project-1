#include "Number.h"


vector<int> findd_Number(char in) {
	vector<int> out;
	out.resize(2);//0數字1權重
	int time = 0;
	char opr[10] = { '(',')','+','-','*','/','^','^','!','!' };
	for (int i = 0; i < 10 + 1; i++) {


		if (i < 10) {
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
vector<string> Postfix_Number(string in) {
	vector<int> number;
	vector<int> lastnumber;
	vector<string> out;
	stack<int> stack;
	bool wronginput = false;
	string opr[10] = { "(",")", "+", "-", "*", "/","^","^","!","!" };
	string temp;

	lastnumber.resize(2); lastnumber.at(0) = -1; lastnumber.at(1) = -1;

	int buf = -1;
	int time = 0;
	for (int i = 0; i < in.length(); i++) {
		number = findd_Number(in[i]);

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
		else if (lastnumber.at(0) == 3 || lastnumber.at(0) == 2 && number.at(0) == 3)
		{
			temp = temp + in[i];
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
		else if (number.at(1) >= buf)
		{
			stack.push(number.at(0));
			if (stack.size() != 0)buf = stack.top() / 2;
		}
		else if (number.at(1) < buf)
		{
			time = stack.size();
			for (int k = 0; k < time; k++) {
				if (stack.size() != 0)buf = stack.top() / 2;
				if (number.at(1) >= buf) {
					break;
				}
				else if (number.at(1) < buf)
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
Number calculate(const string& input) {
	vector<Number> numbers;
	vector<string> postInput = Postfix_Number(input);	//postInput: 中序轉後序後的資料
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
			Number num1, num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (num1 + num2);
			numbers.push_back(temp);
		}
		else if (postInput[i] == "-") {					//減法
			if (numbers.size() < 2) {					//bug: 1---5
				if (numbers.size() == 1) {
					if (!countNegative) {
						Number temp = "0", num;
						num = numbers.at(numbers.size() - 1);
						numbers.erase(numbers.end() - 1);
						temp = temp - num;
						numbers.push_back(temp);
					}
				}
				else {
					countNegative = !countNegative;
				}
			}
			else
			{
				Number num1, num2;
				num2 = numbers.at(numbers.size() - 1);
				numbers.erase(numbers.end() - 1);
				num1 = numbers.at(numbers.size() - 1);
				numbers.erase(numbers.end() - 1);

				Number temp = (num1 - num2);
				numbers.push_back(temp);
			}
		}
		else if (postInput[i] == "*") {					//乘法
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number num1, num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (num1 * num2);
			numbers.push_back(temp);
		}
		else if (postInput[i] == "/") {					//除法
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number num1, num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (num1 / num2);
			numbers.push_back(temp);
		}
		else if (postInput[i] == "^") {					//冪次
			if (numbers.size() < 2)
				throw "輸入錯誤，缺少數值";
			Number num1, num2;
			num2 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);
			num1 = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			Number temp = (num1 ^ num2);
			numbers.push_back(temp);
		}
		else if (postInput[i] == "!") {					//階乘
			if (numbers.size() < 1)
				throw "輸入錯誤，缺少數值";
			Number temp;
			temp = numbers.at(numbers.size() - 1);
			numbers.erase(numbers.end() - 1);

			temp.factorial();
			numbers.push_back(temp);
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
				Number newNum = postInput[i];
				if (countNegative) {
					Number temp = "0";
					newNum = temp - newNum;
				}
				numbers.push_back(newNum);
			}
			else
			{
				throw "找不到變數";
			}
		}
	}
	return numbers.back();
}

void Number::clearZero()
{
	for (int i = this->bigNum.size() - 1; i > point; i--) {
		if (this->bigNum[i])
			break;
		this->bigNum.pop_back();
	}
	while (point)
	{
		if (this->bigNum[0])
			break;
		this->bigNum.erase(this->bigNum.begin());
		this->point--;
	}
	if (this->bigNum.size() == 1 && this->bigNum[0] == 0)
		this->negative = false;
}

bool Number::isZero() const
{
	Number num(*this);
	num.clearZero();
	return (num.bigNum.size() == 1 && num.bigNum[0] == 0);
}

void Number::pushLeft()
{
	bigNum.insert(bigNum.begin(), 0);
	point++;
}

void Number::pushRight()
{
	bigNum.push_back(0);
}

//=====================================****constructor****==========================================

Number::Number()
{
	fraction.resize(2);
	fraction[0] = "0";
	fraction[1] = "1";
	bigNum = { 0 };
	negative = false;
	point = 0;
	isInt = true;
}

Number::Number(const string& rhs)
{
	vector<int> newNum;
	bool hasOperator = false;
	int index;

	for (auto c : rhs) { //判斷是否是算式
		if ((c > '9' || c < '0') && c != '.' && c != '-') {
			hasOperator = true;
			break;
		}
	}

	index = rhs.find_last_of('-');
	if (index == -1) {
		this->negative = false;
	}
	else if (index == 0) {
		this->negative = true;
	}
	else
	{
		hasOperator = true;
	}

	index = rhs.find('.');
	if (index == -1) {
		this->point = 0;
	}
	else
	{
		if (!hasOperator)
			this->point = rhs.length() - index - 1;
	}

	if (hasOperator) {
		//todo calculate
		*this = calculate(rhs);
		newNum = this->bigNum;
	}
	else
	{
		int n;
		if (rhs[0] == '-') {
			n = 1;
		}
		else
		{
			n = 0;
		}
		for (int i = rhs.length() - 1; i >= n; i--) {
			if (rhs[i] != '.')
				newNum.push_back(rhs[i] - '0');
		}
	}
	if (this->point)
		this->isInt = false;
	this->bigNum = newNum;
	this->clearZero();

	Number temp = *this;
	temp.absNum();
	fraction.resize(2);
	fraction[0] = temp.toString();
	fraction[1] = "1";
}

Number::Number(const Number& rhs)
{
	this->fraction = rhs.fraction;
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	this->point = rhs.point;
	this->isInt = rhs.isInt;
}

Number::Number(const double& rhs)
{
	string num = to_string(rhs);
	Number newNum(num);
	*this = newNum;
}

Number::Number(const char* rhs)
{
	string temp = rhs;
	Number newNum = temp;
	*this = newNum;
}


//=====================================****計算****==========================================

void Number::factorial()
{
	this->clearZero();
	if (this->point) {
		throw "階乘不能有小數";
		return;
	}

	if (this->bigNum.size() == 1 && (this->bigNum[0] == 1 || this->bigNum[0] == 2))
		return;
	else if (this->bigNum.size() == 1 && this->bigNum[0] == 0) {
		this->bigNum[0] = 1;
		return;
	}
	else {
		unsigned int num = 0, carry = 0, temp;
		for (int i = this->bigNum.size() - 1; i >= 0; i--) {
			num = num * 10 + this->bigNum[i];
		}

		for (unsigned int i = num - 1; i >= 2; i--) {
			for (int j = 0; j < this->bigNum.size(); j++) {
				temp = bigNum[j] * i + carry;
				bigNum[j] = temp % 10;
				carry = temp / 10;
			}
			while (carry)
			{
				bigNum.push_back(carry % 10);
				carry /= 10;
			}
		}
	}
	this->clearZero();
	fraction[0] = this->toString();
	fraction[1] = "1";
	return;
}

Number& Number::operator=(const Number& rhs)
{
	this->fraction = rhs.fraction;
	this->bigNum = rhs.bigNum;
	this->negative = rhs.negative;
	this->point = rhs.point;
	this->isInt = rhs.isInt;
	return *this;
}

Number& Number::operator=(const double& rhs)
{
	Number newNum(rhs);
	*this = newNum;
	return *this;
}

Number Number::operator+(const Number& rhs)
{
	Number in1(*this), in2(rhs), Ans;

	int dd;
	int mosP = in1.point;
	if (in2.point > mosP) {
		mosP = in2.point;
		dd = mosP - in1.point;
		for (int i = 0; i < dd; i++) {
			in1.pushLeft();
		}
		in1.point = mosP;
	}
	else
	{
		dd = mosP - in2.point;
		for (int i = 0; i < dd; i++) {
			in2.pushLeft();
		}
		in2.point = mosP;
	}

	int max = in1.bigNum.size();
	if (in2.bigNum.size() > in1.bigNum.size()) {
		max = in2.bigNum.size();
	}

	int x, y, buf = 0, sum = 0;

	Ans.bigNum.resize(max);
	for (int i = 0; i < max; i++) {
		if (i > in1.bigNum.size() - 1)
		{
			x = 0;
		}
		else
		{
			x = in1.bigNum.at(i);
			if (in1.negative) {
				x = x * -1;
			}
		}
		if (i > in2.bigNum.size() - 1)
		{
			y = 0;
		}
		else
		{
			y = in2.bigNum.at(i);
			if (in2.negative) {
				y = y * -1;
			}
		}
		sum = x + y;
		Ans.bigNum.at(i) = sum;

	}
	//clea
	Ans.pushRight();

	sum = 0;
	for (int i = 0; i < Ans.bigNum.size(); i++)
	{
		sum = Ans.bigNum.at(i);
		sum = sum + buf;
		buf = 0;
		if (sum > 9) {
			while (sum > 9)
			{
				sum = sum - 10;
				buf = buf + 1;
			}
		}
		else if (sum < -9)
		{
			sum = sum + 10;
			buf = buf - 1;

		}

		Ans.bigNum.at(i) = sum;
	}


	int time = 0;
	for (int i = 0; i < Ans.bigNum.size(); i++)
	{
		time = Ans.bigNum.at(Ans.bigNum.size() - i - 1);
		if (time != 0) {

			break;
		}
	}
	Ans.negative = time < 0;
	if (time != 0) {

		buf = 0;
		Ans.pushRight();

		for (int i = 0; i < Ans.bigNum.size(); i++) {
			Ans.bigNum.at(i) = Ans.bigNum.at(i) + buf;
			buf = 0;
			if (Ans.bigNum.at(i) == 0) {

			}
			else if (Ans.bigNum.at(i) > 0 != !Ans.negative) {
				if (!Ans.negative) {
					while (Ans.bigNum.at(i) < 0)
					{
						Ans.bigNum.at(i) = Ans.bigNum.at(i) + 10;
						buf = buf - 1;
					}
				}
				else
				{
					while (Ans.bigNum.at(i) > 0)
					{
						Ans.bigNum.at(i) = Ans.bigNum.at(i) - 10;
						buf = buf + 1;
					}
				}

			}
			Ans.bigNum.at(i) = abs(Ans.bigNum.at(i));
		}

	}
	Ans.isInt = (this->isInt && rhs.isInt);
	Ans.point = mosP;
	Ans.clearZero();
	//fraction
	Ans.fraction = fraAdd(*this, rhs);
	return Ans;
}

Number Number::operator-(const Number& rhs)
{
	Number a(*this); Number b(rhs);
	b.negative = !b.negative;

	return a + b;
}

Number Number::operator*(const Number& rhs)
{
	Number num1(*this), num2(rhs), result;
	vector<int> tempNum(num1.bigNum.size() + num2.bigNum.size(), 0);
	result.bigNum = tempNum;
	result.negative = !(num1.negative == num2.negative);

	for (int i = 0; i < num1.bigNum.size(); i++) {
		for (int j = 0; j < num2.bigNum.size(); j++) {
			result.bigNum[i + j] += num1.bigNum[i] * num2.bigNum[j];
		}
	}
	int carry = 0;
	for (int i = 0; i < result.bigNum.size(); i++) {
		int temp = result.bigNum[i] + carry;
		result.bigNum[i] = temp % 10;
		carry = temp / 10;
	}

	result.isInt = this->isInt && rhs.isInt;
	result.point = num1.point + num2.point;
	result.clearZero();
	result.fraction = fraMul(*this, rhs);
	return result;
}

Number Number::operator/(const Number& rhs)
{
	Number num1(*this), num2(rhs), result;
	result.negative = !(num1.negative == num2.negative);
	result.isInt = this->isInt && rhs.isInt;
	num1.clearZero();
	num2.clearZero();

	if (num2.isZero()) {
		result.bigNum = { 0 };
		throw "除數不能為0";
		return result;
	}
	else if (num1.isZero()) {
		result.bigNum = { 0 };
		return result;
	}

	else
	{
		num1.negative = false;
		num2.negative = false;

		int time = 0;
		if (num1 < num2) {
			while (num1 < num2 || num1 == num2)
			{
				num2.bigNum.push_back(0);
				num2.point++;				//除10
				time--;
			}
			num2.bigNum.pop_back();
			num2.point--;					//乘10
			time++;
		}
		else {
			while (num1 > num2 || num2 == num1)
			{
				num2.bigNum.insert(num2.bigNum.begin(), 0);//乘10
				time++;
			}
			num2.bigNum.erase(num2.bigNum.begin());//除10
			time--;
		}

		int count = result.point;
		while (!num1.isZero() && (count <= 100||time>-100))
		{
			int n = 0;
			while (num1 > num2 || num2 == num1)
			{
				num1 = num1 - num2;
				n++;
			}
			Number temp;
			temp.negative = result.negative;
			temp.bigNum[0] = n;
			if (time >= 0) {
				for (int i = 0; i < time; i++) {
					temp.bigNum.insert(temp.bigNum.begin(), 0);
				}
			}
			else
			{
				for (int i = time; i < 0; i++) {
					temp.bigNum.push_back(0);
					temp.point++;
				}
			}
			result = result + temp;
			num2.bigNum.push_back(0);//除10
			num2.point++;
			time--;
			
			count++;
		}
	}

	if (result.isInt) {							//如果是integer
		for (int i = result.point; i > 0; i--) {
			result.bigNum.erase(result.bigNum.begin());
			result.point--;
		}
	}
	result.clearZero();
	result.fraction = fraDiv(*this, rhs);
	return result;
}

Number Number::operator^(const Number& rhs)
{
	//	 中國直式開方法
	//	 3			 __3______	<- root	
	//	+3			| 10'23.45	<- origin		index 是兩個數字的前面那個
	// -----		   9
	//	 6口 <-temp	--------------
	//	 ^			   1	<- sub
	//	subNum

	Number num1(*this), num2(rhs), result, origin, temp, root, sub, subNum, tempSubNum;
	bool neg = num2.negative;
	num2.negative = false;
	num1.clearZero();
	num2.clearZero();
	root = 1;
	if (num2.point) {
		if (num2.point == 1 && num2.bigNum[0] == 5) {	//開根號
			if (num1.negative) {
				throw "負數不能開根號";
				return Number();
			}
			origin = num1;
			root = 0;
			int index;
			if (int(origin.bigNum.size() - origin.point) % 2) {	//整數是不是基數
				sub.bigNum.insert(sub.bigNum.begin(), origin.bigNum[origin.bigNum.size() - 1]);
				sub.clearZero();
				index = origin.bigNum.size() - 2;
			}
			else
			{
				sub.bigNum.insert(sub.bigNum.begin(), origin.bigNum[origin.bigNum.size() - 1]);
				sub.bigNum.insert(sub.bigNum.begin(), origin.bigNum[origin.bigNum.size() - 2]);
				sub.clearZero();
				index = origin.bigNum.size() - origin.point - 3;
			}
			bool toPoint = false;
			while ((!sub.isZero() || !toPoint) && root.point < 100)
			{
				int i = 1;
				for (; i <= 10; i++) {		//找到平方數
					temp = i;
					tempSubNum = subNum;
					tempSubNum.bigNum.insert(tempSubNum.bigNum.begin(), 0);	//乘10
					tempSubNum.clearZero();
					tempSubNum = tempSubNum + temp;
					if (temp * tempSubNum > sub) {
						i--;
						temp = i;
						root.bigNum.insert(root.bigNum.begin(), i);
						if (toPoint) {
							root.point++;
						}
						subNum.bigNum.insert(subNum.bigNum.begin(), 0);	//乘10
						subNum = subNum + temp;
						subNum.clearZero();
						break;
					}
				}
				temp = i;
				sub = sub - (temp * subNum);					//sub
				subNum = subNum + temp;							//左邊直式結果
				subNum.clearZero();
				if (index - point < 0) {
					toPoint = true;
					origin.pushLeft();
					origin.pushLeft();
					index += 2;
				}
				sub.bigNum.insert(sub.bigNum.begin(), origin.bigNum[index]);
				sub.bigNum.insert(sub.bigNum.begin(), origin.bigNum[index - 1]);
				sub.clearZero();
				index -= 2;
			}
			root.clearZero();
		}
		for (int i = num2.point; i > 0; i--) {				//清除num2小數點
			num2.bigNum.erase(num2.bigNum.begin());
			num2.point--;
		}
	}
	result = 1;
	temp = 2;
	num2 = num2 / temp;
	int n = 0;
	while (!num2.point && !num2.isZero())			//num2是奇數
	{
		n++;
		num2 = num2 / temp;
	}
	num2 = num2 * temp;
	while (!num2.isZero())
	{
		result = result * num1;
		temp = 1;
		num2 = num2 - temp;
	}
	for (int i = 0; i < n; i++) {
		result = result * result;
	}
	result = result * root;

	if (neg) {
		temp = 1;
		if (!result.isZero()) {
			result = temp / result;
		}
	}

	result.isInt = this->isInt && rhs.isInt;
	result.clearZero();
	result.fraction = fraPow(*this, rhs);
	return result;
}

//=====================================****判斷式****==========================================

bool Number::operator==(const Number& rhs) const
{
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	return (num1.bigNum == num2.bigNum && num1.negative == num2.negative && num1.point == num2.point);
}

bool Number::operator<(const Number& rhs) const
{
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	if (this->negative != rhs.negative)
		return this->negative;							//左邊是負數右邊是正數
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point < num2.bigNum.size() - num2.point); //整數長度不同
	else
	{
		if (num1.point > num2.point) {		//補齊小數點位數
			for (int i = num1.point - num2.point; i > 0; i--)
				num2.pushLeft();
		}
		else
		{
			for (int i = num2.point - num1.point; i > 0; i--)
				num1.pushLeft();
		}

		if (this->negative) {
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return !(num1.bigNum[i] < num2.bigNum[i]);
			}
		}
		else
		{
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return (num1.bigNum[i] < num2.bigNum[i]);
			}
		}
	}
	return false;
}

bool Number::operator>(const Number& rhs) const
{
	Number num1(*this), num2(rhs);
	num1.clearZero();
	num2.clearZero();
	if (this->negative != rhs.negative)
		return !(this->negative);							//左邊是負數右邊是正數
	else if (num1.bigNum.size() - num1.point != num2.bigNum.size() - num2.point)
		return (num1.bigNum.size() - num1.point > num2.bigNum.size() - num2.point); //整數長度不同
	else
	{
		if (num1.point > num2.point) {		//補齊小數點位數
			for (int i = num1.point - num2.point; i > 0; i--)
				num2.pushLeft();
		}
		else
		{
			for (int i = num2.point - num1.point; i > 0; i--)
				num1.pushLeft();
		}

		if (this->negative) {
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return !(num1.bigNum[i] > num2.bigNum[i]);
			}
		}
		else
		{
			for (int i = num1.bigNum.size() - 1; i >= 0; i--) {
				if (num1.bigNum[i] != num2.bigNum[i])
					return (num1.bigNum[i] > num2.bigNum[i]);
			}
		}
	}
	return false;
}


//=====================================****輸入輸出****==========================================

void Number::print(ostream& os) const
{
	if (this->negative && !this->isZero())
		os << "-";
	for (int i = this->bigNum.size() - 1; i >= 0; i--) {
		os << this->bigNum[i];
		if (this->point) {
			if (this->point == i)
				os << '.';
		}
	}
}


ostream& operator<<(ostream& os, const Number& rhs)
{
	rhs.print(os);
	return os;
}

istream& operator>>(istream& is, Number& rhs)
{
	string temp;
	is >> temp;
	rhs = temp;
	return is;
}

//=====================================****分數****==========================================


vector<string> Number::fixFra()
{
	return vector<string>();
}

Number Number::absNum()
{
	this->negative = false;
	return *this;
}

bool Number::isInteger()
{
	return this->isInt;
}

bool Number::isNegative()
{
	return (this->negative);
}

string Number::toString()
{
	string result = "";
	for (int i = 0; i < this->bigNum.size(); i++) {
		result = to_string(this->bigNum[i]) + result;
		if (i + 1 == point) {
			result = "." + result;
		}
	}
	if (this->negative)
		result = "-" + result;

	return result;
}

vector<string> Number::fraAdd(const Number& lhs, const Number& rhs)
{
	vector<string> fra1 = lhs.fraction, fra2 = rhs.fraction;
	if (lhs.negative == rhs.negative) {
		fra1[0] = "(" + fra1[0] + "*" + fra2[1] + "+" + fra1[1] + "*" + fra2[0] + ")";
		fra1[1] = "(" + fra1[1] + "*" + fra2[1] + ")";
		//fra1.fix();
		return fra1;
	}
	else {
		if (lhs.negative) {
			return fraSub(rhs, lhs);
		}
		else {
			return fraSub(lhs, rhs);
		}
	}
}

vector<string> Number::fraSub(const Number& lhs, const Number& rhs)
{
	vector<string> fra1 = lhs.fraction, fra2 = rhs.fraction;
	if (lhs.negative == rhs.negative) {
		fra1[0] = "(" + fra1[0] + "*" + fra2[1] + "-" + fra1[1] + "*" + fra2[0] + ")";
		fra1[1] = "(" + fra1[1] + "*" + fra2[1] + ")";
		//fra1.fix();
		return fra1;
	}
	else {
		if (lhs.negative) {
			Number temp = lhs;
			temp.negative = false;
			return fraAdd(temp, rhs);
		}
		else {
			Number temp = rhs;
			temp.negative = false;
			return fraAdd(lhs, temp);
		}
	}
}

vector<string> Number::fraMul(const Number& lhs, const Number& rhs)
{
	vector<string> newFra;
	newFra.resize(2);
	newFra[0] = "(" + this->fraction[0] + "*" + rhs.fraction[0] + ")";
	newFra[1] = "(" + this->fraction[1] + "*" + rhs.fraction[1] + ")";
	return newFra;
}

vector<string> Number::fraDiv(const Number& lhs, const Number& rhs)
{
	vector<string> newFra;
	newFra.resize(2);
	newFra[0] = "(" + this->fraction[0] + "*" + rhs.fraction[1] + ")";
	newFra[1] = "(" + this->fraction[1] + "*" + rhs.fraction[0] + ")";
	return newFra;
}

vector<string> Number::fraPow(const Number& lhs, const Number& rhs)
{
	vector<string> newFra;
	Number temp = rhs;
	newFra.resize(2);
	newFra[0] = this->fraction[0] + "^" + temp.toString();
	newFra[1] = this->fraction[1] + "^" + temp.toString();
	return newFra;
}



