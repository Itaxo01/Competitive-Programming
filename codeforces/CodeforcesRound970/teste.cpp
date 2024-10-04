

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
 
// Function to return the GCD of given numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Recursive function to return (x ^ n) % m
ll modexp(ll x, ll n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % m, n / 2);
    }
    else {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}
 
// Function to return the fraction modulo mod
ll getFractionModulo(ll a, ll b)
{
    ll c = gcd(a, b);
 
    a = a / c;
    b = b / c;
 
    // (b ^ m-2) % m
    ll d = modexp(b, m - 2);
 
    // Final answer
    ll ans = ((a % m) * (d % m)) % m;
 
    return ans;
}
 
// Driver code
int main()
{
    ll a = 3, b = 10;
 
    cout << getFractionModulo(a, b) << endl;
 
    return 0;
}