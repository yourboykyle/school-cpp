#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string reverseWords(const string& str) {
    stringstream ss(str);
    string word, result = "";
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        result += *it + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int countVowels(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
            count++;
        }
    }
    return count;
}

int countConsonants(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (isalpha(ch) && !(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u')) {
            count++;
        }
    }
    return count;
}

string getFirstWord(const string& str) {
    stringstream ss(str);
    string word;
    ss >> word;
    return word;
}

string getLastWord(const string& str) {
    stringstream ss(str);
    string word, lastWord;
    while (ss >> word) {
        lastWord = word;
    }
    return lastWord;
}

void question1() {
    // Question 1

    string s1, s2;

    cout << "Enter the first string: ";
    getline(cin, s1);

    cout << "Enter the second string: ";
    getline(cin, s2);

    cout << "Length of first string: " << s1.length() << endl;
    cout << "Length of second string: " << s2.length() << endl;

    int firstA = s1.find('a');
    if (firstA != string::npos) {
        cout << "First appearance of 'a' in first string at index: " << firstA << endl;
    }
    else {
        cout << "'a' not found in first string." << endl;
    }

    int firstB = s2.find('b');
    if (firstB != string::npos) {
        cout << "First appearance of 'b' in second string at index: " << firstB << endl;
    }
    else {
        cout << "'b' not found in second string." << endl;
    }

    cout << "First word of first string: " << getFirstWord(s1) << endl;
    cout << "First word of second string: " << getFirstWord(s2) << endl;

    cout << "Last word of first string: " << getLastWord(s1) << endl;
    cout << "Last word of second string: " << getLastWord(s2) << endl;

    cout << "Reversed first string (letter by letter): " << reverseString(s1) << endl;
    cout << "Reversed second string (letter by letter): " << reverseString(s2) << endl;

    cout << "Reversed first string (word by word): " << reverseWords(s1) << endl;
    cout << "Reversed second string (word by word): " << reverseWords(s2) << endl;

    cout << "Total vowels in first string: " << countVowels(s1) << endl;
    cout << "Total consonants in second string: " << countConsonants(s2) << endl;
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char closestVowel(char c) {
    if (c <= 'c') return 'a';
    if (c <= 'g') return 'e';
    if (c <= 'l') return 'i';
    if (c <= 'r') return 'o';
    return 'u';
}

char nextConsonant(char c) {
    if (c == 'z') return 'z';
    do {
        c++;
    } while (isVowel(c));
    return c;
}

void roverspraket() {
    string s, result;
    cin >> s;
    for (char c : s) {
        if (isVowel(c)) result += c;
        else result += c, result += closestVowel(c), result += nextConsonant(c);
    }
    cout << result << endl;
}

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void hidden_palindrome() {
    string s;
    cin >> s;
    int maxLength = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    cout << maxLength << endl;
}

bool isVowel2(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string getLastSyllable(string word) {
    for (int i = word.size() - 1; i >= 0; i--) {
        if (isVowel2(word[i])) return word.substr(i);
    }
    return word;
}

void poetry() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<string> syllables(4);
        for (int j = 0; j < 4; j++) {
            string line;
            getline(cin, line);
            string lastWord = line.substr(line.find_last_of(" ") + 1);
            syllables[j] = getLastSyllable(lastWord);
            transform(syllables[j].begin(), syllables[j].end(), syllables[j].begin(), ::tolower);
        }
        if (syllables[0] == syllables[1] && syllables[1] == syllables[2] && syllables[2] == syllables[3]) {
            cout << "perfect" << endl;
        }
        else if (syllables[0] == syllables[1] && syllables[2] == syllables[3]) {
            cout << "even" << endl;
        }
        else if (syllables[0] == syllables[2] && syllables[1] == syllables[3]) {
            cout << "cross" << endl;
        }
        else if (syllables[0] == syllables[3] && syllables[1] == syllables[2]) {
            cout << "shell" << endl;
        }
        else {
            cout << "free" << endl;
        }
    }
}

string reverseComplement(const string& seq) {
    string complement;
    for (char c : seq) {
        if (c == 'A') complement += 'T';
        else if (c == 'T') complement += 'A';
        else if (c == 'C') complement += 'G';
        else if (c == 'G') complement += 'C';
    }
    reverse(complement.begin(), complement.end());
    return complement;
}

string transcribeDNA(const string& dna) {
    size_t promoter_pos = dna.find("TATAAT");
    if (promoter_pos == string::npos) return "";

    size_t start = promoter_pos + 10;

    for (size_t i = start; i <= dna.size() - 12; ++i) {
        string terminator = dna.substr(i, 6);
        string revComplement = reverseComplement(terminator);

        size_t foundPos = dna.find(revComplement, i + 6);

        /*cout << "Terminator: " << terminator
            << " Reverse Complement: " << revComplement
            << " Found at position: " << foundPos << " (Expected downstream)" << endl;*/

        if (foundPos != string::npos) {
            string transcriptionUnit = dna.substr(start, i - start);

            string rna;
            for (char c : transcriptionUnit) {
                rna += (c == 'A') ? 'U' : (c == 'T') ? 'A' : (c == 'C') ? 'G' : 'C';
            }
            return rna;
        }
    }

    return "";
}

void decoding_DNA() {
	string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
		cout << i + 1 << ": " << transcribeDNA(s) << endl;
    }
}

int main() {
	question1();
    return 0;
}
