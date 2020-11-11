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
        ll a[n];
        ll ans = 0;
        ll cnt = 0;
        bool link[n-1] ;

        fo(i,0,n) cin>>a[i];

        fo(i,0,n-1){
            if(a[i] == a[i+1]) link[i] = true,cnt++;
            else link[i] = false;
            
        }
        ans = n - cnt;
        //fo(i,0,n-1)cout<<link[i];
        cout<<endl;
        //cout<<ans;
        fo(i,0,q){
            ll x,y;
            cin>>x>>y;
            x--;
            a[x] = y;
            
            if(x == 0){
                //cout<<"s1d";
                ll neww = (a[x] == a[x+1]);
                ll oldd = link[x];
                ans += oldd - neww;
                link[x] = (a[x] == a[x+1]);
            }
            else if(x == n-1){
                //cout<<"s2d";
                ll neww = (a[x] == a[x-1]);
                ll oldd = link[x-1];
                ans += oldd - neww;
                link[x-1] = (a[x] == a[x-1]);
            }
            else{
                //cout<<"sd";
                ll neww = (a[x] == a[x+1]);
                ll oldd = link[x];
                ans += oldd - neww;
                link[x] = (a[x] == a[x+1]);

                ll neww2 = (a[x] == a[x-1]);
                ll oldd2 = link[x-1];
                ans += oldd2 - neww2;
                link[x-1] = (a[x] == a[x-1]);
            }
            cout<<ans<<endl;
        }

        

    
    
    }
    return 0;
}