#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <algorithm>

using namespace std;

class Factorial {
private:
    int n;

    bool is_prime(int num) const {
        if (num <= 1) return false;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

public:
    Factorial(int num) : n(num) {}

    long long factorial() const {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    long long primorial() const {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            if (is_prime(i)) {
                result *= i;
            }
        }
        return result;
    }

    long long double_factorial() const {
        long long result = 1;
        for (int i = (n % 2 == 0 ? 2 : 1); i <= n; i += 2) {
            result *= i;
        }
        return result;
    }

    long long fractorial() const {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = lcm(result, static_cast<long long>(i));
        }
        return result;
    }

    int next_prime() const {
        int candidate = n + 1;
        while (!is_prime(candidate)) {
            candidate++;
        }
        return candidate;
    }

    int num_of_factors(int prime) const {
        if (!is_prime(prime)) return 0;
        int count = 0;
        int p = prime;
        while (p <= n) {
            count += n / p;
            p *= prime;
        }
        return count;
    }

    void product_of_primes() const {
        unsigned long long factorial_result = factorial();
        unsigned long long temp = factorial_result;

        std::cout << n << "! = ";
        bool first = true;

        for (int i = 2; i <= temp; i++) {
            while (is_prime(i) && temp % i == 0) {
                if (!first) std::cout << " * ";
                std::cout << i;
                temp /= i;
                first = false;
            }
        }
        std::cout << std::endl;
    }
};

class Algebra {
private:
    int a, b;

    int gcd_recursive(int x, int y) {
        return y == 0 ? x : gcd_recursive(y, x % y);
    }

    int lcm_recursive(int x, int y) {
        return (x * y) / gcd_recursive(x, y);
    }

public:
    Algebra(int x = 0, int y = 0) : a(x), b(y) {}

    void setValues(int x, int y) {
        a = x;
        b = y;
    }

    int gcd_finder() {
        int x = a, y = b;
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    int lcm_finder() {
        return (a * b) / gcd_finder();
    }

    int gcd_finder_recursive() {
        return gcd_recursive(a, b);
    }

    int lcm_finder_recursive() {
        return lcm_recursive(a, b);
    }

    int slow_product() {
        int result = 0;
        int x = abs(a), y = abs(b);
        for (int i = 0; i < y; ++i) {
            result += x;
        }
        if ((a < 0 && b >= 0) || (a >= 0 && b < 0)) {
            result = -result;
        }
        return result;
    }
};

class BaseConverter {
public:
    static int toDecimal(const string& number, int base) {
        int decimal = 0;
        int power = 0;
        for (int i = number.size() - 1; i >= 0; --i) {
            char digit = number[i];
            int value = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'A' + 10;
            decimal += value * pow(base, power++);
        }
        return decimal;
    }

    static string fromDecimal(int number, int base) {
        string result = "";
        while (number > 0) {
            int remainder = number % base;
            result += (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
            number /= base;
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }

    static string convert(const string& number, int fromBase, int toBase) {
        int decimal = toDecimal(number, fromBase);
        return fromDecimal(decimal, toBase);
    }
};

class Matrix {
private:
    double mat[3][3];

public:
    Matrix(double input[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = input[i][j];
            }
        }
    }

    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << std::setw(8) << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix addition(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix scalar_multiply(double scalar) const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.mat[i][j] = mat[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix multiplication(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.mat[i][j] = mat[j][i];
            }
        }
        return result;
    }

    bool check_if_symmetric() const {
        Matrix transposed = transpose();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (mat[i][j] != transposed.mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool check_if_inverse(const Matrix& other) const {
        Matrix identity;
        for (int i = 0; i < 3; ++i) {
            identity.mat[i][i] = 1;
        }

        Matrix product = multiplication(other);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (std::abs(product.mat[i][j] - identity.mat[i][j]) > 1e-9) {
                    return false;
                }
            }
        }
        return true;
    }

    double determinant() const {
        return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
            mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
            mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    }
};

int main() {
    int num;
	cout << "=== Factorial ===\n";
    cout << "Enter a number: ";
    cin >> num;

    Factorial fact(num);

    cout << "Factorial: " << fact.factorial() << endl;
    cout << "Primorial: " << fact.primorial() << endl;
    cout << "Double Factorial: " << fact.double_factorial() << endl;
    cout << "Fractorial: " << fact.fractorial() << endl;
    cout << "Next Prime: " << fact.next_prime() << endl;

    int prime;
    cout << "Enter a prime number to count its factors in " << num << "!: ";
    cin >> prime;
    cout << "Number of factors of " << prime << ": " << fact.num_of_factors(prime) << endl;

    cout << "Product of primes representation of " << num << "!:" << endl;
    fact.product_of_primes();

    Algebra algebra(12, 18);
	cout << "=== Algebra ===\n";
    cout << "GCD (Iterative): " << algebra.gcd_finder() << endl;
    cout << "LCM (Iterative): " << algebra.lcm_finder() << endl;
    cout << "GCD (Recursive): " << algebra.gcd_finder_recursive() << endl;
    cout << "LCM (Recursive): " << algebra.lcm_finder_recursive() << endl;
    cout << "Slow Product: " << algebra.slow_product() << endl;

    cout << "=== Base Converter ===\n";
    string binary = "1010";
    int decimal = BaseConverter::toDecimal(binary, 2);
    string hex = BaseConverter::fromDecimal(decimal, 16);

    cout << "Binary (" << binary << ") to Decimal: " << decimal << endl;
    cout << "Decimal (" << decimal << ") to Hex: 0x" << hex << endl;

    string baseConversion = BaseConverter::convert(binary, 2, 16);
    cout << "Binary (" << binary << ") to Hex (Direct): 0x" << baseConversion << endl;

	cout << "=== Matrix ===\n";
    double matA[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    double matB[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    Matrix A(matA);
    Matrix B(matB);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "\nMatrix B:\n";
    B.print();

    Matrix sum = A.addition(B);
    std::cout << "\nA + B:\n";
    sum.print();

    Matrix scalarMult = A.scalar_multiply(2);
    std::cout << "\n2 * A:\n";
    scalarMult.print();

    Matrix product = A.multiplication(B);
    std::cout << "\nA * B:\n";
    product.print();

    Matrix transposeA = A.transpose();
    std::cout << "\nTranspose of A:\n";
    transposeA.print();

    std::cout << "\nIs A symmetric? " << (A.check_if_symmetric() ? "Yes" : "No") << "\n";

    std::cout << "\nDeterminant of A: " << A.determinant() << "\n";

    return 0;
}