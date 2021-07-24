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

    const ll INF = 1e18;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

ll n;
vi arr;
vi pref;
vvi dp;


ll sums(ll i,ll j) {
    if(i == 0) return pref[j];
    else return pref[j] - pref[i-1];
}

ll calculate(ll i,ll j) {

    if(dp[i][j] != INF) return dp[i][j];

    if(i == j) {
        dp[i][j] = arr[i];
        return dp[i][j];
    }

    ll lef,rig;

    if(dp[i+1][j] != INF) lef = dp[i+1][j];
    lef = calculate(i+1,j);

    if(dp[i][j-1] != INF) lef = dp[i][j-1];
    rig = calculate(i,j-1);

    ll ans1 = arr[i] + (sums(i+1,j)-lef);
    ll ans2 = arr[j] + (sums(i,j-1)-rig);

    dp[i][j] = max(ans1,ans2);
    return dp[i][j];
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read(n);
    arr.assign(n,0);
    pref.assign(n,0);
    dp.assign(n,vi(n,INF));

    cinarr(n,arr);

    pref[0] = arr[0];

    fo(i,1,n) pref[i] = arr[i] + pref[i-1];


    cnl(calculate(0,n-1));
    
    return 0;
}