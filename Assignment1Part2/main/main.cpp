#include <iostream>

using namespace std;

void test_one();
void test_two();
void test_three();

int onea(int n, bool recursive);
int oneb(int n, bool recursive);
int onec(int n, bool recursive);
int oned(int n, bool recursive);
int onee(int n, bool recursive);
int onef(int n, bool recursive);
int oneg(int n, bool recursive);
int oneh(int n, bool recursive);
bool onei(int n, bool recursive);
bool onej(int n, bool recursive);
bool onek(int n, bool recursive);
void onel(int n, bool recursive);

int twoa(int a, int b, bool recursive);
int twob(int a, int b, bool recursive);
int twoc(int a, int b, bool recursive);
int twod(int a, int b, bool recursive);

int decimal_to_binary(int n, bool recursive);
int binary_to_decimal(int n, bool recursive);
int decimal_to_octal(int n, bool recursive);
int octal_to_decimal(int n, bool recursive);

int main() {
    test_one();
    test_two();
    test_three();

    return 0;
}

void test_one() {
    int n = 5;
    int num = 12345;

    cout << "Sum of integers from 1 to " << n << ": " << onea(n, false) << endl;
    cout << "Sum of integers from 1 to " << n << " (Recursive): " << onea(n, true) << endl;

    cout << "Sum of squares from 1 to " << n << ": " << oneb(n, false) << endl;
    cout << "Sum of squares from 1 to " << n << " (Recursive): " << oneb(n, true) << endl;

    cout << "Sum of cubes from 1 to " << n << ": " << onec(n, false) << endl;
    cout << "Sum of cubes from 1 to " << n << " (Recursive): " << onec(n, true) << endl;

    cout << "Factorial of " << n << ": " << oned(n, false) << endl;
    cout << "Factorial of " << n << " (Recursive): " << oned(n, true) << endl;

    cout << "Sum of digits of " << num << ": " << onee(num, false) << endl;
    cout << "Sum of digits of " << num << " (Recursive): " << onee(num, true) << endl;

    cout << "Number of digits of " << num << ": " << onef(num, false) << endl;
    cout << "Number of digits of " << num << " (Recursive): " << onef(num, true) << endl;

    cout << "Sum of divisors of " << n << ": " << oneg(n, false) << endl;
    cout << "Sum of divisors of " << n << " (Recursive): " << oneg(n, true) << endl;

    cout << "Reverse of " << num << ": " << oneh(num, false) << endl;
    cout << "Reverse of " << num << " (Recursive): " << oneh(num, true) << endl;

    int palindromeTest = 12321;
    cout << "Is " << palindromeTest << " a palindrome?: " << onei(palindromeTest, false) << endl;
    cout << "Is " << palindromeTest << " a palindrome? (Recursive): " << onei(palindromeTest, true) << endl;

    int perfectSquareTest = 16;
    cout << "Is " << perfectSquareTest << " a perfect square?: " << onej(perfectSquareTest, false) << endl;
    cout << "Is " << perfectSquareTest << " a perfect square? (Recursive): " << onej(perfectSquareTest, true) << endl;

    int primeTest = 29;
    cout << "Is " << primeTest << " a prime number?: " << onek(primeTest, false) << endl;
    cout << "Is " << primeTest << " a prime number? (Recursive): " << onek(primeTest, true) << endl;

    int primeFactorTest = 56;
    cout << "Prime factorization of " << primeFactorTest << ": ";
    onel(primeFactorTest, false);
    cout << "Prime factorization of " << primeFactorTest << " (Recursive): ";
    onel(primeFactorTest, true);

    cout << endl;
}

void test_two() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    cout << "Slow multiplication of " << a << " and " << b << ": " << twoa(a, b, false) << endl;
    cout << "Slow multiplication of " << a << " and " << b << " (Recursive): " << twoa(a, b, true) << endl;

    cout << "Slow division of " << a << " by " << b << ": " << twob(a, b, false) << endl;
    cout << "Slow division of " << a << " by " << b << " (Recursive): " << twob(a, b, true) << endl;

    cout << "GCD of " << a << " and " << b << ": " << twoc(a, b, false) << endl;
    cout << "GCD of " << a << " and " << b << " (Recursive): " << twoc(a, b, true) << endl;

    cout << "LCM of " << a << " and " << b << ": " << twod(a, b, false) << endl;
    cout << "LCM of " << a << " and " << b << " (Recursive): " << twod(a, b, true) << endl;

    cout << endl;
}

void test_three() {
    int num2;
    cout << "Enter a decimal number: ";
    cin >> num2;

    cout << "Decimal to Binary: " << decimal_to_binary(num2, false) << endl;
    cout << "Decimal to Binary (Recursive): " << decimal_to_binary(num2, true) << endl;

    int bin;
    cout << "Enter a binary number: ";
    cin >> bin;

    cout << "Binary to Decimal: " << binary_to_decimal(bin, false) << endl;
    cout << "Binary to Decimal (Recursive): " << binary_to_decimal(bin, true) << endl;

    cout << "Decimal to Octal: " << decimal_to_octal(num2, false) << endl;
    cout << "Decimal to Octal (Recursive): " << decimal_to_octal(num2, true) << endl;

    int oct;
    cout << "Enter an octal number: ";
    cin >> oct;

    cout << "Octal to Decimal: " << octal_to_decimal(oct, false) << endl;
    cout << "Octal to Decimal (Recursive): " << octal_to_decimal(oct, true) << endl;

    cout << endl;
}

