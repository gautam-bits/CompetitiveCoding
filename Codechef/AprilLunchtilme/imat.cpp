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

    #define vshow1d(arr) {ll n = arr.size(); fo(ii,0,n) {csp(arr[ii]);}cout<<endl;}
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

    const int sz = 4e6 + 10;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vvi transposemat(vvi& mat){
    ll n = mat.size();
    ll m = mat[0].size();

    vvi mat2(m,vi(n,0));

    fo(i,0,n){
        fo(j,0,m){
            mat2[j][i] = mat[i][j];
        }
    }

    return mat2;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<sz> bit,temp;
    
    test(t){     // tno[1..t]


        bit.reset();
    
        ll n,m,b;
        read(n);
        read(m);
        read(b);

        ll ans = 0;

        vvi mat;

        mat.assign(n,vi(m,0));

        cinarr2d(n,m,mat);

        if(n > m) {
            vvi mat2(m,vi(n,0));

            mat2 = transposemat(mat);
            mat.assign(m,vi(n,0));

            mat = mat2;
        }

        n = mat.size();

        m = mat[0].size();

        vshow2d(mat);
        cnl("");


        fo(mask,0,1<<n) {
            ll cpy = mask;
            vi row;

            ll idx = 0;

            while(cpy > 0) {
                if(cpy&1) row.pb(idx);
                idx++;
                cpy >>= 1;
            }

            vi arr(m,0);

            for(ll ro : row) {
                fo(j,0,m){
                    arr[j] += mat[ro][j];
                }
            }

            vshow1d(arr);

            vvi dp(m+1,vi(b+1,0));

            dp[0][0] = 1;

            fo(i,1,b+1) dp[0][i] = 0;
            fo(i,1,n+1) dp[i][0] = 1;

            fo(i,1,n+1){
                fo(j,1,b+1){
                    if(arr[i-1] > j) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                    }

                }
            }

            ans = (ans + dp[n][b])%MOD;


        }

        cnl(ans);

        
        
    
    }
    return 0;
}