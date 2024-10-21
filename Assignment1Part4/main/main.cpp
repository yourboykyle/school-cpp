#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void question1();
void printArray(int arr[][5], int size);
void printArray(int arr[4][4]);
void printDiagonal(int arr[][5], int size);
int sumArray(int arr[][5], int size);
int sumRow(int arr[][5], int size, int row);
int largestRow(int arr[][5], int size);
void question2();
void generatePascalsTriangle(int rows);
void question3();
void flip_vertical(int arr[4][4]);
void flip_horizontal(int arr[4][4]);


int main() {
	question1();
	question2();
	question3();

    return 0;
}

// Question 1

void question1() {
	// Generate array
	srand(time(NULL));

	int arr[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = rand() % 100 + 1;
		}
	}

	cout << "Array:\n";
	printArray(arr, 5);
	cout << "Diagonal:\n";
	printDiagonal(arr, 5);
	cout << "Sum: " << sumArray(arr, 5) << endl;
	cout << "2nd row sum: " << sumRow(arr, 5, 2) << endl;
	cout << "Largest row: " << largestRow(arr, 5) << endl;
}

void printArray(int arr[][5], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printArray(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printDiagonal(int arr[][5], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i][i] << " ";
	}
	cout << endl;
}

int sumArray(int arr[][5], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int sumRow(int arr[][5], int size, int row) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[row][i];
	}
	return sum;
}

int largestRow(int arr[][5], int size) {
	int largest = 0;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		int temp = sumRow(arr, size, i);
		if (temp > sum) {
			sum = temp;
			largest = i;
		}
	}
	return largest;
}

// Question 2

void question2() {
	int rows;
	cout << "Enter number of rows for pascal's triangle: ";
	cin >> rows;

	generatePascalsTriangle(rows);
}

void generatePascalsTriangle(int rows) {
	vector<vector<int>> pascal(rows);

	for (int i = 0; i < rows; i++) {
		pascal[i].resize(i + 1);

		pascal[i][0] = pascal[i][i] = 1;

		for (int j = 1; j < i; j++) {
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			cout << pascal[i][j] << " ";
		}
		cout << endl;
	}
}

// Question 3

void question3() {
	int arr[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	cout << "Original Array:" << endl;
	printArray(arr);

	flip_vertical(arr);
	cout << "Array after vertical flip:" << endl;
	printArray(arr);

	flip_horizontal(arr);
	cout << "Array after horizontal & vertical flip:" << endl;
	printArray(arr);
}

void flip_vertical(int arr[4][4]) {
	int temp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = arr[i][4 - 1 - j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void flip_horizontal(int arr[4][4]) {
	int temp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = arr[4 - 1 - i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}