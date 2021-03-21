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
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

ll R,C;

vvi mat;
ll ans;

void update(ll i, ll j) {
    if(i == 0 && j == 0) return;

    if(i == 0){
        if(abs(mat[i][j] - mat[i][j-1]) <= 1) return;
        if(mat[i][j] > mat[i][j-1]) {
            ans += mat[i][j] - mat[i][j-1] - 1;
            mat[i][j-1] = mat[i][j] - 1;
            update(i,j-1);
        }
        else{
            ans += mat[i][j-1] - mat[i][j] - 1;
            mat[i][j] = mat[i][j-1] - 1;
            return;
        }
    } 

    else if(j == 0){
        if(abs(mat[i][j] - mat[i-1][j]) <= 1) return;
        if(mat[i][j] > mat[i-1][j]) {
            ans += mat[i][j] - mat[i-1][j] - 1;
            mat[i-1][j] = mat[i][j] - 1;
            update(i-1,j);
        }
        else{
            ans += mat[i-1][j] - mat[i][j] - 1;
            mat[i][j] = mat[i-1][j] - 1;
            return;
        }
    }
    else{
        if(abs(mat[i][j] - mat[i-1][j]) <= 1 && abs(mat[i][j] - mat[i][j-1]) <= 1) return;
        else if(mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i][j-1]) {
            ans += mat[i][j] - mat[i-1][j] - 1;
            mat[i-1][j] = mat[i][j] - 1;

            ans += mat[i][j] - mat[i][j-1] - 1;
            mat[i][j-1] = mat[i][j] - 1;

            update(i,j-1);
            update(i-1,j);

        }

        else if(mat[i][j] > mat[i-1][j] && mat[i][j] < mat[i][j-1]) {
            ans += mat[i][j-1] - mat[i][j] - 1;
            mat[i][j] = mat[i][j-1] - 1;

            ans += mat[i][j] - mat[i-1][j] - 1;
            mat[i-1][j] = mat[i][j] - 1;
            update(i-1,j);



        }

        else if(mat[i][j] < mat[i-1][j] && mat[i][j] > mat[i][j-1]) {
            ans += mat[i-1][j] - mat[i][j] - 1;
            mat[i][j] = mat[i-1][j] - 1;

            ans += mat[i][j] - mat[i][j-1] - 1;
            mat[i][j-1] = mat[i][j] - 1;
            update(i,j-1);

        }

        else {
            if(mat[i-1][j] > mat[i][j-1]) {
                ans += mat[i-1][j] - mat[i][j] - 1;
                mat[i][j] = mat[i-1][j] - 1;

                if(abs(mat[i][j] - mat[i][j-1]) > 1) {
                    ans += mat[i][j] - mat[i][j-1] - 1;
                    mat[i][j-1] = mat[i][j] - 1;
                    update(i,j-1);
                }
            }
            else{
                ans += mat[i][j-1] - mat[i][j] - 1;
                mat[i][j] = mat[i][j-1] - 1;

                if(abs(mat[i][j] - mat[i-1][j]) > 1) {
                    ans += mat[i][j] - mat[i-1][j] - 1;
                    mat[i-1][j] = mat[i][j] - 1;
                    update(i-1,j);
                }
            }
            
        }

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