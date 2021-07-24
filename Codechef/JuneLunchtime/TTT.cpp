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
    #define ll int
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
    #define show1d(n,arr) fo(ii,0,nn) {csp(arr[ii]);}cout<<endl;
    #define vshow2d(arr) {ll nnn=arr.size();   fo(iii,0,nnn) {ll mmm = arr[iii].size(); fo(jjj,0,mmm) csp(arr[iii][mmm]); cout << endl;}}
    #define show2d(nn,mm,arr) {fo(ii,0,nn) {fo(jj,0,mm) csp(arr[ii][jj]); cout << endl;}}
    
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
        ll m;
        ll k;
        read(n);
        read(m);
        read(k);

        bool turn = 0;

        vvi mat(n,vi(m,0));

        // show2d(n,m,mat);
        // cnl("");

        vvi dp1(n+1,vi(m+1,0));
        vvi dp2(n+1,vi(m+1,0));

        ll ans = -1;

        ll cnt = 0;

        ll m11 = 0;
        ll m22 = 0;


        fo(i,0,n){
            fo(j,0,m) {
                ll u,v;
                read(u);
                read(v);

                u--;
                v--;
                cnt++;

                if(!turn) {
                    mat[u][v] = 1;

                    dp1[u+1][v+1] = min({dp1[u][v],dp1[u][v+1],dp1[u+1][v]}) + 1;

                    
                }
                else {
                    mat[u][v] = 2;
                }





                // show2d(n,m,mat);
                // cnl("");

                fo(rr,1,n+1){
                    fo(cc,1,m+1){
                        if(mat[rr-1][cc-1] == 1){
                            dp1[rr][cc] = min({dp1[rr][cc-1],dp1[rr-1][cc],dp1[rr-1][cc-1]}) + 1;
                            m11 = max(m11,dp1[rr][cc]);
                        }
                    }
                }

                fo(rr,1,n+1){
                    fo(cc,1,m+1){
                        if(mat[rr-1][cc-1] == 2){
                            dp2[rr][cc] = min({dp2[rr][cc-1],dp2[rr-1][cc],dp2[rr-1][cc-1]}) + 1;
                            m22 = max(m22,dp2[rr][cc]);
                        }
                    }
                }

                // csp(i);csp(j);csp(m1);cnl(m2);

                

                if(ans == -1) {

                    // cnl(cnt);

                    if(m11 >= k){
                        ans = 1;
                        // cnl(cnt);
                    }

                    if(m22 >= k) {
                        ans = 2;
                        // cnl(cnt);
                    }
                    
                }

                turn = !turn;
            }

            
        }

        // cnl(cnt);

        if(ans == 1) {
            cnl("Alice");
        }
        else if(ans == 2) {
            cnl("Bob");
        }
        else {
            cnl("Draw");
        }


    
    }
    return 0;
}