#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long
typedef vector<int> poly;

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

//typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
//typedef vector<vi> vvi;

ll MOD   = 998244353 ;

const int P=998244353;
int fpow(int a,int b){int res=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)res=1ll*res*a%P;return res;} 
void pt(const poly&a){for(int i=0;i<(int)a.size();++i)D("%d ",a[i]);D("\n");}
int getlim(int n){int x=1;while(x<=n)x<<=1;return x;}
void ntt(poly&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	poly w(lim>>1);w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=fpow(g,(P-1)/(i<<1));j<i;++j)w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=a[j+k],y=1ll*a[i+j+k]*w[k]%P;
				a[j+k]=(x+y)%P,a[i+j+k]=(x-y+P)%P;
			}
	}
	if(g==332748118)for(int i=0,I=fpow(lim,P-2);i<(int)a.size();++i)a[i]=1ll*a[i]*I%P;
}
poly pmul(poly a,poly b){
	int need=(int)a.size()+b.size()-1,lim=getlim(need);
	ntt(a,3,lim),ntt(b,3,lim);
	for(int i=0;i<lim;++i)a[i]=1ll*a[i]*b[i]%P;
	ntt(a,332748118,lim);
	return a.resize(need),a;
}



const ll N=2000010;
int n,q,inv[N];
// int main(){
// 	inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1LL*(P-P/i)*inv[P%i]%P;
// 	vector<int> v1 = {1,1};

//   vector<int> v2 = pmul(v1,v1);

//   for(int x : v2) cout<<x<<" ";
// 	return 0;
// }

vector<int> fact;
vector<int> invNo;
vector<int> invFactNo;

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

ll calcMaxBit(vector<int>& vec){
    ll ans = 0;
    for(ll x : vec){
        ans = max(ans, (ll)log2(x) + 1);
    }
    return ans + 1;
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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1LL*(P-P/i)*inv[P%i]%P;


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    ll n;
    cin>>n;

    fact.assign(N+10,1);
    invNo.assign(N+10,1);
    invFactNo.assign(N+10,1);

    calcFact();
    calcInvNo();
    calcInvFactNo();

    vector<int> arr(n);

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
    vector<vector<int>> one_poly((int)sz,vector<int>(n+1,0));
    vector<vector<int>> zero_poly((int)sz,vector<int>(n+1,0));
    vector<vector<int>> prod_poly((int)sz,vector<int>(n+1,0));



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
            prod_poly[i] =  pmul(one_poly[i],zero_poly[i]);
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