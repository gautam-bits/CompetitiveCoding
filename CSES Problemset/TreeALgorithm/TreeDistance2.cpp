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

vvi adjList;
vi visited;
vi cnt;
vi ans;
vi dist;

ll dfs1(ll node,ll di) {
    visited[node] = 1;
    dist[node] = di;
    cnt[node] = 1;

    for(ll ch : adjList[node]) if(!visited[ch]) {
        cnt[node] += dfs1(ch,di+1);
    }

    return cnt[node];
}


void dfs2(ll node){
    visited[node] = 1;
    
    ll n = visited.size();

    for(ll ch : adjList[node]) if(!visited[ch]) {
        ans[ch] = ans[node] - 2*cnt[ch] + n;
        dfs2(ch);
    }
}





    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    read(n);

    adjList.assign(n,vi());
    visited.assign(n,0);
    cnt.assign(n,0);
    ans.assign(n,0);
    dist.assign(n,0);

    fo(i,0,n-1) {
        ll a,b;
        read(a);
        read(b);
        a--;
        b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    ll temp = dfs1(0,0);

    // vshow1d(cnt);
    // vshow1d(dist);

    fo(i,0,n) ans[0] += dist[i];

    visited.assign(n,0);
    dfs2(0);

    vshow1d(ans);

    return 0;
}