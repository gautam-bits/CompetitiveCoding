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
        ll n,q;
        cin>>n>>q;
        int a[n];
        fo(i,0,n) cin>>a[i];
        int t1,t2;
        cin>>t1>>t2;

        a[t1-1] = t2;

        ll haha = n;

        vi ans,ans2;
        //fo(i,0,n) cout<<a[i]<<" ";

        fo(i,0,n-1){
            if(a[i] == a[i+1])haha--;
        }
        // if(ans.size() == 0) haha = n;

        // else {
        //     ans2.pb(ans[0] + 1);
        //     ans2.pb(n - ans[ans.size()-1] - 1 );
        //     fo(i,1,ans.size()){
        //         ans2.pb(ans[i]-ans[i-1]);
        //     }
        //     haha = *max_element(ans2.begin(),ans2.end());
        // }

        cout<<haha<<endl;
    
    
    }
    return 0;
}