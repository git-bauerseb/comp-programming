#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

// Constants
#define MOD 998244353

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

const int N_MAX = 5050;
ll F[N_MAX];
ll F_INV[N_MAX];
ll P[N_MAX];
ll DP[N_MAX][N_MAX];
ll nPrimes;

bool isPrime(ll n) {
	if (n == 2 || n == 3) return true;
	if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
	for (ll i = 5; i*i <= n; i += 6)
	   if (n % i == 0 || n % (i+2) == 0) return false;
	return true;	
}

ll fast_pow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e % 2 == 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}

ll f(ll i, ll j) {
	ll& ref = DP[i][j];
	if (ref >= 0) return ref;

	if (i == nPrimes) return ref = (j == 0);
	ref = (F_INV[P[i]] * f(i+1, j)) % MOD;
	if (j > 0)
		ref = (ref + (F_INV[P[i]-1]) * f(i+1, j-1)) % MOD;
	return ref;
}

void solution() {
	// Precalculate all factorials
	F[0] = 1;
	for (int i = 1; i < N_MAX; ++i) {
	   	F[i] = (i * F[i-1]) % MOD;
	}
	F_INV[0] = 1;
	for (int i = 0; i < N_MAX; ++i)
		F_INV[i] = fast_pow(F[i], MOD - 2);

	int n;
	cin >> n;

	map<int,int> primes;
	map<int,int> nprimes;
	for (int i = 0; i < 2*n; ++i) {
		int num; cin >> num;
		if (isPrime(num)) {primes[num]++;}
		else nprimes[num]++;
	}

	int idx = 0;
	nPrimes = primes.size();

	for (auto it = primes.begin(); it != primes.end(); ++it, ++idx) {
		P[idx] = it->second;
	}

	ll res = F[n];
	for (auto& e : nprimes) res = (res * F_INV[e.second]) % MOD;

	memset(DP, -1, sizeof(DP));
	ll dpS = f(0,n);
	cout << (res * dpS) % MOD << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solution();
	return 0;
}
