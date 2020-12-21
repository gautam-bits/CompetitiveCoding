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
    
    
    typedef vector<ll> vi;
    typedef vector<bool> vb;
    typedef pair<ll,ll> pi;
    
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
        ll n,x;
        cin>>n;
        ll a[n];
        fo(i,0,n) cin>>a[i];

        vector<vb> table(n,vb (35,0));

        vb help(35,0);

        //fill table
        ll idx = 0;
        fo(i,0,n) {
            idx = 0;
            while(a[i]){
                if(a[i]&1){
                    table[i][idx] = 1;
                }
                a[i] >>= 1;
                idx++;
            }
        }

        //greedy use of x operations
        fo(i,0,n){
            rfo(j,34,0){
                if(table[i][j]){
                    if(help[j]){
                        table[i][j] = 0;
                        help[j] = 0;
                    }
                    else {
                        table[i][j] = 0;
                        help[j] = 1;
                        x--;
                        if(!x) break;
                    }
                }
            }
        }

        //test
        fo(i,0,n){
            fo(j,0,35){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }


        
    
    
    }
    return 0;
}