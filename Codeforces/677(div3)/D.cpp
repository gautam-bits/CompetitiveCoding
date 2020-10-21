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

bool funcc(vi& a, vi& b){
    return a.size() > b.size();
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
        ll arr[n];
        fo(i,0,n) cin>>arr[i];
        bool is = true;

        map<ll,vi> mp;
        multiset<ll> valid;
        
        vi ans;
        
        
        fo(i,0,n){
            mp[arr[i]].push_back(i+1);
        }

        vector<vi> abcd(mp.size());
        for(auto x : mp) abcd.pb(x.S);
        sort(abcd.begin(),abcd.end(),funcc);
        ll yo = 0;
        fo(i,0,n){
            for(auto x : abcd){
                if(yo < x.size()) ans.pb(x[yo]);
            }
            yo++;
        }

        fo(i,1,ans.size()){
            if(arr[ans[i] - 1] == arr[ans[i-1] - 1]){
                is = false;
                break;
            }
        }

        if(is){
            cout<<"YES"<<endl;
            fo(i,1,ans.size()){
                cout<<ans[i-1]<<" "<<ans[i]<<endl;
            }
        }
        else
        {
            /* code */
            cout<<"NO"<<endl;
        }
        
        

    

    
    
    }
    return 0;
}