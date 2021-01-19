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
    typedef pair<ll,ll> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx_3d[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
    const int dy_3d[8] = {-1,  0,  1,  1,  1,  0, -1, -1};
    const int dx_2d[4] = {-1 ,  0,  1,  0};
    const int dy_2d[4] = {0  ,  1,  0, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

char graph[1010][1010];
bool visited[1010][1010];
int n,m;
bool yes;
string ans;

map<pi,char> direction;
void instMap(){
    direction[{1,0}]  = 'D';
    direction[{0,1}]  = 'R';
    direction[{-1,0}] = 'U';
    direction[{0,-1}] = 'L';
}


bool isValidateCoord(int x, int y){
    bool ans = true;
    ans &= (x < n & x >=0);
    ans &= (y < m & y >=0);
    return ans;
}

bool dfs(int i, int j) {
    //cout<<i<<" "<<j<<endl;
    visited[i][j] = true;
    if(graph[i][j] == 'B'){
        return true;
    }

    fo(k,0,4){
        int x = i + dx_2d[k];
        int y = j + dy_2d[k];
        if(isValidateCoord(x,y) && graph[x][y] != '#' && (!visited[x][y])){
            if(dfs(x,y)) {
                //cout<<"pare "<<i<<" "<<j<<endl;
                //cout<<x<<" "<<y<<endl;
                ans += direction[{dx_2d[k],dy_2d[k]}];
                return true;
            }
        }
    }
    
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    t = 1;
    while(t--)
    {
        cin>>n>>m;
    
        mem(graph,'#');
        mem(visited,false);
        yes = false;
        ans = "";
        instMap();

        pi pos ;


        fo(i,0,n) {
            fo(j,0,m) {
            cin>>graph[i][j];
            if(graph[i][j] == 'A'){
                    pos = {i,j};
                }
            }
        }


        yes = dfs(pos.F,pos.S);

        if(yes) {
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
        else    cout<<"NO"<<endl;
    }
    return 0;
}