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
    ll n;
    while(cin>>n)
    {   
        ll position[n] ;
        fo(i,0,n) position[i] = i + 1 ;

        while (true) {

            int temp;
            cin>>temp;

            if(temp == 0) break;

            ll orient[n];
            orient[0] = temp;
            stack<ll> st;
            fo(i,1,n) cin>>orient[i];

            ll j = 0,k = 0;

            while(k < n && j < n) {
                if(st.empty()){
                    st.push(position[j]);
                    j++;
                }
                else {
                    if(st.top() == orient[k]) {
                        st.pop();
                        k++;
                    }
                    else {
                        st.push(position[j]);
                        j++;
                    }
                }
            }

            if(j == n-1  && k == n-1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    
    }
    return 0;
}