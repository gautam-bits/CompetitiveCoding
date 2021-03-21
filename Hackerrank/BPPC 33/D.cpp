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
    #define test(t) ing t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {int n = arr.size(); fo(i,0,n) {csp(arr[i]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {int n=arr.size();   fo(i,0,n) {int m = arr[i].size(); fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    

    #define endl "\n" 
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef pair<int,pair<int,int>> ppi;

    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
priority_queue<ppi> pq;
vector<vector<pi>> adjList;
vi taken;

void process(int vtx){
    taken[vtx] = 1;
    fo(j,0,adjList[vtx].size()) {
        pi v = adjList[vtx][j];
        if(!taken[v.F]) pq.push(MP(-v.S,MP(-v.F,-vtx)));
    }
}
int_fast32_t main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    read(n);

    vpi points(n);

    int x,y;

    fo(i,0,n) {
        read(x);
        read(y);

        points[i] = {x,y};
        //csp(x);cnl(y);
    }

    adjList.clear();
    adjList.resize(n);
    taken.assign(n,0);


    fo(i,0,n){
        fo(j,i+1,n){
            int dist = abs((points[i].F - points[j].F)*(points[i].F - points[j].F) + (points[i].S - points[j].S)*(points[i].S - points[j].S));
            //cnl(dist);

            adjList[i].pb({j,dist});
            adjList[j].pb({i,dist});
        }
    }

    
    process(0);

    int cost = 0;

    int cnt  = 0;

    vi ans(n,0);

    while(cnt < n -1) {
        ppi front = pq.top();
        pq.pop();
        int v1 = -front.S.F;
        int v2 = -front.S.S;
        int w = -front.F;

        if(!taken[v1]){
            cost += w;
            ans[v1] = max(ans[v1],w);
            ans[v2] = max(ans[v2],w);
            process(v1);
            cnt++;
        }
    }

    vshow1d(ans);
    
    

    return 0;
}