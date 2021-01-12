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
    #define ll int
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
    //const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
ll arr[1005];
ll N , X, Y;
vi presum;


ll func(ll k,ll k2,ll n,vi& height,multiset<ll>& mset2,ll freq) {     //height is sorted 
        ll idx2 = 0;
        ll a2 = 0 ;
        ll anss2 = 0;
        bool poss12a = true;
        while(a2 < k){
            if(idx2 == n) {
                poss12a = false;
                break;
            } 
            a2 += height[idx2];
            //cnl(a2);
            mset2.insert(height[idx2]);
            idx2++;
        }
        fo(i,0,freq){
            if(idx2 == n) poss12a = false;
            else{
                mset2.insert(height[idx2]);
                a2 += height[idx2];
                idx2++;
            }
        }

        if(!poss12a) {
            anss2 = -1;
        }
        bool poss2 = false;

        while(idx2 < n){
            //mset updation  // remember a update;

            ll wantheight = height[idx2] + a2 - k;

            auto itr = upper_bound(all(mset2),wantheight);

            if(itr != mset2.begin()) {
                itr--;
                ll remove = *itr;
                if(height[idx2] < remove){
                    mset2.erase(itr);
                    a2 += height[idx2] - remove;
                    //cnl(a2);
                    mset2.insert(height[idx2]);
                    // for(auto x : mset2){
                    //     csp(x);
                    // }
                    // cnl("");
                }
                
            }
            
            // check presum  - a >= k a >=k
            if(a2<=k2 && a2 >=k){
                // csp("a2");cnl(a2);
                // cnl(idx2);
                // for(auto x : mset2){
                //     csp(x);
                // }
                // cnl("");
                poss2 = true;

                break;
            }
            idx2++;
        }
        if(a2<=k2 && a2>=k)poss2 = true;
        if(poss2 && anss2 == 0 ) anss2 = idx2+1;
        else anss2 = -1;


        return anss2;
}
    

int main() 
{
    // x is  not smaller than y can be trivial look into this every time
    // replace x with min(x,y)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        read(N);
        read(X);
        read(Y);

        mem(arr,0);
        presum.resize(N);
        vi aartemp(N);

        cinarr(N,arr);

        fo(i,0,N) aartemp[i] = arr[i];
        sort(all(aartemp),greater<ll>());

        vi finn;
        fo(i,0,400){
            multiset<ll> rbc;
            finn.push_back(func(X,Y,N,aartemp,rbc,i));
        }
        sort(all(finn));
        //vshow1d(finn);
        ll ansss = -1;
        for(ll x : finn){
            if(x>0){
                ansss = x;
                break;
            }
        }

        //vi presum(N);
        vector<ll>::iterator itr1,itr2;
        fo(i,0,N) {
            if(i==0) presum[i] = arr[i];
            else presum[i] = arr[i] + presum[i-1];
        }

        if(ansss == -1) {
            //csp(X);
            cnl("-1");
        }
        else {            
            

            bool aws = 0;
            fo(i,0,N){
                if(presum[i] >= X && presum[i] <= Y){
                    aws = 1;
                    break;
                }
            }
            if(aws){
                //csp(X);
                cnl("0");
            }

            else {      //main problme begins

                int answ = -2;
                //swap i and j
                bool flag = 0;
                fo(i,0,N){
                    fo(j,i+1,N){
                        // 3 zones 
                        // 0 - i-1  same    1
                        // i - j-1  +inc    2
                        // j - n-1  same    3
                        // 3 cases (0,1,2)

                        ll inc = arr[j] - arr[i];

                        //case 1
                        if(i > 0) {
                            itr1 = lb(presum.begin(),presum.begin() + i,X);
                            itr2 = ub(presum.begin(),presum.begin() + i,Y);

                            if(itr2 != presum.begin()) {
                                itr2--;
                                if (itr1 == itr2 ) {
                                    answ = 1;
                                    flag = 1;
                                    break;
                                }
                            }

                        }

                        //case 2 
                        if(answ == -2) {
                            itr1 = lb(presum.begin() + i,presum.begin() + j,X-inc);
                            itr2 = ub(presum.begin() + i,presum.begin() + j,Y-inc);
                            if(itr2 != presum.begin() + i) {
                                itr2--;
                                if (itr1 == itr2 ) {
                                    answ = 1;
                                    flag = 1;
                                    break;
                                }
                            }
                        }

                        //case 3
                        //case 2 
                        if(answ == -2) {
                            itr1 = lb(presum.begin() + j,presum.end(),X);
                            itr2 = ub(presum.begin() + j,presum.end(),Y);

                            if(presum.begin() + j != presum.end() && itr2 != presum.begin() + j) {
                                itr2--;
                                if (itr1 == itr2 ) {
                                    answ = 1;
                                    flag = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if(flag) break;
                }
                // if(N == 1){

                // }
                // else
                if(answ == -2) {
                    //csp(X);
                    cnl("2");
                }
                else {
                    //csp(X);
                    cnl("1");
                }
            }
        }
    
    }
    return 0;
}