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
        ll n,x,sum = 0,asum = 0;
        bool equal = true;
        cin>>n>>x;
        ll arr[n];
        fo(i,0,n) {
            cin>>arr[i];
            sum += arr[i];
            if(arr[i] == x)asum++;
            if(arr[i] != x) equal = false;
        }
        if(equal) {
            cout<<"0"<<endl;
        } 
        else if(asum > 0){
            cout<<1<<endl;
        }
        else {
            if(x == 0){
                if(sum == 0) cout<<1<<endl;
                else cout<<2<<endl;
            }
            else{
                if(sum >=0 && x >0){
                    if(n*x == sum) cout<<1<<endl;
                    else cout<<2<<endl;
                }
                else if (sum <0 && x < 0){
                    sum = -sum;
                    x = -x;
                    if(n*x == sum) cout<<1<<endl;
                    else cout<<2<<endl;
                }
                else cout<<2<<endl;
            }
        }


    
    
    }
    return 0;
}