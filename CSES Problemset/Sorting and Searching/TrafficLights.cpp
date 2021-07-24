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
    
    ll x;
    ll n;
    read(x);
    read(n);

    vi arr(n);
    cinarr(n,arr);

    multiset<ll> s1,s2; // s1 = boundries s2 = diffrences

    s1.insert(0);
    s1.insert(x);
    s2.insert(x);


    // csp("s1");
    // for(ll x : s1) csp(x);
    // cnl("");
    // csp("s2");  
    // for(ll x : s2) csp(x);
    // cnl("");  

    

    vi ans(n,0);

    fo(i,0,n) {

        auto itr1 = s1.lb(arr[i]);
        auto itr2 = itr1;
        itr2--;

        ll rmv = *itr1 - *itr2;
        ll add1 = *itr1 - arr[i];
        ll add2 = arr[i] - *itr2;

        // csp("rmv");cnl(rmv);
        // csp("add1");cnl(add1);
        // csp("add2");cnl(add2);

        s2.erase(s2.find(rmv));
        s2.insert(add1);
        s2.insert(add2);
        s1.insert(arr[i]);

        ans[i] = *s2.rbegin();


        // csp("s1");
        // for(ll x : s1) csp(x);
        // cnl("");  
        // csp("s2");
        // for(ll x : s2) csp(x);
        // cnl("");        
    }


    vshow1d(ans);


    return 0;
}