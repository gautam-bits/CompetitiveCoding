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
    cin>>t;
    
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll a[n],ans = 0;
        vector<ll> node;
        fo(i,0,n) cin>>a[i];
        //sort(a,a+n);
        //vector<ll> node;
        bool ok = true;

        fo(i,0,n){
            if(i == 0) {
                if(a[i] > a[i+1]) node.pb(a[i]);
            }
            
            else if(i < n-1) {
                if(a[i] > a[i-1] && a[i] > a[i+1]) node.pb(a[i]);
                else if(a[i] < a[i-1] && a[i] < a[i+1]) node.pb(a[i]);
            }
            else if(i == n-1){
                 if(a[i] > a[i-1]) node.pb(a[i]);
            }
        }
        int len = node.size();

        fo(i,0,len){
            if(i&1){
                ans -= node[i];
            }
            else {
                ans += node[i];
            }
        }
        
        cout<<ans<<endl;
    
    
    }
    return 0;
}