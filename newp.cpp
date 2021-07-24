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

    const ll MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi val;
vector<vpi> adjList;
vpi dp; // first for val without taking , second for val
vi visited;  
vpi ways;

void dfs(ll node,ll parent) {

  bool leaf = 1;


  ll v1 = 0;
  ll t1 = 1;
  ll a4 = 0;

  ll a3 = INT_MAX;
  for(pi ch : adjList[node]) if(ch.F != parent) {
      leaf = 0;
      dfs(ch.F,node);
      // v1 += min(dp[ch.F].F,dp[ch.F].S);
      t1 *= (ways[ch.F].F + ways[ch.F].S);
      if(dp[ch.F].F < dp[ch.F].S) {
        v1 += dp[ch.F].F;
        ways[node].F += ways[ch.F].F;
      } 
      else if(dp[ch.F].F > dp[ch.F].S) {
        v1 += dp[ch.F].S;
        ways[node].F *= ways[ch.F].S;
      }
      else {
        v1 += dp[ch.F].S;
        ways[node].F *= ways[ch.F].S + ways[ch.F].F;
      } 
  }

  // csp("n");csp(node);cnl(t1);


  dp[node].F = v1 + val[node];

  for(pi ch : adjList[node]) if(ch.F != parent) {    
    a3 = min(a3,v1 - min(dp[ch.F].F,dp[ch.F].S) + ch.second + dp[ch.F].F - val[ch.F]); 
  }

  for(pi ch : adjList[node]) if(ch.F != parent) {    
    // a3 = min(a3,v1 - min(dp[ch.F].F,dp[ch.F].S) + ch.second + dp[ch.F].F - val[ch.F]); 

    if(v1 - min(dp[ch.F].F,dp[ch.F].S) + ch.second + dp[ch.F].F - val[ch.F] == a3) {
      a4 += (t1/((ways[ch.F].F + ways[ch.F].S)))*(ways[ch.F].F);
    }
  }


  dp[node].S = a3;
  ways[node].S = a4;

  if(leaf) {
    dp[node].F = val[node];
    dp[node].S = val[node];
    ways[node] = {1,0};
  }

}
    
int main() 
{
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n;
  read(n);

  val.assign(n,0);
  adjList.assign(n,vpi());
  dp.assign(n,{-1,-1});
  visited.assign(n,0);
  ways.assign(n,{1,1});

  cinarr(n,val);

  fo(i,0,n-1) {
    ll u,v,w;

    read(u);
    read(v);
    read(w);

    u--;
    v--;

    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
  }



  dfs(0,-1);

  // fo(i,0,n) {
  //   csp(ways[i].F);cnl(ways[i].S);
  // }

  // cnl(ways[0].F);
  // cnl(ways[])

  // cnl(min(dp[0].F,dp[0].S));


  if(dp[0].F < dp[0].S) {
    csp(dp[0].F);cnl(ways[0].F);
  }
  else if(dp[0].F > dp[0].S) {
    csp(dp[0].S);cnl(ways[0].S);
  }
  else {
    csp(dp[0].S);cnl(ways[0].S + ways[0].F);
  }




  
  return 0;
}