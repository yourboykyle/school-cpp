#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Arithmetic {
public:
	Arithmetic() {}
	Arithmetic(int a, int b) {
		setNumbers(a, b);
	}
	void setNumbers(int a, int b) {
		num1 = a;
		num2 = b;
	}
	int addition() {
		return num1 + num2;
	}
	int subtraction() {
		return num1 - num2;
	}
	int multiplication() {
		return num1 * num2;
	}
	int division() {
		return num1 / num2;
	}
	int modulus() {
		return num1 % num2;
	}
private:
	int num1 = 0;
	int num2 = 1;
};

class Time {
public:
	Time() {}
	Time(int a, int b, int c) {
		setTime(a, b, c);
	}
	void setTime(int a, int b, int c) {
		hour = (a >= 0 && a < 24) ? a : 0;
		minute = (b >= 0 && b < 60) ? b : 0;
		second = (c >= 0 && c < 60) ? c : 0;
	}
	void printMilitary() {
		cout << (hour < 10 ? "0" : "") << hour << ":"
			<< (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second << endl;
	}
	void printStandard() {
		cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
			<< ":" << (minute < 10 ? "0" : "") << minute
			<< ":" << (second < 10 ? "0" : "") << second
			<< (hour < 12 ? " AM" : " PM") << endl;

	}
private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};

class Circle {
public:
	Circle() {}
	Circle(double r) {
		setRadius(r);
	}
	void setRadius(double r) {
		radius = r;
	}
	double getRadius() {
		return radius;
	}
	double circumference() {
		return 2 * 3.14159 * radius;
	}
	double area() {
		return 3.14159 * radius * radius;
	}
private:
	double radius = 0;
};

class Triangle {
public:
	Triangle() {}
	Triangle(double a, double b, double c) {
		setSides(a, b, c);
	}
	void setSides(double a, double b, double c) {
		side1 = a;
		side2 = b;
		side3 = c;
	}
	double perimeter() {
		return side1 + side2 + side3;
	}
	double area() {
		double s = perimeter() / 2;
		return sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}
private:
	double side1 = 0;
	double side2 = 0;
	double side3 = 0;
};

class Box {
public:
	Box() {}
	Box(double l, double w, double h) {
		setDimensions(l, w, h);
	}
	void setDimensions(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	double volume() {
		return length * width * height;
	}
	double surface_area() {
		return 2 * (length * width + length * height + width * height);
	}
private:
	double length = 0;
	double width = 0;
	double height = 0;
};

class Our_fav_n {
private:
	int n;

public:
	Our_fav_n(int num) : n(num) {}

	int sum_to_n() const {
		return (n * (n + 1)) / 2;
	}

	int sum_of_squares() const {
		return (n * (n + 1) * (2 * n + 1)) / 6;
	}

	int sum_of_cubes() const {
		int sum = sum_to_n();
		return sum * sum;
	}

	int factorial() const {
		int product = 1;
		for (int i = 1; i <= n; i++) {
			product *= i;
		}
		return product;
	}

	int sum_of_digits() const {
		int sum = 0, num = n;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}

	int number_of_digits() const {
		int digits = 0, num = n;
		while (num > 0) {
			digits++;
			num /= 10;
		}
		return digits;
	}

	int sum_of_divisors() const {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				sum += i;
			}
		}
		return sum;
	}

	int reverse_number() const {
		int reversed = 0, num = n;
		while (num > 0) {
			reversed = reversed * 10 + num % 10;
			num /= 10;
		}
		return reversed;
	}

	bool is_palindrome() const {
		return n == reverse_number();
	}

