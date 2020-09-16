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
        string subarr,ans = "";
        cin>>subarr;
        int n = subarr.size();
        stack<char> s1;

        fo(i,0,n) {
            if(s1.empty()) {
                s1.push(subarr[i]);
            }
            else {
                if(s1.top() == subarr[i]) {
                    s1.pop();
                }
                else {
                    s1.push(subarr[i]);
                }
            }
        }
        
        if(!s1.size()) {
        cout << "KHALI" <<endl;
        }
        else {
            while(!s1.empty()) {
                ans += s1.top();
                s1.pop();
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
    }
    return 0;
    
}
    
