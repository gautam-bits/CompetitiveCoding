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
    //cin>>t;
    t = 1;
    while(t--)
    {
        string s;
        cin>>s;
        ll freq[26]={0};

        for(char x : s) freq[x-'A']++;
        ll spec_char = -1;

        ll ans = 0;
        fo(i,0,26) if(freq[i]&1) ans++,spec_char = i ; 

        if(ans > 1){
            cout<<"NO SOLUTION"<<endl;
        } else {
            string ans="";
            fo(j,0,26) if(!(freq[j]&1)){
                fo(i,0,freq[j]/2){
                    ans += (char)('A' + j);
                }
            }
            cout<<ans;
            if(spec_char != -1) fo(i,0,freq[spec_char]) cout<<(char)('A' + spec_char);
            reverse(ans.begin(),ans.end());
            cout<<ans;
        }



    
    
    }
    return 0;
}