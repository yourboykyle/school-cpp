#include <iostream>

using namespace std;

class Complex {
    friend ostream &operator<<(ostream&, const Complex &);
    friend istream &operator>>(istream&, const Complex &);
public:
    Complex( double = 0.0, double = 0.0 ); // constructor
    Complex operator+( const Complex &) ; // addition
    Complex operator-( const Complex &) ; // subtraction
    Complex operator*( const Complex &) ; // multiplication
    const Complex &operator=(const Complex &); // assignment
    bool operator==(Complex &);
    bool operator!=(Complex &);
private:
    double real; // real part
    double imaginary; // imaginary part
};

ostream &operator<<(ostream &output, const Complex &number) {
    output << "(" << number.real << ", " << number.imaginary << ")";
    return output;
}
istream &operator>>(istream &input, const Complex &number) {
    input.ignore();
    input >> number.real;
    input.ignore();
    input >> number.imaginary;
    return input;
}
Complex Complex::operator+( const Complex &operand2 ) {
    return Complex( real + operand2.real, imaginary + operand2.imaginary );
}
Complex Complex::operator-( const Complex &operand2 ) {
    return Complex( real - operand2.real, imaginary - operand2.imaginary );
}
Complex Complex::operator*( const Complex &operand2 ) {
    return Complex( real * operand2.real, imaginary * operand2.imaginary );
}
const Complex &Complex::operator=(const Complex &operand2 ) {
    real = operand2.real;
    imaginary = operand2.imaginary;
    return *this;
}
bool Complex::operator==(Complex &operand2) {
    return (real == operand2.real && imaginary == operand2.imaginary);
}
bool Complex::operator!=(Complex &operand2) {
    return (real != operand2.real || imaginary != operand2.imaginary);
}

int main() {
    Complex x, y, z;
    cout << "Enter a complex number in the form (a, b): ";
    cin >> x;
    cout << "Enter a complex number in the form (c, d): ";
    cin >> y;
    z = x + y;
    cout << x << " + " << y << " = " << z << endl;
    z = x - y;
    cout << x << " - " << y << " = " << z << endl;
    z = x * y;
    cout << x << " * " << y << " = " << z << endl;
    if (x == y) {
        cout << x << " is equal to " << y << endl;
    }
    if (x != y) {
        cout << x << " is not equal to " << y << endl;
    }

    return 0;
}