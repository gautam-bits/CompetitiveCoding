    #include <bits/stdc++.h>
    using namespace std;
    

    
    #define pb push_back

    #define ll long long

    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x


    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll n = arr.size(); fo(i,0,n) {csp(arr[i]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    

    #define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;



ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        ll ans = 0;

        ll k = min((ll)1e3,2*n);


        fo(i,1,2*n+1) {
            ans += gcd(n + i*i,n + (i+1)*(i+1));
        }


        cnl(ans);
    
    }
    return 0;
}