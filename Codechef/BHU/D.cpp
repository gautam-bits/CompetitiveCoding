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
vi cost;
vi leav;
vector<bool> visited;
map<pi,ll> mp;


void dfs(ll node,ll height) {

    visited[node] = 1;
    //cnl(adjList[node].size());
    // if(adjList[node].size() == 0) {
    //     //cnl("ff");
        
    //     leav.pb(node);
    //     return;
    // }

    bool le = 1;

    for(ll x : adjList[node]) if(!visited[x]) {
        le = 0;
        cost[x] = cost[node] + height*mp[{x,node}];
        dfs(x,height + 1);
    }

    if(le) {
        leav.pb(node);
    }


}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m;
        read(n);
        read(m);

        vi val(m);

        cinarr(m,val);

        adjList.clear();
        adjList.resize(n);
        cost.assign(n,0);
        leav.clear();
        visited.assign(n,0);
        mp.clear();



        ll u,v,k;

        fo(i,0,n-1) {
            read(u);
            read(v);
            read(k);
            u--;
            v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
            mp[{u,v}] = k;
            mp[{v,u}] = k;
            
        }

        dfs(0,1);

        //vshow2d(adjList);

        vi val2;

        for(ll x : leav) {
            if(x != 0) {
                val2.pb(cost[x]);
            }
        }

        sort(all(val2));
        sort(all(val));

        

        ll m2 = val2.size();

        ll idx1 = 0,idx2 = 0;

        ll ans = 0;

        // vshow2d(adjList);
        

        // vshow1d(val);
        // vshow1d(val2);
        // vshow1d(cost);

        while(idx1 < m && idx2 < m2) {
            if(val[idx1] >= val2[idx2]) {
                idx1++;
                idx2++;
                ans++;
            }

            else{
                idx1++;
            }
        }

        cnl(ans);



        




    
    }
    return 0;
}