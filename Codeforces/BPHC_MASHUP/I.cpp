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


ll solve(vi& arr,ll k){

    //vshow1d(arr);
    ll n = arr.size();

    ll ans = 0;

    ll curr_cnt = 0;

    fo(i,0,k){
        if(arr[i] == 1) curr_cnt++;
    }

    //cnl(curr_cnt);

    if(curr_cnt == 0){
        arr[k-1] = 1;
        arr[k-2] = 1;

        ans+=2;

        curr_cnt +=2;
    }


    else if(curr_cnt == 1){
        if(arr[k-1] == 1){
            arr[k-2] = 1;
            ans++;
        }

        else{
            arr[k-1] = 1;
            ans++;
        }

        curr_cnt +=1;
    }


    fo(i,k,n){

        curr_cnt += arr[i];
        curr_cnt -= arr[i-k];

        if(curr_cnt >= 2){
            continue;
        }

        if(curr_cnt == 1){
            arr[i] = 1;
            ans++;
            curr_cnt++;
        }
        
    }

    //fo(i,0,50) csp(arr[i]);


    return ans;




}


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,k;


    read(n);
    read(m);
    read(k);


    vi arr(n,0);

    fo(i,0,m){
        ll temp;
        read(temp);

        temp--;

        arr[temp] = 1;
    }


    cnl(solve(arr,k));


    // fo(i,0,n){
    //     if(arr[i] == 1) csp(i);
    // }
    return 0;

}