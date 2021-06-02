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

    #define fo(i,a,b) for(ll i=a;i<b;i++)
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
    typedef vector<vi> vvi;

    const ll MOD   = 1000000007 ;
    //const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi vec;

ll ans = 0;

ll n;

vector<bool> visited;

vi te;

bool check() {


    //return 0;
    vi ans(n,1);
    fo(i,1,n){
        if(te[i] < te[i-1]){
            ans[i] = 1 + ans[i-1];
        }

        else {
            rfo(ii,i-1,0){
                if(te[ii] > te[i]){
                    //csp(i);csp(te[ii]);cnl("yo");

                    ans[i] = 1 + ans[ii];
                    break;
                }
            }
        }
    }


    return ans == vec;
}

void brute(ll idx,ll mx){
    //csp(idx);cnl("no");

    if(idx == n){

        //vshow1d(te);
        if(check()) ans = (ans + 1)%MOD;
        
    }

    else if(idx == 0) {
        fo(i,0,n){
            te[idx] = i+1;
            visited[i] = 1;
            ll tem = mx;
            mx = max(mx,i+1);
            brute(idx+1,mx);
            mx = tem;
            visited[i] = 0; 
        }
    }

    else {
        if(vec[idx] == 1) {
            fo(i,mx,n)if(!visited[i]){
                te[idx] = i+1;
                visited[i] = 1;
                ll tem = mx;
                mx = max(mx,i+1);
                brute(idx+1,mx);
                mx = tem;
                visited[i] = 0;

            }
        }
        else {

            fo(i,0,mx)if(!visited[i]){
                te[idx] = i+1;
                visited[i] = 1;
                ll tem = mx;
                mx = max(mx,(ll)i+1);
                brute(idx+1,mx);
                mx = tem;
                visited[i] = 0;

            }

        }
    }


}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        read(n);
        ans = 0;

        vec.assign(n,0);
        visited.assign(n,0);
        te.assign(n,0);

        cinarr(n,vec);


        brute(0,0);
        







        cout<<"Case #"<<tno<<": "<<ans<<endl;
    
    }
    return 0;
}