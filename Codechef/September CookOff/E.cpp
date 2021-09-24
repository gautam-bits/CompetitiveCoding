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

    #define vshow1d(arr) {ll n = arr.size(); fo(ii,0,n) {csp(arr[ii]);}cout<<endl;}
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

    const int MOD   = 1000000007 ;
    const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

vi primeFactors(ll n) {
    vi ans;
    if(n%2 == 0) {   
        ans.pb(2);
        while (n % 2 == 0) n/=2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        if(n%i == 0) {
            ans.pb(i);
            while (n % i == 0) n /= i;
        }
            
    }
    if (n > 2) ans.pb(n);
    return ans;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        ll k = (n+1)/2;

        vi arr(n);
        cinarr(n,arr);

        vi arr2;
        for(ll x : arr) if(x%2 == 0) arr2.pb(x/2);
        ll n2 = arr2.size();
        sort(all(arr2));
        

        if(arr2.size() < k) {
            cnl("NO");
        }

        else if(arr2[0] == 1) {
            cnl("YES");
        }
        else {
        
            bool ye = 0;
            ll cc  = 0;
            ll cc2 = 0;
            unordered_set<ll> vis;
            unordered_set<ll> vis2;

            int itr = 0;
            while(cc < 100 && cc2 < n && itr < 100000){
                ll id = rand()%n2;
                ll el = arr2[id];

                if(vis2.find(el) == vis2.end()) {
                    vis2.insert(el);
                    cc2++;
                }
                else {
                    continue;
                }

                vi pr = primeFactors(el);

                // vshow1d(pr);

                for(ll p : pr) if(vis.find(p) == vis.end()) {
                    vis.insert(p);
                    cc++;
                    ll cnt = 0;
                    for(ll x : arr2) {
                        if(x%p == 0) cnt++;
                        itr++;
                    }

                    if(cnt+1<=k) {
                        ye = 1;
                        break;
                    }
                }
                if(ye == 1) {
                    break;
                }
            }

            if(ye) {
                cnl("YES");
            }
            else {
                cnl("NO");
            }
        }       
    
    }
    return 0;
}