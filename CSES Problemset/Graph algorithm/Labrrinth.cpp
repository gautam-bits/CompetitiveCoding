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
    #define ll int
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
 
    const ll d4x[4] = {1,0,-1,0};
    const ll d4y[4] = {0,1,0,-1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
 
struct ptt {
    ll x;
    ll y;
 
    ptt(vi ar) {
        assert(ar.size() == 2);
        x = ar[0];
        y = ar[1];
    }
 
    ptt() {
        x = -1;
        y = -1;
    }
 

 
    bool operator < (const ptt& d) const {
        if(x == d.x) {
            return y < d.y;
        }
        return x < d.x;
    }
 
    bool operator != (const ptt& d) const {
        return !(d.x == x && d.y == y);
    }
 
    bool operator == (const ptt& d) const {
        return (d.x == x && d.y == y);
    }
 
};
 
 
 
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    read(n);
    read(m);
 
    ptt st,ed;
 
 
    vector<vector<char>> grid(n,vector<char> (m,0));
 
    vector<vector<ptt>> parent(n,vector<ptt> (m,ptt()));
 
    //map<ptt,ptt> parent;
 
    cinarr2d(n,m,grid);
 
 
    fo(i,0,n) {
        fo(j,0,m) {
            if(grid[i][j] == 'A') st = vi({i,j});
            else if(grid[i][j] == 'B') ed = vi({i,j});
        }
    }
 
    
 
    auto isValid = [&](ptt p) {
        return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m && grid[p.x][p.y] != '#';
    };
 
 
    queue<ptt> q;
 
    q.push(st);
 
    parent[st.x][st.y] = ptt();
    
 
    bool poss = 0;
 
 
    while(!q.empty()) {
 
        //cnl("yo");
        
        ptt curr = q.front();
        q.pop();
 
        fo(i,0,4) {
            ptt child(vi({curr.x+d4x[i],curr.y+d4y[i]}));
 
            // csp(curr.x);cnl(curr.y);
 
            //csp(child.x);cnl(child.y);
 
            //if(isValid(child)) cnl("ff");
            
 
            if(isValid(child) && parent[child.x][child.y] == ptt() && child != st) {
 
                //csp(child.x);cnl(child.y);
                q.push(child);
                parent[child.x][child.y] = curr;
                if(grid[child.x][child.y] == 'B') {
                    poss = 1;
                    break;
                }
            }
        }
    }
 
 
    if(!poss) {
        cnl("NO");
        return 0;
    }
 
    cnl("YES");
 
    // csp(ed.x);cnl(ed.y);
 
 
    string ans = "";
 
    ptt curr = ed;
    ll no = 0;
 
    while(parent[curr.x][curr.y] != ptt(vi{-1,-1})) {
        no++;
        ptt temp = parent[curr.x][curr.y];
 
        
 
        if(curr.x - temp.x == 1) ans += 'D';
        else if(curr.x - temp.x == -1) ans += 'U';
        else if(curr.y - temp.y == 1) ans += 'R';
        else if(curr.y - temp.y == -1) ans += 'L';
 
        curr = temp;
 
 
    }
 
    reverse(all(ans));
 
    cnl(no);
    cnl(ans);
 
    
 
 
    
 
 
 
 
    return 0;
}