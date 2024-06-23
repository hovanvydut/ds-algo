#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Function to find modular inverse using Extended Euclidean Algorithm
ll modInverse(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        ll q = a / m;
        ll t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) {
        x += m0;
    }

    return x;
}

// Function to find X such that X^3 ≡ C (mod N)
ll findX(ll C, vector<ll>& primes) {
    ll N = 1;
    for (ll prime : primes) {
        N *= prime;
    }

    ll X = 0;
    for (ll prime : primes) {
        ll Ni = N / prime;
        ll Mi = modInverse(Ni, prime);
        ll ai = (C % prime + prime) % prime; // Ensure ai is non-negative

        ll Xi = modExp(ai, (prime + 2) / 3, prime); // Calculate cube root modulo prime
        X = (X + ai * Ni % N * Mi % N) % N; // Apply Chinese Remainder Theorem
    }

    return X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    vector<ll> primes(m);
    for (int i = 0; i < m; ++i) {
        cin >> primes[i];
    }

    ll C;
    cin >> C;

    ll X = findX(C, primes);
    cout << X << endl;

    return 0;
}
