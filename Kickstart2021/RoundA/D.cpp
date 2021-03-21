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
    #define ctc(x) cout << "Case #"<<x<<": "
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

bool dfs(ll node,vvi& adj,vector<bool>& visited,ll parent){
    visited[node] = 1;

    for(ll xxx : adj[node]) {
        if(!visited[xxx]) {
            if(dfs(xxx,adj,visited,node)) return true;
        }
        else if(xxx != parent){
            return true;
        }
    }

    return false;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vvi mat(n,vi(n,0));
        vvi price(n,vi(n,0));

        cinarr2d(n,n,mat);
        cinarr2d(n,n,price);

        vi temp(n);

        cinarr(n,temp);
        cinarr(n,temp);

        vpi idxes;

        map<pi,ll> mp;

        fo(i,0,n){
            fo(j,0,n){
                if(mat[i][j] == -1) {
                    idxes.pb({i,j});
                }
            }
        }

        ll sz = idxes.size();

        ll cost = 1e17;

        fo(i,0,1<<sz) {
            vi tem;

            ll cpy_i = 0;
            ll id = 0;

            while(cpy_i > 0){
                if(cpy_i & 1) tem.pb(id);
                cpy_i >>= 1;
                id++;
            }

            vpi new1;

            for(ll gg: tem){
                new1.pb(idxes[gg]);
            }

            //vector<pair<pi,pi>> edge;
            

            ll sz2 = new1.size();
            vvi adj(sz2);
            fo(tt,0,sz2){
                fo(ttt,tt+1,sz){
                    if(new1[ttt].F == new1[tt].F || new1[ttt].S == new1[tt].S) {
                        adj[ttt].pb(tt);
                        adj[tt].pb(ttt);
                    }
                }
            }

            vector<bool> visited(sz2,0);

            bool yes = dfs(0,adj,visited,-1);

            if(yes) {
                ll tcc = 0;

                for(pi dfd : new1) {
                    tcc += price[dfd.F][dfd.S];
                }
                cost = min(cost,tcc);
            }


        }

        ctc(tno);cnl(cost);





        
    
    }
    return 0;
}