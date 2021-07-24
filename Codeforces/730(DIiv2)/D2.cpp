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
    // #define endl "\n" 
    
    
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

ll query(ll q) {
    cnl(q);

    ll r;
    read(r);

    return r;
}

ll opp(ll x,ll k) {
    vi temp;

    while(x > 0) {
        temp.push_back(x%k);
        x /= k;
    }
    ll sz = temp.size();
    fo(i,0,sz) {
        temp[i] = (k - temp[i])%k;
    }

    ll ans = 0;
    ll curr = 1;

    fo(i,0,sz) {
        ans += curr*temp[i];
        curr *= k;
    }

    return ans;

}

ll xr(ll x,ll y,ll k) {

    vi temp1(40,0);
    vi temp2(40,0);

    ll idx1 = 0;
    while(x > 0) {
        temp1[idx1] = (x%k);
        x /= k;
        idx1++;
    }

    ll idx2 = 0;
    while(y > 0) {
        temp2[idx2] = (y%k);
        y /= k;
        idx2++;
    }

    fo(i,0,40) temp1[i] += temp2[i];

    ll sz = temp1.size();
    fo(i,0,sz) {
        temp1[i] %= k;
    }

    ll ans = 0;
    ll curr = 1;

    fo(i,0,sz) {
        ans += curr*temp1[i];
        curr *= k;
    }

    return ans;



}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cnl(opp(1,3));
    // cnl(xr(opp(1,3),0,3));
    
    test(t){     // tno[1..t]
    
        ll n,k;
        read(n);
        read(k);

        ll curr = 0;

        fo(i,0,n) {

            if(i == 0) {
                ll ans = query(0);
                if(ans == 1) {
                    break;
                }
                // curr = xr(curr,0,k);
            }
            else {

                ll send = xr(curr,i,k);

                ll yo = opp(i,k);
                ll ans = query(send);
                if(ans == 1) {
                    break;
                }

                curr = xr(curr,send,k);
            }

        }




    
    }
    return 0;
}