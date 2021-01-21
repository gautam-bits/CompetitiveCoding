#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9+7
//#define int long long
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
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(vector<int>& arr, int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 

int32_t main()
{
    fast
    int t=1;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> vec(n),diff(n-1);
        for(int i = 0 ; i < n ; i++) {
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        for(int i = 1 ; i < n ; i++) {
            diff[i-1] = abs(vec[i] - vec[0]);
        }
        //for(int i = 0 ; i < n-1 ; i++) cout<<diff[i]<<" ";
        ///cout<<endl;
        cout<<findGCD(diff,n-1)<<endl;

    }
    return 0;
}