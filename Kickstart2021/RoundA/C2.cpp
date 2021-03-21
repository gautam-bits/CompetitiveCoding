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
    #define ctc(x) cout << "Case #"<<x<<": "
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
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    const ll d2x[4] = {0,-1,0,1};
    const ll d2y[4] = {1,0,-1,0};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

ll R,C;

vvi mat;
ll ans;

void update(ll i,ll j);

bool check(ll i, ll j) {
    return i >= 0 && i < R && j >= 0 && j < C;
}

void upd(ll m1,ll m2,ll i,ll j) {

    if(abs(mat[m1][m2] - mat[i][j]) > 1) {
        if(mat[m1][m2] > mat[i][j]) {
            ans += mat[m1][m2] - mat[i][j] - 1;
            mat[i][j] = mat[m1][m2] - 1;
            update(i,j);
        }
        else {
            ans += mat[i][j] - mat[m1][m2] - 1;
            mat[m1][m2] = mat[i][j] - 1;
        }
    }

}

void update(ll i,ll j) {
    vvi ne;
    fo(k,0,4){
        ll xx = i + d2x[k];
        ll yy = j + d2y[k];
        if(check(xx,yy)){
            ne.pb({mat[xx][yy],xx,yy});
        }
    }

    sort(all(ne));
    reverse(all(ne));

    ll sz = ne.size();

    fo(k,0,sz) {
        upd(i,j,ne[k][1],ne[k][2]);
    }




} 


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        read(R);
        read(C);

        mat.assign(R,vi (C,0));
        ans = 0;

        cinarr2d(R,C,mat);


        fo(i,0,R){
            fo(j,0,C){
                update(i,j);
            }
            
        }

        ctc(tno);cnl(ans);


    
    }
    return 0;
}