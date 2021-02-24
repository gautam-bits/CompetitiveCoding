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
    //const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
ll N,M;
pi st,ed;
vector<vector<char>> matrix;
vvi ans;
queue<pi> qu;
// ans = - 1 // not visited


bool isValid(ll i, ll j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void insertQ(pi node){
    //csp(node.F);cnl(node.S);
    ll idx = -1;
    ll val = -1; 


    //csp(node.F);cnl(node.S);

    //insert to
    idx = 1;
    val = ans[node.F][node.S];
    while(isValid(node.F, node.S - idx) && matrix[node.F][node.S - idx] != '*' && (ans[node.F][node.S - idx] == -2 || ans[node.F][node.S - idx] >= val + 1)) {
        //csp(node.F);cnl(node.S - idx);
        ans[node.F][node.S - idx] = val + 1;
        qu.push({node.F,node.S - idx});
        idx++;
    }

    //insert bottom
    idx = 1;
    val = ans[node.F][node.S];
    while(isValid(node.F, (node.S) + idx) && matrix[node.F][node.S + idx] != '*'  && (ans[node.F][node.S + idx] == -2 || ans[node.F][node.S + idx] >= val + 1)) {
        
        ans[node.F][node.S + idx] = val + 1;
        qu.push({node.F,node.S + idx});
        idx++;
    }

    //insert left
    idx = 1;
    val = ans[node.F][node.S];
    while(isValid((node.F) - idx, node.S) && matrix[node.F - idx][node.S] != '*' && (ans[node.F - idx][node.S] == -2 || ans[node.F - idx][node.S] >= val + 1)) {
        ans[node.F - idx][node.S] = val + 1;
        qu.push({node.F - idx,node.S});
        idx++;
    }

    //insert right
    idx = 1;
    val = ans[node.F][node.S];
    while(isValid(node.F + idx, node.S) && matrix[node.F + idx][node.S] != '*' && (ans[node.F + idx][node.S] == -2 || ans[node.F + idx][node.S] >= val + 1)) {
        ans[node.F + idx][node.S] = val + 1;
        qu.push({node.F + idx, node.S});
        idx++;
    }
}

void bfs() {
    
    assert(qu.size() == 0);

    qu.push({st.F,st.S});
    ans[st.F][st.S] = -1;

    while(!qu.empty()) {
        
        pi curr = qu.front();

        
        // csp(curr.F);cnl(curr.S);
        // cnl("");

        qu.pop();

        

        //insert at i j
        insertQ(curr);

    }


}




int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read(M);
    read(N);
    

    matrix.assign(N, vector<char> (M,'.'));
    ans.assign(N, vi (M,-2));

    bool rand = 0;
    fo(i,0,N) {
        fo(j,0,M) {
            read(matrix[i][j]);
            if(matrix[i][j] == 'C'){
                if(rand){
                    ed = {i,j};
                }
                else{
                    st = {i,j};
                    rand = 1;
                }
            }
        }
    }



    bfs();

    //vshow2d(ans);

    cnl(ans[ed.F][ed.S]);
    
    return 0;
}