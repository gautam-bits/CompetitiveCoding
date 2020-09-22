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
    
    // ll t;
    // cin>>t;
    
    ll n ;
    while(cin>>n)
    {   
        //cout<<n<<"teri ma ka"<<endl;
        ll total = 1<<n;
        ll weight[total];
        ll ans[total] = {0},final[total] = {0};
    
        fo(i,0,total) cin>>weight[i] ;
    
        fo(i,0,total) {
            //ll sum = 0 ;
            ll temp = 1;
            fo(j,0,n) {
                ll rand = i ^ (temp<<j);
                ans[i] += weight[rand];
            }
        }
        
        fo(i,0,total) {
            //ll sum = 0 ;
            ll maxxx = 0;
            ll temp = 1;
            fo(j,0,n) {
                ll rand = i ^ (temp<<j);
                maxxx = max(maxxx,ans[rand]);
            }
            final[i] = maxxx + ans[i];
        }
        cout<<*max_element(final,final + total)<<endl;
        sort(weight,weight + total);
        //fo(i,0,total) cout<<final[i]<<" ";
        //cout<<endl;
        //cout<<ans[total - 1] + ans[total - 2]<<endl;
    }
    return 0;
}