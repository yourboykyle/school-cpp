#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Binary {
    friend ostream &operator<<(ostream &, const Binary &);
    friend istream &operator>>(istream &, Binary &);
public:
    Binary(int = 0);
    Binary operator+(const Binary &);
    Binary operator-(const Binary &);
    Binary operator*(const Binary &);
    Binary operator/(const Binary &);
    Binary &operator++();
    Binary &operator--();
    bool operator<(const Binary &);
    bool operator>(const Binary &);
    bool operator<=(const Binary &);
    bool operator>=(const Binary &);
    bool operator==(const Binary &);
    bool operator!=(const Binary &);

private:
    string DtoB(int);
    int BtoD(const string &);
    void updateBinary();
    string numberInBinary;
    int numberInDecimal;
};

// Constructor
Binary::Binary(int n) {
    numberInDecimal = n;
    numberInBinary = DtoB(n);
}

// Operator Overloads
Binary Binary::operator+(const Binary &b) {
    return Binary(numberInDecimal + b.numberInDecimal);
}

Binary Binary::operator-(const Binary &b) {
    return Binary(numberInDecimal - b.numberInDecimal);
}

Binary Binary::operator*(const Binary &b) {
    return Binary(numberInDecimal * b.numberInDecimal);
}

Binary Binary::operator/(const Binary &b) {
    if (b.numberInDecimal == 0) throw runtime_error("Division by zero.");
    return Binary(numberInDecimal / b.numberInDecimal);
}

Binary &Binary::operator++() {
    ++numberInDecimal;
    updateBinary();
    return *this;
}

Binary &Binary::operator--() {
    --numberInDecimal;
    updateBinary();
    return *this;
}

bool Binary::operator<(const Binary &b) {
    return numberInDecimal < b.numberInDecimal;
}

bool Binary::operator>(const Binary &b) {
    return numberInDecimal > b.numberInDecimal;
}

bool Binary::operator<=(const Binary &b) {
    return numberInDecimal <= b.numberInDecimal;
}

bool Binary::operator>=(const Binary &b) {
    return numberInDecimal >= b.numberInDecimal;
}

bool Binary::operator==(const Binary &b) {
    return numberInDecimal == b.numberInDecimal;
}

bool Binary::operator!=(const Binary &b) {
    return numberInDecimal != b.numberInDecimal;
}

// Private Methods
string Binary::DtoB(int n) {
    if (n == 0) return "0";
    string result;
    while (n > 0) {
        result += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int Binary::BtoD(const string &binary) {
    int result = 0;
    for (char c : binary) {
        if (c != '0' && c != '1') throw invalid_argument("Invalid binary format.");
        result = result * 2 + (c - '0');
    }
    return result;
}

void Binary::updateBinary() {
    numberInBinary = DtoB(numberInDecimal);
}

// Stream Operators
ostream &operator<<(ostream &output, const Binary &b) {
    output << b.numberInBinary;
    return output;
}

istream &operator>>(istream &input, Binary &b) {
    string binaryInput;
    input >> binaryInput;

    if (!all_of(binaryInput.begin(), binaryInput.end(), [](char c) { return c == '0' || c == '1'; })) {
        throw invalid_argument("Input must be a valid binary number.");
    }

    b.numberInBinary = binaryInput;
    b.numberInDecimal = b.BtoD(binaryInput);
    return input;
}

int main() {
    try {
        Binary b1, b2;
        cout << "Enter two binary numbers: ";
        cin >> b1 >> b2;

        cout << "b1 = " << b1 << endl;
        cout << "b2 = " << b2 << endl;

        cout << "b1 + b2 = " << b1 + b2 << endl;
        cout << "b1 - b2 = " << b1 - b2 << endl;
        cout << "b1 * b2 = " << b1 * b2 << endl;
        cout << "b1 / b2 = " << b1 / b2 << endl;

        ++b1;
        cout << "++b1 = " << b1 << endl;

        --b2;
        cout << "--b2 = " << b2 << endl;

        cout << "b1 < b2 = " << (b1 < b2 ? "true" : "false") << endl;
        cout << "b1 > b2 = " << (b1 > b2 ? "true" : "false") << endl;
        cout << "b1 <= b2 = " << (b1 <= b2 ? "true" : "false") << endl;
        cout << "b1 >= b2 = " << (b1 >= b2 ? "true" : "false") << endl;
        cout << "b1 == b2 = " << (b1 == b2 ? "true" : "false") << endl;
        cout << "b1 != b2 = " << (b1 != b2 ? "true" : "false") << endl;

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
