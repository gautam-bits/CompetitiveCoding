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
    typedef vector<vi> vvi;

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
ll func(ll n){
    ll ans = 0;
    while(n>0) {
        n >>=1;
        ans++;
    }
    return ans;
} 

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m;
        read(n);
        read(m);
        vi arrn(n),arrm(m);
        ll ans = 0;

        cinarr(n,arrn);
        cinarr(m,arrm);

        ll a1 = *max_element(all(arrn));
        ll a2 = *max_element(all(arrm));

        ll sz = func(max(a1,a2));

        sz = 1 << sz;

        
        vector<bool> visited(sz);
        visited[0] = 1;

        queue<ll> line;

        for(ll& x : arrn) {
            line.push(x);
            visited[x] = 1;
            //cnl(x);
        }
        ll cnt = 0;
        while(!line.empty()) {
            if(cnt == 1200) break;
            ll temp = line.front();
            line.pop();

            for(ll& x : arrn){
                ll aaa = temp | x;
                if(!visited[aaa]){
                    line.push(aaa);
                    visited[aaa] = 1;
                    //cnl(aaa);
                }
            }
            for(ll& x : arrm){
                ll bbb = temp & x;
                if(!visited[bbb]){
                    line.push(bbb);
                    visited[bbb] = 1;
                    //cnl(bbb);
                }
            }
            cnt++;
        }

        for(bool x : visited) if(x) ans++;

        cnl(ans);

        
    
    }
    return 0;
}