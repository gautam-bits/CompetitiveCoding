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
vi parent ;
vi rank_element;
vi sz_set;
ll noOfDisSets;

ll findSet(ll i) {              // find the representative element of i in the forest
    if(i == parent[i]) {
        return i;
    }
    parent[i] = findSet(parent[i]);
    return parent[i];
}

bool isSameSet(ll i,ll j){
    return findSet(i) == findSet(j);
}

void unionSet(ll i, ll j) {    // merging sets containing i and j
    if(!isSameSet(i,j)) {
        ll x = findSet(i);
        ll y = findSet(j);

        noOfDisSets--; // if we are merging 2 different sets

        if(rank_element[x] > rank_element[y]){
            parent[y] = x;
            sz_set[x] += sz_set[y];  //increasing the size
        }
        else {
            parent[x] = y;
            sz_set[y] += sz_set[x];  //increasing the size
            if(rank_element[x] == rank_element[y]) rank_element[y]++;
        }

    }
}

ll sizeOfSet(ll i) {    // returns size of set that currently contains i
    ll x = findSet(i);
    return sz_set[x];
}

ll noOfDisjointSets() {
    return noOfDisSets;
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m,k;
        read(n);
        read(m);
        read(k);

        //reset global variables
        parent.assign(n,0);
        rank_element.assign(n,0);
        sz_set.assign(n,1);
        noOfDisSets = n;
        fo(i,0,n)parent[i] = i;


        vvi edges(m);

        ll u,v,w;

        fo(i,0,m) {
            read(u);read(v);read(w);
            u--;v--;

            edges[i] = {w,u,v};
        }

        sort(all(edges));

        vector<bool> visited(m,0);

        
        fo(i,0,m) {
            if(edges[i][0] <= k) {
                if(!isSameSet(edges[i][1],edges[i][2])) {
                    visited[i] = 1;
                    unionSet(edges[i][1],edges[i][2]);
                }
            }
        }

        if(noOfDisSets == 1) {
            ll mx = 0;

            fo(i,0,m) {
                if(visited[i]) {
                    mx = max(mx,edges[i][0]);
                }
            }

            ll temp_ans = k - mx;

            fo(i,0,m) {
                if(!visited[i]) {
                    if(abs(edges[i][0] - k) < temp_ans) {
                        temp_ans = abs(edges[i][0] - k);
                    }
                }
            }

            cnl(temp_ans);
        }

        else {
            fo(i,0,m) {
                if(!visited[i]) {
                    if(!isSameSet(edges[i][1],edges[i][2])) {
                        visited[i] = 1;
                        unionSet(edges[i][1],edges[i][2]);
                    }
                }
            }

            ll ans = 0;

            fo(i,0,m){
                if(visited[i] && edges[i][0] > k) {
                    ans += edges[i][0] - k;
                }
            }

            cnl(ans);


        }




    
    }
    return 0;
}