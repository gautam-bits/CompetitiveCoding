    #include <bits/stdc++.h>
    using namespace std;
    
    #define pb push_back
    #define ll long long


    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x


    #define fo(i,a,b) for(int i=a;i<b;i++)

    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    
    #define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    const ll MOD   = 1000000007 ;

    

vvi adjList;
vector<bool> visited;
vi longSum;
vi allSum;


ll dfs1(ll node){
    visited[node] = 1;

    ll sum = 0;
    for(ll child : adjList[node]) if(!visited[child]){
        ll te = dfs1(child);
        sum = (sum + te)%MOD;
    }

    longSum[node] = (longSum[node] + sum)%MOD;
    sum = (sum + longSum[node])%MOD;

    return sum;
}

void dfs2(ll node) {
    visited[node] = 1;
    for(ll child : adjList[node]) if(!visited[child]){
        dfs2(child);
        longSum[node] = (longSum[node] + longSum[child])%MOD;
    }
}


void dfs3(ll node) {
    visited[node] = 1;

    ll sum = 0;
    ll temp = 0;
    for(ll child : adjList[node])if(!visited[child]) {
        sum = (sum + longSum[child])%MOD;
        allSum[node] = (allSum[node] - longSum[child]*longSum[child] + MOD*MOD)%MOD;
        dfs3(child);
    }

    allSum[node] = (allSum[node] + sum*sum)%MOD;
}


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        adjList.assign(n,vi());
        visited.assign(n,0);
        longSum.assign(n,1);
        allSum.assign(n,0);


        auto addEdge = [](ll u,ll v)  {
            adjList[u].pb(v);
            adjList[v].pb(u);
            return;
            


        fo(i,0,n-1){
            ll u,v;
            read(u);read(v);
            u--;v--;
            addEdge(u,v);
        }

        ll ans = 0;


        dfs1(0);
        fo(i,0,n) ans =(ans + longSum[i])%MOD;
        visited.assign(n,0);


        dfs2(0);
        visited.assign(n,0);

        dfs3(0);
        fo(i,0,n) ans =(ans + allSum[i])%MOD;




        cnl(ans);


    
    }
    return 0;
}