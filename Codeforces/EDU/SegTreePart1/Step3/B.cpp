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
// seg tree template taken from https://github.com/Ashishgup1/Competitive-Coding/blob/master/Segment%20Tree.cpp

struct data
{
	//Use required attributes
	ll sum;

	//Default Values
	data() : sum(0) {};
};

struct SegTree
{
	ll N;
	vector<data> st;
	vector<bool> cLazy;
	vector<ll> lazy;
	vector<ll> array;

	void init(ll n,vector<ll> arr)
	{
		N = n;
		array = arr;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.sum = l.sum + r.sum;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(ll node, ll L, ll R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].sum = lazy[node];
		cLazy[node] = 0;
	}

	void build(ll node, ll L, ll R)
	{
		if(L==R)
		{
			st[node].sum = array[L];
			return;
		}
		ll M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(ll node, ll L, ll R, ll i, ll j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		ll M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	data pQuery(ll node, ll L, ll R, ll pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		ll M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

    ll find_kth(ll node,ll L,ll R,ll k) {

        //csp(L);csp(R);csp(k);cnl(st[2*node].sum);
        if(cLazy[node])
			propagate(node, L, R);

        
        if(L == R){
            return L;
        }


        ll M = (L + R)/2;

        if(st[2*node].sum >= k){
            return find_kth(2*node,L,M,k);
        }

        else {
            return find_kth(2*node+1,M+1,R,k-st[2*node].sum);
        }


        
    }

	void Update(ll node, ll L, ll R, ll i, ll j, ll val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		ll M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(ll node, ll L, ll R, ll pos, ll val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		ll M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(ll pos)
	{
		return pQuery(1, 1, N, pos);
	}

	data query(ll l, ll r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(ll pos, ll val)
	{
		pUpdate(1, 1, N, pos, val);
	}

	void update(ll l, ll r, ll val)
	{
		Update(1, 1, N, l, r, val);
	}
};


int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    read(n);

    vi arr1(n+1,1);

    vi arr2(n+1);

    fo(i,1,n+1) read(arr2[i]);

    vi ans(n+1);


    SegTree myseg;
    myseg.init(n,arr1);

    myseg.build(1,1,n);

    //cnl(myseg.query(1,n).sum 3m );

    ///ll idx = myseg.find_kth(1,1,n,4);
    //cnl(idx);


    rfo(i,n,1){
        //cnl(arr2[i]+1);
        ll idx = myseg.find_kth(1,1,n,myseg.st[1].sum - arr2[i]);
        ans[i]= idx;
        myseg.update(idx,0);
    }

    fo(i,1,n+1) csp(ans[i]);
    cnl("");





    return 0;
}