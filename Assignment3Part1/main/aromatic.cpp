#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class ARAR {
private:
    string aromaticNumber;

    static int romanToBaseValue(char roman) {
        unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        return romanValues[roman];
    }

    int calculateValue(const string &aromatic) const {
        int total = 0;
        int len = aromatic.size();
        for (size_t i = 0; i < len; i += 2) {
            int arabic = aromatic[i] - '0';
            int currentValue = arabic * romanToBaseValue(aromatic[i + 1]);
            if (i + 2 < len && romanToBaseValue(aromatic[i + 1]) < romanToBaseValue(aromatic[i + 3])) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
        }
        return total;
    }

public:
    ARAR(const string &aromatic) : aromaticNumber(aromatic) {}
    ARAR(int value) : aromaticNumber(to_string(value)) {}
    int getValue() const { return calculateValue(aromaticNumber); }
    string getAromaticNumber() const { return aromaticNumber; }

    ARAR operator+(const ARAR &other) const { return ARAR(getValue() + other.getValue()); }
    ARAR operator-(const ARAR &other) const { return ARAR(getValue() - other.getValue()); }
    ARAR operator*(const ARAR &other) const { return ARAR(getValue() * other.getValue()); }
    ARAR operator/(const ARAR &other) const {
        if (other.getValue() == 0) throw invalid_argument("Division by zero is undefined");
        return ARAR(getValue() / other.getValue());
    }
    ARAR operator%(const ARAR &other) const {
        if (other.getValue() == 0) throw invalid_argument("Modulus by zero is undefined");
        return ARAR(getValue() % other.getValue());
    }

    ARAR operator-() const { return ARAR(-getValue()); }
    ARAR& operator++() { *this = *this + ARAR(1); return *this; }
    ARAR operator++(int) { ARAR temp = *this; ++(*this); return temp; }
    ARAR& operator--() { *this = *this - ARAR(1); return *this; }
    ARAR operator--(int) { ARAR temp = *this; --(*this); return temp; }

    bool operator==(const ARAR &other) const { return getValue() == other.getValue(); }
    bool operator!=(const ARAR &other) const { return getValue() != other.getValue(); }
    bool operator<(const ARAR &other) const { return getValue() < other.getValue(); }
    bool operator<=(const ARAR &other) const { return getValue() <= other.getValue(); }
    bool operator>(const ARAR &other) const { return getValue() > other.getValue(); }
    bool operator>=(const ARAR &other) const { return getValue() >= other.getValue(); }

    friend ostream& operator<<(ostream &os, const ARAR &ar) {
        os << ar.getAromaticNumber();
        return os;
    }

    friend istream& operator>>(istream &is, ARAR &ar) {
        is >> ar.aromaticNumber;
        return is;
    }
};

void printOperationResult(const ARAR &num1, const string &operation, const ARAR &num2, const ARAR &result) {
    cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
}

int main() {
    string input1, input2;
    cout << "Enter the first ARAR number: ";
    cin >> input1;
    cout << "Enter the second ARAR number: ";
    cin >> input2;

    ARAR num1(input1), num2(input2);

    try {
        printOperationResult(num1, "+", num2, num1 + num2);
        printOperationResult(num1, "-", num2, num1 - num2);
        printOperationResult(num1, "*", num2, num1 * num2);
        printOperationResult(num1, "/", num2, num1 / num2);
        printOperationResult(num1, "%", num2, num1 % num2);
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}