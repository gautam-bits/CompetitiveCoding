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


ll K;
bool solve(vi& arr,ll sz){
    ll n = arr.size();
    vi temp(n);
    vi minn(n,0);

    fo(i,0,n){
        if(arr[i] >= sz) temp[i] = 1;
        else temp[i] = -1;
    }

    fo(i,1,n) temp[i] += temp[i - 1];

    minn[0] = min((ll)0,temp[0]);

    fo(i,1,n) minn[i] = min(temp[i],minn[i-1]);

    if(temp[K-1] > 0) return 1;

    fo(i,K,n){
        if(temp[i] - minn[i-K] > 0) return 1;
    }

    return 0;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll n,k;
    read(n);
    read(k);

    K = k;

    vi arr(n);

    cinarr(n,arr);

    ll lo = 1;

    ll hi = n + 1;


    while(lo + 1 <{
        ll mid = (lo + hi)/2;

        if(solve(arr,mid)){
            lo = mid ;
        }
        else {
            hi = mid;
        }
    }

    //if(solve(arr,hi)) lo = hi;
    // if(solve(arr,hi + 1)) ans = hi + 1;
    // if(solve(arr,hi + 2)) ans = hi + 2;
    // if(solve(arr,hi + 3)) ans = hi + 3;
    

    cnl(lo);



    
    
    return 0;
}