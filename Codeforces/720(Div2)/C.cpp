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
    //#define endl "\n" 
    
    
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

ll ask(ll t,ll i, ll j,ll x){
    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
    ll ans;
    read(ans);
    return ans;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vi permu(n+1,0); //[1...n]

        ll idx_1 = 0;
        ll idx_n = 0;

        vi poss1;
        vi possn;


        //i - i+1
        fo(te,1,n/2 + 1) {

            ll i = 2*te - 1;
            ll mx1,mx2,mn1,mn2;
            mx1=mx2=mn1=mn2=0;


            mn1 = ask(2,i,i+1,1);


            if(mn1 == 1){
                idx_1 == i;
                break;
            }

            if(mn1 == 2){
                poss1.pb(i+1);
            }
            
        }

        ll mn1s = ask(2,1,n,1);

        if(mn1s == 2 && !bs(all(poss1),n)) poss1.pb(n);


        if(idx_1 == 0){
            if(poss1.size() == 1){
                idx_1 = poss1[0];
            }

            else{
                ll i1 = poss1[0];
                ll i2 = poss1[1];

                ll ak1 = ask(2,i1,i2,1);
                ll ak2 = ask(2,i2,i1,1);

                if(ak1 == 1){
                    idx_1 = i1;
                }

                else{
                    idx_1 = i2;
                }
            }
        }

        permu[idx_1] = 1;


        fo(te,1,n/2 + 1) {

            ll i = 2*te - 1;
            ll mx1,mx2,mn1,mn2;
            mx1=mx2=mn1=mn2=0;


            mx1 = ask(1,i,i+1,n-1);


            if(mx1 == n){
                idx_n == i+1;
                break;
            }

            if(mx1 == n-1){
                possn.pb(i);
            }
            
        }

        ll mx1s = ask(1,1,n,n-1);

        if(mx1s == n-1 && !bs(all(possn),n)) possn.pb(n);


        if(idx_n == 0){
            if(possn.size() == 1){
                idx_n = possn[0];
            }

            else{
                ll i1 = possn[0];
                ll i2 = possn[1];

                ll ak1 = ask(1,i1,i2,n-1);
                ll ak2 = ask(1,i2,i1,n-1);

                if(ak1 == n){
                    idx_n = i1;
                }

                else{
                    idx_n = i2;
                }
            }
        }

        permu[idx_n] = n;


        fo(i,1,n+1){
            if(permu[i] == 0){
                ll akn = ask(1,idx_1,i,n-1);
                permu[i] = akn;
            }
        }



        


        cout<<"! ";

        fo(i,1,n+1) cout<<permu[i]<<" ";

        cout<<endl;




    
    }
    return 0;
}