#include <bits/stdc++.h>
using namespace std;
    
#define pb push_back
#define MP make_pair
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

#define fo(i,a,b) for(int i=a;i<b;i++)
#define rfo(i,b,a) for(int i=b;i>=a;i--)

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;

vector<vpi> adjlist;
vector<bool> visited;
vi parent;
vi sidebranch;
vvi ans;


void dfs(ll node){
    visited[node] = 1;

    if(node == 0) {
        ans[node][0] = 0;
        ans[node][1] = sidebranch[node];
        
    }

    for(pi x : adjlist[node]) if(!visited[x.first]) {

        ans[x.first][0] = min(2*x.second + ans[node][0],x.second + sidebranch[x.first] + ans[node][1]);
        ans[x.first][1] = min(2*x.second + sidebranch[x.first] + ans[node][0],x.second + ans[node][1]);

        dfs(x.first);

    }
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<"yo";
    ll n;
    cin>>n;

    // cout<<"yo";

    visited.assign(n,0);
    parent.assign(n,-1);
    sidebranch.assign(n,0);
    ans.assign(n,vi(2,0));
    adjlist.assign(n,vpi());

    

    fo(i,0,n-1){
        ll u,v,w;
        cin>>u>>v>>w;
        
        u--;
        v--;
        adjlist[u].pb({v,w});
        adjlist[v].pb({u,w});
    }

    fo(i,0,n) {
        cin>>sidebranch[i];
    }

    // cout<<"yo";

    dfs(0);

    // cout<<"yo";

    ll q;
    cin>>q;


    fo(i,0,q){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;

        cout<<ans[u][0]<<endl;


    }


    
	return 0;
}
