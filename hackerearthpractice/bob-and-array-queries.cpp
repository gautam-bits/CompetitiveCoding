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
    //const int N     = 100005 ;
    const int MAX   = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
ll arr[(int)5e5+6];
ll seg_tree[(int)2e6 + 21];
ll N,Q;

ll mid(ll x, ll y) {
    return x + (y-x)/2;
}
ll left(ll x){
    return (x<<1) + 1;
}
ll right(ll x){
    return (x<<1) + 2;
}

ll query(ll index,ll L,ll R, ll x,ll y){
    //complete overlap
    if(L>=x && R<=y) return seg_tree[index];

    //no overlap
    if(y<L || x>R) return 0;

    //partial overlap
    ll middle = mid(L,R);
    ll lans = query(left(index),L,middle,x,y);
    ll rans = query(right(index),middle+1,R,x,y);

    return lans+rans;

}

void update(ll index,ll L,ll R,ll x){
    //if we reached segment end
    if(L == R) {
        seg_tree[index] = bitcount(x);
        return;
    }
    // intermidiate node updation(remember to update only 1 node to keep it in logn)
    
    ll middle = mid(L,R);
    
    if(x <= middle){
        update(left(index),L,middle,x);
    }
    else {
        update(right(index),middle+1,R,x);
    }
    seg_tree[index] = seg_tree[left(index)] + seg_tree[right(index)];
};


// approach - segment represents the total no of set bits from [i...j]
// whenever query comes update arr and if query 3 quety betwenn [x...y]

// rememver queries are 1 indexed
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read(N);
    read(Q);
    mem(arr,0);
    mem(seg_tree,0);

    int type;

    fo(i,0,Q) {
        read(type);
        int x,y;
        if(type == 1){
            read(x);
            x--;
            arr[x] = 2*arr[x] + 1;
            update(0,0,N-1,x);
        }
        if(type == 2){
            read(x);
            arr[x] = arr[x]/2;
            update(0,0,N-1,x);
        }
        else {
            read(x);read(y);
            cnl(query(0,1,N-1,x,y));
        }

    }



    return 0;
}