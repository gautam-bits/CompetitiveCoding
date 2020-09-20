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
    const ll dl[6] = {-1,1,0,0,0,0};
    const ll dr[6] = {0,0,-1,1,0,0};
    const ll dc[6] = {0,0,0,0,-1,1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

bool validateCoordinate(ll x, ll y,ll z, ll L,ll R,ll C){
    if(x<L && x>=0)
        if(y<R && y>=0)
            if(z<C && z>=0)
                return true;
    return false;
}

void exploreNeighbours(ll& a,ll& b,ll& c,ll& L,ll& R,ll& C,ll& nodes_in_next_layer,vector<vector<vector<bool>>>& visited,vector<vector<vector<char>>>& inputMatrix,queue<ll>& lq,queue<ll>& rq,queue<ll>& cq) {
    fo(i,0,6){
            ll newL = a + dl[i];
            ll newR = b + dr[i];
            ll newC = c + dc[i];
        
            if(!validateCoordinate(newL,newR,newC,L,R,C)) continue;
            if(visited[newL][newR][newC]) continue;
            if(inputMatrix[newL][newR][newC] == '#') continue;

            lq.push(newL);
            rq.push(newR);
            cq.push(newC);

            visited[newL][newR][newC] =   true;
            nodes_in_next_layer++;
        }
}

void solve(ll& sl,ll& sr,ll& sc,ll& L,ll& R,ll& C,vector<vector<vector<bool>>>& visited,vector<vector<vector<char>>>& inputMatrix,queue<ll>& lq,queue<ll>& rq,queue<ll>& cq,bool reached_end,ll& nodes_in_next_layer,ll& nodes_left_in_layer,ll& move_count){
    lq.push(sl);
    rq.push(sr);
    cq.push(sc);
    visited[sl][sr][sc] = true ;

    while(!lq.empty()) {
        ll a = lq.front();
        ll b = rq.front();
        ll c = cq.front();

        lq.pop();
        rq.pop();
        cq.pop();

        if(inputMatrix[a][b][c] == 'E'){
            reached_end = true;
            break;
        }

        
        exploreNeighbours(a,b,c,L,R,C,nodes_in_next_layer,visited,inputMatrix,lq,rq,cq);
        nodes_left_in_layer--;
        if(nodes_left_in_layer == 0){
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }

    }

    if(reached_end)
        cout<<"Escaped in "<<move_count<<" minute(s)."<<endl;
    else
        cout<<"Trapped!"<<endl;
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    while(true){
        ll L,R,C;
        cin>>L>>R>>C;
        
        if(L == 0 && R == 0 && C == 0) break;
        
        vector<vector<vector<char>>> inputMatrix(L,vector<vector<char>>(R,vector<char>(C,' ')));
        ll sl,sr,sc;
        queue<ll> lq,rq,cq;

        ll move_count = 0 ;
        ll nodes_left_in_layer = 1 ;
        ll nodes_in_next_layer = 0 ;
        bool reached_end = false ;
        vector<vector<vector<bool>>> visited(L,vector<vector<bool>>(R,vector<bool>(C,false))); 

        // fo(i,0,L)
        //     fo(j,0,R)
        //         fo(k,0,C)
        //             visited[i][j][k]= false;
        
        

        fo(i,0,L){
            fo(j,0,R){
                fo(k,0,C){
                    cin>>inputMatrix[i][j][k];

                    if(inputMatrix[i][j][k] == 'S'){
                        sl = i;
                        sr = j;
                        sc = k;
                    }
                }
            }
        }

        solve(sl,sr,sc,L,R,C,visited,inputMatrix,lq,rq,cq,reached_end,nodes_in_next_layer,nodes_left_in_layer,move_count);
    }

    return 0;
}