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
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    
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
        ll x1,y1,x2,y2,ans=-1;
        cin>>x1>>y1>>x2>>y2;

        queue<pair<pair<pi,pi>,ll>> q1;

        q1.push({{{x1,y1},{0,0}},0});

        if(x1 == x2 && y1==y2){
            cout<<0<<endl;
            continue;
        }

        while(!q1.empty()){

            pair<pair<pi,pi>,ll> temp = q1.front();

            ll x = temp.F.F.F,y = temp.F.F.S;
            ll t11 = temp.F.S.F,t22 = temp.F.S.S;

            // int x = temp.F.F.F,y = temp.F.F.S;

            q1.pop();


            ll ee_x = x + 2*y, ee_y = y;
            ll ww_x = x - 2*y, ww_y = y;
            ll nn_y,nn_x;
            if(y + 2*x > 0) nn_x = x, nn_y = y + 2*x;
            else  nn_x = -x, nn_y = -y - 2*x;
            ll ss_y,ss_x;
            if(y - 2*x > 0) ss_x = x, ss_y = y - 2*x;
            else  ss_x = -x, ss_y = -y + 2*x;

            // pair<pair<pi,pi>,ll> nn = {{{nn_x,nn_y},{x,y}},temp.S + 1};
            // pair<pair<pi,pi>,ll> ss = {{{ss_x,ss_y},{x,y}},temp.S + 1};
            // pair<pair<pi,pi>,ll> ee = {{{ee_x,ee_y},{x,y}},temp.S + 1};
            // pair<pair<pi,pi>,ll> ww = {{{ww_x,ww_y},{x,y}},temp.S + 1};

            if(ee_x == x2 && ee_y == y2){
                ans= temp.S + 1;
                break;
            }
            else if(ww_x == x2 && ww_y == y2){
                ans= temp.S + 1;
                break;
            }
            else if(nn_x == x2 && nn_y == y2){
                ans= temp.S + 1;
                break;
            }
            else if(ss_x == x2 && ss_y == y2){
                ans= temp.S + 1;
                break;
            }
            if(ee_x != t11 || ee_y != t22) q1.push({{{ee_x,ee_y},{x,y}},temp.S + 1});
            if(ww_x != t11 || ww_y != t22) q1.push({{{ww_x,ww_y},{x,y}},temp.S + 1});
            if(nn_x != t11 || nn_y != t22) q1.push({{{nn_x,nn_y},{x,y}},temp.S + 1});
            if(ss_x != t11 || ss_y != t22) q1.push({{{ss_x,ss_y},{x,y}},temp.S + 1});
            
        }

        cout<<ans<<endl;
    }
    return 0;
    
}
    
