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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        ll m;
        read(n);
        read(m);


        vvi arr(n, vi (m,0));
        vvi arr2(n*m);

        ll cnt = 0;

        fo(i,0,n) {
            fo(j,0,m){
                ll temp;
                read(temp);
                arr[i][j] = temp;
                arr2[cnt] = {temp,i,j};
                cnt++;
            }
        }



        sort(all(arr2));

        // fo(i,0,n*m) csp(arr2[i][0]);
        // cnl("");

        vvi visited(n, vi (m,0));
        vvi ans(n, vi (m,-1));


        fo(i,0,n*m){
            ans[arr2[i][1]][i] = arr2[i][0];
            visited[arr2[i][1]][arr2[i][2]] = 1;
        }

        // vshow2d(visited);
        // cnl("");
        // vshow2d(ans);
        // cnl("");

        // fo(i,0,n){
        //     fo(j,0,m){
        //         if(ans[i][j] == -1) {
        //             fo(k,0,m){
        //                 if(visited[i][k] == 0) {
        //                     ans[i][j] = arr[i][k];
        //                     visited[i][k] = 1;
        //                     break;
        //                 }
        //             }

        //             // vshow2d(visited);
        //             // cnl("");
        //             // vshow2d(ans);
        //             // cnl("");
        //         }
        //     }
        // }

        // // vshow2d(visited);
        // // cnl("");
        vshow2d(ans);


    
    }
    return 0;
}