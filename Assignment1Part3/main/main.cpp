#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;
const int MAX_MARK = 26; // Random values go from 0 to 25

void question1();
void question2();

double mean(int[], int);
double median(int[], int);
double mode(int[], int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);
int number_of_evens(int[], int);
void printArray(int[], int);
void printHistogram(int[], int);

int main() {
	question1();
    cout << "\n\n\n";
    question2();

    return 0;
}

// Question 2

void question2() {
    int size;

    // 2a

    cout << "=== Question 2 ===\n\nEnter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array in reverse order:" << endl;
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2b

    cout << "Enter the size of the array: ";
    cin >> size;

    arr = new int[size];

    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 50) + 1;  // Random number between 1 and 50
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    cout << "Array: ";
	printArray(arr, size);
    cout << "The sum of the elements is: " << sum << endl;
}

// Question 1

void question1() {
    srand(time(0));
    int marks[SIZE];

    for (int i = 0; i < SIZE; i++) {
        marks[i] = rand() % MAX_MARK;
    }

    cout << "=== Question 1 ===\n\nMarks Array:" << "\n\n";
    printArray(marks, SIZE);

    cout << "\nMean of marks: " << mean(marks, SIZE) << endl;

    cout << "Median of marks: " << median(marks, SIZE) << endl;

    int frequency[MAX_MARK] = { 0 };
    cout << "Mode of marks: " << mode(marks, frequency, SIZE) << endl;

    cout << "Number of even numbers in marks: " << number_of_evens(marks, SIZE) << endl;
}

double mean(int arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total / size;
}

double median(int arr[], int size) {
    int tempArr[SIZE];
    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }
    bubbleSort(tempArr, size);

    if (size % 2 == 0) {
        return (tempArr[size / 2 - 1] + tempArr[size / 2]) / 2.0;
    }
    else {
        return tempArr[size / 2];
    }
}

double mode(int arr[], int freq[], int size) {
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    int modeVal = 0;
    int maxCount = freq[0];
    for (int i = 1; i < MAX_MARK; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            modeVal = i;
        }
    }

    printHistogram(freq, MAX_MARK);
    cout << endl;

    return modeVal;
}

void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int number_of_evens(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
	cout << endl;
}

void printHistogram(int freq[], int size) {
    cout << "\nHistogram:" << endl;
    for (int i = 0; i < size; i++) {
        if (freq[i] > 0) {
            cout << setw(2) << i << ": "; // Makes it so the colons are aligned nicely
            for (int j = 0; j < freq[i]; j++) {
                cout << "*";
            }
            cout << " (" << freq[i] << ")" << endl;
        }
    }
}