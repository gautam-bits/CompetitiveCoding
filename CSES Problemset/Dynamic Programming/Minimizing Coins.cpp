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
    t = 1 ;

    
    while(t--)
    {
        ll n,x;
        cin>>n>>x;

        ll a[n];

        fo(i,0,n)cin>>a[i];
        //cout<<22;

        int d = 10000;

        ll dp[1000099] ;
        fo(i,0,1000099) dp[i] = (ll)1e11;

        dp[0] = 0;

        fo(i,0,n)dp[a[i]] = 1;
    
        fo(i,1,x+10){
            fo(j,0,n){
                if(i>=a[j] ) dp[i] = min(dp[i], 1 + dp[i-a[j]]);
            }
        }
        if(dp[x] == (ll)1e11){
            cout<<-1;
        } else {
            cout<<dp[x];
        }
    
    }
    return 0;
}