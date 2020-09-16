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
bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
}

pair<ll,bool> find(ll halfSum) {

    int temp = (ll)((sqrt(1 + 8*halfSum) - 2)/2);
    if(isPerfectSquare(1 + 8*halfSum)) {
        if((ll)((sqrt(1 + 8*halfSum) - 2))%2 == 0){
            return(MP(temp, true));
        }
        else {
            return(MP(temp, false));
        }
    }
    else {
        return(MP(temp, false));
    }

    // if(r > l) {
    //     ll mid = l + (r - l)/2;
    //     ll a = (mid*(mid + 1))/2;
    //     ll b = ((mid + 1)*(mid + 2))/2;
    //     if(a < halfSum && b > halfSum ) {
    //         return mid ;
    //     }
    //     else if(b < halfSum) {
    //         return binarySearchIndex(mid + 1, r, halfSum);
    //     }
    //     else {
    //          return binarySearchIndex(l , mid - 1, halfSum);
    //     }
    // }
    // else {
    //     return - 1;
    // }
}  
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
        if(n%4 == 3 || n%4==0) {
            ll halfsum = (n*(n + 1))/2;
            auto ans = find(halfsum);
            cout<<n<<" "<<ans.F<<endl;
            //ll finalans = (ans*(ans + 1))/2;
            if(ans.S) {
                cout<<(ans.F*(ans.F - 1))/2 + ((n - ans.F)*(n - ans.F - 1))/2<<endl;
            }
            else {
                cout<<n - ans.F<<endl;
            }
        }
        else {
            cout<<0<<endl;
        }
    
    
    }
    return 0;
}