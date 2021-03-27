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
    
    test(t){     // tno[1..t]
    
        ll n,q;
        read(n);
        read(q);

        vi arr(n);

        fo(i,0,n) arr[i] = i + 1;

        vi ans(300);

        ll temp;

        ll cnt = 0;
        fo(i,1,11){
            fo(j,i+1,11){
                fo(k,j+1,11){

                    cout<<i<<" "<<j<<" "<<k<<endl;
                    read(temp);
                    assert(temp != -1);
                    ans[cnt] = temp;
                    cnt++;
                }
            }
        }

        ll cnt_meg = 0;



        do {
            bool yes1 = 1,yes2 = 1,yes3 = 1;

            vi idxx(n + 1);

            fo(i,0,n) idxx[arr[i]] = i + 1;

            ll cnt = 0;


            fo(i,1,11) {
                fo(j,i+1,11){
                    fo(k,j+1,11){

                        vi tem;
                        tem.clear();

                        if(ans[cnt] != i) tem.pb(i);
                        if(ans[cnt] != j) tem.pb(j);
                        if(ans[cnt] != k) tem.pb(k);

                        assert(tem.size() == 2);


                        if((idxx[ans[cnt]] > idxx[tem[0]] && idxx[ans[cnt]] > idxx[tem[1]] ) || (idxx[ans[cnt]] < idxx[tem[0]] && idxx[ans[cnt]] < idxx[tem[1]] )) {
                            yes1 = 0;
                            yes2 = 0;
                            yes3 = 0;
                            break;
                        }


                        cnt++;
                        assert(cnt < 120);
                    }
                    if(yes1 == 0) {
                        break;
                    }
                }
                if(yes2 == 0){
                    break;
                }
            }

            if(yes3 == 1 || cnt_meg > 100){
                break;
            }

            cnt_meg++;
        } while(next_permutation(all(arr)));

        vshow1d(arr);

        ll ttt;
        read(ttt);
        assert(ttt != -1);



        
    
    }
    return 0;
}