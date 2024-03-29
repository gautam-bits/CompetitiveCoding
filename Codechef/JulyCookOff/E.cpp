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
    #define ll int
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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll arr[1005];
    ll cn[1005] = {0};
    ll dp[1005][1005];

    test(t){     // tno[1..t]
    
        ll n,k;
        read(n);
        read(k);

        for(int i = 0 ; i < n ; i++) read(arr[i]);
    

        fo(j,0,k+1) {
            fo(i,0,1005) cn[i] = 0;
            fo(i,0,n) {
                if(j == 0) {
                    dp[i][j] = max(dp[i][j],cn[arr[i]] + 1);
                    cn[arr[i]] = dp[i][j];
                }
                else {
                    if(i>0)dp[i][j] = dp[i-1][j-1] + 1;
                    dp[i][j] = max(dp[i][j],cn[arr[i]] + 1);
                    cn[arr[i]] = dp[i][j];
                }
            }
            fo(i,1,n) dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }

        fo(i,0,1005) cn[i] = 0;

        ll ans = 0;

        fo(i,0,n){
            fo(j,0,k+1){
                ans = max(ans,dp[i][j]);
            }
        }

        fo(j,0,k+1) {
            fo(i,0,n) {
                // csp(dp[i][j]);
                dp[i][j] = 0;
            }
            // cnl("");
        }

        cnl(ans);

        
    }
    return 0;
}