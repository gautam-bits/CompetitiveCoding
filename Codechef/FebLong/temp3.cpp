#include <bits/stdc++.h>
using namespace std;
#define M1 998244353
#define M2 998244353
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define rfo(i,a,b) for(ll i=b-1;i>=a;i--)
#define endl "\n"

#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define V(a) vector<a>

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

ll MOD   = 998244353 ;
ll N     = 200005 ;
const int MAX   = 2e4 + 7;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

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



// power x^y mod M
ll powM(ll x,ll y,ll m)
{
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
}


//inverse Mod Modulo
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



void fft(V(ll) &a,ll n,bool invert,ll m,ll x)
{
    fo(i,0,n)
    {
        ll y=0;
        fo(j,0,__builtin_ctzll(n))
        {
            if((1LL<<j)&i)
            {
                y|=(1LL<<(__builtin_ctzll(n)-j-1));
            }
        }
        if(y>i)
        {
            swap(a[i],a[y]);
        }
    }
    if(invert) x=modI(x,m);
    //if(invert) x=invNo[x];
    fo(s,1,__builtin_ctzll(n)+1)
    {
        ll y=powM(x,(n/(1LL<<s)),m);
        fo(j,0,(n/(1LL<<s)))
        {
            ll r=1;
            fo(i,0,(1LL<<(s-1)))
            {
                ll u=a[i+j*(1LL<<s)];
                ll v=(r*a[i+j*(1LL<<s)+(1LL<<(s-1))])%m;
                a[i+j*(1LL<<s)]=u+v;
                if(a[i+j*(1LL<<s)]>m) a[i+j*(1LL<<s)]-=m;
                a[i+j*(1LL<<s)+(1LL<<(s-1))]=u-v;
                if(a[i+j*(1LL<<s)+(1LL<<(s-1))]<0) a[i+j*(1LL<<s)+(1LL<<(s-1))]+=m;
                r*=y;
                r%=m;
            }
        }
    }
    if(invert)
    {
        ll invn=modI(n,m);
        //ll invn = invNo[n];
        fo(i,0,n)
        {
            a[i]=(a[i]*invn)%m;
        }
    }
    return;
}

void PolyMult(V(ll) &a,V(ll) &b,V(ll) &v,ll m,ll x)
{
    ll n=1;
    while(n<((ll)a.size())+((ll)b.size()))
    { 
        n<<=1;
    }
    V(ll) fa(a.begin(),a.end());
    fa.resize(n,0);
    V(ll) fb(b.begin(),b.end());
    fb.resize(n,0);
    ll y=powM(x,(m-1)/n,m);
    fft(fa,n,false,m,y);
    fft(fb,n,false,m,y);
    v.resize(n,0);
    fo(i,0,n)
    {
        v[i]=((fa[i]*fb[i])%m);
    }
    fft(v,n,true,m,y);
    v.resize(((ll)a.size())+((ll)b.size())-1,0LL);
    return;
}



ll calcMaxBit(vi& vec){
    ll ans = 0;
    for(ll x : vec){
        ans = max(ans, (ll)log2(x) + 1);
    }
    return ans + 1;
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

    ll sz = calcMaxBit(arr);

    vector<ll> one_pos(sz,0);
    vector<ll> zero_pos(sz,0);


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

    fo(i,0,sz) {
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
    vector<vector<ll>> one_poly((ll)sz,vector<ll>(n+1,0));
    vector<vector<ll>> zero_poly((ll)sz,vector<ll>(n+1,0));
    vector<vector<ll>> prod_poly((ll)sz,vector<ll>(n+1,0));



    //fill one_poly
    fo(i,0,sz){
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
    fo(i,0,sz){
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

    ll prime_root = 62;

    fo(i,0,sz){
        if(one_pos[i] != 0)
            PolyMult(one_poly[i],zero_poly[i],prod_poly[i],MOD,prime_root);
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
        fo(j,0,sz){
            ans[x] = add(ans[x],mul(prod_poly[j][x],binpow(2,j)));
        }
    }

    //check ans
    // fo(i,0,n+1){
    //     cout<<ans[i]<<" ";
    // }

    //answer->prefexanswer

    fo(i,2,n+1){
        ans[i] = add(ans[i],ans[i-1]);
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

    return 0;
}