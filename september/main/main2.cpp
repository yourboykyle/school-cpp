#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;
    vector<vector<int>> prefixFreq(26, vector<int>(s.size() + 1, 0));

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            prefixFreq[j][i + 1] = prefixFreq[j][i];
        }
        if (isalpha(s[i])) {
            prefixFreq[s[i] - 'a'][i + 1]++;
        }
    }

    while (q--) {
        int i, j;
        char c;
        cin >> i >> j >> c;
        i--, j--;
        int letterIdx = c - 'a';
        cout << prefixFreq[letterIdx][j + 1] - prefixFreq[letterIdx][i] << endl;
    }
    return 0;
}
