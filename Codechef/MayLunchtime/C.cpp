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

vector<bool> visited;
vvi adjList;
vi parent;
vector<bool> isCoin;
vi maxdepth;
vi depth;
ll ans;

void dfs(ll node) {

    bool islef = 1;

    for(ll ch : adjList[node]) if(ch != parent[node]) {
        islef = 0;
        dfs(ch);
    }

    if(islef) {
        if(isCoin[node]){
            depth[node] = 1;
            //csp("dpt");cnl(node);
            maxdepth[node] = 1;
        }
    }

    else {
        if(isCoin[node]) {
            ll mx = 0;
            ll chmx = -1;
            for(ll ch : adjList[node]) if(ch != parent[node]) {
                if(depth[ch] > mx){
                    mx = depth[ch];
                    chmx = ch;
                }
            }
            for(ll ch : adjList[node]) if(ch != parent[node]) {
                if(ch == chmx) maxdepth[node] += maxdepth[ch];
                else if(depth[ch] == mx) maxdepth[node]++;
            }

            mx++;
            depth[node] = mx;
        }

        else{

            ll mx1 = 0;
            ll mxidx = -1;
            ll mx2 = -100000000;

            fo(i,0,adjList[node].size()) if(adjList[node][i] != parent[node]) {
                ll ch = adjList[node][i];

                if(depth[ch] > mx1){
                    mx1 = depth[ch];
                    mxidx = i;
                }

            }
            fo(i,0,adjList[node].size()) if(adjList[node][i] != parent[node]) {
                ll ch = adjList[node][i];

                if(depth[ch] > mx2 && i != mxidx){
                    mx2 = depth[ch];
                }

            }

            if(mx1 > 0){
                ll ccch = adjList[node][mxidx];
                if(maxdepth[ccch] > 1) {
                    depth[node] = mx1 + 1;
                }
                else {
                    depth[node] = max(mx1,mx2+1);
                } 
            }

            fo(i,0,adjList[node].size()) if(adjList[node][i] != parent[node]) {
                ll ch = adjList[node][i];

                if(i == mxidx){
                    if(depth[ch] + 1 == depth[node]){
                        maxdepth[node] += maxdepth[ch] - 1; 
                    }
                }
                else {
                    if(depth[ch] +1 == depth[node]){
                        maxdepth[node] += maxdepth[ch];
                    }
                }

            }


            ans += mx1;

            if(mx1 > 0) isCoin[node] = 1;

        }
    }
}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);
        string str;
        read(str);

        visited.assign(n,0);
        adjList.assign(n,vi());
        isCoin.assign(n,0);
        depth.assign(n,0);
        parent.assign(n,-1);
        maxdepth.assign(n,0);
        ans = 0;

        fo(i,0,n) {
            if(str[i] == '1') isCoin[i] = 1; 
        }

        fo(i,1,n){
            ll temp;
            read(temp);
            temp--;
            adjList[i].pb(temp);
            adjList[temp].pb(i);
            parent[i] = temp;
        }


        dfs(0);
        //vshow1d(depth);

        cnl(ans);





    
    }
    return 0;
}