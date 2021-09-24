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
    typedef vector<vpi> vvpi;
 
    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    const ll INF = 1e18;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
 
vvpi adjList;
vi dist;
vector<bool> visited;
 
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    read(n);
    read(m);
 
    dist.assign(n,INF);
    adjList.assign(n,vpi());
    visited.assign(n,0);
 
    fo(i,0,m) {
        ll u,v,w;
        read(u);
        read(v);
        read(w);
        u--;
        v--;
 
        adjList[u].pb({v,w});
    }
 
 
    priority_queue<pi,vector<pi>,greater<pi>> pq;
 
    pq.push({0,0});
 
    dist[0] = 0;
 
 
 
    while(!pq.empty()) {
        //cnl("yo");
        
        ll u = pq.top().S;

        //cnl(u);
        pq.pop();
 
        if(visited[u]) continue;
 
        visited[u] = 1; 
 
        
 
        for(pi x : adjList[u]) {
 
            ll v = x.F;
            ll w = x.S;
 
            //csp(v);csp(w);csp(dist[v]);cnl(dist[u] + w);
 
            if(dist[v] > dist[u] + w) {
 
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
 
    vshow1d(dist);
 
    return 0;
}