
    
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
    


bool solve(vi& height, ll k) {
        ll n = height.size();

        fo(i,k,n){ // [i-(i-k)]
            bool yo = 1;
            ll lef = i - k;
            ll rig = i;

            ll t1 = height[lef];
            ll t2 = height[rig];

            fo(j,1,k) {
                ll te;

                te = (k*t1 + j*(t2-t1))/k;
                
                if(te < height[lef+j]){
                    yo = 0;
                    break;
                }
            }

            csp(lef);cnl(rig);

            if(yo) return 1; 
        }

        return 0;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vi height(n);

        cinarr(n,height);


        ll lo = 1;
        ll hi = n;

        // while(hi - lo > 1) {
        //     ll mid = (hi + lo) / 2;
        //     csp("call");cnl(mid);
        //     bool temp = solve(height,mid);
        //     if(temp) lo = mid;
        //     else hi = mid;
        // }

        if(solve(height,5)) csp("lody");


        //if(solve(height,lo+1))lo++;
        cnl(lo);
    
    }
    return 0;
}