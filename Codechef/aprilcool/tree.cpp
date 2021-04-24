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

bool issquare(ll x) {
    if(x <= 1) return 1;
    ll a1 = (ll)sqrt(x);
    ll a2 = (ll)sqrt(x-1);

    return a1 != a2;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;

        ll x,y;
        read(x);  //even
        read(y);  //odd

        n = (ll)sqrt(x+y);

        if(x + y != n*n) {
            cnl("NO");
            //cnl(1);
            continue;
        }

        ll a,b;

        ll temp = n*n - 2*y;
        //cnl(temp);

        if(!issquare(temp)) {
            cnl("NO");
            //cnl(2);
            continue;
        }

        b = n - (ll)sqrt(temp);

        if(b%2 == 1) {
            cnl("NO");
            //cnl(3);
            continue;
        }

        b /= 2;

        a = n - 1 - b;

        // cnl(a);
        // cnl(b);

        if(a*a + b*b + 2*a + 1 != x) {
            cnl("NO");
            //cnl(4);
            continue;
        }

        cnl("YES");

        assert(b > 0);

        cnl(n);

        assert(n > 1);

        ll cnt = 2;

        fo(i,0,b) {
            csp(1);cnl(cnt);
            cnt++;
        }

        fo(i,0,a) {
            csp(2);cnl(cnt);
            cnt++;
        }








    
    }
    return 0;
}