#include <iostream>
#include <iomanip>

using namespace std;

class PhoneNumber {
    friend ostream &operator<<(ostream&, const PhoneNumber &);
    friend istream &operator>>(istream&, PhoneNumber &);
private:
    char areaCode[ 4 ]; // 3-digit area code and null
    char exchange[ 4 ]; // 3-digit exchange and null
    char line[ 5 ]; // 4-digit line and null
};

ostream &operator<<(ostream &output, const PhoneNumber &number) {
    output << "(" << number.areaCode << ") "
           << number.exchange << "-" << number.line;
    return output;
}
istream &operator>>(istream &input, PhoneNumber &number) {
    input.ignore();
    input >> setw(4) >> number.areaCode;
    input.ignore(2);
    input >> setw(4) >> number.exchange;
    input.ignore();
    input >> setw(5) >> number.line;
    return input;
}

int main() {
    PhoneNumber phone;
    cout << "Enter phone number in the form (123) 456-7890:" << endl;
    cin >> phone;
    cout << "The phone number entered was: ";
    cout << phone << endl;

    return 0;
}