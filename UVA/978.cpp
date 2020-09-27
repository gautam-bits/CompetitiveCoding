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
        ll b,sg,sb,temp;
        cin>>b>>sg>>sb;
        multiset<ll,greater<ll>> teamg,teamb;
        fo(i,0,sg) {
            cin>>temp;
            teamg.insert(temp);
        }
        fo(i,0,sb) {
            cin>>temp;
            teamb.insert(temp);
        }

        while(teamb.size() && teamg.size() ){
            ll size_g = teamg.size();
            ll size_b = teamb.size();

            ll iterations = min(b,min(size_g,size_b));

            auto it_g = teamg.begin();
            auto it_b = teamb.begin();

            vector<ll> teamg_e,teamg_i,teamb_e,teamb_i;

            while(iterations--) {
                if(*it_g > *it_b) {
                    ll temp = *it_g - *it_b;
                    // teamg.erase(it_g);
                    // teamb.erase(it_b);
                    // teamg.insert(temp);
                    teamg_e.pb(*it_g);
                    teamb_e.pb(*it_b);
                    teamg_i.pb(temp);
                }
                else if(*it_b > *it_g) {
                    ll temp = *it_b - *it_g;
                    // teamg.erase(it_g);
                    // teamb.erase(it_b);
                    // teamb.insert(temp);
                    teamg_e.pb(*it_g);
                    teamb_e.pb(*it_b);
                    teamb_i.pb(temp);
                }
                else {
                    // teamg.erase(it_g);
                    // teamb.erase(it_b);
                    teamg_e.pb(*it_g);
                    teamb_e.pb(*it_b);
                }
                it_g++;
                it_b++;
            } 
            for(auto x : teamg_e) teamg.erase(teamg.find(x));
            for(auto x : teamb_e) teamb.erase(teamb.find(x));
            for(auto x : teamg_i) teamg.insert(x);
            for(auto x : teamb_i) teamb.insert(x);

        }

        if(teamg.size()){
            cout<<"green wins"<<endl;
            for(auto x : teamg) cout<<x<<endl;
            cout<<endl;
        }
        else if(teamb.size()){
            cout<<"blue wins"<<endl;
            for(auto x : teamb) cout<<x<<endl;
            cout<<endl;
        }
        else{
            cout<<"green and blue died"<<endl;
            cout<<endl;
        }
        

    
    
    }
    return 0;
}