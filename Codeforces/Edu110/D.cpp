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

ll parent(ll i,ll k){
    ll temp = (k-i)/2;
    return k - temp;
}
ll child0(ll i,ll k) {
    ll temp = k - i;
    ll temp2 =  2*temp + 1;

    return k - temp2;
}

ll child1(ll i,ll k) {
    return child0(i,k) + 1;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        ll n;
        read(n);
        string str;
        read(str);

        ll k = (1<<n) - 1;

        vi val(k,1);

        // prepross
        fo(i,0,k) {
            ll ch0 = child0(i,k);
            ll ch1 = child1(i,k);

            if(ch0 >= 0) {
                if(str[i] == '?') {
                    val[i] = val[ch0] + val[ch1];
                }
                else if(str[i] == '1') {
                    val[i] = val[ch1];
                }
                else {
                    val[i] = val[ch0];
                }
            }

            else {
                if(str[i] == '?') {
                    val[i] = 2;
                }
                else if(str[i] == '1') {
                    val[i] = 1;
                }
                else {
                    val[i] = 1;
                }
            }
        }

        //vshow1d(val);
        

        ll q;
        read(q);

        fo(i,0,q) {

            ll idx;
            char c;
            read(idx);
            read(c);
            idx--;

            str[idx] = c;

            ll ch0 = child0(idx,k);
            ll ch1 = child1(idx,k);

            
            if(ch0 >= 0) {
                if(str[idx] == '?') {
                    val[idx] = val[ch0] + val[ch1];
                }
                else if(str[idx] == '1') {
                    val[idx] = val[ch1];
                }
                else {
                    val[idx] = val[ch0];
                }
            }

            else {
                if(str[idx] == '?') {
                    val[idx] = 2;
                }
                else if(str[idx] == '1') {
                    val[idx] = 1;
                }
                else {
                    val[idx] = 1;
                }
            }
            

            ll curr = idx;
            while(parent(curr,k) < k) {
                curr = parent(curr,k);

                ll ch0 = child0(curr,k);
                ll ch1 = child1(curr,k);

                if(ch0 >= 0) {
                    if(ch0 >= 0) {
                        if(str[curr] == '?') {
                            val[curr] = val[ch0] + val[ch1];
                        }
                        else if(str[curr] == '1') {
                            val[curr] = val[ch1];
                        }
                        else {
                            val[curr] = val[ch0];
                        }
                    }

                    else {
                        if(str[curr] == '?') {
                            val[curr] = 2;
                        }
                        else if(str[curr] == '1') {
                            val[curr] = 1;
                        }
                        else {
                            val[curr] = 1;
                        }
                    }
                }

            }


            //vshow1d(val);
            cnl(val[k-1]);

        }
    
    return 0;
}