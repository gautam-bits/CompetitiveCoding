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
        ll a[n];
        fo(i,0,n) cin>>a[i];
        sort(a,a + n);

        if(n&1) {
            //cout<<n/2;
            int anssss = 0;
            vector<ll> aaa, bbb,temp;
            fo(i,0,n/2) aaa.pb(a[i]);
            fo(i,n/2,n) bbb.pb(a[i]);
            fo(i,0,n/2){
                // cout<<bbb[i]<<" ";
                // cout<<aaa[i]<<" ";
                temp.pb(bbb[i]);
                temp.pb(aaa[i]);
            }
            // cout<<bbb[n/2 -1]<<endl;
            temp.pb(bbb[n/2 -1]);
            fo(i,1,n) {
                if(temp[i] < temp[i-1] && temp[i] < temp[i+1])anssss++;
                i++;
            }
            cout<<anssss<<endl;
            fo(i,0,n) cout<<temp[i]<<" ";
            cout<<endl;

        }
        else{
            //cout<<n/2 - 1;
            int anssss = 0;
            vector<ll> aaa, bbb ,temp;
            fo(i,0,n/2 - 1) aaa.pb(a[i]);
            fo(i,n/2 - 1,n) bbb.pb(a[i]);
            fo(i,0,n/2 - 1){
                // cout<<bbb[i]<<" ";
                // cout<<aaa[i]<<" ";
                temp.pb(bbb[i]);
                if(i>0) temp.pb(aaa[i - 1]);
            }
            // cout<<bbb[n/2 - 1]<<" ";
            // cout<<bbb[n/2]<<endl;
            temp.pb(bbb[n/2 - 1]);
            temp.pb(aaa[n/2 - 2]);
            temp.pb(bbb[n/2]);

            fo(i,2,n) {
                if(temp[i] < temp[i-1] && temp[i] < temp[i+1])anssss++;
                i++;
            }
            cout<<anssss<<endl;
            fo(i,0,n) cout<<temp[i]<<" ";
            cout<<endl;
        }

    
    
    }
    return 0;
}