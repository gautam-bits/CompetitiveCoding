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
    
    test(t){     // tno[1..t]
    
        ll a,b;
        read(a);
        read(b);

        ll ans = 0;

        ll xx = sqrt(1+a);
        ll n = (ll)(xx) - 1;
        n = min(n,b-1);

        ans += (n*(n+1))/2;

        //csp("a");cnl((n*(n+1))/2);

        ll c = min(a,b+1);

        ll itr = (ll)(xx) + 2;
        
        // itr c

        // vi lol;
        // lol.pb(a);
        // rfo(i,(ll)(sqrt(a)),0) {
        //     ll tem = a/i;
        //     if(tem > a && tem < c) lol.pb(tem);
        // }
        // lol.pb(b);

        // fo(i,0,lol.size() - 1){
        //     ll te = a/lol[i];
        //     ans += te*(lol[i+1]-lol[i] - 1);
        // }

        // ans += a/c;

        ll aaa = a/itr;
        ll bbb = a/c;

        fo(i,bbb,aaa+1){
            ll lef = max(itr,a/(i+1)+1);
            ll rig = min(c,a/i);

            ans += i*(rig-lef + 1);
        }

        // fo(i,itr,c+1){

        //     //csp(a);cnl(itr);
        //     ans += (a)/i;
            
        // }
        //csp("b");cnl(ans - ((n*(n+1))/2));


        cnl(ans);


    
    }
    return 0;
}