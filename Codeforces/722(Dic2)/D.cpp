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

    const int MOD   = 998244353 ;
    const int N     = 100005 ;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

const int MAX = 1000010;
 
// array to store prime factors
int factor[MAX] = { 0 };
 
// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
    factor[1] = 1;
 
    // Initializes all the positions with their value.
    for (int i = 2; i < MAX; i++)
        factor[i] = i;
 
    // Initializes all multiples of 2 with 2
    for (int i = 4; i < MAX; i += 2)
        factor[i] = 2;
 
    // A modified version of Sieve of Eratosthenes to
    // store the smallest prime factor that divides
    // every number.
    for (int i = 3; i * i < MAX; i++) {
        // check if it has no prime factor.
        if (factor[i] == i) {
            // Initializes of j starting from i*i
            for (int j = i * i; j < MAX; j += i) {
                // if it has no prime factor before, then
                // stores the smallest prime divisor
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}
 
// function to calculate number of factors
int calculateNoOFactors(int n)
{
    if (n == 1)
        return 1;
 
    int ans = 1;
 
    // stores the smallest prime number
    // that divides n
    int dup = factor[n];
 
    // stores the count of number of times
    // a prime number divides n.
    int c = 1;
 
    // reduces to the next number after prime
    // factorization of n
    int j = n / factor[n];
 
    // false when prime factorization is done
    while (j != 1) {
        // if the same prime number is dividing n,
        // then we increase the count
        if (factor[j] == dup)
            c += 1;
 
        /* if its a new prime factor that is factorizing n,
           then we again set c=1 and change dup to the new
           prime factor, and apply the formula explained
           above. */
        else {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }
 
        // prime factorizes a number
        j = j / factor[j];
    }
 
    // for the last prime factor
    ans = ans * (c + 1);
 
    return ans;
}
 
// Driver program to test above function
// int main()
// {
//     // generate prime factors of number
//     // upto 10^6
//     generatePrimeFactors();
 
//     int a[] = { 10, 30, 100, 450, 987 };
 
//     int q = sizeof(a) / sizeof(a[0]);
 
//     for (int i = 0; i < q; i++)
//         cout << calculateNoOFactors(a[i]) << " ";
 
//     return 0;
// }
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        generatePrimeFactors();
    
        ll n;
        read(n);

        vi arr(n+5,0);
        vi sum(n+5,0);

        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 3;

        arr[3] = 6;


        sum[0] = 1;

        sum[1] = 2;
        sum[2] = 5;
        sum[3] = 11;



        fo(i,4,n+1){
            arr[i] = (sum[i-1] + 1 )%MOD;

            arr[i] += calculateNoOFactors(i) - 2;
            sum[i] = (sum[i-1] + arr[i])%MOD;
        }    

        cnl(arr[n]);
    
    return 0;
}