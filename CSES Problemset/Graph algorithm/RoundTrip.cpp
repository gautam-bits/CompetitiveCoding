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
    // #define endl "\n" 
    
    
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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    read(n);
    read(m);

    vvi adjList(n,vi());
    vector<int> parent(n,-2);



    auto addEdge = [&] () {
        ll u,v;
        read(u);
        read(v);
        u--;
        v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    };

    fo(i,0,m) addEdge();



    auto bfs = [&] (ll node) -> pi {

        bool found  = 0;

        queue<ll> q;
        q.push(node);
        parent[node] = -1;

        

        while(!q.empty()) {
            ll curr = q.front();
            q.pop();

            for(ll child : adjList[curr]) if(child != parent[curr]) {

                if(parent[child] != -2) {

                    return {child,curr};
                    
                }

                else {
                    parent[child] = curr;
                    q.push(child);
                }


            }


        }

        return {-1,-1};
    };

    fo(i,0,n){
        if(parent[i] == -2) {
            
            pi exists = bfs(i);
            

            if(exists != pi({-1,-1})) {
                csp(exists.F + 1);cnl(exists.S + 1);

                fo(i,0,n){
                    csp(i);cnl(parent[i]);
                }


                vi arr1,arr2;

                ll curr;

                curr = exists.S;

                ll xx;

                
                //cnl(exists.F);
                if(parent[exists.F] < 0) xx = -1;
                else xx = parent[parent[exists.F]];

                while(parent[curr] != xx) {
                    arr1.pb(curr + 1);
                    curr = parent[curr];
                }

                cnl("yo");

                arr1.pb(curr + 1);

                curr = exists.F;

                while(parent[curr] != xx) {
                    arr2.pb(curr + 1);
                    curr = parent[curr];
                }

                reverse(all(arr2));

                cnl(arr1.size() + arr2.size() + 1);

                for(ll x : arr1) csp(x);
                for(ll x : arr2) csp(x);

                cnl(arr1[0]);







                return 0;
            }
        }
    }



    cnl("IMPOSSIBLE");







    return 0;
}