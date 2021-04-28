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

    #define vshow1d(arr) {ll nn = arr.size(); fo(ii,0,nn) {csp(arr[ii]);}cout<<endl;}
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
    
    string str;
    ll n;
    read(str);

    str += '$';

    n = str.size();

    vi equi_class(n);
    vpi order_pair(n);
    vi sorted_order(n);
    vi array(n);

    //fill array
    fo(i,0,n) array[i] = i;

    //sort array with base character

    sort(all(array),[&str] (ll& a1,ll& a2) -> bool {
        return str[a1] < str[a2];
    });

    //csp("array");vshow1d(array);


    ll idx = 0;

    equi_class[array[0]] = idx;

    fo(i,1,n) {

        if(str[array[i]] != str[array[i-1]]) idx++;
        equi_class[array[i]] = idx;

    }

    //csp("equ  ");vshow1d(equi_class);

    

    ll k = (ll)log2(n) + 1;

    fo(i,1,k+1) {

        fo(j,0,n) {
            order_pair[j] = {equi_class[j],equi_class[(j + (1<<(i-1)))%n]};
        }

        // fo(j,0,n) {
        //     csp(order_pair[j].F);cnl(order_pair[j].S);
        // }

        sort(all(array),[&order_pair] (ll& a1,ll& a2) -> bool {
            return order_pair[a1] < order_pair[a2];
        });

        

        ll idx = 0;

        equi_class[array[0]] = idx;

        fo(j,1,n) {

            if(order_pair[array[j]] != order_pair[array[j-1]]) idx++;
            equi_class[array[j]] = idx;

        }

        
    }

    vshow1d(array);


    



    return 0;
}


/*

repeat log(n):
    newpair from prev eqclass
    sort pair
    new eqclass from prev pair


*/