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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll n;
    read(n);
    vi arr(n);

    cinarr(n,arr);

    //ll anss = 1;

    vi maxxx_idx;
    vi minnn_idx;
    vi rando;

    ll rando_maxx = -100000;

    fo(i,1,n-1) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) maxxx_idx.pb(i);
        if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) minnn_idx.pb(i);
    }

    if(maxxx_idx.size() == 0) {
        cnl(0);
        return 0;
    }

    if(arr[1] < arr[0]) rando.pb(minnn_idx[0] + 1);
    if(arr[n-1] > arr[n-2]) rando.pb(n - minnn_idx[minnn_idx.size() -1]);

    if(rando.size() > 0) rando_maxx = *max_element(all(rando));


    vpi lol;


    for(ll xx : maxxx_idx) {

        ll t1,t2;
        if(minnn_idx.size() == 0) {
            lol.pb({xx+1,n-xx});
        }
        
        else{
            auto itr = ub(all(minnn_idx),xx);

            if(itr == minnn_idx.end()) {
                t2 = n - xx;
            }
            else t2 = *itr - xx + 1;

            if(itr == minnn_idx.begin()) {
                t1 = xx + 1;
            }

            else {
                itr--;
                t1 = xx - *itr + 1;
            }

            lol.pb({t1,t2});

        }
    }

    bool ok = 1;  // set

    ll mx_id = 0;
    ll mx_no  = 0;


    fo(i,0,lol.size()) {
        if(max(lol[i].F,lol[i].S) > mx_no){
            mx_no = max(lol[i].F,lol[i].S);
            mx_id = i;
        }
    }

    fo(i,0,lol.size()) if(i != mx_id) {
        if(max(lol[i].F,lol[i].S) == mx_no) ok = 0;
    }

    if(lol[mx_id].F != lol[mx_id].S) ok = 0;

    if(lol[mx_id].F % 2 == 0) ok = 0;

    if(mx_no <= rando_maxx) ok = 0;


    if(ok) cnl(1);
    else cnl(0);




    
    
    return 0;
}