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
    const ll N     = 3000005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,q,m;
        read(n);
        read(q);
        read(m);

        vi arr(n + 5,0);

        cinarr(n,arr);

        vi help(N,0);

        map<pi,ll> my_map ; // initializing empty map

        ll x;
        ll y;

        // update over q

        while(q--) {

            read(x);
            read(y);

            x--;
            y--;

            if(arr[x] > m){
                //vshow1d(help)
                continue;
            }

            else if(arr[y] > m && arr[x] <= m){
                //vshow1d(help)
                
                help[arr[x]] = help[arr[x]] + 1;

                help[m + 1] = help[m + 1] - 1;


            }

            else if (arr[y] <= m) {
                help[arr[x]] = help[arr[x]] + 1;

                help[m + 1] = help[m + 1] - 1;

                my_map[MP(arr[x],arr[y])] ++;
            }



            //q--;
        }


        // ll xxx,yyy,zzz,kkk;

        for(auto element : my_map){

            ll xxx = element.F.F;
            ll yyy = element.F.S;
            ll zzz = element.S;
            ll kkk = 2*xxx + yyy;


            //update b

            help[xxx + yyy] = help[xxx + yyy] - zzz;
            help[kkk] = help[kkk] + zzz;

            while(kkk + yyy <= m){

                kkk = kkk + yyy;
                help[kkk] = help[kkk] - zzz;
                help[kkk + xxx] = help[kkk + xxx] + zzz;
                kkk = kkk + xxx;
            }

        }

        fo(i,1,m+1){
            help[i] = help[i] + help[i-1];
        }

        cnl(*max_element(help.begin() + 1,help.begin() + m + 1));



    
    }
    
    return 0;
}