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
        ll n,ans=0,rand,sumOfAll ;
        cin>>n;
        ll shifter = 1,bitsShip = 1 ;
        fo(i,0,20) {
            if(i == 0) {
                cout<<1<<" "<<0<<endl;
                fflush(stdout);
                cin>>sumOfAll;
                ans += sumOfAll&1;
            }
            else {
                ll temp = shifter<<bitsShip ;
                ll te ;
                cout<<1<<" "<<temp<<endl;
                fflush(stdout);
                cin>>te ;
                if(te > sumOfAll) {
                    ll randdd = te - sumOfAll;
                    randdd = randdd>>bitsShip;
                    randdd = (n - randdd)/2;
                    randdd = randdd&1;
                    ans += randdd<<bitsShip;
                }
                else {
                    ll randdd = sumOfAll - te;
                    randdd = randdd>>bitsShip;
                    randdd = (n + randdd)/2;
                    randdd = randdd&1;
                    ans += randdd<<bitsShip;
                }
                // te = te<<bitsShip;
                // te = te&1;
                // ans += te>>bitsShip;
                bitsShip++;
            }
            
        }
        cout<<2<<" "<<ans<<endl;
        fflush(stdout);
        cin>>rand;
        if(rand == -1) break;
    }
    return 0;
}