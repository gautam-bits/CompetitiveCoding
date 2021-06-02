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
#define N 1000000007
#define M 998244353
#define pie 3.14159265359
using namespace std;
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
//flush input by fflush(stdin);
//------------------------------------------------------------------------------------------------------------------------------
vector<vector<long long>>adj;
map<long,bool>vis,viss; 
vector<long long>rnk,parent,sz;
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
map<ll,vll> ccost; vll w,c; ll n,k;



void yg1(ll ct, ll cct, ll indx){

    if(indx>=k){ccost[ct-cct].push_back(ct); return;}

    yg1(ct+c[indx], cct, indx+1);
    yg1(ct, cct+c[indx], indx+1);
    yg1(ct,cct,indx+1);

}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(nullptr);
    
    cin>>n>>k;
    
    ll temp; ll sm=0; ll smm=0;
    for(ll i=0;i<n;i++){
        cin>>temp; w.push_back(temp); sm+=temp;
    }
    for(ll i=0;i<k;i++){
        cin>>temp; c.push_back(temp); smm+=temp;
    }

    yg1(0,0,0); 

    set<ll> st;


    for(auto el : ccost[0]) {
        st.insert(el);
    }


    set<ll> st2;


    for(ll x : st){
        for(int i = 0 ; i < n ; i++){

            //cout<<x<<" "<<w[i]<<endl;
            st2.insert(2*x+w[i]);
        }
    }


    for(ll x : st2) cout<<x<<"\n";

    

    



    return 0;
}