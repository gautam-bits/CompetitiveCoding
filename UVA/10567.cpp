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
    t = 1;
    
    while(t--)
    {
        string str;
        cin>>str;
        ll q;
        cin>>q;
        //pre processing
        vi letter_idx[52];  // a..z A..Z
        fo(i,0,str.length()) {
            if(str[i] - 'a' >= 0) letter_idx[str[i]-'a'].push_back(i);
            else letter_idx[str[i]-'A' + 26].push_back(i);
        }
        // fo(i,0,52) {
        //     fo(j,0,letter_idx[i].size()){
        //         cout<<letter_idx[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        fo(i,0,q){     //upper_bound
            string tem;
            cin>>tem;
            int sz = tem.size();
            ll ans1[sz] ;
            
            ll curr = -1;

            bool matched = true;
            fo(j,0,sz){
                //find vec
                ll vec_idx = -1;
                if(tem[j] - 'a' >= 0) vec_idx = tem[j] - 'a';
                else vec_idx = tem[j] - 'A' + 26;

                //binsearch for curr with exception
                auto itr = upper_bound(letter_idx[vec_idx].begin(),letter_idx[vec_idx].end(),curr);
                if(itr == letter_idx[vec_idx].end()) {
                    matched = false;
                    break;
                }
                //update curr
                curr = *itr;
                //cout<<"curr"<<curr<<endl; 
                ans1[j] = curr;    
            }
            //print ans
            if(!matched) cout<<"Not matched"<<endl;
            else cout<<"Matched "<<ans1[0]<<" "<<ans1[sz-1]<<endl;

        }
    
    
    }
    return 0;
}