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
        ll a[n],ans = 0;
        fo(i,0,n) cin>>a[i];
        map<ll,bool> freq;

        ll i = 0, j = 1;
        freq[a[0]] = true;
        
           
        if(n == 1) {
            cout<<1<<endl;
        }

        
        else{
            while(j<n){
                //cout<<j<<" "<<freq[a[j]]<<endl;
                if(freq[a[j]] ) {
                    freq[a[i]] = false;
                    i++;
                    
                }
                else{
                    //cout<<ans<<" "<<i<<" "<<j<<endl;
                    ans = max(ans,j - i + 1);
                    freq[a[j]] = true;
                    j++;
                }
            }
            cout<<ans<<endl;
        }
        
    
    }
    
    return 0;
}