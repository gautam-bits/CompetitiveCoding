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

ll func(ll k,ll n,vi& height,vi& preheight,multiset<ll>& mset2,ll freq) {      
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
            mset2.insert(height[idx2]);
            idx2++;
        }
        fo(i,0,freq){
            if(idx2 == n) poss12a = false;
            else{
                mset2.insert(height[idx2]);
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
                mset2.erase(itr);
                a2 += height[idx2] - remove;
                mset2.insert(height[idx2]);
            }
            
            // check presum  - a >= k a >=k
            if(preheight[idx2] - a2 >= k && a2 >=k){
                poss2 = true;
                break;
            }
            idx2++;
        }
        if(poss2 && anss2 == 0 ) anss2 = idx2+1;
        else anss2 = -1;


        return anss2;
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,k;
        read(n);
        read(k);

        vi height(n);
        cinarr(n,height);
        sort(all(height),greater<ll>());
        vi preheight(n);

        preheight[0] = height[0];
        fo(i,1,n) preheight[i] = height[i] + preheight[i-1];
        
        vi finnn;
        fo(i,0,40){
            multiset<ll> rootset;
            finnn.push_back(func(k,n,height,preheight,rootset,i));
        }
        sort(all(finnn));
        ll anssss = -1;
        for(ll x : finnn){
            if(x>0) {
                anssss = x;
                break;
            }
        }

        cnl(anssss);

        
    }
    return 0;
}