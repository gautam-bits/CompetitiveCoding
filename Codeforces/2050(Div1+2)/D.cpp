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
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    const ll INF = 1e10;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//


vvi dp;
vector<vpi> adjList;

ll N,M,K;

ll calculate(ll node,ll k) {
    if(k == 0){
        dp[node][k] = 0;
        return 0;
    }

    if(dp[node][k] != INF) return dp[node][k];

    ll nn = node - M;
    ll ss = node + M;
    ll ee = node + 1;
    ll ww = node - 1;

    ll ans = INF;

    for(pi x : adjList[node]) {
        if(dp[x.F][k-1] != INF) {
            ans = min(ans,dp[x.F][k-1] + x.S);
        }
        else {
            ll te = calculate(x.F,k-1);
            dp[x.F][k-1] = te;
            ans = min(ans,dp[x.F][k-1] + x.S);
        }
    }

    return ans;
}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    read(N);
    read(M);
    read(K);

    
    adjList.clear();
    adjList.resize(N*M);

    dp.clear();

    dp.assign(N*M,vi(K+1,INF));


    fo(i,0,N){
        fo(j,0,M-1){
            ll x = j + i*M;
            ll y = x + 1;
            ll val;
            read(val);
            adjList[x].pb({y,val});
            adjList[y].pb({x,val});
        }
    }

    fo(i,0,N-1){
        fo(j,0,M){
            ll x = j + i*M;
            ll y = x + M;
            ll val;
            read(val);
            adjList[x].pb({y,val});
            adjList[y].pb({x,val});
        }
    }

    if(K%2 == 1) {
        
        fo(i,0,N){
            fo(j,0,M) {
                csp(-1);
            }
            cnl("");
        }

        return 0;
    }

    fo(i,0,N){
        fo(j,0,M) {
            ll temp = calculate(j + i*M,K/2);
            temp *=2;
            csp(temp);
        }
        cnl("");
    }



    


    
    
    return 0;
}