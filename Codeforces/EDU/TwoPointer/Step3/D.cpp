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
    #define vshow2d(arr) {ll n=arr.size();   fo(ii,0,n) {ll m = arr[ii].size(); fo(jj,0,m) csp(arr[ii][jj]); cout << endl;}}
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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n1;
    read(n1);
    vi arr1(n1);
    cinarr(n1,arr1);
    sort(all(arr1));

    ll n2;
    read(n2);
    vi arr2(n2);
    cinarr(n2,arr2);
    sort(all(arr2));

    ll n3;
    read(n3);
    vi arr3(n3);
    cinarr(n3,arr3);
    sort(all(arr3));

    ll n4;
    read(n4);
    vi arr4(n4);
    cinarr(n4,arr4);
    sort(all(arr4));


    ll min_diff = 1e15;
    vi ans(4);


    fo(i,0,n1) {
        ll curr_diff = 0;
        //vi curr(4,1e15);
        vi temp;
        vvi curr(4,vi(2,1e15));
        curr[0][0] = arr1[i];

        vi::iterator itr;

        itr = lb(all(arr2),arr1[i]);
        if(itr != arr2.end()){
            curr[1][0] = *itr;
        }
        if(itr != arr2.begin()) {
            itr--;
            curr[1][1] = *itr;
        }

        

        itr = lb(all(arr3),arr1[i]);
        if(itr != arr3.end()){
            curr[2][0] = *itr;
        }
        if(itr != arr3.begin()) {
            itr--;
            curr[2][1] = *itr;
        }

        itr = lb(all(arr4),arr1[i]);
        if(itr != arr4.end()){
            curr[3][0] = *itr;
        }
        if(itr != arr4.begin()) {
            itr--;
            curr[3][1] = *itr;
        }

        //vshow2d(curr);

        fo(aa,0,2){
            if(curr[0][aa] != 1e15){
                fo(b,0,2){
                    if(curr[1][b] != 1e15);
                    fo(c,0,2){
                        if(curr[2][c] != 1e15);
                        fo(d,0,2){
                            if(curr[3][d] != 1e15){
                                //csp(aa);csp(b);csp(c);cnl(d);
                                
                                vi temp1 = {curr[0][aa],curr[1][b],curr[2][c],curr[3][d]};
                                vi temp2 = {curr[0][aa],curr[1][b],curr[2][c],curr[3][d]};
                                //vshow1d(temp2);
                                sort(all(temp2));
                                if(temp2[3] - temp2[0] < min_diff) {
                                    min_diff = temp2[3] - temp2[0];
                                    fo(j,0,4) ans[j] = temp1[j];
                                }
                                
                            }
                        }
                    }
                }
            }
        }

    }

    vshow1d(ans);



    return 0;
}