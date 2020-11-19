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
        ll a[n],sum = 0;

        ll ans=0,ans1=0,ans2=0,ans3=0,ans4=0,ans5=0;
        ll a1,a2,a3,a4,a5;
        a1 = a2 = a3 = a4 = a5 = 0;

        fo(i,0,n)cin>>a[i],sum+=a[i];

        ans1 = sum/n;
        ans2 = ans1-1;
        ans3 = ans1 + 1;
        ans4 = ans1 + 2;
        ans5 = ans1 - 2;


        fo(i,0,n){
            a1+=abs(a[i]-ans1);
            a2+=abs(a[i]-ans2);
            a3+=abs(a[i]-ans3);
            a4+=abs(a[i]-ans4);
            a5+=abs(a[i]-ans5);

        }
        ans = min(min(a1,min(a2,a3)),min(a4,a5));

        cout<<ans<<endl;

    
    
    }
    return 0;
}