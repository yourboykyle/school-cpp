#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class ARAR {
private:
    string aromaticNumber;

    static int romanToBaseValue(char roman) {
        // For converting between base 10 and roman numerals
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
    // Constructor, assigns the aromatic number to aromticNumber
    ARAR(const string &aromatic) : aromaticNumber(aromatic) {}

    int getValue() const {
        return calculateValue(aromaticNumber);
    }

    string getAromaticNumber() const {
        return aromaticNumber;
    }

    // Operator overloading functions
    int operator+(const ARAR &other) const {
        return getValue() + other.getValue();
    }

    int operator-(const ARAR &other) const {
        return getValue() - other.getValue();
    }

    int operator*(const ARAR &other) const {
        return getValue() * other.getValue();
    }

    int operator/(const ARAR &other) const {
        if (other.getValue() == 0) {
            throw invalid_argument("Division by zero is undefined");
        }
        return getValue() / other.getValue();
    }

    int operator%(const ARAR &other) const {
        if (other.getValue() == 0) {
            throw invalid_argument("Modulus by zero is undefined");
        }
        return getValue() % other.getValue();
    }
};

void printOperationResult(const ARAR &num1, const string &operation, const ARAR &num2, int result) {
    cout << num1.getAromaticNumber() << " " << operation << " " << num2.getAromaticNumber()
         << " = " << result << endl;
}

int main() {
    cout << "Enter the first ARAR number: ";
    string input1;
    cin >> input1;

    cout << "Enter the second ARAR number: ";
    string input2;
    cin >> input2;

    ARAR num1(input1);
    ARAR num2(input2);

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