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

vector<vector<vector<ll>>> dp;

ll solve(string& num,ll n,ll lastdig,bool tight) {
    if(n==0) {
        return 1;
    }
    if(dp[n][lastdig][tight] != -1) return dp[n][lastdig][tight];

    ll ubb = tight ? num[num.size() - n] -'0': 9;

    ll ans = 0;

    if(lastdig == ubb) {
        for(ll dig = 0 ; dig <= 9 ; dig++){
            if(dig != lastdig) {
                ans += solve(num,n-1,dig,tight&1);
            }
        }
    }

    else {
        for(ll dig = 0 ; dig <= 9 ; dig++){
            if(dig != lastdig) {
                ans += solve(num,n-1,dig,0);
            }
        }
    }
    return dp[n][lastdig][tight] =  ans;

}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;

    string mx = to_string(b);
    string mn = to_string(a-1);
    dp.assign(20,vector<vector<ll>>(10,vector<ll>(2,-1)));

    ll ans1 = 0;
    ll ans2 = 0;

    for(ll i = 0 ; i <= mx[0] - '0'; i++) {
        if(i==mx[0] - '0') ans1+=solve(mx,mx.size(),i,1);
        else ans1+=solve(mx,mx.size(),i,0);
    }

    for(ll i = 0 ; i <= mn[0] - '0'; i++) {
        if(i==mn[0] - '0') ans2+=solve(mn,mn.size(),i,1);
        else ans2+=solve(mn,mn.size(),i,0);
    }

    cnl(ans1);

    
    int ans = ans1 - ans2;

    cout<<ans<<endl;
    return 0;
}