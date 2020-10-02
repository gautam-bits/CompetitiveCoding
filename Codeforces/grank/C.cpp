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
        ll n,l;
        cin>>n>>l;
        ll flag[n+2];
        double ans = -1.0 ;

        flag[0] = 0;
        fo(i,1,n+1) cin>>flag[i];
        flag[n+1] = l;

        // pair<ll,ll> te = {0,0};
        vector<pair<double,ll>> time_vel_1(n + 2,{0.0,0}) , time_vel_2(n + 2,{0.0,0});
        ll ini_vel_1 = 1, ini_vel_2 = 1,t_1 = 0 , t_2 = 0;

        fo(i,0,n+2) {
            if(i == 0) {
                time_vel_1[0] = {0.0,1};
            }
            else {
                ll speed = time_vel_1[i-1].S + 1;
                double time = time_vel_1[i-1].F + ((double)(flag[i] - flag[i-1]))/time_vel_1[i-1].S;
                time_vel_1[i] = {time,speed};
            }
        }
        
        rfo(i,n + 1,0) {
            if(i == n+1) {
                time_vel_2[i] = {0.0,1};
            }
            else {
                ll speed = time_vel_2[i+1].S + 1;
                double time = time_vel_2[i+1].F + ((double)(flag[i + 1] - flag[i]))/time_vel_2[i+1].S;
                time_vel_2[i] = {time,speed};
            }
        }
        // fo(i,0,n+2){
        //     cout<<time_vel_2[i].F<<" "<<time_vel_2[i].S<<endl;
        // }

        fo(i,0,n+2){
            if(time_vel_2[i].F == time_vel_1[i].F){
                ans = time_vel_2[i].F;
                break;
            }
        }

        if(ans == -1.0) {
            ll itr = -1;

            fo(i,0,n+2){
                if(time_vel_1[i].F > time_vel_2[i].F){
                    itr = i;
                    break;
                }
            }

            itr--;
            if(time_vel_1[itr].F > time_vel_2[itr + 1].F)
                ans = time_vel_1[itr].F + ((double)(flag[itr +1] - flag[itr] - (time_vel_2[itr + 1].S)*(time_vel_1[itr].F - time_vel_2[itr + 1].F )))/(time_vel_1[itr].S + time_vel_2[itr + 1].S);
            else{
                itr++;
                ans = time_vel_2[itr].F + ((double)(flag[itr] - flag[itr - 1] - (time_vel_1[itr - 1].S)*(time_vel_2[itr].F - time_vel_1[itr - 1].F )))/(time_vel_1[itr].S + time_vel_2[itr + 1].S);
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        cout<<ans<<endl;

    
    
    }
    return 0;
}