#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Extended Euclidean Algorithm: Returns gcd(a, b) and updates x, y
// such that a*x + b*y = gcd(a, b)
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Safely handles negative modulos in C++
ll normalize(ll x, ll mod) {
    return (x % mod + mod) % mod;
}

// Merges: x ≡ a1 (mod m1) AND x ≡ a2 (mod m2)
// Returns {new_a, new_m}. If no solution, returns {-1, -1}
pair<ll, ll> merge_CRT(ll a1, ll m1, ll a2, ll m2) {
    ll p, q;
    ll d = extGCD(m1, m2, p, q);
    
    // Condition for existence of a solution: (a2 - a1) must be divisible by gcd(m1, m2)
    if ((a2 - a1) % d != 0) {
        return {-1, -1}; // No solution exists
    }
    
    // We need to calculate: k1 = p * (a2 - a1) / d
    // Be careful with overflows here! Using __int128 if m1*m2 > 10^18
    ll m_new = (m1 / d) * m2; // This is LCM(m1, m2)
    
    // Calculate the new 'a' carefully to avoid negative numbers and overflow
    ll diff = normalize(a2 - a1, m_new);
    ll k1 = normalize((ll)((__int128)p * (diff / d) % (m2 / d)), m2 / d);
    
    ll a_new = normalize(a1 + k1 * m1, m_new);
    
    return {a_new, m_new};
}