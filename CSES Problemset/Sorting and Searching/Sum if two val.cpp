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
    struct custom_hash {
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            x ^= FIXED_RANDOM;
            return x ^ (x >> 16);
        } 
    };
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    t = 1;
    
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll temp;

        bool possible = false;
        unordered_set<ll,custom_hash> s1;
        
        ll a[n];
        fo(i,0,n)cin>>a[i];

        fo(i,0,n){

            if(!s1.empty() && (s1.find(x - a[i]) != s1.end())){
                ll xx = -1;
                fo(j,0,n) if(a[j] == (x-a[i])){
                    xx = j;
                    break;
                }
                cout<<i+1<<" "<<xx+1<<endl;
                possible = true;
                break;
            }
            s1.insert(a[i]);

        }

        if(!possible){
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}