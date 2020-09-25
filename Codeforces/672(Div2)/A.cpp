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
        ll n;
        cin>>n;
        ll a[(int)1e6],b[n],ans = 0, fino[n]={0};
        // map<ll,ll> mp;
        // fo(i,0,n) {
        //     cin>>a[i];
        //     b[i] = a[i] ;
        // }
        // sort(b, b+ n);
        // fo(i,0,n){
        //     mp[b[i]]=i;
        // }
        // fo(i,0,n){    
        //     fino[mp[a[i]]] = abs((int)(lower_bound(b,b+n,a[i])- b) - i);    
        // }

        //int ans = sort(a,a+n);

        //fo(i,0,n)cout<<fino[i]<<" ";

        fo(i,0,n){
            if(fino[i]>0){
                fino[i] = 0;
                break;
            }
        }
        
        fo(i,0,n){
            ans+= fino[i];
        }
        
        
        ll rand = (n*(n-1))/2 - 1;
        
        //cout<<ans<<endl;
        if(ans <= rand) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    
    
    }
    return 0;
}