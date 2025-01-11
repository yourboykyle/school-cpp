#include <iostream>
#include <string>
#include <stdexcept>

class Octal {
private:
    int value;

    bool isValidOctal(const std::string& octalStr) const {
        for (char ch : octalStr) {
            if (ch < '0' || ch > '7') return false;
        }
        return true;
    }

    std::string decimalToOctal(int n) const {
        if (n == 0) return "";
        return decimalToOctal(n / 8) + std::to_string(n % 8);
    }

public:
    Octal() : value(0) {}
    Octal(int decimalValue) : value(decimalValue) {}
    Octal(const std::string& octalStr) {
        if (!isValidOctal(octalStr)) throw std::invalid_argument("Invalid octal number");
        value = std::stoi(octalStr, nullptr, 8);
    }

    Octal operator-() const { return Octal(-value); }
    Octal& operator++() {
        ++value;
        return *this;
    }
    Octal operator++(int) {
        Octal temp = *this;
        ++value;
        return temp;
    }

    Octal operator+(const Octal& other) const { return Octal(value + other.value); }
    Octal operator-(const Octal& other) const { return Octal(value - other.value); }
    Octal operator*(const Octal& other) const { return Octal(value * other.value); }
    Octal operator/(const Octal& other) const {
        if (other.value == 0) throw std::invalid_argument("Division by zero");
        return Octal(value / other.value);
    }
    Octal operator%(const Octal& other) const {
        if (other.value == 0) throw std::invalid_argument("Modulo by zero");
        return Octal(value % other.value);
    }

    bool operator==(const Octal& other) const { return value == other.value; }
    bool operator!=(const Octal& other) const { return value != other.value; }
    bool operator<(const Octal& other) const { return value < other.value; }
    bool operator<=(const Octal& other) const { return value <= other.value; }
    bool operator>(const Octal& other) const { return value > other.value; }
    bool operator>=(const Octal& other) const { return value >= other.value; }

    friend std::ostream& operator<<(std::ostream& os, const Octal& oct) {
        if (oct.value == 0) {
            os << "0";
        } else {
            os << oct.decimalToOctal(std::abs(oct.value));
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Octal& oct) {
        std::string octalStr;
        is >> octalStr;
        if (!oct.isValidOctal(octalStr)) throw std::invalid_argument("Invalid octal number");
        oct.value = std::stoi(octalStr, nullptr, 8);
        return is;
    }
};

int main() {
    Octal o1("17");
    Octal o2(10);

    std::cout << "o1: " << o1 << std::endl;
    std::cout << "o2: " << o2 << std::endl;

    Octal o3 = o1 + o2;
    std::cout << "o1 + o2: " << o3 << std::endl;

    Octal o4 = o1 - o2;
    std::cout << "o1 - o2: " << o4 << std::endl;

    std::cout << "Is o1 > o2? " << (o1 > o2) << std::endl;

    ++o1;
    std::cout << "After increment, o1: " << o1 << std::endl;

    std::cout << "Enter an octal number: ";
    Octal o5;
    std::cin >> o5;
    std::cout << "You entered: " << o5 << std::endl;

    return 0;
}