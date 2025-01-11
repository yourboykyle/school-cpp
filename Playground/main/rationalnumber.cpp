#include <iostream>

using namespace std;

class Rational {
    friend ostream &operator<<( ostream &, Rational &);
    friend istream &operator>>(istream &, Rational &);
public:
    Rational (int n = 0, int d = 1);
    Rational operator+(const Rational &);
    Rational operator-(const Rational &);
    Rational operator*(const Rational &);
    Rational operator/(const Rational &);
    bool operator<( Rational &);
    bool operator>( Rational &);
    bool operator==( Rational &);
    void printRational ();
private:
    int numerator;
    int denominator;
};

Rational::Rational(int n, int d) {
    numerator = n;
    denominator = d;
}
Rational Rational::operator+(const Rational &r) {
    Rational temp;
    temp.numerator = numerator * r.denominator + denominator * r.numerator;
    temp.denominator = denominator * r.denominator;
    return temp;
}
Rational Rational::operator-(const Rational &r) {
    Rational temp;
    temp.numerator = numerator * r.denominator - denominator * r.numerator;
    temp.denominator = denominator * r.denominator;
    return temp;
}
Rational Rational::operator*(const Rational &r) {
    Rational temp;
    temp.numerator = numerator * r.numerator;
    temp.denominator = denominator * r.denominator;
    return temp;
}
Rational Rational::operator/(const Rational &r) {
    Rational temp;
    temp.numerator = numerator * r.denominator;
    temp.denominator = denominator * r.numerator;
    return temp;
}
bool Rational::operator<( Rational &r) {
    return (numerator * r.denominator < denominator * r.numerator);
}
bool Rational::operator>( Rational &r) {
    return (numerator * r.denominator > denominator * r.numerator);
}
bool Rational::operator==( Rational &r) {
    return (numerator * r.denominator == denominator * r.numerator);
}

void Rational::printRational() {
    cout << numerator << "/" << denominator;
}

ostream &operator<<( ostream &output, Rational &r) {
    output << r.numerator << "/" << r.denominator;
    return output;
}
istream &operator>>(istream &input, Rational &r) {
    input >> r.numerator >> r.denominator;
    return input;
}

int main() {
    Rational r1(1, 2), r2(1, 3), r3;
    r3 = r1 + r2;
    cout << r1 << " + " << r2 << " = " << r3 << endl;
    r3 = r1 - r2;
    cout << r1 << " - " << r2 << " = " << r3 << endl;
    r3 = r1 * r2;
    cout << r1 << " * " << r2 << " = " << r3 << endl;
    r3 = r1 / r2;
    cout << r1 << " / " << r2 << " = " << r3 << endl;
    if (r1 < r2) {
        cout << r1 << " < " << r2 << endl;
    }
    if (r1 > r2) {
        cout << r1 << " > " << r2 << endl;
    }
    if (r1 == r2) {
        cout << r1 << " == " << r2 << endl;
    }
    return 0;
}