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
    #define ctc(x) cout << "Case #"<<x<<": "
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
    
        

        ll r,c;

        read(r);
        read(c);


        vvi mat(r,vi (c,0));

        cinarr2d(r,c,mat);

        vvi lef(r,vi (c,0));
        vvi rig(r,vi (c,0));
        vvi up(r,vi (c,0));
        vvi down(r,vi (c,0));

        fo(i,0,r) {
            ll cnt = 0;
            fo(j,0,c){
                if(mat[i][j] == 1) {
                    cnt++;
                    rig[i][j] = cnt;
                }
                if(j == c-1 || mat[i][j+1] == 0) {
                    rig[i][j] = cnt;
                    cnt = 0;
                }
            }
        }

        fo(i,0,r) {
            ll cnt = 0;
            rfo(j,c-1,0){
                if(mat[i][j] == 1) {
                    cnt++;
                    lef[i][j] = cnt;
                }
                if(j == 0 || mat[i][j-1] == 0) {
                    lef[i][j] = cnt;
                    cnt = 0;
                }
            }
        }

        fo(j,0,c) {
            ll cnt = 0;
            fo(i,0,r){
                if(mat[i][j] == 1) {
                    cnt++;
                    down[i][j] = cnt;
                }
                if(i == r-1 || mat[i+1][j] == 0) {
                    down[i][j] = cnt;
                    cnt = 0;
                }
            }
        }

        fo(j,0,c) {
            ll cnt = 0;
            rfo(i,r-1,0){
                if(mat[i][j] == 1) {
                    cnt++;
                    up[i][j] = cnt;
                }

                if(i == 0 || mat[i-1][j] == 0) {
                    up[i][j] = cnt;
                    cnt = 0;
                }
            }
        }

        ll ans = 0;

        fo(i,0,r){
            fo(j,0,c){
                if(up[i][j] != 0){
                    if(lef[i][j] != 0){
                        ll mn = min(up[i][j],lef[i][j]);
                        ll mx = max(up[i][j],lef[i][j]);
                        // if(2*mn == mx && mn > 1){
                        //     csp("ul");csp(i);cnl(j);
                        //     ans += mn - 1;
                        // }
                        if(mn > 1 && mx > 1){
                            ans += min(mn,mx/2) - 1;
                            ans += min(mn/2,mx) - 1;
                            // ans -= mn - 1;
                        }
                    }
                    if(rig[i][j] != 0){
                        ll mn = min(up[i][j],rig[i][j]);
                        ll mx = max(up[i][j],rig[i][j]);
                        // if(2*mn == mx && mn > 1){
                        //     csp("ur");csp(i);cnl(j);
                        //     ans += mn - 1;
                        // }
                        if(mn > 1 && mx > 1){
                            ans += min(mn,mx/2) - 1;
                            ans += min(mn/2,mx) - 1;
                            // ans -= mn - 1;
                        }
                    }
                }
                if(down[i][j] != 0){
                    if(lef[i][j] != 0){
                        ll mn = min(down[i][j],lef[i][j]);
                        ll mx = max(down[i][j],lef[i][j]);
                        // if(2*mn == mx && mn > 1){
                        //     csp("dl");csp(i);cnl(j);
                        //     ans += mn - 1;
                        // }
                        if(mn > 1 && mx > 1){
                            ans += min(mn,mx/2) - 1;
                            ans += min(mn/2,mx) - 1;
                        }
                    }
                    if(rig[i][j] != 0){
                        ll mn = min(down[i][j],rig[i][j]);
                        ll mx = max(down[i][j],rig[i][j]);
                        // if(2*mn == mx && mn > 1){
                        //     csp("dr");csp(i);cnl(j);
                        //     ans += mn - 1;
                        // }
                        if(mn > 1 && mx > 1){
                            ans += min(mn,mx/2) - 1;
                            ans += min(mn/2,mx) - 1;
                            // ans -= mn - 1;
                        }
                    }
                }
            }
        }
        // vshow2d(up);
        // cnl("");
        // vshow2d(down);
        // cnl("");
        // vshow2d(rig);
        // cnl("");
        // vshow2d(lef);
        // cnl("");


        ctc(tno);cnl(ans);
        
    
    }
    return 0;
}