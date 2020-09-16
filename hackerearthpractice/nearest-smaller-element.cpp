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
vector<int> prevSmaller(vector<int> &A) {
        stack<int> s;
        int n = A.size();
        vector <int> res;
        fo(i,0,n) {
            if (i == 0) {
                res.push_back(-1);
                s.push(A[i]);
                continue;
            }
            while (!s.empty() && s.top() >= A[i]) {
                s.pop();
            }
            if (s.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }
            s.push(A[i]);
        }
        return res;
    }  
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
       int n;
        cin >> n;
        vector<int> a;
        fo(i,0,n) {
            cin >> a[i];
        }

        vector<int> ans =  prevSmaller(a);
        fo(i,0,n) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
    }
    return 0;
}