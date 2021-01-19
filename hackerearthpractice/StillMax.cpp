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
vi min_no;
vi max_no;
ll noOfDisSets;
ll as;
ll abs_diff;

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
    //assert(i>=0 && i <as && j >=0 && j<as);
    if(!isSameSet(i,j)) {
        ll x = findSet(i);
        ll y = findSet(j);

        noOfDisSets--; // if we are merging 2 different sets

        if(rank_element[x] > rank_element[y]){
            parent[y] = x;
            sz_set[x] += sz_set[y];  //increasing the size
            min_no[x] = min(min_no[x],min_no[y]);
            max_no[x] = max(max_no[x],max_no[y]);
            abs_diff = max(abs_diff,max_no[x] - min_no[x]);
        }
        else {
            parent[x] = y;
            sz_set[y] += sz_set[x];  //increasing the size
            min_no[y] = min(min_no[x],min_no[y]);
            max_no[y] = max(max_no[x],max_no[y]);
            abs_diff = max(abs_diff,max_no[y] - min_no[y]);
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
#################################################################
NOTE - IF DATA IS NOT IN 0-N-1 RANGE USE A MAP <DATA,INT[0..N-1]>
#################################################################
*/
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        ll n;
        read(n);

        //reset global variables
        parent.assign(n,0);
        rank_element.assign(n,0);
        sz_set.assign(n,1);
        min_no.assign(n,0);
        max_no.assign(n,0);
        noOfDisSets = n;
        as = n;
        abs_diff = 0;
        fo(i,0,n)parent[i] = i;


        //start from here
        vpi edges(n-1);
        vi sequence(n-1);
        ll e1,e2;

        fo(i,0,n-1){
            read(e1);read(e2);
            e1--;e2--;
            edges[i] = MP(e1,e2);
            //csp(edges[i].F);cnl(edges[i].S);
        }

        //node values
        vi values(n);
        ll val;

        fo(i,0,n){
            read(val);
            values[i] = val;
            max_no[i] = val;
            min_no[i] = val;
        }

        ll tem;

        fo(i,0,n-1){
            read(tem);
            tem--;
            sequence[i] = tem;
            //cnl(sequence[i]);
        }

        reverse(all(sequence));

        vi answer(n-1);

        fo(i,0,n-1){
            answer[i] = abs_diff;
            //ll as = max_no[findSet(edges[sequence[i]].F)] - min_no[findSet(edges[sequence[i]].F)];
            //answer[i] = as;
            //cnl(sequence[i]);
            //csp(edges[sequence[i]].F);cnl(edges[sequence[i]].S);
            unionSet(edges[sequence[i]].F, edges[sequence[i]].S);
            //fo(j,0,n) csp(min_no[j]);
            //cnl("");
            //ll as = max_no[findSet(edges[sequence[i]].F)] - min_no[findSet(edges[sequence[i]].F)];
            
            
        }

        reverse(all(answer));

        fo(i,0,n-1) cnl(answer[i]);

    
    
    return 0;
}