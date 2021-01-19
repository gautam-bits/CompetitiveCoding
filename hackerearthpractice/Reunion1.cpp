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
ll max_sz;
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
            max_sz = max(max_sz,sz_set[x]);
        }
        else {
            parent[x] = y;
            sz_set[y] += sz_set[x];  //increasing the size
            max_sz = max(max_sz,sz_set[y]);
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

// remember set is [0...n-1] 
/*
################################################################
NOTE - IF DATA IS NOT IN 0-N-1 RANGE USE A MAP <DATA,INT[0..N-1]>
################################################################
*/
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,k;
    read(n);
    read(k);

    string str = "";
    char ddd;
    fo(i,0,n){
        read(ddd);
        str += ddd;
    }
    //reset global variables
    parent.assign(n,0);
    rank_element.assign(n,0);
    sz_set.assign(n,0);
    noOfDisSets = n;
    max_sz = 0;
    fo(i,0,n)parent[i] = i;
    fo(i,0,n) if(str[i] == '1') sz_set[i] = 1;

    //start from here
    fo(i,1,n) {
        if(str[i] == '1' && str[i-1] == '1'){
            unionSet(i,i-1);
        }
    }

    ll type;
    fo(i,0,k){
        read(type);
        if(type == 1){
            cnl(max_sz);
        }
        else{
            ll xx;
            read(xx);
            xx--;
            str[xx] = '1';
            ll xxx = findSet(xx);
            sz_set[xxx] = max(sz_set[xxx],(ll)1);
            max_sz = max(max_sz,sz_set[xxx]);

            if(xx == 0){
                if(str[xx+1] == '1'){
                    unionSet(xx,xx+1);
                }
            }
            else if(xx == n-1){
                if(str[xx-1] == '1'){
                    unionSet(xx,xx-1);
                }
            }
            else {
                if(str[xx+1] == '1'){
                    unionSet(xx,xx+1);
                }
                if(str[xx-1] == '1'){
                    unionSet(xx,xx-1);
                }
            }
        }
    }


    

    return 0;
}