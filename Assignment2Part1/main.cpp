#include <iostream>

using namespace std;

void 1a(int n, bool recursive);
void 1b(int n, bool recursive);
void 1c(int n, bool recursive);
void 1d(int n, bool recursive);
void 1e(int n, bool recursive);
void 1f(int n, bool recursive);
void 1g(int n, bool recursive);
void 1h(int n, bool recursive);
void 1i(int n, bool recursive);
void 1j(int n, bool recursive);
void 1k(int n, bool recursive);
void 1l(int n, bool recursive);

int main() {
	//
}

void 1b(int n, bool recursive) {
	int sum = 0;

	if (!recursive) {
		for (int i = 1; i <= n; i++) {
			sum += pow(i, 2);
		}
	}
	else {
		for (int i = n; i > 0; i--) {
			sum += pow(i, 2);
		}
	}

	return sum;
}

void 1a(int n, bool recursive) {
	int sum = 0;

	if (!recursive) {
		for (int i = 1; i <= n; i++) {
			sum++;
		}
	} else {
		for (int i = n; i > 0; i--) {
			sum++;
		}
	}

	return sum;
}