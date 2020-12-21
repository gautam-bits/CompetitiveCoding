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
bool visited[(int)1e6] ;
ll cycle;
void dfss(ll cur, ll parent,vector<vi>& adjList) {
    visited[cur]= 1;
    for(int x : adjList[cur]){
        if(x != parent){
            if(visited[x]){
                cycle++;
                break;
            }
        }
        dfss(x,cur,adjList);
    }
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        mem(visited,0);
        cycle = 0 ;
        

        vector<vi> adjLs(m);
        vector<vi> row(n);
        vector<vi> col(n);

        fo(i,0,m){
            ll r,c;
            cin>>r,c;
            row[r-1].push_back(i);
            col[c-1].push_back(i);
        }

        fo(i,0,n){
            for(ll x : row[i]){
                for(ll t : row[i]){
                    if(x != t);
                    adjLs[x].push_back(t);
                }
            }
        }
        fo(i,0,n){
            for(ll x : col[i]){
                for(ll t : col[i]){
                    if(x != t);
                    adjLs[x].push_back(t);
                }
            }
        }


        //dfss(0,-1,adjLs);
        cout<<cycle<<endl;




    



    }
    return 0;
}