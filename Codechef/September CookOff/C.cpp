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
    
        ll n;
        read(n);
        string s,p;
        read(s);
        read(p);

        ll a11 = 0;
        ll a00 = 0;
        ll a01 = 0;
        ll a10 = 0;

        fo(i,0,n) {
            if(s[i] == '0') a00++;
            if(s[i] == '1') a01++;
            if(p[i] == '0') a10++;
            if(p[i] == '1') a11++;
        }

        // bool ye = 1;

        // while(a10>0 || a01>0) {
        //     if(a11 >= 2 && a10 > 0) {
        //         a00++;
        //         a10--;
        //     }

        //     else if(a00 >= 2 && a01 > 0) {
        //         a11++;
        //         a01--;
        //     }

        //     else if(a11 >= 1 && a10 > 1) {
        //         a00 += 2;
        //         a10 -= 2;
        //     }

        //     else if(a00 >= 1 && a01 > 1) {
        //         a11 += 2;
        //         a01 -= 2;
        //     }

        //     else if(a01 >= 2 && a10 >= 1) {
        //         a01 -= 2;
        //         a10 -= 1;
        //         a11 += 2;
        //         a00 += 1;
        //     }
        //     else if(a10 >= 2 && a01 >= 1) {
        //         a01 -= 1;
        //         a10 -= 2;
        //         a11 += 1;
        //         a00 += 2;
        //     }

        //     else if(a01 >= 1 && a10 >= 1 && (a11 > 0 || a00 > 0)) {
        //         a01--;
        //         a10--;
        //         a11++;
        //         a00++;
        //     }

        //     else {
        //         ye = 0;
        //         break;
        //     }
        // }

        // if(ye) {
        //     assert(a10 == 0 && a01 == 0);
        //     cnl("YES");
        // }
        // else {
        //     cnl("NO");
        // }

        if(s == p) {
            cnl("YES");
        }

        else if(a10&&a11) {
            cnl("YES");
        }

        else {
            cnl("NO");
        }

    
    }
    return 0;
}