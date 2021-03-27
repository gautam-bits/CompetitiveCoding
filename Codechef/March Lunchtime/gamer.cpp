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

    
        ll n;
        ll k;
        read(n);
        read(k);

        vvi pairs(n);

        set<ll> points;

        fo(i,0,n) {
            ll a,b,c;
            read(a);
            read(b);
            read(c);
            points.insert(a);
            points.insert(b);
            pairs[i] = {b,a,c};
        }

        sort(all(pairs));

        fo(i,0,n){
            ll te = pairs[i][0];
            pairs[i][0] = pairs[i][1];
            pairs[i][1] = te;
        }

        ll sz = points.size();

        vi newpts;

        for(ll x : points) newpts.pb(x);


        vi low_ans(sz,0);
        vi high_ans(sz,0);
        vi low_rev_ans(sz,0);
        vi high_rev_ans(sz,0);

        fo(i,0,sz) {
            for(vi& vec : pairs){
                if(vec[0] < newpts[i] ) {
                    low_ans[i] += vec[2];
                }
            }
        }

        fo(i,0,sz) {
            for(vi& vec : pairs){
                if(vec[1] <= newpts[i]) {
                    high_ans[i] += vec[2];
                }
            }
        }

        rfo(i,sz-1,0){
            for(vi& vec : pairs){
                if(vec[0] >= newpts[i]) {
                    high_rev_ans[i] += vec[2];
                }
            }
        }

        rfo(i,sz-1,0){
            for(vi& vec : pairs){
                if(vec[1] > newpts[i]) {
                    low_rev_ans[i] += vec[2];
                }
            }
        }

        ll ans = 0;

        fo(i,0,sz) {
            fo(j,i,sz){
                ll temp  = high_ans[j] - low_ans[i];
                temp = max(temp,high_rev_ans[i] - low_rev_ans[j] );
                temp = max(temp,(ll)0);
                temp -= (k*(newpts[j] - newpts[i])); 


                ans = max(ans,temp);
            }
        }

        cnl(high_ans[3]);

        cnl(ans);



    return 0;
}