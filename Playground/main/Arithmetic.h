#pragma once

class Arithmetic {
public:
	Arithmetic(int, int);
	void setNumbers(int, int);
	int addition();
	int subtraction();
	int multiplication();
	int division();
	int modulus();
private:
	int num1;
	int num2;
};