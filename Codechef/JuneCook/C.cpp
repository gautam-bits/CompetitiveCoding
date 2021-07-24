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
    // #define endl "\n" 
    
    
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

        vi arr(n);

        cinarr(n,arr);

        if(n < 3) {
            if(n == 1) {
                cnl(0);
                continue;
            }
            if(n == 2){
                if(arr[0] ^ arr[1] == 0){
                    cnl(-1);
                    continue;
                }

                else {
                    cnl(0);
                    continue;
                }

            }

            
        }

        // cnl("yp");
        map<ll,pi> mp;

        fo(i,0,n){
            mp[arr[i]] = {0,0};
        }

        fo(i,0,n){
            // cnl(arr[i]);
            if(i&1)mp[arr[i]].S++;
            else mp[arr[i]].F++;
        }

        bool poss = 0;
        int val = 0;
        bool isone = 0;

        // cnl(mp[1].F);


        for(auto el : mp) {
            if(el.F > 0 && el.S.F > 1){
                val = el.F;
                // cnl(val);
                // cnl("rr");
                isone = 0;
                poss = 1;
                break;
            }

            if(el.F > 0 && el.S.S > 1){
                val = el.F;
                isone = 1;
                // cnl("rdd");
                poss = 1;
                break;
            }


        }


        if(!poss){
            cnl(-1);
        }

        else {
            if(isone){
                vi yoyo;
                fo(i,0,n){
                    if(i&1){
                        if(arr[i] == val){
                            yoyo.push_back(i);
                        }
                    }
                }
                assert(yoyo.size() >= 2);

                cnl(n-2);
                fo(i,0,n) if(!(i&1)){
                    if(i!=yoyo[0] && i != yoyo[1]){
                        csp(yoyo[0] + 1);csp(yoyo[1] + 1);cnl(i+1);
                    }
                }
                fo(i,0,n) if((i&1)){
                    if(i!=yoyo[0] && i != yoyo[1]){
                        csp(yoyo[0] + 1);csp(1);cnl(i+1);
                    }
                }
            }
            else {
                vi yoyo;
                fo(i,0,n){
                    if(!(i&1)){
                        if(arr[i] == val){
                            yoyo.push_back(i);
                        }
                    }
                }
                assert(yoyo.size() >= 2);

                cnl(n-2);
                fo(i,0,n) if((i&1)){
                    if(i!=yoyo[0] && i != yoyo[1]){
                        csp(yoyo[0] + 1);csp(yoyo[1] + 1);cnl(i+1);
                    }
                }
                fo(i,0,n) if(!(i&1)){
                    if(i!=yoyo[0] && i != yoyo[1]){
                        csp(yoyo[0] + 1);csp(2);cnl(i);
                    }
                }
            }
        }

    
    }
    return 0;
}