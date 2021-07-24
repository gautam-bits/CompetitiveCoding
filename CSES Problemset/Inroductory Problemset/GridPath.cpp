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
    //#define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const ll dx[4] = {-1, 0, 1, 0};
    const ll dy[4] = {0, 1, 0, -1};

    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

const ll sz = 7;

vector<vector<bool>> visited;
ll ans;
string curr;
string given;

bool match() {
    //cnl(curr);
    if(curr.size() < sz*sz - 1) return 0;
    assert(curr.size() == given.size() && curr.size() == sz*sz - 1);

    fo(i,0,sz*sz - 1)  if(given[i] != '?' && given[i] != curr[i]) return 0;

    csp("king");cnl(curr);cnl(ans);
    return 1;
}


bool valid(ll x,ll y) {
    return x >=0 && x < sz && y >= 0 && y < sz;
}


void dfs(ll x,ll y) {
    //csp(x);csp(y);cnl(curr);

    //visited[x][y] = 1;

    if(x == sz-1 && y == sz-1) {
        if(match()) {
            ans++;
        }

        return;
    }

    fo(i,0,4){
        ll xx = x + dx[i];
        ll yy = y + dy[i];

        //csp(x);csp(y);csp(xx);cnl(yy);

        if(valid(xx,yy) && !visited[xx][yy]) {
            visited[xx][yy] = 1;
            
            if(xx - x == 1) curr += 'D';
            else if(xx - x == -1) curr += 'U';
            else if(yy - y == 1) curr += 'L';
            else if(yy - y == -1) curr += 'R';

            dfs(xx,yy);

            visited[xx][yy] = 0;
            curr.pop_back();
        }


    }
}




    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read(given);
    visited.assign(sz,vector<bool>(sz,0));
    ans = 0;
    curr = "";
    visited[0][0] = 1;

    dfs(0,0);
    cnl(ans);
    return 0;
}