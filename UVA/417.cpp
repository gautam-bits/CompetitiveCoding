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
    
    string str;

    set<string> allStr;

    fo(i,0,26){
        string temp;
        temp += (char)('a' + i);
        allStr.insert(temp);
    }
    fo(i,0,26){
        fo(j,i+1,26){
            string temp;
            temp += (char)('a' + i);
            temp += (char)('a' + j);
            allStr.insert(temp);
        }
    }
    fo(i,0,26){
        fo(j,i+1,26){
            fo(k,j+1,26){
                string temp;
                temp += (char)('a' + i);
                temp += (char)('a' + j);
                temp += (char)('a' + k);
                allStr.insert(temp);
            }
        }
    }
    fo(i,0,26){
        fo(j,i+1,26){
            fo(k,j+1,26){
                fo(l,k+1,26){
                    string temp;
                    temp += (char)('a' + i);
                    temp += (char)('a' + j);
                    temp += (char)('a' + k);
                    temp += (char)('a' + l);
                    allStr.insert(temp);
                }
            }
        }
    }

    fo(i,0,26){
        fo(j,i+1,26){
            fo(k,j+1,26){
                fo(l,k+1,26){
                    fo(m,l+1,26){
                        string temp;
                        temp += (char)('a' + i);
                        temp += (char)('a' + j);
                        temp += (char)('a' + k);
                        temp += (char)('a' + l);
                        temp += (char)('a' + m);
                        allStr.insert(temp);
                    }
                }
            }
        }
    }

        

    while(cin>>str)
    {
        if(allStr.find(str) != allStr.end()){
            int ans = 0;
            auto pos = allStr.find(str);
            for (auto it = allStr.begin(); it != pos; it++) ans++;
            cout<<ans<<endl;
        }
        else {
            cout<<0<<endl;
        } 
    }
    return 0;
}