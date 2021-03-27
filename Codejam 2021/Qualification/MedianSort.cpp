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

    ll t,n,q;
    read(t);
    read(n);
    read(q);
    
    while(t--){     // tno[1..t]
    
        // ll n,q;
        // read(n);
        // read(q);

        vi arr(n);

        fo(i,0,n) arr[i] = i + 1;

        vi ans(300);

        ll temp;

        ll cnt1 = 0;
        fo(i,1,n+1){
            fo(j,i+1,n+1){
                fo(k,j+1,n+1){

                    cout<<i<<" "<<j<<" "<<k<<endl;
                    read(temp);
                    if(temp == -1) exit(1);
                    ans[cnt1] = temp;
                    cnt1++;
                }
            }
        }


        ll c2 = 0;
        do {
            bool yes1 = 1,yes2 = 1,yes3 = 1;

            vi idxx;
            idxx.clear();
            idxx.resize(100);

            fo(i,0,n) idxx[arr[i]] = i + 1;

            ll cnt = 0;


            fo(i,1,n+1) {
                fo(j,i+1,n+1){
                    fo(k,j+1,n+1){

                        vi tem;
                        tem.clear();

                        if(ans[cnt] != i) tem.pb(i);
                        if(ans[cnt] != j) tem.pb(j);
                        if(ans[cnt] != k) tem.pb(k);

                        if(tem.size() != 2) exit(1);


                        if((idxx[ans[cnt]] > idxx[tem[0]] && idxx[ans[cnt]] > idxx[tem[1]] ) || (idxx[ans[cnt]] < idxx[tem[0]] && idxx[ans[cnt]] < idxx[tem[1]] )) {
                            yes1 = 0;
                            yes2 = 0;
                            yes3 = 0;
                            break;
                        }


                        cnt++;
                        if(cnt > 120) exit(1);
                    }
                    if(yes1 == 0) {
                        break;
                    }
                }
                if(yes2 == 0){
                    break;
                }
            }

            if(yes3 == 1){
                break;
            }

            c2++;

        } while(next_permutation(all(arr)));

        vshow1d(arr);

        ll ttt;
        read(ttt);
        if(ttt == -1) exit(1);


    
    }
    return 0;
}