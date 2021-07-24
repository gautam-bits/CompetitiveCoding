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
        ll m;
        read(n);
        read(m);

        vi arr1(n);
        vi arr2(m);

        cinarr(n,arr1);
        cinarr(m,arr2);

        sort(all(arr1));
        sort(all(arr2));

        vi pref1(n);
        vi pref2(m);
        vi suff1(n);
        vi suff2(m);

        pref1[0] = arr1[0];
        pref2[0] = arr2[0];

        suff1[n-1] = arr1[n-1];
        suff2[m-1] = arr2[m-1];

        fo(i,1,n) {
            pref1[i] = pref1[i-1] + arr1[i];
        }

        fo(i,1,m) {
            pref2[i] = pref2[i-1] + arr2[i];
        }

        rfo(i,n-2,0){
            suff1[i] = suff1[i+1] + arr1[i];
        }

        rfo(i,m-2,0){
            suff2[i] = suff2[i+1] + arr2[i];
        }

        // vshow1d(pref1);
        // vshow1d(pref2);

        // vshow1d(suff1);
        // vshow1d(suff2);

        ll mn = 1e15;

        fo(i,0,n) {
            ll val = arr1[i];
            // arr1 >= val arr2 <= val


            ll v1 = 0,v2 = 0;

            auto itr1 = lb(all(arr1),val);

            if(itr1 != arr1.begin()) {
                //cnl("yo");
                itr1--;
                ll idx = (ll)(itr1-arr1.begin());
                v1 = (idx+1)*val - pref1[idx]; 
            }

            auto itr2 = lb(all(arr2),val);

            if(itr2 != arr2.end()) {
                ll idx = (ll)(itr2-arr2.begin());
                
                v2 = suff2[idx] - (m-idx)*val;
            }

            // csp(val);csp(v1);cnl(v2);

            mn = min(mn,v1+v2);
        }

        fo(i,0,m) {
            ll val = arr2[i];
            // arr1 >= val arr2 <= val

            ll v1 = 0,v2 = 0;

            auto itr1 = lb(all(arr1),val);

            if(itr1 != arr1.begin()) {
                itr1--;
                ll idx = (ll)(itr1-arr1.begin());
                v1 = (idx+1)*val - pref1[idx]; 
            }

            auto itr2 = lb(all(arr2),val);

            if(itr2 != arr2.end()) {
                ll idx = (ll)(itr2-arr2.begin());
                v2 = suff2[idx] - (m-idx)*val;
            }

            mn = min(mn,v1+v2);
        }

        cnl(mn);
    
    
    return 0;
}