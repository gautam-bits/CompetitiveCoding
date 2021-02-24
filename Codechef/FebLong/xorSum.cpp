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

    const int MOD   = 998244353 ;
    const int N     = 1005 ;   // use this 
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi fact;
vi invNo;
vi invFactNo;




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

ll Binomial(ll N, ll R)
{
    ll ans = mul(mul(fact[N],invFactNo[R]),invFactNo[N-R]);
    return ans;
}
void calcFact() {
    fo(i,2,N+1) {
        fact[i] = mul(i,fact[i-1]);
    }
}

void calcInvNo() {
    fo(i,2,N+1){
        invNo[i] = invNo[MOD%i]*(MOD - MOD/i)%MOD;
    }
}

void calcInvFactNo(){
    fo(i,2,N+1){
        invFactNo[i] = mul(invNo[i], invFactNo[i-1]);
    }
}

ll calcMaxBit(vi& vec){
    ll ans = 0;
    for(ll x : vec){
        ans = max(ans, (ll)log2(x) + 1);
    }
    return ans;
}

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact.assign(N+10,1);
    invNo.assign(N+10,1);
    invFactNo.assign(N+10,1);

    calcFact();
    calcInvNo();
    calcInvFactNo();

    ll sz;
    read(sz);

    vi arr(sz);
    cinarr(sz,arr);
    //cnl(sz);
    //get the answer for 1 to m

    vi prefix_answer(sz+1,0);

    ll max_bit = calcMaxBit(arr);
    vi noSetBit(max_bit + 2,0);
    
    for(ll x : arr){
        ll itr = 0;
        ll temp = x;



        while(temp>0) {
            if(temp&1){
                noSetBit[itr]++;
            }
            temp >>= 1;
            itr++;
        }
    }

    fo(i,1,sz+1){
        prefix_answer[i] += prefix_answer[i-1];

        //real task
        // here i is value of m
        ll m = i;

        fo(pos,0,max_bit){
            ll x = noSetBit[pos];
            ll y = sz - x;
            ll iter = 1;
            while(iter <= x ) {
                
                if(x >= 0 && iter >= 0 && (m - iter) >= 0 && y >= 0 && x >= iter && y >= (m - iter)) {
                    ll temp = mul(Binomial(x,iter),Binomial(y,m-iter));
                    temp = mul(temp,binpow(2,pos));
                    prefix_answer[i] = add(prefix_answer[i],temp);

                    //csp("add");;csp(m);csp(pos);cnl(mul(Binomial(x,iter),Binomial(y,m-iter)));


                }

                iter += 2;
            }
            
        }
    }

    ll q;
    read(q);

    //vshow1d(noSetBit);
    fo(i,0,q){
        ll temp;
        read(temp);
        cnl(prefix_answer[temp]);
    }


    
    
    return 0;
}

