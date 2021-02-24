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
    
ll check(vvi& pref_ans , ll k , ll sz){
    ll n = pref_ans.size();
    ll m = pref_ans[0].size();
    ll mn = (ll) 1e16;

    fo(i,sz-1,n) {
        fo(j,sz-1,m){
            ll a,b,c,d;

            if(i == sz - 1) a = 0;
            else a = pref_ans[i-sz][j];

            if(j == sz - 1) b = 0;
            else b = pref_ans[i][j-sz];

            if(i == sz - 1 || j == sz - 1) c = 0;
            else c = pref_ans[i-sz][j-sz];

            d = pref_ans[i][j] - a - b + c;

            mn = min(mn,d);
        }
    }

    return mn;

}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m,k;
        read(n);
        read(m);
        read(k);

        vector<vector<char>> grid(n,vector<char> (m));

        vvi pref_ans(n,vi (m,0));

        //cinarr2d(n,m,grid);

        ll tot = 0;

        fo(i,0,n){
            fo(j,0,m) {
                read(grid[i][j]);
                if(grid[i][j] == '0') tot++;
            }
        }

        fo(i,0,n){
            fo(j,0,m){
                if(i == 0){
                    if(j == 0) {
                        if(grid[i][j] == '1') pref_ans[i][j] = 1;
                    }
                    else{
                        if(grid[i][j] == '1') pref_ans[i][j] = 1 + pref_ans[i][j-1];
                        else pref_ans[i][j] =  pref_ans[i][j-1];
                    }
                }
                else {
                    if(j == 0) {
                        if(grid[i][j] == '1') pref_ans[i][j] = 1 + pref_ans[i-1][j];
                        else pref_ans[i][j] =  pref_ans[i-1][j];
                    }
                    else{
                        if(grid[i][j] == '1') pref_ans[i][j] = 1 + pref_ans[i][j-1] + pref_ans[i-1][j] - pref_ans[i-1][j-1];
                        else pref_ans[i][j] =  pref_ans[i][j-1] + pref_ans[i-1][j] - pref_ans[i-1][j-1];
                    }
                }
            }
        }


        ll lo = 0;

        ll hi = min(n,m) + 1;

        while(hi - lo > 1){
            // cnl("yp");
            ll mid = (hi + lo) / 2;

            ll ans = check(pref_ans,k,mid);

            if(ans <= k && (mid*mid) <= tot){
                lo = mid;
            }
            else {
                hi = mid;
            }
        }

        //if(tot == 0) cnl(0);
        cnl(lo);

        

    
    }
    return 0;
}