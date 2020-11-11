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
    
    
    typedef vector<ll> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

void dfs1(vector<vi>& graph, vi& val, ll node){
    if(graph[node].empty()) {
        val[node] = 1;
        return;
    }
    for(ll x : graph[node]){
        dfs1(graph,val,x);
        val[node] += val[x];
    }
    val[node]++;
}  
ll anss(vector<vi>& graph, vi& val, ll node){
    if(graph[node].empty()) {
        return val[node];
    }
    ll maxx = -1;
    for(ll x : graph[node]){
        maxx = max(maxx,anss(graph,val,x));
    }
    return val[node] + maxx;
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    //cout<<t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        //cout<<n;
        vector<vi> graph(n+1);
        vi val(n+1,0); // val[node]
        //vi ans(n+1,0);

        ll temp;
        fo(i,2,n+1){
            cin>>temp;
            graph[temp].pb(i);
        }

        dfs1(graph,val,1);
        // fo(i,1,n+1){
        //     cout<<val[i]<<" ";
        // }
    
        cout << anss(graph,val,1)<< endl;
    }
    return 0;
}