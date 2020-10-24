//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<' '<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const ll MOD =  1e9 + 7 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
const int N = 1000001;
 
// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    //cin>>t;
    t = 1;
    
    while(t--)
    {   

        ll p = 1000000007;
        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);

        ll n,x,pos;
        cin>>n>>x>>pos;
        ll facttt[10001];
        // facttt[1] = 1;
        // fo(i,2,10001){
        //     facttt[i] = (i * facttt[i-1])%MOD;
        // }
        ll val[n] = {0};   //0 any // 1 grea // -1 sml

        ll left = 0;
        ll right = n;
        ll middle;
        val[pos]  = 2;

        while(left < right){
            middle = (left + right)/2;
            if(middle == pos ){
                //cout<<"yo";
                left = middle + 1;
            }
            else if(middle < pos){
                left = middle + 1;
                val[middle] = -1;
                //cout<<"lo";
            }
            else{
                right = middle;
                val[middle] = 1;
                //cout<<"fo";
            }
        }

        ll lt=0,nlt=0,gt=0,ngt=0,ext=0;

        lt = x - 1;
        gt = n - x;

        fo(i,0,n){
            if(val[i] == 1)ngt++;
            else if(val[i] == -1) nlt++;
            else if(val[i] == 0) ext++;
        }
        // cout<<gt<<" "<<ngt<<endl;
        // cout<<lt<<" "<<nlt<<endl;
        // cout<<ext<<endl;

        ll aaa = max(Binomial(lt,nlt,MOD),(ll)1);
        ll bbb = max(Binomial(gt,ngt,MOD),(ll)1);

        ll ans = (aaa*bbb)%MOD;
        ans = (ans*fact[ext])%MOD;
        ans =  (ans*fact[nlt])%MOD;
        ans =  (ans*fact[ngt])%MOD;

        

        if(nlt > lt || ngt > gt) cout<<0<<endl;
        else cout<<ans<<endl;



    
        
    
    
    }
    return 0;
}