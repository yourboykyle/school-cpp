#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <tuple>

using namespace std;

void goat_fence();
void who_is_in_the_middle();
void triangle_times();
void mimi_and_pizza();
void tri();
void flying_plushies();
void not_enough_users();
void vasile_and_haircuits();
void optimal_skiing();
void big_chess();
void pink();
void ren_ashbell();
void tudor_drinks_some_tea();
void zamka();
void students_council_breakfast();

int main()
{
    students_council_breakfast();
}

void students_council_breakfast() {
    int pinkCost, greenCost, redCost, orangeCost, targetAmount;
    cin >> pinkCost >> greenCost >> redCost >> orangeCost >> targetAmount;

    vector<tuple<int, int, int, int>> combinations;
    int minTickets = INT_MAX;

    // Brute force all possible combinations
    for (int pink = 0; pink * pinkCost <= targetAmount; pink++) {
        for (int green = 0; green * greenCost <= targetAmount; green++) {
            for (int red = 0; red * redCost <= targetAmount; red++) {
                for (int orange = 0; orange * orangeCost <= targetAmount; orange++) {
                    int total = pink * pinkCost + green * greenCost + red * redCost + orange * orangeCost;
                    if (total == targetAmount) {
                        combinations.push_back(make_tuple(pink, green, red, orange));
                        int totalTickets = pink + green + red + orange;
                        if (totalTickets < minTickets) {
                            minTickets = totalTickets;
                        }
                    }
                }
            }
        }
    }

    for (tuple<int, int, int, int> combo : combinations) {
        cout << "# of PINK is " << get<0>(combo)
            << " # of GREEN is " << get<1>(combo)
            << " # of RED is " << get<2>(combo)
            << " # of ORANGE is " << get<3>(combo) << endl;
    }

    cout << "Total combinations is " << combinations.size() << ".\n";
    cout << "Minimum number of tickets to print is " << minTickets << ".\n";
}

void zamka() {
    int l, d, x, n = 0, m = 0;
    cin >> l >> d >> x;

    // Find the minimum number
    for (int i = l; i <= d; i++) {
		int sum = 0;
		int temp = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == x) {
			n = i;
			break;
		}
	}

	// Find the maximum number
	for (int i = d; i >= l; i--) {
		int sum = 0;
		int temp = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == x) {
			m = i;
			break;
		}
	}

	cout << n << endl;
	cout << m << endl;
}

void tudor_drinks_some_tea() {
    int count = 0;

    for (int i = 0; i < 5; i++) {
        char x;
        cin >> x;
        if (x == 'P') {
            count++;
        }
    }

    cout << count << endl;
}

void ren_ashbell() {
    int n, ren_power;
    bool ren_strongest = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> ren_power;
        } else {
            int power;
            cin >> power;
            if (power >= ren_power) {
                ren_strongest = false;
            }
        }
    }
    cout << (ren_strongest ? "YES\n" : "NO\n");
}

void pink() {
    int n = 0, r = 0, g = 0, b = 0, count = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        if (240 <= r && r <= 255 && 0 <= g && g <= 200 && 95 <= b && b <= 220) {
            count++;
        }
    }

    cout << count << endl;
}

void big_chess() {
    int w, h;
    
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    cout << "0";
                }
                else {
                    cout << "1";
                }
            } else {
                if (j % 2 == 0) {
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
        }
        cout << endl;
    }
}

void optimal_skiing() {
    int n, m, shortest = INT_MAX;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;

        int time = 0;
        for (int j = 0; j < m; j++) {
            time += [=] { int x; cin >> x; return x; }();
        }

        if(time < shortest) {
			shortest = time;
		}
    }

    cout << shortest << endl;
}

void vasile_and_haircuits() {
    int n, l, a, b, f;
    vector<string> answers;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> l >> a >> b >> f;

        if(l - f >= a && l - f <= b)
            answers.push_back("Yes");
        else
            answers.push_back("No");
    }

    for (string answer : answers) {
        cout << answer << endl;
    }
}

void not_enough_users() {
    int n, k, d;

    cin >> n >> k >> d;

    for (int i = 0; i < d; i++) {
        n *= k;
    }

    cout << n << endl;
}

void flying_plushies() {
    int n, m, count = 0;
    vector<int> plushies;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        plushies.push_back([=] { int plushie; cin >> plushie; return plushie; }());
    }

    for (int i : plushies) {
        if (i >= n) {
            count++;
        }
    }

    cout << count << endl;
}

void tri() {
	int a, b, c;
	cin >> a >> b >> c;

	if(a + b == c)
        cout << a << "+" << b << "=" << c << endl;
    else if(a == b + c)
		cout << a << "=" << b << "+" << c << endl;
	else if(a - b == c)
		cout << a << "-" << b << "=" << c << endl;
	else if(a == b - c)
		cout << a << "=" << b << "-" << c << endl;
	else if(a * b == c)
		cout << a << "*" << b << "=" << c << endl;
	else if(a == b * c)
		cout << a << "=" << b << "*" << c << endl;
	else if(a / b == c)
		cout << a << "/" << b << "=" << c << endl;
	else if(a == b / c)
		cout << a << "=" << b << "/" << c << endl;
}

void mimi_and_pizza() {
    int b, p;
    char veg;

    cin >> b >> p >> veg;

    if(veg == 'Y') { // between B and D
        if (5 * p < b) {
			cout << "B\n";
		} else if(2 * p < b) {
			cout << "D\n";
        } else {
            cout << "NO PIZZA\n";
        }
	} else if(veg == 'N') { // between A and C
		if (5 * p < b) {
			cout << "A\n";
		} else if (2 * p < b) {
			cout << "C\n";
		} else {
            cout << "NO PIZZA\n";
        }
	} else {
        cout << "NO PIZZA\n";
    }
}

void triangle_times() {
	int a, b, c;
	cin >> a >> b >> c;
    
    if (a + b + c != 180) {
        cout << "Error\n";
    } else if (a == b && b == c) {
		cout << "Equilateral\n";
	} else if (a == b || b == c || a == c) {
		cout << "Isosceles\n";
    } else {
		cout << "Scalene\n";
	}
}

void who_is_in_the_middle() {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[3] = { a, b, c };
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << arr[1] << endl;
}

void goat_fence() {
    int n = 0, min_fencing_length = INT_MAX;
    cin >> n;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i != 0) {
            continue;
        }
        int j = n / i;

        if (i * j == n) {
            int fencing_length = i * 2 + j * 2;
            if (fencing_length < min_fencing_length) {
                min_fencing_length = fencing_length;
            }
        }
    }

    cout << min_fencing_length << endl;
}