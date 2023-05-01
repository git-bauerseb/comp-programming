#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

const int N_MAX = 100000;
int PRIMES[N_MAX];

int generatePrimes(int limit) {
    int num = 1;
    PRIMES[0] = 2;
    for (int i = 3; i <= limit; i += 2) {
        if (isPrime(i)) {
            PRIMES[num++] = i;
        }
    }

    return num;
}


void solution() {
    int n; cin >> n;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; ++i) {int num; cin >> num;
        ones += (num == 1) ? 1 : 0;
        twos += (num == 2) ? 1 : 0;
    }
    generatePrimes(n*2+1);

    vi nums(n, 0);
    int ptr = 0;
    int pref = 0;
    for (int i = 0; i < n; ++i) {
        if (PRIMES[ptr] - pref == 2 && twos) {
            nums[i] = 2;
            pref += 2;
            twos--;
            ptr++;
        } else if (PRIMES[ptr] - pref == 1 && ones) {
            nums[i] = 1;
            pref += 1;
            ones--;
            ptr++;
        } else if (!twos) {
            nums[i] = 1; pref += 1; ones--;
        } else if (!ones) {
            nums[i] = 2; pref += 2; twos--;
        } else {
            if (pref % 2 == 0) {nums[i] = 1; pref += 1; ones--;}
            else {nums[i] = 2; pref += 2; twos--;}
        }
    }

    for (auto& e : nums) cout << e << " ";
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    solution();

	return 0;
}