int decimal_to_binary(int n, bool recursive) {
    if (!recursive) {
        int binary = 0, place = 1;
        while (n > 0) {
            int remainder = n % 2;
            binary += remainder * place;
            n /= 2;
            place *= 10;
        }
        return binary;
    }
    else {
        if (n == 0) return 0;
        return (n % 2) + 10 * decimal_to_binary(n / 2, true);
    }
}

int binary_to_decimal(int n, bool recursive) {
    if (!recursive) {
        int decimal = 0, place = 0;
        while (n > 0) {
            int remainder = n % 10;
            decimal += remainder * pow(2, place);
            n /= 10;
            place++;
        }
        return decimal;
    }
    else {
        if (n == 0) return 0;
        return (n % 10) * pow(2, 0) + 2 * binary_to_decimal(n / 10, true);
    }
}

int decimal_to_octal(int n, bool recursive) {
    if (!recursive) {
        int octal = 0, place = 1;
        while (n > 0) {
            int remainder = n % 8;
            octal += remainder * place;
            n /= 8;
            place *= 10;
        }
        return octal;
    }
    else {
        if (n == 0) return 0;
        return (n % 8) + 10 * decimal_to_octal(n / 8, true);
    }
}

int octal_to_decimal(int n, bool recursive) {
    if (!recursive) {
        int decimal = 0, place = 0;
        while (n > 0) {
            int remainder = n % 10;
            decimal += remainder * pow(8, place);
            n /= 10;
            place++;
        }
        return decimal;
    }
    else {
        if (n == 0) return 0;
        return (n % 10) * pow(8, 0) + 8 * octal_to_decimal(n / 10, true);
    }
}

int twoa(int a, int b, bool recursive) {
    if (!recursive) {
        int result = 0;
        for (int i = 0; i < b; i++) {
            result += a;
        }
        return result;
    }
    else {
        if (b == 0) return 0;
        return a + twoa(a, b - 1, true);
    }
}

int twob(int a, int b, bool recursive) {
    if (!recursive) {
        int count = 0;
        while (a >= b) {
            a -= b;
            count++;
        }
        return count;
    }
    else {
        if (a < b) return 0;
        return 1 + twob(a - b, b, true);
    }
}

int twoc(int a, int b, bool recursive) {
    if (!recursive) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    else {
        if (b == 0) return a;
        return twoc(b, a % b, true);
    }
}

int twod(int a, int b, bool recursive) {
    int gcd = twoc(a, b, recursive);
    return twoa(a / gcd, b, recursive);
}

int onea(int n, bool recursive) {
    if (!recursive) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }
    else {
        if (n == 1) return 1;
        return n + onea(n - 1, true);
    }
}

int oneb(int n, bool recursive) {
    if (!recursive) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i * i;
        }
        return sum;
    }
    else {
        if (n == 1) return 1;
        return n * n + oneb(n - 1, true);
    }
}

int onec(int n, bool recursive) {
    if (!recursive) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        return sum;
    }
    else {
        if (n == 1) return 1;
        return n * n * n + onec(n - 1, true);
    }
}

int oned(int n, bool recursive) {
    if (!recursive) {
        int prod = 1;
        for (int i = 1; i <= n; i++) {
            prod *= i;
        }
        return prod;
    }
    else {
        if (n == 1) return 1;
        return n * oned(n - 1, true);
    }
}

int onee(int n, bool recursive) {
    if (!recursive) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    else {
        if (n == 0) return 0;
        return n % 10 + onee(n / 10, true);
    }
}

int onef(int n, bool recursive) {
    if (!recursive) {
        int count = 0;
        while (n != 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    else {
        if (n == 0) return 0;
        return 1 + onef(n / 10, true);
    }
}

int oneg(int n, bool recursive) {
    if (!recursive) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) sum += i;
        }
        return sum;
    }
    else {
        static int i = 1;
        if (i > n) return 0;
        int div = (n % i == 0) ? i : 0;
        i++;
        return div + oneg(n, true);
    }
}

int oneh(int n, bool recursive) {
    if (!recursive) {
        int reverse = 0;
        while (n != 0) {
            reverse = reverse * 10 + n % 10;
            n /= 10;
        }
        return reverse;
    }
    else {
        static int reverse = 0;
        if (n == 0) return reverse;
        reverse = reverse * 10 + n % 10;
        return oneh(n / 10, true);
    }
}

bool onei(int n, bool recursive) {
    if (!recursive) {
        return n == oneh(n, false);
    }
    else {
        return n == oneh(n, true);
    }
}

bool onej(int n, bool recursive) {
    if (!recursive) {
        int sqrtN = sqrt(n);
        return sqrtN * sqrtN == n;
    }
    else {
        static int i = 1;
        if (i * i > n) return false;
        if (i * i == n) return true;
        i++;
        return onej(n, true);
    }
}

bool onek(int n, bool recursive) {
    if (!recursive) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    else {
        static int i = 2;
        if (n <= 1) return false;
        if (i > sqrt(n)) return true;
        if (n % i == 0) return false;
        i++;
        return onek(n, true);
    }
}

void onel(int n, bool recursive) {
    if (!recursive) {
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
        cout << endl;
    }
    else {
        static int i = 2;
        if (n == 1) return;
        if (n % i == 0) {
            cout << i << " ";
            onel(n / i, true);
        }
        else {
            i++;
            onel(n, true);
        }
    }
}