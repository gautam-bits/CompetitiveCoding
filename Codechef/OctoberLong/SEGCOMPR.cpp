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
    #define all(x) x.begin(),x.end()
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
        ll n;
        cin>>n;
        int a[n],ans = 0;

        fo(i,0,n) cin>>a[i];

        fo(i,0,n){
            fo(j,i,n){
                vector<ll> tem;
                fo(x,i,j+1)tem.pb(a[x]);
                ll aa = 0;
                if(i == j) aa = a[i],ans += a[i];
                
                else {

                    ll maxxx = *max_element(all(tem));
                    //cout<<a[i]<<" "<<a[j]<<" "<<maxxx<<"ffddf"<<endl; 
                    ll aaaaa = 0,lafd,cntttt = 0;
                    if(maxxx == 0){
                        aa = 0,ans += 0;
                        continue;
                    }
                    while(maxxx){
                        maxxx >>= 1;
                        aaaaa++;
                    }
                    aaaaa--;
                    lafd = 1<<aaaaa;
                    //cout<<a[i]<<" "<<a[j]<<" "<<lafd<<"ffddf"<<endl;
                    fo(k,0,tem.size()){
                        if(tem[k] >= lafd)cntttt++;
                    }
                    //cout<<a[i]<<" "<<a[j]<<" "<<cntttt<<"ffddf"<<endl;
                    if(!(cntttt&1)){
                        ll cntt2 = 0;
                        fo(k,0,tem.size()){
                            if(tem[k] > lafd)cntt2++;
                        }
                        if(tem.size() - cntttt >= cntt2) aa = 0,ans += 0;
                        if(tem.size() - cntttt + max((ll)0,cntttt - 2)/2 >= 2) aa = 0,ans += 0;
                        else if(tem.size() - cntttt == 0){
                            ll hhhhh = 0;
                            fo(k,0,tem.size()){
                                hhhhh ^= tem[k];
                            }
                            if(hhhhh == 0) continue;
                            ll ffffff = 0;
                            while(hhhhh){
                                hhhhh >>= 1;
                                ffffff++;
                            }
                            ffffff--;
                            ans += 0*(1<<ffffff);
                        }
                        else{
                            ans += 2;
                        }
                        


                        
                    }
                    else if(cntttt&1){
                        aa = lafd,ans+=aa;
                    }
                    // else{
                    //     aa = 0,ans += ;
                    // }

                    // fo(k,0,tem.size()){
                    //     aa ^= tem[k];
                    // }
                    // if(aa != 0){
                    //     ll tee = 0;
                    //     while(aa){
                    //         aa >>= 1;
                    //         tee++;
                    //     }
                    //     tee--;
                    //     aa = 1<<tee;
                    // }
                    // ans += aa;
                }  
                //cout<<a[i]<<" "<<a[j]<<" "<<aa<<endl;  

            }
        } 

        cout<<ans<<endl;
    
    
    }
    return 0;
}