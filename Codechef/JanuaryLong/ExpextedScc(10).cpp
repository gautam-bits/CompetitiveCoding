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

    const ll MOD   = 998244353 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
// use these overloaded operators for both p and q
ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

ll divide(ll x, ll y)
{
    return mul(x, binpow(y, MOD - 2));
}
   
int main() 
{
    // for m=1(1d)      => ans[i]  = k*ans[i-1] + k^i - k^(i-1);
    // for m=2(2layers) => ans[i] = idk?
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll m,n,k;
    read(m);
    read(n);
    read(k);

    if(m == 1) {
        vi ans(n+3,0);   //ans is p
        ans[1] = k;
        ans[2] = mul(k,add(2*k,-1)); 
        fo(i,3,n+1){
            ans[i] = add(mul(ans[i-1],k),add(binpow(k,i),mul(-1,binpow(k,i-1))));
        }

        
        //cnl(ans[n]);
        //cnl(binpow(k,n));
        cnl(divide(ans[n],binpow(k,n)));
        //cnl(divide(4,2));
    }
    else {
        if(k == 1) cnl(1);
        else {
            vi ans(n+3);
            ans[1] = mul(k,add(mul(2,k),-1));
            //csp(1);cnl(ans[1]);
            fo(i,2,n+1){

                //assert((ans[i-1] + k)

                ll ad = divide(add(ans[i-1],k),binpow(k,2));
                ll as = ad - 1; 
                //cnl(as);
                ll xs = k;
                //cnl(xs);
                ll xd = mul(mul(k,3),k-1);
                //cnl(xd);

                ll ys = mul(mul(3,k),k-1);
                //cnl(ys);
                ll yd = mul(ys,k-2);
                //cnl(yd);

                ll temp = add(add(binpow(k,2),mul(mul(-1,3),k)),3);
                //csp("te");cnl(temp);
                ll zs = mul(mul(k,k-1),k-2);
                //cnl(zs);
                ll zd = mul(mul(k,k-1),temp);
                //cnl(zd);

                ll answ = 0;

                answ = add(answ,mul(xs,as));
                //cnl(answ);
                answ = add(answ,mul(xd,ad));
                //cnl(answ);

                answ = add(answ,mul(ys,add(as,1)));
                //cnl(answ);
                answ = add(answ,mul(yd,add(ad,1)));
                //cnl(answ);
                
                answ = add(answ,mul(zs,add(as,2)));
                //cnl(answ);
                answ = add(answ,mul(zd,add(ad,2)));
                //cnl(answ);

                ans[i] = answ;
                //csp(i);cnl(ans[i]);

            }
            cnl(divide(ans[n],binpow(k,2*n)));
        }
    }


    



    return 0;
}


    // else {
    //     vi ans(n+3,0);
    //     ans[1] = mul(k,2*k - 1);

    //     fo(i,2,n+1){
    //         ll temp = 0;
    //         temp = add(temp,mul(binpow(k,2),ans[i-1]));
    //         temp = add(temp,mul(mul(k,2),binpow(k-1,3)));
    //         temp = add(temp,mul(mul(k,3),binpow(k-1,2)));
    //         ans[i] = temp;
    //     }

    //     cnl(divide(ans[n],binpow(k,2*n)));

    // }