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

        vi arr1(n);
        vi arr2(n);
        vi diff1(n);
        vi diff2(n);
        vi val1(n);
        vi val2(n);

        vi ans1(n);
        vi ans2(n);

        cinarr(n,arr1);
        cinarr(n,arr2);

        cinarr(n-1,diff1);
        cinarr(n-1,diff2);

        val1 = arr1;
        val2 = arr2;

        ll mn = 1e15;

        ll sm1 = 0;
        ll sm2 = 0;

        fo(i,0,n) sm1 += arr1[i];
        fo(i,0,n) sm2 += arr2[i];

        rfo(i,n-2,0) arr1[i] += arr1[i+1];
        rfo(i,n-2,0) arr2[i] += arr2[i+1];

        mn = min(arr1[n-1],arr2[n-1]);

        rfo(i,n-1,0) {
            if(i == n-1) {
                ans1[i] = arr1[i];
                ans2[i] = arr2[i];
            }
            else{
                ans1[i] = min(val1[i] + ans1[i+1],val1[i] + ans2[i+1]+ diff1[i]);
                ans2[i] = min(val2[i] + ans2[i+1],val2[i] + ans1[i+1]+ diff2[i]);
            }
        }


        


        cnl(min(ans1[0],ans2[0]));
    
    }
    return 0;
}