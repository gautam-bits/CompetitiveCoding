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

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> ans;
map<int,vector<pair<int,int>>> queries;
vector<int> curr;


void dfs(int node) {
    visited[node] = 1;
    curr.push_back(node);
    int n = curr.size();
    for(auto que : queries[node]) {
        if(que.first <= n - 1) {
            ans[que.second] = curr[n - que.first - 1] + 1;
        }
    }

    for(int ch : adjList[node]) if(!visited[ch]) {
        dfs(ch);
    }

    curr.pop_back();
}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    adjList.assign(n,vector<int>());
    visited.assign(n,0);
    ans.assign(q,-1);
    queries.clear();
    curr.clear();

    for(int i = 1 ; i < n ; i++) {
        int temp;
        cin>>temp;
        temp--;
        adjList[i].push_back(temp);
        adjList[temp].push_back(i);
    }

    for(int i = 0 ; i < q ; i++) {
        int x,k;
        cin>>x>>k;
        x--;
        queries[x].push_back({k,i});
    }

    dfs(0);

    for(int i = 0 ; i < q ; i++) {
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}