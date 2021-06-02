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
    //#define endl "\n" 
    
    
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
    read(n);

    vector<bool> visited(n,0);

    map<double,ll> mp;
    vpi mp2(n);

    multiset<double> myset;

    fo(i,0,n) {
        //cnl("yo");
        ll a,b,c,d;
        read(a);
        read(b);
        read(c);
        read(d);

        double s1 = (((double)c/(double)d) +1.0)/((double)a/(double)b);
        double s2 = (((double)c/(double)d))/(((double)a/(double)b) + 1.0);

        mp[s1] = i;
        mp[s2] = i;

        assert(s1 != s2);

        mp2[i] = {s1,s2};

        myset.insert(s1);
        myset.insert(s2);
    }

    //for(double x : myset) cnl(x);

    fo(i,0,1) {
        double curr = *myset.begin();

        
        auto itr = myset.begin();
        itr++;
        double c2 = *itr;


        if(curr == c2) {
            csp("ans");csp(mp[c2]+1);cnl(mp[curr] + 1);

            // myset.erase(myset.find(mp2[mp[c2]].F));
            // myset.erase(myset.find(mp2[mp[c2]].S));
            // myset.erase(myset.find(mp2[mp[curr]].F));
            // myset.erase(myset.find(mp2[mp[curr]].S));


        }

        else {
            myset.erase(myset.begin());
        }

        for(double x : myset) cnl(x);
    }






    return 0;
}