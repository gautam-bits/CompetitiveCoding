#include <bits/stdc++.h>
using namespace std;
#define M1 998244353
#define M2 998244353
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define rfo(i,a,b) for(ll i=b-1;i>=a;i--)

#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define V(a) vector<a>

using cd = complex<double>;

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

ll MOD   = 998244353 ;
ll N     = 300005 ;
const int MAX   = 2e4 + 7;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int mod = 998244353;
const int root = 3;
const int root_1 = 332748118;
const int root_pw = 1 << 20;

ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = modI(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vi multiply(vi& a, vi& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vi result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i];
    return result;
}


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



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    ll n;
    cin>>n;
    N = n;

    fact.assign(N+10,1);
    invNo.assign(N+10,1);
    invFactNo.assign(N+10,1);

    calcFact();
    calcInvNo();
    calcInvFactNo();

    vector<ll> arr(n);

    fo(i,0,n) {
        cin>>arr[i];
    }

    vector<ll> one_pos(32,0);
    vector<ll> zero_pos(32,0);


    fo(i,0,n) {
        ll x = arr[i];

        ll itr = 0;

        while(x > 0){
            if(x&1){
                one_pos[itr]++;
            }
            x >>= 1;
            itr++;
        }
    }

    fo(i,0,31) {
        zero_pos[i] = n - one_pos[i];
    }

    //DEBUG TWO and ONE POSS
    // fo(i,0,31) cout<<one_pos[i]<<" ";
    // cout<<endl;
    // fo(i,0,31) cout<<zero_pos[i]<<" ";
    // cout<<endl;

    // Remember digits above max are used 

    //CHECKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
    //add only if one poss is not zero


    //remember what one poly and zero poly are
    vector<vector<ll>> one_poly((ll)32,vector<ll>(n+5,0));
    vector<vector<ll>> zero_poly((ll)32,vector<ll>(n+5,0));
    vector<vector<ll>> prod_poly((ll)32,vector<ll>(n+5,0));



    //fill one_poly
    fo(i,0,31){
        ll x = one_pos[i];

        ll itr = 1;
        while(itr <= x){
            one_poly[i][itr] = Binomial(x,itr);

            itr += 2;
        }
    }


    //check one polly
    // cout<<n<<endl;
    // fo(i,0,n+5) cout<<one_poly[0][i]<<" ";
    // cout<<endl;


    //fill zero_polly
    fo(i,0,31){
        ll x = zero_pos[i];

        ll itr = 0;
        while(itr <= x){
            zero_poly[i][itr] = Binomial(x,itr);

            itr += 1;
        }
    }

    //check zero polly
    //cout<<n<<endl;
    // fo(i,0,n+5) cout<<zero_poly[2][i]<<" ";
    // cout<<endl;

    ll prime_root = 3;

    fo(i,0,31){
        prod_poly[i] =  multiply(one_poly[i],zero_poly[i]);
    }

    //check prod polly
    // fo(i,0,32){
    //     fo(j,0,n+1){
    //         cout<<prod_poly[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
      

    vector<ll> ans(n+1,0);



    fo(x,1,n+1){
        fo(j,0,31){
            ans[x] = add(ans[x],mul(prod_poly[j][x],binpow(2,j)));
        }
    }

    //check ans
    // fo(i,0,n+1){
    //     cout<<ans[i]<<" ";
    // }

    //answer->prefexanswer

    fo(i,2,n+1){
        ans[i] += ans[i-1];
    }

    //check ans
    // fo(i,0,n+1){
    //     cout<<ans[i]<<" ";
    // }


    ll qq;
    cin>>qq;

    fo(i,0,qq){
        ll noo;
        cin>>noo;
        cout<<ans[noo]<<endl;
    }




    // V(ll) a1 = {1,1,4};
    // V(ll) a2 = {1};
    // V(ll) cc ;

    // //cout<<PrimRoot(M2,0)<<endl;
    // PolyMult(a1,a2,cc,M2,PrimRoot(M2,0));

    // for(int i = 0 ; i < cc.size();i++){
    //     cout<<cc[i]<<" ";
    // }

    return 0;
}