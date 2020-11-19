//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<' '<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    t = 1;
    
    while(t--)
    {
        ll n,sum = 0;
        cin>>n;
        //cout<<n;
        ll a[n];
        ll ans = (ll)(1e18);
        fo(i,0,n)cin>>a[i],sum+=a[i];
        ll temp_ans = 0;
        ll incr = 1,incr_cpy;
        ll itr = 0 ;

        while(incr < (1 << n)){
            incr_cpy = incr;
            itr = 0;
            temp_ans = 0;
            while(incr_cpy){
                if(incr_cpy&1) temp_ans += a[itr];
                itr++;
                incr_cpy >>= 1;
            }
            ans = min(ans,abs(sum - (2*temp_ans)));
            incr++;
        }

        cout<<ans;


    
    
    }
    return 0;
}