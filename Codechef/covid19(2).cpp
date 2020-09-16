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
        ll n;
        cin>>n;
        float time[n][n];
        vector<int> speed(n),ans(n,0);
        bool willTouch[n][n] ;

        fo(i,0,n) { 
            fo(j,0,n) {
                willTouch[i][j] = false ;
            }
            willTouch[i][i] = true ;
        }
        
        fo(i,0,n) {
            cin>>speed[i];
        }
    
        fo(i,0,n)
            fo(j,0,n)
                time[i][j] = -1.0 ;

        fo(i,0,n) {
            fo(j,i+1,n) {
                    if(speed[j] < speed[i]) {
                        time[i][j] = ((float)(j - i))/(speed[i] - speed[j]);
                        time[j][i] = ((float)(j - i))/(speed[i] - speed[j]);
                    }
            }
        }

        fo(i,0,n) {
            // fo(i,0,n) { 
            //     fo(j,0,n) {
            //         cout<<willTouch[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            queue<ll> touched ;
            fo(j,0,n){
                if(time[i][j] > 0.0){
                    willTouch[i][j] = true ;
                    touched.push(j);
                }
            }
            while(touched.size() != 0) {
                int temp = touched.front();
                touched.pop();
                fo(k,0,n) {
                    if(time[temp][k] > 0.0 && time[i][temp] > 0.0 && time[temp][k] > time[i][temp]  && temp != k && willTouch[i][k] == false) {
                        willTouch[i][k] = true;
                        touched.push(k);
                    }
                }
            }
            
            // fo(i,0,n) { 
            //     fo(j,0,n) {
            //         cout<<willTouch[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        }

        fo(i,0,n) 
            fo(j,0,n)
                if(willTouch[i][j] == true) 
                    ans[i]++;
        
        cout<<*min_element(ans.begin(),ans.end())<<" "<<*max_element(ans.begin(),ans.end())<<endl;

        // fo(i,0,n) { 
        //     fo(j,0,n) {
        //         cout<<willTouch[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    
    }
    return 0;
}