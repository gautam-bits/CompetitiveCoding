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
        
        if(n == 1){
            cout<<"1"<<endl;
        }
        else if(n == 3){
            cout<<"1 3 2"<<endl;
        }
        else if(n == 5){
            cout<<"2 3 1 5 4"<<endl;
        }
        else if(n == 6){
            cout<<"1 3 2 6 4 5"<<endl;
        }
        else if(n == 7){
            cout<<"1 3 2 6 4 5 7"<<endl;
        }
        else if(bitcount(n) == 1){
            cout<<"-1"<<endl;
        }
        else {
            ll a[n + 1];

            a[0] = -1;
            a[1] = 1;
            a[2] = 3;
            a[3] = 2;
            a[4] = 6;
            a[5] = 4;
            a[6] = 5;
            a[7] = 7;
            
            
            fo(i,8,n+1){
                if(bitcount(i) == 1){
                    a[i] = i + 1;
                    a[i+1] = i;
                    i++;
                }
                else{
                    a[i] = i;
                }
            }

            fo(i,1,n+1){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            


        }
    
    
    }
    return 0;
}