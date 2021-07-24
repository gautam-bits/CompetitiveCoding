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

void pr(ll x) {
    fo(i,0,x) cout<<"1";
    fo(i,0,10-x)cout<<"0";
    cout<<endl;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    

        string a,b,c;
        read(a);
        read(b);
        read(c);

        ll c1=0,c2=0,c3=0;

        for(char x : a) if(x == '1') c1++;
        for(char x : b) if(x == '1') c2++;
        for(char x : c) if(x == '1') c3++;

        priority_queue<ll> pq;
        pq.push(c1);
        pq.push(c2);
        pq.push(c3);

        ll cnt = 0;
        bool fl = 0;

        while(cnt < 10){
            ll temp = pq.top();
            pq.pop();

            if(temp > 0){
                temp--;
                cnt++;
                pq.push(temp);
            }
            else {
                fl = 1;
                break;
            }
        }

        if(fl) {
            pr(cnt);
            continue;
        }

        while(1) {
            ll temp1 = pq.top();
            ll temp2 = pq.top();
            pq.pop();
            pq.pop();

            if(temp2 == 0) {
                break;
            }
            else {
                temp1--;
                temp2--;
                pq.push(temp1);
                pq.push(temp2);
            }
        }

        cnt -= pq.top();

        pr(cnt);
    
    }
    return 0;
}