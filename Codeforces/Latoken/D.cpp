// This is an intellectual property of Diablo Escada ,
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

    #define vshow1d(arr) {ll nn = arr.size(); fo(ii,0,nn) {csp(arr[ii]);}cout<<endl;}
    #define show1d(n,arr) fo(i,0,n) {csp(arr[i]);}cout<<endl;
    #define vshow2d(arr) {ll nn=arr.size();   fo(ii,0,nn) {ll m = arr[ii].size(); fo(j,0,m) csp(arr[ii][j]); cout << endl;}}
    #define show2d(n,m,arr) {fo(i,0,n) {fo(j,0,m) csp(arr[i][j]); cout << endl;}}
    
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    //#define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi query(ll node,ll n){
    cout<<"? "<<node+1<<endl;
    vi vec(n);
    cinarr(n,vec);
    return vec;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    read(n);

    vvi adjlist(n);

    set<ll> visited;

    queue<ll> q;

    q.push(0);
    visited.insert(0);

    ll cnt = 1;


    while(cnt < n) {
        ll curr = q.front();
        q.pop();

        
        vi vec = query(curr,n);

        vvi vec1(n);

        fo(i,0,n){
            if(visited.size() == 0 || visited.find(i) == visited.end()) {
                vec1[vec[i]].pb(i);
            }
            
        }

        

        // if(curr == 2) {
        //     vshow1d(vec1);
        //     vshow1d(vec2);
        // }

        vshow2d(vec1);

        fo(i,1,n){
            cnl("gy");
            if(vec1[i].size() == 0){
                cnl("gyf");
                break;
            }
            else if(vec1[i].size() > 1) {
                for(ll x : vec1[i]){
                    adjlist[vec1[i-1][0]].pb(x);
                    q.push(x);
                    visited.insert(x);
                    cnt++;
                }
                break;
            }
            else {
                
                adjlist[vec1[i-1][0]].pb(vec1[i][0]);
                visited.insert(vec1[i][0]);
                cnt++;
                
            }
        }

        
    }

    cout<<"!"<<endl;

    fo(i,0,n){
        cout<<"yp"<<endl;
        fo(j,0,adjlist[i].size()) {
            cout<<i+1<<" "<<adjlist[i][j]+1<<endl;
        }
    }





    
    
    return 0;
}