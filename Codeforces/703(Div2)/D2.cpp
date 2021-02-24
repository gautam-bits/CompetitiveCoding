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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    read(n);


    ll temp ;



    cout<<"? "<<1<<" "<<n<<endl;

    read(temp);


    if(n == 2){
        ll ans = temp;

        if(ans == 1)cnl(2);
        else cnl(1);
        return 0;

    }

    ll lo = 1;
    ll hi = n;

    while(lo + 2 < hi){
        ll mid = (lo + hi)/2;

        ll lef = -1;
        ll rig = -1;

        if(temp <= mid){
            cout<<"? "<<lo<<" "<<mid<<endl;

            read(lef);

            if(lef == temp){
                hi = mid;
            }
            else{

                
                cout<<"? "<<mid + 1<<" "<<hi<<endl;
                read(rig);
                

                
                lo = mid + 1;
                temp = rig;
            }
        }
        else {
            cout<<"? "<<mid + 1<<" "<<hi<<endl;
            read(rig);


            if(rig == temp){
                lo = mid + 1;
            }

            else{
                cout<<"? "<<lo<<" "<<mid<<endl;
                read(lef);

                hi = mid;

                temp = lef;
            }

        }

        

    }


    if(hi - lo == 1){
        ll ans;
        if(temp == lo) ans = hi;
        else ans = lo;

        cout<<"! "<<ans<<endl;
        return 0;
    }
    
    ll ans;
    if(temp == lo) {
        cout<<"? "<<lo + 1<<" "<<hi<<endl;
        read(ans);

        if(ans == hi) cout<<"! "<<lo + 1<<endl;
        else cout<<"! "<<hi<<endl;
    }

    else if(temp == hi){
        cout<<"? "<<lo<<" "<<lo + 1<<endl;
        read(ans);

        if(ans == lo) cout<<"! "<<lo + 1<<endl;
        else cout<<"! "<<lo<<endl;
    }

    else {
        cout<<"? "<<lo<<" "<<lo + 1<<endl;
        read(ans);

        if(ans == lo) cout<<"! "<<hi<<endl;
        else cout<<"! "<<lo<<endl;
    }




    
    
    return 0;
}