// This is an intellectual property of Diablo Escata ,
// So please use it with extreme CAUTION .


//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define lb lower_bound
    #define ub upper_bound
    #define bs binary_search

    #define cnl(x) cout << x << endl
    #define csp(x) cout << x << " "
    #define read(x) cin >> x
    #define cinarr(n,arr) fo(i,0,n) read(arr[i]);
    #define cinarr2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) read(arr[i][j]);}}
    #define all(v) v.begin(),v.end()

    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll n = arr.size(); fo(i,0,n) {csp(arr[i]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {ll n=arr.size();   fo(i,0,n) {ll m = arr[i].size(); fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<bool> vb;
    typedef vector<vb> vvb;
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//


void special_dfs(ll curr,ll dom,ll n,vvb& adjMat,vb& visited,vvb& answer){
    visited[curr] = 1;
    answer[dom][curr] = 0;
    if(curr == dom) return;
    fo(i,0,n){
        if(adjMat[curr][i] && !visited[i]) special_dfs(i,dom,n,adjMat,visited,answer); 
    }
}
void dfs(ll x, vb& notconn, vb& visited,vvb& adjMat){
    //cout<<x<<"discaard"<<endl;
    visited[x] = 1;
    notconn[x] = 0;
    ll n = adjMat.size();
    fo(i,0,n){
        if(adjMat[x][i] && !visited[i]) dfs(i,notconn,visited,adjMat);
    }
}

void print_answer(vvb& answer) {
    ll n = answer.size();
    
    fo(i,0,n){
        cout<<"+";
        fo(j,0,2*n-1)cout<<"-";
        cout<<"+"<<endl;
        fo(j,0,n){
            cout<<"|";
            if(answer[i][j]) cout<<"Y";
            else cout<<"N"; 
        }
        cout<<"|"<<endl;
    }
    cout<<"+";
    fo(j,0,2*n-1)cout<<"-";
    cout<<"+"<<endl;

}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vvb adjMat(n,vb (n,0));
        vb visited(n,0);

        char temp;
        
        fo(i,0,n) fo(j,0,n) if(read(temp) && temp == '1') adjMat[i][j] = 1;
        
        vvb answer(n,vb (n,1));

        
        fo(i,0,n) {
            fill(all(visited),0);
            special_dfs(0,i,n,adjMat,visited,answer);
        }

        fo(i,0,n) answer[i][i] = 1;    //trivial

        // not connected
        vb notconn(n,1);
        fill(all(visited),0);
        dfs(0,notconn,visited,adjMat);

        //show1d(n,notconn);
        fo(i,0,n){
            if(notconn[i]){
                fo(j,0,n){
                    answer[i][j]  = 0;
                }
            }
        }

        fo(i,0,n){
            fo(j,0,n){
                if(notconn[j]){
                    answer[i][j] = 0;
                }
            }
        }

        cout<<"Case "<<tno<<":"<<endl;
        print_answer(answer);

        
    
    }
    return 0;
}