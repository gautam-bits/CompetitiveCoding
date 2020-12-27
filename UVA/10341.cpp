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
    #define EPS 1e-9
    
    
    typedef vector<ll> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
double funcd(double x,vi& input){
    double ans = input[0]*(double)exp(-1*x) + input[1]*sin(x) + input[2]*cos(x) + input[3]*tan(x) + (double)input[4]*x*x + (double)input[5];
    //cout<<x<<" "<<ans<<endl;
    return ans ;
}  
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vi input(6);
    
    while(cin>>input[0])
    {
        fo(i,0,5)cin>>input[i+1];
        double lo = 0.0 ;
        double hi = 1.0;
        double mid = 0.0;
        double ans = 0.0;

        if(funcd(1.0,input)*funcd(0.0,input) > 0.0){
            cout<<"No solution"<<endl;
        }
        else if(funcd(1.0,input) == 0.0) cout<<"1.0000"<<endl;
        else if(funcd(0.0,input) == 0.0) cout<<"0.0000"<<endl;
        else {
            while(fabs(hi - lo) > EPS){                
                mid = (lo + hi)/2;
                //cout<<"mid"<<mid<<endl;
                if(funcd(mid,input)*funcd(lo,input) <= 0.0) {
                    //cout<<funcd(mid,input)<<endl;
                    hi = mid;
                }
                else lo = mid;
            }  
            cout<<setprecision(4)<<(lo+hi)/2<<endl;
            
        }
    
    }
    return 0;
}