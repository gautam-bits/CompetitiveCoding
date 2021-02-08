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
    
        ll n;
        read(n);

        vi cc(n);
        cinarr(n,cc);

        vi aa(n);
        cinarr(n,aa);

        vi bb(n);
        cinarr(n,bb);

        vi end_chains;

        end_chains.pb(0);

        fo(i,2,n){
            if(aa[i] == bb[i]) end_chains.pb(i-1);
            else if(aa[i] > bb[i]) {
                ll temp = aa[i];
                aa[i] = bb[i];
                bb[i] = temp;
            }
        }
        end_chains.pb(n-1);

        vshow1d(end_chains);
        //vshow1d(bb);

        ll max_len = 0;
        fo(i,1,end_chains.size()) {
            
            ll ch1 = end_chains[i-1];
            ll ch2 = end_chains[i];

            ll temp = 0;

            temp += abs(bb[ch1+1] - aa[ch1+1]) + 1;
            cnl(abs(bb[ch1+1] - aa[ch1+1]) + 1);
            // if(ch2 == n-1) {
            //     //cnl(cc[ch2]);
            //     temp += cc[ch2];
            // }
            // else temp += abs(bb[ch2+1] - aa[ch2+1] + 1);

            temp += cc[ch2];
            cnl(cc[ch2]);
            fo(j,ch1+1,ch2){
                //cnl("ff");
                temp += cc[j] - (bb[j+1] - aa[j+1] - 1);
                cnl(cc[j] - (bb[j+1] - aa[j+1] - 1));
            }
            csp("poss ");cnl(temp);
            max_len = max(max_len,temp);
        }

        cnl(max_len);
    
    }
    return 0;
}