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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;

        vi nodes[n];
        vector<bool> visited (n,false);
        vi ans(n,0);

        ll u,v;

        fo(i,0,n-1){
            cin>>u>>v;
            u--;
            v--;
            nodes[u].pb(v) ;
            nodes[v].pb(u) ;
        }

        queue<ll> rajat;

        rajat.push(0);
        visited[0] = true;
        ans[0] = 1;

        while(!rajat.empty()) {
            ll curr = rajat.front();
            rajat.pop();

            for(ll x : nodes[curr]){
                if(!visited[x]){
                    if(ans[curr] == 1) ans[x] = 2;
                    else ans[x] = 1;
                    visited[x] = true;
                    rajat.push(x);
                }  
            }
        }

        fo(i,0,n) cout<<ans[i]<<" ";
        cout<<endl;



    
    
    }
    return 0;
}