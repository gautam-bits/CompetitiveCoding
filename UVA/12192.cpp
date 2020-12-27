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
    
    ll n,m;
    
    
    while(cin>>n>>m)
    {   
        if( n + m == 0) break;
        vi numbers[n+m-1];
        fo(i,0,n){
            fo(j,0,m){
                ll temp;
                cin>>temp;
                numbers[j - i + n - 1].push_back(temp);
            }
        }
        
        ll q;
        cin>>q;
        fo(i,0,q) {
            ll l,r;
            cin>>l>>r;
            ll ans = 0;
            fo(j,0,n+m-1) {
                auto itrL = lower_bound(numbers[j].begin(),numbers[j].end(),l);
                auto itrR = upper_bound(numbers[j].begin(),numbers[j].end(),r);
                ans = max(ans,(ll)(itrR - itrL));
            }
            cout<<ans<<endl;

        }
        cout<<"-"<<endl;
    
    
    }
    return 0;
}