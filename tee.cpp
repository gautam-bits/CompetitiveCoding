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



// code of LCA taken from cp algorithms  https://cp-algorithms.com/graph/lca.html
struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};




	
int main() 
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	test(t){     // tno[1..t]
	
		ll n,r,q;
		read(n);
		read(q);
		read(r);

		r--;

		vector<vector<ll>> adjList(n);

		vector<ll> dist(n,0);
		vector<bool> visited(n,0);


		vector<vector<pair<ll,ll>>> pi(n);

		ll aa,bb,cc;

		fo(i,0,n-1){
			read(aa);
			read(bb);
			read(cc);

			aa--;
			bb--;

			adjList[aa].pb(bb);
			adjList[bb].pb(aa);

			pi[aa].pb({bb,cc});
			pi[bb].pb({aa,cc});

		}

		LCA mylca(adjList,r);


		queue<ll> qu;

		qu.push(r);
		visited[r] = 1;


		while(!qu.empty()) {
			ll node = qu.front();

			qu.pop();

			for(auto pai : pi[node]) {
				if(!visited[pai.F]) {
					dist[pai.F] = dist[node] + pai.S;
					visited[pai.F] = 1;
					qu.push(pai.F);
				}
			}
		}

		fo(i,0,q) {
			ll l,r;
			read(l);
			read(r);

			l--;
			r--;

			ll xx = mylca.lca(l,r);

			cnl(dist[l] + dist[r] - (2*dist[xx]));
		}








	
	}
	return 0;
}