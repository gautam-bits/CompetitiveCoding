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

        vi arr(n);

        cinarr(n,arr);

        vvi value(n,vi());


        fo(i,0,n){
            value[arr[i]-1].pb(i);
        }

        ll minans = 1e15;
        ll ans = -1;

        vi answer(n,1e15);


        fo(i,0,n) {
            if(value[i].size() > 0) {
                ll mx = 0;

                mx = max(mx,value[i][0] + 1);

                fo(j,1,value[i].size()){
                    mx = max(mx,value[i][j]-value[i][j-1]);
                }

                mx = max(mx,n - *value[i].rbegin());

                // if(mx < minans) {
                //     minans = mx;
                //     ans = i+1;
                // }

                answer[mx-1] = min(answer[mx-1],(ll)i+1);
            }
        }

        // csp(minans);cnl(ans);

        fo(i,0,n) if(answer[i] == 1e15) answer[i] = -1;


        ll idx = 0;

        fo(i,0,n) {
            if(answer[i] == -1){
                idx++;
            }
            else{
                break;
            }
        }

        fo(i,idx+1,n) {
            if(answer[i] == -1) answer[i] = answer[i-1];
            else answer[i] = min(answer[i],answer[i-1]);
        }



        // fo(i,0,minans-1) csp(-1);
        // fo(i,minans-1,n) csp(ans);
        // cnl("");


        vshow1d(answer);
    
    }
    return 0;
}