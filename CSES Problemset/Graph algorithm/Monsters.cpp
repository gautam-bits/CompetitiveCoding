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

    //cnl(m);
 
    ptt st;

    vector<ptt> ed;
 
 
    vector<vector<char>> grid(n,vector<char> (m,0));
 
    vector<vector<ptt>> parent(n,vector<ptt> (m,ptt()));

    vvi dist(n,vi(m,-1));
    vvi dist2(n,vi(m,-1));
 
    //map<ptt,ptt> parent;
 
    cinarr2d(n,m,grid);

    //cnl(grid[0][0]);
 
 
    fo(i,0,n) {
        fo(j,0,m) {
            if(grid[i][j] == 'A') st = vi({i,j});
            else if(grid[i][j] == 'M') ed.pb(vi({i,j}));
        }
    }
 
    // vshow2d(grid);
    
 
    auto isValid = [&](ptt p) {
        return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m && grid[p.x][p.y] != '#';
    };
 
 
    // queue<ptt> q;
 
    // q.push(st);
 
    // parent[st.x][st.y] = ptt();
    
 
    // bool poss = 0;
 
 
    // while(!q.empty()) {
 
    //     //cnl("yo");
        
    //     ptt curr = q.front();
    //     q.pop();
 
    //     fo(i,0,4) {
    //         ptt child(vi({curr.x+d4x[i],curr.y+d4y[i]}));

            
 
    //         if(isValid(child) && parent[child.x][child.y] == ptt() && child != st) {
 
    //             //csp(child.x);cnl(child.y);
    //             q.push(child);
    //             parent[child.x][child.y] = curr;
    //             if(grid[child.x][child.y] == 'B') {
    //                 poss = 1;
    //                 break;
    //             }
    //         }
    //     }
    // }

    queue<ptt> q1;
 
    for(ptt pt : ed) {
        q1.push(pt);
        dist[pt.x][pt.y] = 0;
    }
 
 
    while(!q1.empty()) {
 
        //cnl("yo");
        
        ptt curr = q1.front();
        q1.pop();
 
        fo(i,0,4) {
            ptt child(vi({curr.x+d4x[i],curr.y+d4y[i]}));

            
 
            if(isValid(child) && dist[child.x][child.y] == -1) {
 
                //csp(child.x);cnl(child.y);
                q1.push(child);
                dist[child.x][child.y] = dist[curr.x][curr.y] + 1;
                // parent[child.x][child.y] = curr;
            }
        }
    }

    //vshow2d(dist);


    queue<ptt> q;
 
    q.push(st);
 
    parent[st.x][st.y] = ptt();

    dist2[st.x][st.y] = 0;
    
 
    bool poss = 0;
 
 
    while(!q.empty()) {
 
        //cnl("yo");
        
        ptt curr = q.front();
        q.pop();
 
        fo(i,0,4) {
            ptt child(vi({curr.x+d4x[i],curr.y+d4y[i]}));

            
 
            if(isValid(child) && parent[child.x][child.y] == ptt() && child != st && (dist[child.x][child.y] < 0 || dist[child.x][child.y] > dist2[curr.x][curr.y] + 1)) {
 
                //csp(child.x);cnl(child.y);
                q.push(child);
                parent[child.x][child.y] = curr;
                dist2[child.x][child.y] = dist2[curr.x][curr.y] + 1;
            }
        }
    }


    //vshow2d(dist);

    


    fo(i,0,n){
        fo(j,0,m){
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(dist2[i][j] >= 0) {

                    //csp(i);cnl(j);


                    string ans = "";
 
                    ptt curr = vi({i,j});
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

                    cnl("YES");
                
                    cnl(no);
                    cnl(ans);


                    return 0;

                }
            }
        }
    }
 

    cnl("NO");
 
    // if(!poss) {
    //     cnl("NO");
    //     return 0;
    // }
 
    // cnl("YES");
 
    // // csp(ed.x);cnl(ed.y);
 
 
    // string ans = "";
 
    // ptt curr = ed;
    // ll no = 0;
 
    // while(parent[curr.x][curr.y] != ptt(vi{-1,-1})) {
    //     no++;
    //     ptt temp = parent[curr.x][curr.y];
 
        
 
    //     if(curr.x - temp.x == 1) ans += 'D';
    //     else if(curr.x - temp.x == -1) ans += 'U';
    //     else if(curr.y - temp.y == 1) ans += 'R';
    //     else if(curr.y - temp.y == -1) ans += 'L';
 
    //     curr = temp;
 
 
    // }
 
    // reverse(all(ans));
 
    // cnl(no);
    // cnl(ans);
 
    
 
 
    
 
 
 
 
    return 0;
}