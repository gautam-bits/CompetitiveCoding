//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll unsigned long long
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
        ll x, y;
        cin>>y>>x;

        ll abc2 = max(x,y);
        ll abc = abc2-1;
        abc *= abc;
        abc2 = abc2*abc2 ;
        //cout<<abc2 - min(x,y) + 1<<endl;
        // if(abc & 1){
        //     cout<< abc + min(x,<<endl;
        // }
        // else {
        //     cout<< abc2 - <<endl;
        // }

        if(abc&1){
            if(y < x)cout<<abc+y<<endl;
            else cout<<abc+y + y - x<<endl;
        } else {
            if(y < x)cout<<abc+x + x - y<<endl;
            else cout<<abc+ + x<<endl;
        }


    
    
    }
    return 0;
}