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
    t = 1;
    
    while(t--)
    {
        ll n;
        cin>>n;

        if(n%4 == 1 || n%4 == 2) cout<<"NO"<<endl;
        else if(n%4 == 0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            fo(i,0,n/4 ){
                cout<< 4*i + 1<<" ";
                cout<< 4*i + 4<<" ";
            }
            cout<<endl;
            cout<<n/2<<endl;
            fo(i,0,n/4 ){
                cout<< 4*i + 2<<" ";
                cout<< 4*i + 3<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<(n-3)/2 + 2<<endl;
            cout<<1<<" ";
            cout<<2<<" ";
            fo(i,0,(n-3)/4 ){
                cout<< 4*i + 4<<" ";
                cout<< 4*i + 7<<" ";
            }
            cout<<endl;
            cout<<(n-3)/2 + 1<<endl;
            cout<<3<<" ";
            fo(i,0,n/4 ){
                cout<< 4*i + 5<<" ";
                cout<< 4*i + 6<<" ";
            }
            cout<<endl;
        }
    
    
    }
    return 0;
}