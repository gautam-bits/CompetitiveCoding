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
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
vector<ll> bfs(ll s , ll e, ll n){

} 
// vector<ll> solve(int s, ll n) {
//     queue<ll> q;
//     q.emplace(s);

//     vector<bool> visited(n,false);
//     visited[s - 1] = true;

//     vector<ll> prev(n,-1);
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         vector<int> neighbours = g[node - 1]
//     }

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m,a,b,q ;
        
        cin>>n>>m ;
        vector<int> adj[10] ;

        fo(i,0,m){
            cin>>a>>b;
            adj[a - 1].pb(b);
            adj[b - 1].pb(a);
        }
        cin>>q;
        fo(i,0,q){
            cin>>a>>b;
            a--;
            bool present = false;

            fo(j,0,adj[a].size())
                if(adj[a][j] == b)
                    present = true;
            
            if(present) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
    
    
    }
    return 0;
}