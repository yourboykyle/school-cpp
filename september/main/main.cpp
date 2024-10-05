#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>

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
void troubling_triangles();
void crayola_lightsaber();
void deforestation();
void marathon();
void global_warming();
void battle_positions();
void world_trade_foundation();
void frisbee_golf();
void nadan();
void playlist_panic();
void a_greedy_problem();
void tandem_bicycle();
void molly_and_difference();
void just_the_factoradics();
void natjecanje();
void go_faster();
void sawmill();
void largest_permutation();
void house_of_cards();
void bus_jam();
void chair_stacking();
void factor_solitaire();

int main()
{
    factor_solitaire();
}

void factor_solitaire() {
    int n, cost = 0;
    cin >> n;

    while (n > 1) {
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) {
                cost += n / i;
                n = i;
                break;
            }
        }
    }

    cout << cost << endl;
}

void chair_stacking() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int median_x = x[N / 2], median_y = y[N / 2];
    long long total_time = 0;

    for (int i = 0; i < N; i++) {
        total_time += abs(x[i] - median_x) + abs(y[i] - median_y);
    }

    cout << total_time << endl;
}

void bus_jam() {
    int N, M, H;
    cin >> N >> M >> H;

    vector<int> buses(N);
    for (int i = 0; i < N; i++) {
        cin >> buses[i];
    }

    int breaks = 0;
    for (int i = 1; i < N; i++) {
        int gap = buses[i] - buses[i - 1];
        if (gap > H) {
            breaks += (gap - 1) / M;
        }
    }

    cout << breaks << endl;
}

void house_of_cards() {
    int N, K;
    cin >> N >> K;
    vector<int> widths(N);

    for (int i = 0; i < N; i++) {
        cin >> widths[i];
    }

    sort(widths.begin(), widths.end(), greater<int>());

    int count = 1;
    int last_width = widths[0];

    for (int i = 1; i < N; i++) {
        if (last_width - widths[i] >= K) {
            count++;
            last_width = widths[i];
        }
    }

    cout << count << endl;
}

