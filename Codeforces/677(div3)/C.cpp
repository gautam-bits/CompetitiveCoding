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
        ll arr[n];

        fo(i,0,n)cin>>arr[i];

        ll  ans = -1;
        ll maxx = *max_element(arr,arr+n);

        fo(i,0,n){
            if(arr[i] == maxx){
                if(i == 0){
                    if(arr[i+1] < maxx) {
                        ans = i + 1;
                        break;
                    }
                }
                else if(i == n -1){
                    if(arr[i-1] < maxx) {
                        ans = i + 1;
                        break;
                    }
                }
                else{
                    if(arr[i + 1] < maxx || arr[i-1] < maxx){
                        ans = i + 1;
                        break;
                    } 
                }
            }
        }

        if(n == 1)cout<<1<<endl;
        else cout<<ans<<endl;
    
    }
    return 0;
}