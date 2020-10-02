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
        int a[n],b[n],c[n];
        fo(i,0,n)cin>>a[i];
        fo(i,0,n)cin>>b[i];
        fo(i,0,n)cin>>c[i];
        cout<<a[0]<<" ";
        ll temp = a[0];
        fo(i,1,n-1){
            if(a[i] != temp){
                cout<<a[i]<<" ";
                temp = a[i];
            }
            else if(b[i] != temp){
                cout<<b[i]<<" ";
                temp = b[i];
            }
            else if(c[i] != temp){
                cout<<c[i]<<" ";
                temp = a[i];
            }
        }
        
        if(a[n-1] != a[0] && a[n-1] != temp){
                cout<<a[n-1]<<" ";
                temp = a[n-1];
            }
        else if(b[n-1] != a[0] && b[n-1] != temp){
                cout<<b[n-1]<<" ";
                temp = b[n-1];
            }
        else if(c[n-1] != a[0] && c[n-1] != temp){
                cout<<c[n-1]<<" ";
                temp = a[n-1];
        }
        cout<<endl;
    
    
    }
    return 0;
}