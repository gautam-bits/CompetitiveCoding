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

void dfs2(vector<vector<int>>& adjList,vector<bool>& visited,vector<int>& dist,int node,int val) {
    visited[node] = 1;
    dist[node] = val;

    for(int x : adjList[node]) if(!visited[x]) {
        dfs2(adjList,visited,dist,x,val+1);
    }
    
}

void dfs3(vector<vector<int>>& adjList,vector<bool>& visited,vector<bool>& isspec,vector<int>& specval,int node,int val){
    visited[node] = 1;
    if(isspec[node]) {
        specval[node] = node;
        val = node;
        //csp(node);cnl(specval[node]);
    }
    else{
        specval[node] = val;
        //csp(node);cnl(specval[node]);
    }
    for(int x : adjList[node]) if(!visited[x]) {
        dfs3(adjList,visited,isspec,specval,x,val);
    }
}

int dfs4(vector<vector<int>>& adjList,vector<bool>& visited,vector<bool>& isspec,vector<int>& downval,int node) {

    visited[node] = 1;

    int va = -1;

    for(int x : adjList[node]) if(!visited[x]) {
        va = dfs4(adjList,visited,isspec,downval,x);
        if(va != -1){
            downval[node] = va;
        }
    }

    if(downval[node] != -1) return downval[node];

    if(isspec[node]){
        downval[node] = node;
        return downval[node];
    }

    return -1;



}

void dfs5(vector<vector<int>>& adjList,vector<bool>& visited,vector<int>& downval,vector<int>& downval2,int node,int val) {
    visited[node] = 1;

    if(downval[node] == -1){
        downval2[node] = val;
    }
    else{
        val = node;
    }

    for(int x : adjList[node]) if(!visited[x]) {
        dfs5(adjList,visited,downval,downval2,x,val);
    }



}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        int n,k,a;

        read(n);
        read(k);
        read(a);

        a--;

        vi spec(k);

        ll temp;

        fo(i,0,k) {
            read(temp);
            temp--;
            spec[i] = temp;
        }

        vector<vector<int>> adjList(n);

        fo(i,0,n-1) {
            int u,v;
            read(u);
            read(v);
            u--;
            v--;

            adjList[u].pb(v);
            adjList[v].pb(u);

        }

        vector<bool> visited(n,0);
        vector<int> dist(n,0);
        vector<int> specval(n,-1);
        vector<bool> isspec(n,0);
        vector<int> downval(n,-1);
        vector<int> downval2(n,-1);

        fo(i,0,k) isspec[spec[i]] = 1;


        dfs2(adjList,visited,dist,a,0);

        visited.assign(n,0);

        dfs3(adjList,visited,isspec,specval,a,-1);

        visited.assign(n,0);

        dfs4(adjList,visited,isspec,downval,a);

        visited.assign(n,0);

        dfs5(adjList,visited,downval,downval2,a,-1);

        //vshow1d(specval);




        //vshow1d(specval);
        vector<int> ans(n,-1e9);
        vector<int> ans2(n);


        fo(i,0,n){
            if(downval[i] != -1){
                ans[i] = dist[i];
                ans2[i] = downval[i]+1;
            }
            else if(downval2[i] != -1) {
                ans[i] = 2*dist[downval2[i]] - dist[i];
                ans2[i] = downval[downval2[i]]+1;
            }
            else {
                ans[i] = -dist[i];
                ans2[i] = spec[0]+1;
            }
        }

        vshow1d(ans);
        vshow1d(ans2);


        

    
    }
    return 0;
}

/*
1
10 3 1
2 5 8
1 3
1 2
3 4
2 5
2 7
2 6
6 8
5 9
8 10

*/