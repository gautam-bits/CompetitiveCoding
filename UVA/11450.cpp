// This is an intellectual property of Diablo Escata ,
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
ll M,C, cost[25][25];
ll dp[210][25];      //money, garment
ll shop(ll money, ll g) {
    if(money < 0) return (ll)-1e6;
    if(g == C) return M - money;
    if(dp[money][g] != -1) return dp[money][g];
    ll ans = -1 ;
    fo(model,1,cost[g][0] + 1){
        ans = max(ans,shop(money - cost[g][model],g+1));
    }

    dp[money][g] = ans;
    return ans;
    
}
void print_shop(ll money, ll g) {
    //cnl("dfdf");
    if(money < 0 || g == C) return;
    fo(model,1,cost[g][0] + 1) {
        if(shop(money - cost[g][model],g + 1) == dp[money][g]) {
            csp(cost[g][model]);
            print_shop(money-cost[g][model],g+1);
            if(g == C-1)cnl("");
            break;
        }
        
    }
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        read(M);
        read(C);
        ll ans;
        fo(i,0,C){
            read(cost[i][0]);
            fo(j,1,cost[i][0] + 1) read(cost[i][j]);
        }
        mem(dp,-1);

        ans = shop(M,0);
        //show2d(M,C,dp);
        if(ans < 0) {
            cnl("no solution");
        }
        else {
            //print_shop(M,0);   for printing backtracingly
            cnl(ans);
        }
    }
    return 0;
}