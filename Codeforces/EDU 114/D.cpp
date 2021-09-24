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
    #define ll2 long long
    #define lb lower_bound
    #define ub upper_bound
    #define bs binary_search

    #define endl "\n" 

    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x
    #define cinarr(n,arr) fo(i,0,n) read(arr[i]);
    #define cinarr2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) read(arr[i][j]);}}
    #define all(v) v.begin(),v.end()

    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll n = arr.size(); fo(ii,0,n) {csp(arr[ii]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {ll n=arr.size();   fo(i,0,n) {ll m = arr[i].size(); fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
int32_t main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        ll n;
        read(n);

        vvi mat(n);
        vi te2(n);

        fo(i,0,n) {
            ll sz;
            read(sz);
            vi te(sz);
            
            fo(j,0,sz) read(te[j]);
            mat[i] = te;
        }

        set<vi> s;

        ll m;
        read(m);

        fo(i,0,m) {
            fo(j,0,n) {
                read(te2[j]);
                te2[j]--;
            }
            s.insert(te2);
        }

        vi curr(n+1);
        vi to(n);
        vi te(n);
        ll sm = 0;

        fo(i,0,n) {
            curr[i+1] = (ll)mat[i].size()-1;
            sm += mat[i][(ll)mat[i].size()-1];
        }
        curr[0] = sm;

        priority_queue<vi> pq;
        pq.push(curr);

        // for(auto x : s) vshow1d(x);

        // vshow1d(curr);

        // cnl("ffffffff");

        ll diff;
        while(!pq.empty()) {
            to = pq.top();

            // vshow1d(to);
            pq.pop();

            fo(i,0,n) te[i] = to[i+1];
            if(s.find(te) == s.end()) {
                fo(i,0,n) te[i]++;
                vshow1d(te);
                return 0;
            }

            fo(i,0,n) {
                if(to[i+1] > 0) {
                    diff = mat[i][to[i+1]] - mat[i][to[i+1]-1];
                    to[i+1]--;
                    to[0] -= diff;
                    pq.push(to);
                    to[i+1]++;
                    to[0] += diff;
                }
            }
        }



    
    
    return 0;
}

/**
 🍪 the_hyp0cr1t3
 🍪 20.09.2021 20:55:53
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5, K = 10;

struct item {
    int val;
    array<int, K> build;

    bool operator<(const item& o) const {
        return val < o.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n;

    item start;
    start.val = 0;
    start.build.fill(0);

    vector<vector<int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> start.build[i];
        a[i].resize(start.build[i]--);
        for(auto& x: a[i])
            cin >> x;
        start.val += a[i].back();
    }

    cin >> m;
    set<array<int, K>> forbidden;
    while(m--) {
        array<int, K> b{};
        for(i = 0; i < n; i++)
            cin >> b[i], --b[i];
        forbidden.insert(b);
    }

    priority_queue<item> pq;
    pq.emplace(start);
    while(true) {
        auto cur = pq.top(); pq.pop();
        if(!forbidden.count(cur.build)) {
            for(i = 0; i < n; i++)
                cout << cur.build[i] + 1 << ' ';
            return 0;
        }
        for(i = 0; i < n; i++) if(cur.build[i]) {
            auto nxt = cur;
            nxt.val -= a[i][cur.build[i]] - a[i][--nxt.build[i]];
            pq.emplace(nxt);
        }
    }
} // ~W