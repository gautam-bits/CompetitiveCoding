//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<' '<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAXN = 2e5 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
void getFactorization(int x,set<int>& ret) 
{ 
    //vector<int> ret; 
    while (x != 1) 
    { 
        ret.insert(spf[x]); 
        x = x / spf[x]; 
    } 

} 

bool areDisjoint(set<int>& s1,set<int>& s2){
    int m = s1.size();
    int n = s2.size();

    set<int> aaaa;
    for(ll x : s1)aaaa.insert(x);
    for(ll x : s2)aaaa.insert(x);

    if(aaaa.size() == m + n) return true;
    else
    {
        return false;
    }
    
}
int main() 
{
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        fo(i,0,n)cin>>a[i];
        vector<set<int>> factorsprefix(n);
        vector<set<int>> factorssuffix(n);

        int ans = -1;
        
        fo(i,0,n){
            if(i == 0){
                getFactorization(a[i],factorsprefix[i]);
            }
            else {
                for(int x : factorsprefix[i-1]) factorsprefix[i].insert(x);
                getFactorization(a[i],factorsprefix[i]);
            }
        }
        rfo(i,n-1,0){
            if(i == n-1){
                getFactorization(a[i],factorssuffix[i]);
            }
            else {
                for(int x : factorssuffix[i+1]) factorssuffix[i].insert(x);
                getFactorization(a[i],factorssuffix[i]);
            }
        }

        fo(i,0,n-1){
            if(areDisjoint(factorsprefix[i],factorssuffix[i + 1])){
                ans = i + 1;
                break;
            }
        }

        cout<<ans<<endl;

        // set<int> aa  ;
        // getFactorization(12246,aa);
        //  for(int aav : factorssuffix[0])cout<<aav<<" ";
        //  cout<<endl;
        //   for(int aav : factorssuffix[1])cout<<aav<<" ";
        //  cout<<endl;
        //   for(int aav : factorssuffix[2])cout<<aav<<" ";
        //  cout<<endl;
        //   for(int aav : factorssuffix[3])cout<<aav<<" ";
        //  cout<<endl;




    
    
    }
    return 0;
}