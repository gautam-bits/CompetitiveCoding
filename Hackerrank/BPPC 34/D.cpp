// This is an intellectual property of Diablo Escada ,
// So please use it with extreme CAUTION .


//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define lb lower_bound
    #define ub upper_bound
    #define bs binary_search

    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x
    #define cinarr(n,arr) fo(i,0,n) read(arr[i]);
    #define cinarr2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) read(arr[i][j]);}}
    #define all(v) v.begin(),v.end()

    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll n = arr.size(); fo(i,0,n) {csp(arr[i]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {ll n=arr.size();   fo(i,0,n) {ll m = arr[i].size(); fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    const ll MOD   = 1000000007 ;
    const ll N     =  2004005;
    const ll MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll mul2(ll x, ll y)
{
    return (x * 1ll * y) % (MOD-1);
}



ll binpow(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

ll binpow2(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul2(ans, x);
        x = mul2(x, x);
        y >>= 1;
    }
    return ans;
}

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store inverse of 1 to N
ll factorialNumInverse2[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse2[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];

ll fact2[N+1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p = MOD)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p = MOD)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p = MOD)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 

// Function to precompute inverse of numbers
void InverseofNumber2(ll p = MOD-1)
{
    naturalNumInverse2[0] = naturalNumInverse2[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse2[i] = naturalNumInverse2[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial2(ll p = MOD-1)
{
    factorialNumInverse2[0] = factorialNumInverse2[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse2[i] = (naturalNumInverse2[i] * factorialNumInverse2[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial2(ll p = MOD-1)
{
    fact2[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact2[i] = (fact2[i - 1] * i) % p;
    }
}
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p = MOD)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

ll Binomial2(ll N, ll R, ll p = MOD-1)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact2[N] * factorialNumInverse2[R])
              % p * factorialNumInverse2[N - R])
             % p;
    return ans;
}
 



ll divide(ll x, ll y)
{
    return mul(x, binpow(y, MOD - 2));
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> is_prime(N+1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }


    InverseofNumber();
    InverseofFactorial();
    factorial();

    InverseofNumber2();
    InverseofFactorial2();
    factorial2();
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vi arr(n);
        

        cinarr(n,arr);

        ll pno = 0;

        fo(i,0,n) if(is_prime[arr[i]]) pno++;


        ll ans = 1;


        fo(i,0,pno+1){

            ll pot = 1,nos = 1 ;

            pot = i + 2;

            ll nos1 = Binomial2(pno,i,MOD-1);
            ll nos2  = binpow2(2,n-pno);

            //nos = mul(Binomial(pno,i),binpow(2,n-pno));

            nos = (nos1*nos2)%(MOD-1);

            ans = mul(ans,binpow(pot,nos));

        }

        cnl(ans);
    
    }
    return 0;
}