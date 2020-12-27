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
    
    ll n;
    
    
    while(cin>>n)
    {
        ll price[n];
        fo(i,0,n)cin>>price[i];

        sort(price,price+n);
        ll money;
        cin>>money;
        ll i = 0, j = n-1;
        ll a = -1,b = -1;
        bool ans = false;
        while(j > i) {
            if(price[i] + price[j] > money) j--;
            else if (price[i] + price[j] < money) i++;
            else {
                ans = true;
                a = i;
                b = j;
                i++;
            }
        }
        if(ans){
            cout<<"Peter should buy books whose prices are "<<price[a]<<" and "<<price[b]<<".";
            cout<<endl;
            cout<<endl;

        }
    
    }
    return 0;
}