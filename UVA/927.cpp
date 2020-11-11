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
ll poly[30];    // global polynomial


ll solve(ll n, ll d, ll k ) {
    ll k_top = (k + d - 1)/d;
    ll itr = (ll)( (1 + sqrt(8*k_top - 7)) / 2  );
    ll ans = 0;
    fo(i,0,n+1){
        //cout<<k_top<<" "; 
        ans += poly[i]*((ll)pow(itr,i));
    }
    return ans;
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {   
        ll n;
        cin>>n;
        //ll poly[n+1];
        mem(poly,0);
        fo(i,0,n+1)cin>>poly[i];
        
        ll d,k;
        cin>>d>>k;

        cout<<solve(n,d,k)<<endl;


    
    
    }
    return 0;
}