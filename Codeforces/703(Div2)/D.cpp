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
    //#define endl "\n" 
    
    
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

ll query(ll l,ll r){
    assert(r > l);
    ll temp;
    cout<<"? "<<l<<" "<<r<<endl;
    read(temp);
    return temp;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    
    ll n;
    read(n);

    ll root = query(1,n);

    if(root == 1){
         // binary search for 2 to n
        ll lo = 2;
        ll hi = n;

        ll ans = lo;

        while(lo < hi) {
            ll mid = (lo + hi)/2;

            ll idx = query(root,mid);

            if(idx == root){
                ans = mid;
            hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        cout<<"! "<<lo<<endl;
    }

     else {
        //check weather answer is to left or right
        bool dir = 0; // 0-> lef 1-> rig

        
        ll te = query(1,root);

        if(te != root)  dir = 1;

        if(dir){
            //right case

            ll lo = root + 1;
            ll hi = n;

            ll ans = lo;

            while(lo < hi) {
                ll mid = (lo + hi)/2;

                ll idx = query(root,mid);

                if(idx == root){
                    ans = mid;
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            cout<<"! "<<lo<<endl;

        }
        else {
            //left case

            ll lo = 1;
            ll hi = root - 1;


            while(lo < hi) {
                ll mid = (lo + hi + 1)/2;

                ll idx = query(mid,root);

                if(idx != root){
                    hi = mid - 1;
                }
                else {
                    lo = mid ;
                }
            }

            cout<<"! "<<lo<<endl;

        }
        
     }


    return 0;
}