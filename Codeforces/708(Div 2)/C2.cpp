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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b)/gcd(a,b);
}

vi primefactors(ll n) {
    vi ans;
    while(n%2 == 0) {
        ans.pb(2);
        n /= 2;
    }

    for(ll i = 3; i <= sqrt(n) ; i += 2) {
        while(n % i == 0) {
            ans.pb(i);
            n /= i;
        }
    }

    if(n > 2) ans.pb(n);
    return ans;
} 

pi nos2(ll n){
    ll ans = 0;

    while(n%2 == 0) {
        n/=2;
        ans++;
    }
    // csp(ans);cnl(n);
    return {ans,n};
    
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
    
    test(t){     // tno[1..t]
    
        ll n,k;
        read(n);
        read(k);

        while(k > 3) {
            n--;
            k--;
            csp(1);
        }

        pi ans = nos2(n);
        // csp(ans.F);cnl(ans.S);

        //vshow1d(factors);

        if(ans.S > 1) {
            ll yo = ans.S;
            //cnl(yo);

            ll t1 = n/yo;

            ll yo2 = (yo-1)/2;

            csp(t1);
            csp(t1*yo2);
            cnl(t1*yo2);

        }

        

        else {
            ll t1 = n/4;

            csp(t1);
            csp(t1);
            cnl(2*t1);
        }

        


    
    }
    return 0;
}