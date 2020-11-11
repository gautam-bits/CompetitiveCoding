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
void printnew(ll a,ll b){
    cout<<"Closest sum to "<<a<<" is "<<b<<"."<<endl;
} 
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    ll t = 1;
    
    while(cin>>n && n != 0)
    {
        ll a[n];
        fo(i,0,n) cin>>a[i];

        ll m;
        cin>>m;
        cout<<"Case "<<t<<":"<<endl;
        fo(i,0,m){
            ll key;
            cin>>key;
            ll itr1 = 0, itr2 = n-1;
            ll ans1=(ll)(-1e17),ans2=(ll)(-1e17);
            while(itr1 < itr2) {
                if(a[itr1] + a[itr2] < key){
                    ans1 = a[itr1] + a[itr2];
                    itr1++;
                }
                else if(a[itr1] + a[itr2] > key){
                    ans2 = a[itr1] + a[itr2];
                    itr2--;
                }
                else{
                    ans1 = a[itr1] + a[itr2];
                    break;
                }
            }
            if(abs(ans1-key) > abs(ans2-key))printnew(key,ans2);
            else printnew(key,ans1);
            

        }
        t++;
    
    }
    return 0;
}