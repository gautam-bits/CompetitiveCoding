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
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int c = max(a,b), d = min (a,b);
        
        if(d == 0) cout<<0<<endl;
        else if ( c >= 2*d ) cout<<d<<endl;
        else if( c == d && c%3 != 2) cout<<2 * (c/3) <<endl;
        else if( c == d ) cout<<2 * (c/3) + 1 <<endl;
        else {
            ll n = 2*d - c ;
            if(n%3 == 0) {
                int x = n/3 ;
                cout<< d - x<<endl; ;
            }
            else {
                int x = n/3 ;
                int y =  x + 1 ;
                int a1 = 2*x + (c - 3*x)/2;
                //if((c-3*x)%2 == 1 && (d - ((c - 3*x)/2)) > 1 ) a1++;
                int a2 = d - y ;
                if(d - 3*y < 0) a2 = -1;
                cout<<max(a1,a2)<<endl;
            }
        }
 
    
    }
    return 0;
}