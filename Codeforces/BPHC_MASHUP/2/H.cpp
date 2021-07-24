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

vpi merggepairs(vpi s) {
    sort(all(s));
    ll sz = s.size();
    vpi ans;

    fo(i,0,sz) {
        if(i == 0){
            ans.pb(s[i]);
        }
        else {
            pi temp = ans[ans.size()-1];
            if(s[i].F - temp.S <= 1) {
                ans[ans.size()-1] = {temp.F,max(temp.S,s[i].S)};
            }
            else {
                ans.pb(s[i]);
            }
        }
    }

    return ans;
}

vpi lef(vpi& s,ll n) {
    ll sz = s.size();
    vpi ans;

    if(s[0].F > 1) ans.pb({1,s[0].F-1});

    fo(i,1,sz) {
        ans.pb({s[i-1].S + 1,s[i].F-1});
    }

    if(s[sz-1].S < n) ans.pb({s[sz-1].S+1,n});

    return ans;

}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll s,n,m;
        read(s);
        read(n);
        read(m);

        vpi sprinklers(s),sp2(s);
        vi queries(m);
        vpi yoyo(n+1,{-1,-1});

        fo(i,0,s){
            ll u,v;
            read(u);
            read(v);

            sprinklers[i] = {u,v};
        }

        cinarr(n,queries);

        sp2 = merggepairs(sprinklers);

        vpi fin = lef(sp2,n);

        // fo(i,0,fin.size()) {
        //     csp(fin[i].F);cnl(fin[i].S);
        // }

        for(pi p : fin){
            ll le = p.S - p.F + 1;

            //cnl(le);
            if(yoyo[le].S < p.S) {
                yoyo[le] = p;
                //csp(le);csp(yoyo[le].F);cnl(yoyo[le].S);
            }
            else if(yoyo[le].S == p.S && yoyo[le].F < p.F) yoyo[le] = p;
        }

        rfo(i,n-1,1) {
            if(yoyo[i].S < yoyo[i+1].S) yoyo[i] = {yoyo[i+1].S-i+1,yoyo[i+1].S};
            else if(yoyo[i].S == yoyo[i+1].S && yoyo[i].F < yoyo[i+1].S-i+1) yoyo[i] = {yoyo[i+1].S-i+1,yoyo[i+1].S};
        }

        // fo(i,1,n+1) {
        //     csp(i);csp(yoyo[i].F);cnl(yoyo[i].S);
        // }

        for(ll xx : queries) {
            //cnl(xx);
            if(yoyo[xx].F == -1) {
                csp(-1);
                cnl(-1);
            }
            else {
                csp(yoyo[xx].F);
                cnl(yoyo[xx].S);
            }
        }




    
    }
    return 0;
}