#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9+7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define min3(a, b, c) min((int)c, min((int)a,(int)b))
#define min4(a, b, c, d) min((int)d, min((int)c, min((int)a,(int)b)))
#define rrep(i, n) for(int i=n-1; i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

template<typename T>
void pop_front(vector<T> &v)
{
    if(v.size()>0)v.front()=move(v.back()), v.pop_back();
}
int cc(int n) {
    return (n*(n+1))/2;
}
int32_t main()
{
    fast
    int n;
    cin>>n;
    vector<int> arr(n),prexor(n),suffix0(n),suffix1(n);
    
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    
    prexor[0] = arr[0]%2;

    for(int i = 0 ; i < n ; i++) arr[i] = arr[i] % 2;

    for(int i = 1 ; i < n ; i++){
        prexor[i] = arr[i]^prexor[i-1];
    }

    if(prexor[n-1] == 0){
        suffix0[n-1] = 1;
        suffix1[n-1] = 0;
    }
    else {
        suffix0[n-1] = 0;
        suffix1[n-1] = 1;
    }

    for(int i = n-2 ; i >= 0 ; i--) {
        if(prexor[i] == 0){
            suffix0[i] = 1 + suffix0[i+1];
            suffix1[i] = suffix1[i+1];
        }
        else {
            suffix0[i] = suffix0[i+1];
            suffix1[i] = 1 + suffix1[i+1];
        }
    }

    int ans = 0;

    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            ans += suffix0[i];
        }
        else{
            if(prexor[i-1] == 0){
                ans += suffix0[i];
            }
            else {
                ans += suffix1[i];
            }
        }
    }

    // for(int i = 0 ; i < n ; i++) cout<<prexor[i]<<" ";
    // cout<<endl;
    // for(int i = 0 ; i < n ; i++) cout<<suffix0[i]<<" ";
    // cout<<endl;
    // for(int i = 0 ; i < n ; i++) cout<<suffix1[i]<<" ";
    // cout<<endl;
    cout<<ans<<endl;


    return 0;
}