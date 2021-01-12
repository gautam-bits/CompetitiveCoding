// This is an intellectual property of Diablo Escata ,
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
        map<ll,ll> freq;
        vector<pair<vi,vi>> numbers(n);   //F is > 0 , S is < 0

		fo(i,0,n){
			vi t1,t2;
			numbers[i] = MP(t1,t2);
		}

        ll sz = 0,temp = 0;

        ll ans = 0, ans_mp = 0;

        fo(i,0,n) {
            read(sz);
            fo(j,0,sz) {
                read(temp);
                freq[abs(temp)]++;
                if(temp>0) {
                    numbers[i].F.push_back(abs(temp));
                }
                else {
                    numbers[i].S.push_back(abs(temp));
                }
            }
        }

        fo(i,0,n){
            reverse(all(numbers[i].S));
        }

        // fo(i,0,n){
        //     sort(all(numbers[i].F));
        //     sort(all(numbers[i].S));
        // }
		
        fo(i,0,n){
			//cnl(i+1);
            //for positive vector
            for(ll x : numbers[i].F){
                if(freq[x] == 1) {
                    ans += numbers[i].S.size();
					//csp("POS");csp(x);cnl(numbers[i].S.size());
                }
                else {
                    if(numbers[i].S.size() != 0 &&  bs(all(numbers[i].S),x)) {
                        ans += numbers[i].S.size();
						//csp("POS");csp(x);cnl(numbers[i].S.size());
                    }
                    else{
                        ll aaa = 0, bbb = 0;
                        if(numbers[i].S.size() != 0) {
                            aaa = (ll)(upper_bound(all(numbers[i].S),x) - numbers[i].S.begin()); 
                        }
                        if(numbers[i].F.size() != 0) {   



                            bbb = (ll)( numbers[i].F.end() - upper_bound(all(numbers[i].F),x)); 
                        }
                        ans += 1 + 2*aaa + 2*bbb - numbers[i].S.size();
						//csp("POS");csp(x);cnl(1 + aaa + bbb);
                    }
                }
            }
			
			//for neg
            for(ll x : numbers[i].S){
                if(freq[x] == 1) {
                    ans += numbers[i].F.size();
					//csp("NEG");csp(x);cnl(numbers[i].F.size());
                }
                else {
                    if(numbers[i].F.size() != 0 &&  bs(all(numbers[i].F),x)) {
                        ans += numbers[i].F.size();
						//csp("NEG");csp(x);cnl(numbers[i].F.size());
                    }
                    else{

                        ll aaa = 0, bbb = 0;
                        if(numbers[i].F.size() != 0) {
                            aaa = (ll)(upper_bound(all(numbers[i].F),x) - numbers[i].F.begin()); 
                        }
                        if(numbers[i].S.size() != 0) {
                            bbb = (ll)( numbers[i].S.end() - upper_bound(all(numbers[i].S),x)); 
                        }
                        ans += 1 + 2*aaa + 2*bbb - numbers[i].F.size();
						//csp("NEG");csp(x);cnl(1 + aaa + bbb);
                    }
                }
            }
        }
        for(auto entry : freq){
            if(entry.S > 1) {
                ans_mp += entry.S - 2;
            }
        }
        ll fin = ans-ans_mp;
		//cnl(ans);
		//assert(fin%2 == 0);
        cnl((ans-ans_mp)/2);

    
    }
    return 0;
}