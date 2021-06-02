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

    vi vec;

    fo(i,1,1e4){
        ll x = i;
        ll y = i+1;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = xx + yy;
        ll temp = stoll(zz);

        vec.pb(temp);
    }

    fo(i,1,1e4){
        ll x = i;
        ll y = i+1;
        ll z = i+2;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = to_string(z);
        string zzz = xx + yy + zz;
        ll temp = stoll(zzz);

        vec.pb(temp);
    }

    fo(i,1,1e2){
        ll x = i;
        ll y = i+1;
        ll z = i+2;
        ll u = i+3;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = to_string(z);
        string uu = to_string(u);
        string zzz = xx + yy + zz+uu;
        ll temp = stoll(zzz);

        vec.pb(temp);
    }

    fo(i,1,100){
        ll x = i;
        ll y = i+1;
        ll z = i+2;
        ll u = i+3;
        ll v = i+4;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = to_string(z);
        string uu = to_string(u);
        string vv = to_string(v);
        string zzz = xx + yy + zz+uu + vv;
        ll temp = stoll(zzz);

        vec.pb(temp);
    }

    fo(i,1,50){
        ll x = i;
        ll y = i+1;
        ll z = i+2;
        ll u = i+3;
        ll v = i+4;
        ll w = i+5;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = to_string(z);
        string uu = to_string(u);
        string vv = to_string(v);
        string ww = to_string(w);
        string zzz = xx + yy + zz+uu + vv + ww;
        ll temp = stoll(zzz);

        vec.pb(temp);
    }

    fo(i,1,10){
        ll x = i;
        ll y = i+1;
        ll z = i+2;
        ll u = i+3;
        ll v = i+4;
        ll w = i+5;
        ll c = i+6;
        string xx = to_string(x);
        string yy = to_string(y);
        string zz = to_string(z);
        string uu = to_string(u);
        string vv = to_string(v);
        string ww = to_string(w);
        string cc = to_string(c);
        string zzz = xx + yy + zz+uu + vv + ww + cc;
        ll temp = stoll(zzz);

        vec.pb(temp);
    }



    sort(all(vec));


    //vshow1d(vec);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        
    
    }
    return 0;
}