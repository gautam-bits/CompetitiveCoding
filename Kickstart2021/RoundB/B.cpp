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

        

        vi arr(n);
        cinarr(n,arr);

        if(n == 2) {
            cout<<"Case #"<<tno<<": ";cnl(2);
            continue;
        }

        vi diff(n-1,0);

        fo(i,0,n-1) {
            diff[i] = arr[i + 1] - arr[i];
        }

        ll ans = 2;

        //vshow1d(diff);


        fo(i,1,n-1) {
            if(diff[i] != diff[i-1] && (diff[i] + diff[i-1] + (ll)2e9) % 2 == 0 ) {

                ll temp = 2;
                ll te = (diff[i] + diff[i-1]) / 2;
                ll lef = 0;
                ll idx1 = i - 2;
                while(idx1 >= 0 && diff[idx1] == te) {
                    lef++;
                    idx1--;
                }

                ll rig = 0;
                ll idx2 = i + 1;
                while(idx2 < n - 1 && diff[idx2] == te) {
                    rig++;
                    idx2++;
                }


                temp  += lef + rig + 1;

                

                ans = max(ans,temp);

                

            }

            if(diff[i] != diff[i-1]) {
                ll lef2 = 0;
                ll idx3 = i - 1;
                while(idx3 >= 0 && diff[idx3] == diff[i-1]) {
                    lef2++;
                    idx3--;
                }

                ll rig2 = 0;
                ll idx4 = i;
                //csp(diff[idx4]);cnl(idx4);
                //vshow1d(diff);
                while(idx4 < n - 1 && diff[idx4] == diff[i]) {
                    rig2++;
                    idx4++;
                }

                ans = max(ans,lef2+2);
                ans = max(ans,rig2+2);

            }


            
        }

        ll t2 = 2;

        fo(i,1,n-1) {
            if(diff[i] == diff[i-1]) t2++;
            else {
                ans = max(t2,ans);
                t2 = 2;
            }
        }

        t2 = 2;

        ll yo = diff[0];

        diff[0]= diff[1];



        fo(i,1,n-1) {
            if(diff[i] == diff[i-1]) t2++;
            else {
                ans = max(t2,ans);
                t2 = 2;
            }
        }

        t2 =2;
        diff[0] = yo;

        diff[n-2] = diff[n-3];

        fo(i,1,n-1) {
            if(diff[i] == diff[i-1]) t2++;
            else {
                ans = max(t2,ans);
                t2 = 2;
            }
        }

        // cnl(t2);
        // vshow1d(diff);

        ans = max(t2,ans);

        cout<<"Case #"<<tno<<": ";cnl(ans);
    
    }
    return 0;
}