	bool is_prime() const {
		if (n <= 1) return false;
		for (int i = 2; i <= std::sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

	void print_prime_factors() const {
		int num = n;
		for (int i = 2; i <= num; i++) {
			while (num % i == 0) {
				std::cout << i << " ";
				num /= i;
			}
		}
		std::cout << std::endl;
	}
};

class Rectangle {
private:
	float length;
	float width;
public:
	Rectangle(float l = 1.0, float w = 1.0) {
		setLength(l);
		setWidth(w);
	}

	void setLength(float l) {
		if (l > 0.0 && l < 20.0) {
			length = l;
		}
		else {
			cout << "Invalid length. Must be between 0.0 and 20.0" << endl;
		}
	}

	void setWidth(float w) {
		if (w > 0.0 && w < 20.0) {
			width = w;
		}
		else {
			cout << "Invalid width. Must be between 0.0 and 20.0" << endl;
		}
	}

	float getLength() const {
		return length;
	}

	float getWidth() const {
		return width;
	}

	float area() const {
		return length * width;
	}

	float perimeter() const {
		return 2 * (length + width);
	}
};

class Box2 {
	friend float surface_area(const Box2& box);
private:
	float length;
	float width;
	float height;
public:
	Box2() {
		length = 1.0;
		width = 1.0;
		height = 1.0;

	}
	Box2(float l, float w, float h) {
		setLength(l);
		setWidth(w);
		setHeight(h);
	}
	void setLength(float l) {
		length = l;
	}
	void setWidth(float w) {
		width = w;
	}
	void setHeight(float h) {
		height = h;
	}
	float volume() {
		return length * width * height;
	}
};
float surface_area(const Box2& box) {
	return 2 * (box.length * box.width + box.length * box.height + box.width * box.height);
}

class Rational {
public:
	Rational(int a = 0, int b = 1) {
		numerator = a;
		denominator = b;

	}
	Rational addition(const Rational& amp) {
		Rational temp;
		temp.numerator = numerator * amp.denominator + denominator * amp.numerator;
		temp.denominator = denominator * amp.denominator;
		temp.reduction();
		return temp;

	}
	Rational subtraction(const Rational& amp) {
		Rational temp;
		temp.numerator = numerator * amp.denominator - denominator * amp.numerator;
		temp.denominator = denominator * amp.denominator;
		temp.reduction();
		return temp;


	}
	Rational multiplication(const Rational& amp) {
		Rational temp;
		temp.numerator = numerator * amp.numerator;
		temp.denominator = denominator * amp.denominator;
		temp.reduction();
		return temp;


	}
	Rational division(const Rational& amp) {
		Rational temp;
		temp.numerator = numerator * amp.denominator;
		temp.denominator = denominator * amp.numerator;
		temp.reduction();
		return temp;
	}
	void printRational(void) {
		if (denominator == 0) {
			cout << "\nCannot divide by zero!\n";
		}
		else if (numerator == 0) {
			cout << 0;
		}
		else {
			cout << numerator << '/' << denominator;
		}
	}
	void printRationalAsDouble(void) {
		cout << (double)numerator / (double)denominator;
	}
private:
	int numerator;
	int denominator;
	void reduction(void) {
		int largest;
		largest = (numerator > denominator) ? numerator : denominator;
		int gcd = 0;
		for (int loop = 2; loop <= largest; loop++) {
			if (numerator % loop == 0 && denominator % loop == 0) {
				gcd = loop;
			}
		}
		if (gcd != 0) {
			numerator /= gcd;
			denominator /= gcd;
		}
	}
};

class Complex {
public:
	Complex(double realPart = 0.0, double imaginaryPart = 0.0)
		: real(realPart), imaginary(imaginaryPart) {}

	Complex addition(const Complex& c) const {
		return Complex(real + c.real, imaginary + c.imaginary);
	}

	Complex subtraction(const Complex& c) const {
		return Complex(real - c.real, imaginary - c.imaginary);
	}

	Complex multiplication(const Complex& c) const {
		double newReal = (real * c.real) - (imaginary * c.imaginary);
		double newImaginary = (real * c.imaginary) + (imaginary * c.real);
		return Complex(newReal, newImaginary);
	}

	void print() const {
		cout << real;
		if (imaginary >= 0)
			cout << " + " << imaginary << "i";
		else
			cout << " - " << -imaginary << "i";
	}

private:
	double real;
	double imaginary;
};

class IntegerSet {
public:
	IntegerSet() {
		for (int i = 0; i <= 100; ++i) set[i] = 0;
	}

	IntegerSet UnionOfIntegerSets(const IntegerSet& other) const {
		IntegerSet unionSet;
		for (int i = 0; i <= 100; ++i) {
			unionSet.set[i] = set[i] | other.set[i];
		}
		return unionSet;
	}

	IntegerSet IntersectionOfIntegerSets(const IntegerSet& other) const {
		IntegerSet intersectionSet;
		for (int i = 0; i <= 100; ++i) {
			intersectionSet.set[i] = set[i] & other.set[i];
		}
		return intersectionSet;
	}

	void InsertElement(int element) {
		if (element >= 0 && element <= 100) {
			set[element] = 1;
		}
	}

	void DeleteElement(int element) {
		if (element >= 0 && element <= 100) {
			set[element] = 0;
		}
	}

	void SetPrint() const {
		bool isEmpty = true;
		for (int i = 0; i <= 100; ++i) {
			if (set[i] == 1) {
				cout << i << " ";
				isEmpty = false;
			}
		}
		if (isEmpty) {
			cout << "---";
		}
		cout << endl;
	}

	bool IsEqualTo(const IntegerSet& other) const {
		for (int i = 0; i <= 100; ++i) {
			if (set[i] != other.set[i]) {
				return false;
			}
		}
		return true;
	}

private:
	int set[101];
};

int main(int argc, char *argv[])
{
	cout << "--- Arithmetic ---\n";
	Arithmetic arithmetic;
	cout << "Addition: " << arithmetic.addition() << endl;
	cout << "Subtraction: " << arithmetic.subtraction() << endl;
	cout << "Multiplication: " << arithmetic.multiplication() << endl;
	cout << "Division: " << arithmetic.division() << endl;
	cout << "Modulus: " << arithmetic.modulus() << endl;

	cout << "\n--- Time ---\n";
	Time time;
	cout << "Uninitialized time:\n";
	time.printMilitary();
	time.printStandard();
	time.setTime(13, 27, 6);
	cout << "Initialized time:\n";
	time.printMilitary();
	time.printStandard();
	time.setTime(99, 99, 99);
	cout << "Invalid time:\n";
	time.printMilitary();
	time.printStandard();

	cout << "\n--- Circle ---\n";
	Circle circle(3);
	cout << "Radius: " << circle.getRadius() << endl;
	cout << "Circumference: " << circle.circumference() << endl;
	cout << "Area: " << circle.area() << endl;

	cout << "\n--- Triangle ---\n";
	Triangle triangle(1, 2, 3);
	cout << "Perimeter: " << triangle.perimeter() << endl;
	cout << "Area: " << triangle.area() << endl;

	cout << "\n--- Box ---\n";
	Box box(1, 2, 3);
	cout << "Volume: " << box.volume() << endl;
	cout << "Surface Area: " << box.surface_area() << endl;

	cout << "\n--- Our_fav_n ---\n";
	Our_fav_n myNumber(10);
	std::cout << "Sum to n: " << myNumber.sum_to_n() << std::endl;
	std::cout << "Sum of squares: " << myNumber.sum_of_squares() << std::endl;
	std::cout << "Sum of cubes: " << myNumber.sum_of_cubes() << std::endl;
	std::cout << "Factorial: " << myNumber.factorial() << std::endl;
	std::cout << "Sum of digits: " << myNumber.sum_of_digits() << std::endl;
	std::cout << "Number of digits: " << myNumber.number_of_digits() << std::endl;
	std::cout << "Sum of divisors: " << myNumber.sum_of_divisors() << std::endl;
	std::cout << "Reversed number: " << myNumber.reverse_number() << std::endl;
	std::cout << "Is palindrome: " << (myNumber.is_palindrome() ? "Yes" : "No") << std::endl;
	std::cout << "Is prime: " << (myNumber.is_prime() ? "Yes" : "No") << std::endl;
	std::cout << "Prime factors: ";
	myNumber.print_prime_factors();

	cout << "\n--- Rectangle ---\n";
	Rectangle rectangle;
	cout << "Length: " << rectangle.getLength() << endl;
	cout << "Width: " << rectangle.getWidth() << endl;
	cout << "Area: " << rectangle.area() << endl;
	cout << "Perimeter: " << rectangle.perimeter() << endl;
	rectangle.setLength(10);
	rectangle.setWidth(5);
	cout << "Length: " << rectangle.getLength() << endl;
	cout << "Width: " << rectangle.getWidth() << endl;
	cout << "Area: " << rectangle.area() << endl;
	cout << "Perimeter: " << rectangle.perimeter() << endl;

	cout << "\n--- Box 2 ---\n";
	Box2 box2(1, 2, 3);
	cout << "Volume: " << box2.volume() << endl;
	cout << "Surface Area: " << surface_area(box2) << endl;

	cout << "\n--- Rational ---\n";
	Rational r1(4, 5);
	Rational r2(2, 3);
	cout << "Rational 1: ";
	r1.printRational();
	cout << " = ";
	r1.printRationalAsDouble();
	cout << endl;
	cout << "Rational 2: ";
	r2.printRational();
	cout << " = ";
	r2.printRationalAsDouble();
	cout << endl;
	Rational r3 = r1.addition(r2);
	cout << "Addition: ";
	r3.printRational();
	cout << " = ";
	r3.printRationalAsDouble();
	cout << endl;
	Rational r4 = r1.subtraction(r2);
	cout << "Subtraction: ";
	r4.printRational();
	cout << " = ";
	r4.printRationalAsDouble();
	cout << endl;
	Rational r5 = r1.multiplication(r2);
	cout << "Multiplication: ";
	r5.printRational();
	cout << " = ";
	r5.printRationalAsDouble();
	cout << endl;
	Rational r6 = r1.division(r2);
	cout << "Division: ";
	r6.printRational();
	cout << " = ";
	r6.printRationalAsDouble();
	cout << endl;

	cout << "\n--- Complex ---\n";
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3 = c1.addition(c2);
	cout << "Addition: ";
	c3.print();
	cout << endl;
	Complex c4 = c1.subtraction(c2);
	cout << "Subtraction: ";
	c4.print();
	cout << endl;
	Complex c5 = c1.multiplication(c2);
	cout << "Multiplication: ";
	c5.print();
	cout << endl;

	cout << "\n--- IntegerSet ---\n";
	IntegerSet set1, set2;

	set1.InsertElement(10);
	set1.InsertElement(20);
	set1.InsertElement(30);

	set2.InsertElement(20);
	set2.InsertElement(40);
	set2.InsertElement(50);

	cout << "Set 1: ";
	set1.SetPrint();
	cout << "Set 2: ";
	set2.SetPrint();

	IntegerSet unionSet = set1.UnionOfIntegerSets(set2);
	cout << "Union: ";
	unionSet.SetPrint();

	IntegerSet intersectionSet = set1.IntersectionOfIntegerSets(set2);
	cout << "Intersection: ";
	intersectionSet.SetPrint();

	cout << "Set 1 is " << (set1.IsEqualTo(set2) ? "equal" : "not equal") << " to Set 2\n";

	set1.DeleteElement(10);
	cout << "Set 1 after deleting 10: ";
	set1.SetPrint();

	return 0;
}