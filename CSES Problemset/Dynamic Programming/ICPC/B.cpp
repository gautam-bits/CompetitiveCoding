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


class DSU {
public:
    vi parent ;
    vi rank_element;
    vi sz_set;
    ll noOfDisSets;

    DSU(ll n) {
        //reset global variables
        parent.assign(n,0);
        rank_element.assign(n,0);
        sz_set.assign(n,1);
        noOfDisSets = n;
        fo(i,0,n)parent[i] = i;
    }
 
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

};





pi dd(vi& a,vi& b,vi& val) {
    vi aa;
    vi bb;
    for(ll x : a)aa.pb(val[x]);
    for(ll x : b)bb.pb(val[x]);
    sort(all(aa));
    sort(all(bb));

    

}

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m;
        read(n);
        read(m);

        vi val(n);
        cinarr(n,val);


        // answe
        vpi finaledges; 
        ll answ = 0;
        ll ansk = n - 1; //doubt


        DSU mydsu(n);

        fo(i,0,m){
            ll u,v;
            read(u);
            read(v);
            u--;
            v--;

            if(!mydsu.isSameSet(u,v)) {
                finaledges.push_back({u+1,v+1});
                mydsu.unionSet(u,v);
            }
        }


        // cout<<(mydsu.noOfDisjointSets())<<endl;

        //map of val to idx
        map<ll,ll> valtidx;

        map<ll,vi> grps;


        fo(i,0,n) {
            ll p = mydsu.findSet(i);
            grps[p].push_back(i);
        }

        vvi temp;

        for(auto el : grps) temp.pb(el.second);

        sort(all(temp),[&] (vi& a,vi& b) -> bool {
            vi aa;
            vi bb;
            for(ll x : a)aa.pb(val[x]);
            for(ll x : b)bb.pb(val[x]);
            sort(all(aa));
            sort(all(bb));
            return aa < bb;
        });





        bool st = 1;
        

        for(auto& el : grps) {
            if(st) {
                for(auto x : el.S) {
                    valtidx[val[x]] = x;
                }
                st = 0;
            }
            else {
                ll mn = 1e15;
                ll mni = -1;
                ll mni2 = -1;

                for(auto x : el.S) {
                    ll v = val[x];

                    auto itr = valtidx.upper_bound(v);

                    if(itr != valtidx.end()) {
                        ll cc = abs(itr->first - v);
                        if(cc < mn) {
                            mn = cc;
                            mni = itr->second;
                            mni2 = x;
                        }
                    }

                    if(itr != valtidx.begin()) {
                        itr--;
                        ll cc = abs(itr->first - v);
                        if(cc < mn) {
                            mn = cc;
                            mni = itr->second;
                            mni2 = x;
                        }
                    }
                }

                answ += mn;
                finaledges.push_back({mni+1,mni2+1});

                for(auto x : el.S) {
                    valtidx[val[x]] = x;
                }
                
            }
        }

        csp(answ);cnl(ansk);

        for(auto x : finaledges) {
            csp(x.F);cnl(x.S);
        }

        


    
    }
    return 0;
}