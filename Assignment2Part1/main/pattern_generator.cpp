#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

void generatePatterns(int n, int k) {
    cout << "The bit patterns are" << endl;
    string pattern(k, '1');
    pattern += string(n - k, '0');
    do {
        cout << pattern << endl;
    } while (prev_permutation(pattern.begin(), pattern.end()));
}

class Combinatorics {
public:
    static int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; ++i)
            result *= i;
        return result;
    }

    static int combinations(int n, int r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }

    static int permutations(int n, int r) {
        return factorial(n) / factorial(n - r);
    }

    static void generateCombinations(vector<int>& elements, int r) {
        vector<bool> mask(elements.size(), false);
        fill(mask.begin(), mask.begin() + r, true);
        cout << "Combinations are:" << endl;
        do {
            for (size_t i = 0; i < elements.size(); ++i) {
                if (mask[i])
                    cout << elements[i] << " ";
            }
            cout << endl;
        } while (prev_permutation(mask.begin(), mask.end()));
    }

    static void generatePermutations(vector<int>& elements, int r) {
        sort(elements.begin(), elements.end());
        vector<int> subset(elements.begin(), elements.begin() + r);
        cout << "Permutations are:" << endl;
        do {
            do {
                for (int val : subset)
                    cout << val << " ";
                cout << endl;
            } while (next_permutation(subset.begin(), subset.end()));
        } while (next_permutation(elements.begin(), elements.end()));
    }
};

int main() {
    int pairs;
    cout << "Enter the number of n, k pairs: ";
    cin >> pairs;

    for (int i = 0; i < pairs; ++i) {
        int n, k;
        cout << "Enter n and k: ";
        cin >> n >> k;
        generatePatterns(n, k);
    }

    int n, r;
    cout << "Enter n and r for combinatorics (n >= r): ";
    cin >> n >> r;

    vector<int> elements(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
        cin >> elements[i];

    cout << "Number of combinations: " << Combinatorics::combinations(n, r) << endl;
    cout << "Number of permutations: " << Combinatorics::permutations(n, r) << endl;

    Combinatorics::generateCombinations(elements, r);
    Combinatorics::generatePermutations(elements, r);

    return 0;
}
