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

vector<bool> taken; // global boolean flag to avoid cycle
priority_queue<pair<ll,ll>> pq;

ll distt(ll vtx,ll j, vector<vi>& AdjList) {
    ll ans = 0;
    //cout<<AdjList[0].size()<<" "<<AdjList.size()<<endl;
    fo(i,0,AdjList[0].size()){
        ans += abs(AdjList[vtx][i] - AdjList[j][i]);
    }
    return ans;
}


void process(ll vtx, vector<vi>& AdjList) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    //cout<<AdjList[0].size()<<" "<<AdjList.size()<<endl;
    for (ll j = 0; j < (ll)AdjList.size(); j++) {
    if(j != vtx && !taken[j]){
        //pair<ll,ll> v = AdjList[vtx][j];
        // cout<<"jffd"<<endl;
        //pq.push({v.second, v.first});
        ll tem = distt(vtx,j,AdjList);
        //cout<<vtx<<" "<<j<<" "<<tem<<endl;
        pq.push({tem,j});
    }
    
} }

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    //cin>>t;
    t = 1;
    
    while(t--)
    {
        //cout<<"dd";
        //taken.a
        ll n,d;
        cin>>n>>d;
        
        //ll temp[n][d];
        //vi abc (d,0);
        vector<vi> temp(n, vi (d,0));

        //vector<vector<pair<ll,ll>>> adjList(n);

        fo(i,0,n) fo(j,0,d) cin>>temp[i][j];

        // fo(i,0,n){
        //     fo(j,0,n){
        //         if(j!=i){
        //             ll te = 0;
        //             fo(x,0,d){
        //                 te += abs(temp[i][x] - temp[j][x]);
        //             }
        //             adjList[i].pb({j,te});
        //         }
        //     }
        // }

        taken.assign(n, 0);
        // priority_queue<ii> pq;
        //priority_queue<pair<int,int>> ff;

        process(0,temp);

        ll mst_cost = 0,cnt = 0;
        while (cnt < n - 1) { // repeat until V vertices (E=V-1 edges) are taken
        pair<ll,ll> front = pq.top(); pq.pop();
        ll u = front.second;
        ll w = front.first; // negate the id and weight again
        if (!taken[u]) // we have not connected this vertex yet
        cnt++, mst_cost += w, process(u,temp); // take u, process all edges incident to u
        }

        cout<<mst_cost<<endl;    
    
    }
    return 0;
}