#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

class Roman {
private:
    map<char, int> romanToIntMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    vector<pair<int, string>> intToRomanMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    int romanToInt(const string &roman) {
        int result = 0;
        for (int i = 0; i < roman.length(); i++) {
            if (i + 1 < roman.length() && romanToIntMap[roman[i]] < romanToIntMap[roman[i + 1]]) {
                result += romanToIntMap[roman[i + 1]] - romanToIntMap[roman[i]];
                i++;
            } else {
                result += romanToIntMap[roman[i]];
            }
        }
        return result;
    }

    string intToRoman(int value) const {
        if (value > 1000) return "CONCORDIA CUM VERITATE";
        string result;
        for (int i = 0; i < intToRomanMap.size(); i++) {
            while (value >= intToRomanMap[i].first) {
                result += intToRomanMap[i].second;
                value -= intToRomanMap[i].first;
            }
        }
        return result;
    }

public:
    Roman() : value(0) {}
    Roman(const string &roman) : value(romanToInt(roman)) {}
    Roman(int v) : value(v) {}

    string toRoman() const { return intToRoman(value); }

    Roman operator+(const Roman &other) const { return Roman(value + other.value); }
    Roman operator-(const Roman &other) const { return Roman(max(0, value - other.value)); }
    Roman operator*(const Roman &other) const { return Roman(value * other.value); }
    Roman operator/(const Roman &other) const {
        if (other.value == 0) throw invalid_argument("Division by zero");
        return Roman(value / other.value);
    }
    Roman operator%(const Roman &other) const {
        if (other.value == 0) throw invalid_argument("Division by zero");
        return Roman(value % other.value);
    }
    Roman operator-() const { return Roman(-value); }
    Roman& operator++() { ++value; return *this; }
    Roman operator++(int) { Roman temp = *this; ++value; return temp; }
    Roman& operator--() { value = max(0, value - 1); return *this; }
    Roman operator--(int) { Roman temp = *this; value = max(0, value - 1); return temp; }

    bool operator==(const Roman &other) const { return value == other.value; }
    bool operator!=(const Roman &other) const { return value != other.value; }
    bool operator<(const Roman &other) const { return value < other.value; }
    bool operator<=(const Roman &other) const { return value <= other.value; }
    bool operator>(const Roman &other) const { return value > other.value; }
    bool operator>=(const Roman &other) const { return value >= other.value; }

    friend ostream& operator<<(ostream &os, const Roman &roman) {
        os << roman.toRoman();
        return os;
    }

    friend istream& operator>>(istream &is, Roman &roman) {
        string input;
        is >> input;
        roman.value = roman.romanToInt(input);
        return is;
    }

private:
    int value;
};

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();

    for (int t = 0; t < testCases; t++) {
        string input;
        getline(cin, input);
        int plusPos = input.find('+');
        int equalsPos = input.find('=');
        string roman1 = input.substr(0, plusPos);
        string roman2 = input.substr(plusPos + 1, equalsPos - plusPos - 1);

        Roman num1(roman1);
        Roman num2(roman2);
        Roman result = num1 + num2;

        cout << input << result.toRoman() << endl;
        if (t < testCases - 1) cout << endl;
    }

    return 0;
}