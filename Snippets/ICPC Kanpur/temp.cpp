//------------------------------------C_O_D_E_G_H_O_S_T_2_0_0_1---------------------------------------------------------------
//firstly save by ctrl+s before running the code
//press f5 to debug and input in terminal
//typcast by e.g (long long)variable and for constant e.g 5ll
//convert char digit to digit value by char-'0  and value  to char digit by valuedigit+'0'
//-----------------------------------------------------------------------------------------------------------------------------
//count set bits using __builtin_popcount(n);
// cout << fixed << setprecision(10) << pi <<" "<<npi<<endl;-->synax to set precision(not round off) for float/double datatype pi , npi
//ceil or floor used for double and return double 
//log also return double
//use floor(n)==(ceil)n to see if a double n is integer
//for int x,y to get ceil in x/y do as (x+(y-1))/y and x/y itself equals floor only (but returns int)
//log2(n)==floor(log2(n))-->to check if power of 2 
//to_string() to conv numeric to string and stoll(string) to conv string to ll
//------------------------------------------FUN BEIGINS!-----------------------------------------------------------------------
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define N 1000000000
#define M 998244353
#define pie 3.14159265359
#define ll long long
#define pll  pair<ll,ll>
#define vll  vector<ll>
#define vpll  vector<pll>
#define  vvll vector<vll>
#define pi  pair<int,int>
#define vi  vector<int>
#define vpi  vector<pi>
#define  vvi vector<vi>
#define endl "\n"                   //"\n" not flushes output but endl do
#define umap unordered_map<ll,ll>
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define fre(i,a,b) for(ll i=a;i>=b;i--)
#define sortall(v) sort(v.begin(), v.end());
//use int not long long for values utp 1e9 if time constraints very close
//------------------------------------------------------------------------------------------------------------------------------
vector<vector<long long>>adj;
map<long,bool>vis,viss; 
vector<long long>parent,sz,par,siz;
ll components=0;
ll dr[]={1,0,-1,0};
ll dc[]={0,1,0,-1};
#define sieve_max 1000000
int spf[sieve_max+1];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
//---------------------------------------------------------------------------------------------------------------------------------
ll inv(ll a){
    return binpow(a, 400000000-1,N);
}
int main(){
    ios_base::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(nullptr);
    ll t,temp;
   cin>>t;
   while(t--){
       ll k,d;
       cin>>k>>d;
       ll ans=k;
       ll f= k*inv(2); f%=N;

       ll ct= binpow(k,d-1,N)-1; if(ct<0)ct+=N; ct%=N; 
       ct= ct*k ; ct%=N; 

    ct= ct* inv(k-1); ct%=N;
    ans= ans+ ( ct* f)%N; ans%=N; if(ans<0)ans+=N;
    cout<<ans<<endl;

   }
  

return 0;
}   