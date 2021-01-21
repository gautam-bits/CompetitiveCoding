
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9+7
//#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define min3(a, b, c) min((int)c, min((int)a,(int)b))
#define min4(a, b, c, d) min((int)d, min((int)c, min((int)a,(int)b)))
#define rrep(i, n) for(int i=n-1; i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

template<typename T>
void pop_front(vector<T> &v)
{
    if(v.size()>0)v.front()=move(v.back()), v.pop_back();
}

unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int32_t main()
{
    fast

    int n,k;
    cin>>n>>k;

    vector<int> vec(k);

    int sum = 0;
    for(int i = 0 ; i < k ; i++) {
        cin>>vec[i];
        sum += vec[i];
    }

    int hh = n - sum - k + 1;
    int gg = k + 1;
    //cout<<<<gg<<endl;
    cout<<nCrModPFermat(hh + gg - 1,gg -1,1000000007)<<endl;





    
    return 0;
}
