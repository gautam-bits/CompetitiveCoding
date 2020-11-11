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
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
void printnew(ll a,ll b,ll c){
    cout<<"1/"<<a<<" = "<<"1/"<<b<<" + 1/"<<c<<endl;
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll k;
    
    while(cin>>k)
    {
        ll y = k + 1;
        vector<pi> pairs;
        ll ans = 0;
        while(y <= 2*k){
            if((k*y)%(y-k) == 0 && (k*y)/(y-k) >= y) {
                pairs.pb({(k*y)/(y-k),y});
                ans++;
            }
            y++;
        }

        cout<<ans<<endl;
        fo(i,0,ans){
            printnew(k,pairs[i].F,pairs[i].S);
        }
    
    
    }
    return 0;
}