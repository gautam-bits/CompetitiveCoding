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
    
    ll t;
    read(t);

    ll tno = 1;

    while(t--) {
    
        ll n,m,kk;
        read(n);
        read(m);
        read(kk);
        //csp("fff");cnl(kk);
        

        vvi grid(n,vi (m,0));

        cinarr2d(n,m,grid);
        


        fo(i,0,n) {
            fo(j,0,m) {
                if(i == 0) {
                    if(j == 0) {
                        grid[i][j] = grid[i][j];
                    }
                    else {
                        grid[i][j] = grid[i][j] + grid[i][j-1];
                    }
                }
                else {
                    if(j == 0) {
                        grid[i][j] = grid[i][j] + grid[i-1][j];
                    }
                    else {
                        grid[i][j] = grid[i][j] + grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1];
                    }
                }
            }
        }

        //vshow2d(grid);

        ll ans = 1e15;

        ll mx = 0;


        fo(i,0,n) {
            fo(j,0,m)  {
                fo(k,i,n) {
                    fo(l,j,m) {
                        ll temp = 0;

                        temp += grid[k][l];
                        if(i > 0) temp -= grid[i-1][l];
                        if(j > 0) temp -= grid[k][j-1];
                        if(i> 0 && j > 0) temp += grid[i-1][j-1];
                        //cnl(k);
                        //csp("fg");cnl(temp);

                        ll ar = (k - i + 1)*(l - j + 1);

                        if(ar >= mx && temp <= kk){
                            if(ar == mx) ans = min(ans,temp);
                            else ans = temp;
                            mx = ar;
                            //ans = min(ans,temp);
                        }
                        
                    }
                }
            }
        }

        if(ans == 1e15) ans = 0;
        cout<<"Case #"<<tno<<": "<<mx<<" "<<ans<<endl;


        tno++;

    }

    return 0;
}