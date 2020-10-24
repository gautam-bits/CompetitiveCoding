// C++ program to comput n! % p using Wilson's Theorem 
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
int power(int x, unsigned int y, int p) 
{ 
	int res = 1; // Initialize result 
	x = x % p; // Update x if it is more than or 
	// equal to p 
	while (y > 0) { 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res * x) % p; 

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = (x * x) % p; 
	} 
	return res; 
} 

// Function to find modular inverse of a under modulo p 
// using Fermat's method. Assumption: p is prime 
int modInverse(int a, int p) 
{ 
	return power(a, p - 2, p); 
} 

// Returns n! % p using Wilson's Theorem 
int modFact(int n, int p) 
{ 
	// n! % p is 0 if n >= p 
	if (p <= n) 
		return 0; 

	// Initialize result as (p-1)! which is -1 or (p-1) 
	int res = (p - 1); 

	// Multiply modulo inverse of all numbers from (n+1) 
	// to p 
	for (int i = n + 1; i < p; i++) 
		res = (res * modInverse(i, p)) % p; 
	return res; 
} 
int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res; 
}
ll ans;
    ll fact(ll n)
    {
        if(n<INT_MAX)
        {
        ans=1;
        for(int i=2;i<=n;i++)
         ans=(ans*i)%1000000007;
         return ans;
        }
    }

// Driver method 
int main() 
{ 
	int n = 25, p = 29; 
	cout << fact(41); 
	return 0; 
} 
