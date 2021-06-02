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

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vvi dp;
ll prod;
vi a,b;

ll calc(ll i,ll j) {

    //return 5;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(i == j) {
        dp[i][j] = prod;
        return prod;
    }

    if(j == i + 1) {
        ll ans = prod - a[j]*b[j] - a[i]*b[i] + a[j]*b[i] + a[i]*b[j];
        dp[i][j] = ans;
        return ans;
    }

    ll a1;

    if(dp[i+1][j-1] != -1) {
        a1 = dp[i+1][j-1];
    }

    else a1 = calc(i+1,j-1);

    ll ans = a1 - a[j]*b[j] - a[i]*b[i] + a[j]*b[i] + a[i]*b[j];

    dp[i][j] = ans;

    return ans;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    read(n);

    a.assign(n,0);
    b.assign(n,0);
    prod = 0;
    //dp.clear();
    dp.assign(n,vi(n,-1));

    cinarr(n,a);
    cinarr(n,b);

    fo(i,0,n) prod += a[i]*b[i];

    ll fin = -1;


    fo(i,0,n){
        fo(j,i,n) {
            fin = max(fin,calc(i,j));
        }
    }

    cnl(fin);




    return 0;
}