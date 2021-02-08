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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m;
        read(n);
        read(m);
        //ignore idx 0
        vi a(n+1,0);
        fo(i,1,n+1) read(a[i]);

        vi b(n+1,0);
        fo(i,1,n+1) read(b[i]);

        vi c(m,0);
        cinarr(m,c);

        //initiall check

        vi tot_want(n+1,0);
        vi tot_get(n+1,0);
        vi tot_have(n+1,0);
        vi key_el_all(n+1,-1);

        vector<queue<int>> qu(n+1);

        fo(i,1,n+1){
            if(a[i] != b[i]) {
                tot_want[b[i]]++;
                qu[b[i]].push(i);
            }
        }

        fo(i,0,m){
            tot_get[c[i]]++;
        }

        fo(i,1,n+1){
            tot_have[b[i]]++;
        }

        fo(i,1,n+1){
            key_el_all[b[i]] = i;
        }
        bool poss1 = 1;

        fo(i,1,n+1){
            if(tot_want[i] <= tot_get[i]) continue;
            else {
                poss1 = 0;
                break;
            }
        }

        if(!poss1) {
            cnl("NO");
        }
        else {
            //cnl("yes");
            
            vector<bool> isWant(m,0);

            fo(i,0,m){
                if(tot_have[c[i]] > 0) isWant[i] = 1;
            }

            if(!(isWant[m-1])) {
                cnl("NO");
            }
            else{
                cnl("YES");
                vi ans(m,0);

                ll key_el;

                if(qu[c[m-1]].size() == 0){
                    // fo(i,1,n+1){
                    //     if(b[i] == c[m-1]){
                    //         key_el = i;
                    //         break;
                    //     }
                    // }
                    key_el = key_el_all[c[m-1]];
                }
                else{
                    key_el = qu[c[m-1]].back();
                }
                ans[m-1] = key_el;
                //key_el = key_el_all[c[m-1]];

                fo(i,0,m-1){
                    if(isWant[i]){
                        if(qu[c[i]].size() == 0){
                            ans[i] = key_el_all[c[i]];
                        }
                        else{
                            ans[i] = qu[c[i]].front();
                            qu[c[i]].pop();
                        }
                    }
                    else{
                        ans[i] = key_el;
                    }
                }

                vshow1d(ans);

            }


        }


    
    }
    return 0;
}