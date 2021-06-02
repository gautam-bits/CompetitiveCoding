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

string calc(vi temp){

    assert(temp.size() > 0);
    string ans = "";

    fo(i,0,temp.size()) {
        ans += to_string(temp[i]) + ".";
    }

    return ans.substr(0,ans.size()-1);
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vi arr(n);

        cinarr(n,arr);

        vvi stk(n,vi());

        vvi answer(n,vi());

        vi levels(n,-1);

        stack<vi> st;

        
        ll level = -1;

        fo(i,0,n){

            if(i == 0){
                
                vi temp;
                temp.pb(arr[i]);
                answer[i] = temp;
                st.push(temp);
            }

            else {
                if(arr[i] == 1){

                    
                    vi temp = st.top();
                    temp.pb(arr[i]);
                    answer[i] = temp;

                    
                    st.push(temp);
                }

                else{
                    


                    vi temp;

                    while(st.size() > 0 && st.top()[st.top().size()-1] != arr[i]-1){
                        st.pop();
                    }

                    
                        temp = st.top();
                        temp.pop_back();
                        st.pop();
                    
                    temp.pb(arr[i]);
                    answer[i] = temp;

                    st.push(temp);

                    

                  
                    

                    
                
                }
            }


        }

        fo(i,0,n){
            cnl(calc(answer[i]));
        }
    
    }
    return 0;
}