void largest_permutation() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    unordered_map<int, int> pos;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 0; i < N && K > 0; i++) {
        int largest = N - i;
        if (arr[i] != largest) {
            int swap_idx = pos[largest];
            pos[arr[i]] = swap_idx;
            pos[largest] = i;
            swap(arr[i], arr[swap_idx]);
            K--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sawmill() {
    int N;
    cin >> N;
    vector<int> energy(N), length(N);

    for (int i = 0; i < N; i++) cin >> energy[i];
    for (int i = 0; i < N; i++) cin >> length[i];

    sort(energy.begin(), energy.end());
    sort(length.rbegin(), length.rend());

    long long total_energy = 0;
    for (int i = 0; i < N; i++) {
        total_energy += 1LL * energy[i] * length[i];
    }

    cout << total_energy << endl;
}

void go_faster() {
    int N;
    cin >> N;
    int on, off;
    int min_benefit = 0, max_benefit = 0, current_passengers = 0;

    for (int i = 1; i < N; ++i) {
        cin >> on >> off;
        current_passengers += on - off;
        max_benefit = max(max_benefit, current_passengers);
        min_benefit = min(min_benefit, current_passengers);
    }

    cout << max(0, min_benefit) << endl;
    cout << max(0, max_benefit) << endl;
}

void natjecanje() {
    int N, S, R;
    cin >> N >> S >> R;

    vector<int> damaged(S), reserve(R);

    for (int i = 0; i < S; i++) cin >> damaged[i];
    for (int i = 0; i < R; i++) cin >> reserve[i];

    sort(damaged.begin(), damaged.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < R; j++) {
            if (damaged[i] == reserve[j]) {
                damaged[i] = reserve[j] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < S; i++) {
        if (damaged[i] == -1) continue;
        for (int j = 0; j < R; j++) {
            if (reserve[j] == -1) continue;
            if (abs(damaged[i] - reserve[j]) == 1) {
                reserve[j] = damaged[i] = -1;
                break;
            }
        }
    }

    int unable_to_start = 0;
    for (int i = 0; i < S; i++) {
        if (damaged[i] != -1) unable_to_start++;
    }

    cout << unable_to_start << endl;
}

void just_the_factoradics() {
    const int MAX_DIGITS = 30;
    int test_cases = 10;

    while (test_cases--) {
        string input;
        cin >> input;

        int length = input.size();
        int index = 0;
        
        for (int i = length - 1; i >= 0; i--) {
            if (index < i + 1) {
                cout << input[index++] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void molly_and_difference() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int min_diff = INT_MAX;
    for (int i = 1; i < N; i++) {
        min_diff = min(min_diff, A[i] - A[i - 1]);
    }

    cout << min_diff << endl;
}

void tandem_bicycle() {
    int question, N;
    cin >> question >> N;

    vector<int> Dmojistan(N), Pegland(N);
    for (int i = 0; i < N; i++) cin >> Dmojistan[i];
    for (int i = 0; i < N; i++) cin >> Pegland[i];

    sort(Dmojistan.begin(), Dmojistan.end());

    if (question == 1) {
        sort(Pegland.begin(), Pegland.end());
    }
    else {
        sort(Pegland.begin(), Pegland.end(), greater<int>());
    }

    int totalSpeed = 0;
    for (int i = 0; i < N; i++) {
        totalSpeed += max(Dmojistan[i], Pegland[i]);
    }

    cout << totalSpeed << endl;
}

void a_greedy_problem() {
    const int MOD = 1e9 + 7;

    int N, T, Q;
    cin >> N >> T >> Q;

    vector<int> times(N);
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int t = T; t >= times[i]; --t) {
            for (int j = N; j >= 1; --j) {
                dp[j][t] = (dp[j][t] + dp[j - 1][t - times[i]]) % MOD;
            }
        }
    }

    while (Q--) {
        int a, b, q;
        cin >> a >> b >> q;
        a--; b--;

        if (times[a] + times[b] > q) {
            cout << 0 << endl;
            continue;
        }

        int remainingTime = q - times[a] - times[b];
        vector<int> mask;
        for (int i = 0; i < N; ++i) {
            if (i != a && i != b) {
                mask.push_back(times[i]);
            }
        }

        vector<int> dp_mask(remainingTime + 1, 0);
        dp_mask[0] = 1;

        for (int time : mask) {
            for (int t = remainingTime; t >= time; --t) {
                dp_mask[t] = (dp_mask[t] + dp_mask[t - time]) % MOD;
            }
        }

        int result = 0;
        for (int t = 0; t <= remainingTime; ++t) {
            result = (result + dp_mask[t]) % MOD;
        }

        cout << result << endl;
    }
}

void playlist_panic() {
    int N;
    cin >> N;

    vector<int> song_durations(N);

    for (int i = 0; i < N; i++) {
        int minutes, seconds;
        cin >> minutes >> seconds;
        song_durations[i] = minutes * 60 + seconds;
    }

    int X, Y;
    cin >> X >> Y;
    int total_time = X * 60 + Y;

    sort(song_durations.begin(), song_durations.end());

    int count = 0;
    int current_time = 0;

    for (int i = 0; i < N; i++) {
        if (current_time + song_durations[i] <= total_time) {
            current_time += song_durations[i];
            count++;
        }
        else {
            break;
        }
    }

    cout << count << endl;
}

void nadan() {
    int K, N;
    cin >> K >> N;

    vector<int> projects(N);
    int sum = 0;

    for (int i = 0; i < N; i++) {
        projects[i] = i + 1;
        sum += projects[i];
    }

    K -= sum;

    for (int i = N - 1; i >= 0 && K > 0; i--) {
        int add = min(K, i);
        projects[i] += add;
        K -= add;
    }

    for (int i = 0; i < N; i++) {
        cout << projects[i] << endl;
    }
}

void frisbee_golf() {
    long long D;
    cin >> D;

    int disks[] = { 1000, 500, 100, 50, 10, 5, 1 };
    int throws[7] = { 0 };

    for (int i = 0; i < 7; i++) {
        throws[i] = D / disks[i];
        D %= disks[i];
    }

    for (int i = 6; i >= 0; i--) {
        cout << throws[i] << " ";
    }
}

void world_trade_foundation() {
    int N, K;
    cin >> N >> K;

    vector<int> denominations(N);
    for (int i = 0; i < N; i++) {
        cin >> denominations[i];
    }

    int coin_count = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K >= denominations[i]) {
            coin_count += K / denominations[i];
            K %= denominations[i];
        }
    }

    if (K == 0)
        cout << coin_count << endl;
    else
        cout << -1 << endl;
}

void battle_positions() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(n + 2, 0);

    for (int i = 0; i < q; i++) {
        int l, r, value;
        cin >> l >> r >> value;
        arr[l] += value;
        arr[r + 1] -= value;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
        if (arr[i] < k) count++;
    }

    cout << count << endl;
}

void global_warming() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> temps(n);
        for (int i = 0; i < n; ++i) {
            cin >> temps[i];
        }

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        vector<int> diffs(n - 1);
        for (int i = 1; i < n; ++i) {
            diffs[i - 1] = temps[i] - temps[i - 1];
        }

        int cycle_length = n - 1;
        for (int len = 1; len <= n - 1; ++len) {
            bool valid = true;
            for (int i = len; i < n - 1; ++i) {
                if (diffs[i] != diffs[i % len]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cycle_length = len;
                break;
            }
        }

        cout << cycle_length << endl;
    }
}

void marathon() {
    int N, Q;
    cin >> N >> Q;

    vector<int> ratings(N + 1, 0);
    vector<int> prefixSum(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> ratings[i];
        prefixSum[i] = prefixSum[i - 1] + ratings[i];
    }
    
    int totalSum = prefixSum[N];
    
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        int skippedSum = prefixSum[b] - prefixSum[a - 1];
        cout << totalSum - skippedSum << endl;
    }
}

void deforestation() {
    int N;
    cin >> N;

    vector<int> mass(N);
    for (int i = 0; i < N; ++i) {
        cin >> mass[i];
    }

    vector<long long> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + mass[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;

        long long result = prefixSum[R + 1] - prefixSum[L];
        cout << result << endl;
    }
}

void crayola_lightsaber() {
    int n, count = 0;
	string str, prevStr = "";

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;

        if (str != prevStr) {
            count++;
            prevStr = str;
        } else {
            break;
        }
    }

    cout << count << endl;
}

void troubling_triangles() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double a = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;

        double ab, bc, ac, p;
        ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        ac = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        p = ab + bc + ac;

        cout << fixed << setprecision(2) << a << " " << p << endl;
    }
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