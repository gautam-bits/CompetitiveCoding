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
    //const int N     = 100005 ;
    
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
ll height[1005];         //change while submitting to 4005
ll postsum[1005];
ll dp[500][500][500];   //change all while submitting to 4005
ll N,K;
ll calculate(ll idx,ll sum1,ll sum2){
    //cnl("call");
    if(idx == N) {
        if(sum1 >= K && sum2 >= K) return 0;
        else return (ll)1e7;
    }
    if(sum1 >= K && sum2 >= K) return 0;
    if(sum1 >= K) {
        if(postsum[idx] + sum2 < K) return (ll)1e7;
        ll tem = idx ;
        ll temans = 0;
        ll temsum = sum2;
        while(temsum < K){
            temsum += height[tem];
            temans++;
            tem++;
        }
        return temans;
    }
    if(sum2 >= K) {
        if(postsum[idx] + sum1 < K) return (ll)1e7;
        ll tem = idx ;
        ll temans = 0;
        ll temsum = sum1;
        while(temsum < K){
            temsum += height[tem];
            temans++;
            tem++;
        }
        return temans;
    }
    
    ll ans ;
    ll a,b,c;
    if(dp[idx+1][sum1+height[idx]][sum2] != -1) a = dp[idx+1][sum1+height[idx]][sum2];
    else a = calculate(idx+1,sum1+height[idx],sum2);

    if(dp[idx+1][sum1][sum2+height[idx]] != -1) b = dp[idx+1][sum1][sum2+height[idx]];
    else b = calculate(idx+1,sum1,sum2+height[idx]);


    ans = min(a+1,b+1);
    dp[idx][sum1][sum2] = ans;
    return ans;
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        N = K = 0;

        read(N);
        read(K);
        //cnl(N);
        //cnl(K);
        mem(height,0);
        mem(postsum,0);
        mem(dp,-1);
        
        cinarr(N,height);
        sort(height,height+N,greater<ll>());
        rfo(i,N-1,0){
            if(i==N-1) postsum[i] = height[i];
            else postsum[i] = height[i] + postsum[i+1];
        }
        ll ans = calculate(0,0,0);

        if(ans > N) ans = -1;
        cnl(ans);
    
    }
    return 0;
}