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
        vi arr;

        map<ll,ll> mp;
        ll temp;

        fo(i,0,n) {
            read(temp);

            mp[temp]++;
        }

        for(auto x : mp) {
            arr.pb(x.S);
        }

        //vshow1d(arr);

        sort(all(arr));

        ll sz = arr.size();

        vi pre_arr(sz,0);

        vi post_arr(sz,0);

        pre_arr[0] = arr[0];

        fo(i,1,sz){
            pre_arr[i] = arr[i] + pre_arr[i-1];
        }

        post_arr[sz-1] = arr[sz-1];

        rfo(i,sz-2,0){
            post_arr[i] = arr[i] + post_arr[i+1];
        }

        ll ans = 1e15;

        fo(i,0,sz){
            ll s1 = 0;
            ll s2 = 0;
            auto itr1 = lb(all(arr),arr[i]);
            auto itr2 = ub(all(arr),arr[i]);

            if(itr1 != arr.begin()) {
                itr1--;
                s1 = pre_arr[(ll)(itr1-arr.begin())];
                itr1++;
            }

            if(itr2 != arr.end()){
                s2 = post_arr[(ll)(itr2-arr.begin())];
            }

            ll temp_ans = arr[i]*(sz - (itr2-arr.begin()));

            temp_ans = s1 + s2 - temp_ans;


            ans = min(ans,temp_ans);


        }

        cnl(ans);

    
    }
    return 0;
}