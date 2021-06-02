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

bool tr(ll l1,ll b1,ll l2,ll b2,ll l3,ll b3){
    if(l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) return 1;

    if(b1 == b2 && b2 == b3 && b1 == l1 + l2 + l3) return 1;

    return 0;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll l1,b1,l2,b2,l3,b3;

    cin>>l1>>b1>>l2>>b2>>l3>>b3;



    if(tr(l1,b1,l2,b2,l3,b3)) {
        cnl("YES");
        return 0;
    }

    if(tr(l1,b1,l3,b3,l2,b2)) {
        cnl("YES");
        return 0;
    }

    if(tr(l2,b2,l1,b1,l3,b3)) {
        cnl("YES");
        return 0;
    }
    if(tr(l2,b2,l3,b3,l1,b1)) {
        cnl("YES");
        return 0;
    }

    if(tr(l3,b3,l1,b1,l2,b2)) {
        cnl("YES");
        return 0;
    }
    if(tr(l3,b3,l2,b2,l1,b1)) {
        cnl("YES");
        return 0;
    }
    ll temp;

    fo(i,0,8){

        ll ii = i;
        bool f1 = ii&1;
        ii >>= 1;
        bool f2 = ii&1;
        ii >>=1;
        bool f3 = ii&1;

        if(f1) {
            temp = l1;
            l1 = b1;
            b1 = temp;
        }

        if(f2) {
            temp = l2;
            l2 = b2;
            b2 = temp;
        }

        if(f3) {
            temp = l3;
            l3 = b3;
            b3 = temp;
        }

        if(tr(l1,b1,l2,b2,l3,b3)) {
            cnl("YES");
            return 0;
        }

        if(tr(l1,b1,l3,b3,l2,b2)) {
            cnl("YES");
            return 0;
        }

        if(tr(l2,b2,l1,b1,l3,b3)) {
            cnl("YES");
            return 0;
        }
        if(tr(l2,b2,l3,b3,l1,b1)) {
            cnl("YES");
            return 0;
        }

        if(tr(l3,b3,l1,b1,l2,b2)) {
            cnl("YES");
            return 0;
        }
        if(tr(l3,b3,l2,b2,l1,b1)) {
            cnl("YES");
            return 0;
        }


        if(f1) {
            temp = l1;
            l1 = b1;
            b1 = temp;
        }

        if(f2) {
            temp = l2;
            l2 = b2;
            b2 = temp;
        }

        if(f3) {
            temp = l3;
            l3 = b3;
            b3 = temp;
        }


        
    }

    





    cnl("NO");






    return 0;
}