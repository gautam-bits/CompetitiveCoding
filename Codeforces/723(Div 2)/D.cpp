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

    #define fo(i,a,b) for(ll i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define test(t) ll t; cin >> t; fo(tno,1,t+1)

    #define vshow1d(arr) {ll nn = arr.size(); fo(ii,0,nn) {csp(arr[ii]);}cout<<endl;}
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
    
    test(t){     // tno[1..t]
    
        string str;
        read(str);

        ll n = str.size();

        // ANOT 

        map<char,ll> mp;

        mp['A'] = 0;
        mp['N'] = 1;
        mp['O'] = 2;
        mp['T'] = 3;


        vvi arr(4,vi());


        vi cnt(4,0);



        fo(i,0,n){
            arr[mp[str[i]]].pb(i);
            cnt[mp[str[i]]]++;
        }


        string ans = "";

        fo(i,0,n) ans += '-';


        //vshow2d(arr);
        //cnl("end");

        fo(i,0,n){


            ll a1,a2,a3,a4;

            a1=a2=a3=a4=1e10;

            vi::iterator itr1,itr2,itr3,itr4,itr;

            //csp("arr[0]");csp(i);vshow1d(arr[0]);


            if(cnt[0] > 0) {
                itr1 = lb(all(arr[0]),i);
                if(itr1 != arr[0].end()) {
                    //cnl(*itr1-i);
                    a1 = min(a1,*itr1-i);
                    
                }

                if(itr1 != arr[0].begin()) {
                    itr1--;
                    itr = itr1;

                    //cnl("tt");

                    if(i-*itr < a1) {
                        a1 = i - *itr;
                        itr1 = itr;
                    }
                }
            }

            //cnl(a1);
            //csp("0");cnl(cnt[0]);

            

            if(cnt[1] > 0) {
                itr2 = lb(all(arr[1]),i);
                if(itr2 != arr[1].end()) {
                    a2 = min(a2,*itr2-i);
                    
                }

                if(itr2 != arr[1].begin()) {
                    itr = --itr2;

                    if(i - *itr < a2) {
                        a2 = i-*itr;
                        itr2 = itr;
                    }
                }
            }

            //cnl(a2);

            if(cnt[2] > 0) {
                itr3 = lb(all(arr[2]),i);
                if(itr3 != arr[2].end()) a3 = min(a3,*itr3-i);

                if(itr3 != arr[2].begin()) {
                    itr = --itr3;

                    if(i - *itr < a3) {
                        a3 = i - *itr;
                        itr3 = itr;
                    }
                }
            }

            //cnl(a3);


            if(cnt[3] > 0) {
                itr4 = lb(all(arr[3]),i);
                if(itr4 != arr[3].end()) a4 = min(a4,*itr4-i);

                if(itr4 != arr[3].begin()) {
                    itr = --itr4;

                    if(i-*itr < a4) {
                        a4 = i - *itr;
                        itr4 = itr;
                    }
                }
            }

            //cnl(a4);


            vi temp = {a1,a2,a3,a4};

            ll mx = 0;

            for(ll x : temp){
                if(x > mx && x != 1e10) {
                    mx = x;
                }
            }

            //csp("mx");cnl(mx);


            if(mx == a1){
                ans[i] = 'A';
                arr[0].erase(itr1);
                cnt[0]--;
                
            }

            else if(mx == a2){
                ans[i] = 'N';
                arr[1].erase(itr2);
                cnt[1]--;
                
            }

            else if(mx == a3){
                ans[i] = 'O';
                arr[2].erase(itr3);
                cnt[2]--;
                
            }
            else if(mx == a4){
                ans[i] = 'T';
                arr[3].erase(itr4);
                cnt[3]--;

            }


        }


        cnl(ans);




        
    
    }
    return 0;
}