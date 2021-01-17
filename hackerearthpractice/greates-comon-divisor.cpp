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

//################################
// ALERTTTTT
// THIS IS 0 INDEXED SEGMENT TREE SO THE ROOT SEGMET IS LABELLED 0
// AND CORRESPONDINGLY THE SUBSEQUENT LEFT AND RIGHT SEGMENT
// take care of query no. and convert them to indexes
//################################

ll A[(ll)1e5 + 5];
ll tree_max[(ll)2e6 + 20];
ll tree_sum[(ll)2e6 + 20];
ll lazy_replace[(ll)2e6 + 20];
ll lazy_gcd[(ll)2e6 + 20];

int get_mid(int x,int y) {
    return x + (x-y)/2;
}

int left(int x) {      //0 - indexed
    return (x << 1) + 1;
}

int right(int x) {      //0 - indexed
    return (x << 1) + 2;
}


void build_both(ll index, ll L, ll R) {     // done
    if(L == R) {
        tree_max[index] = A[L];
        tree_sum[index] = A[L];
    }
    else {
        ll mid = get_mid(L,R);

        build_both(left(index), L, mid);
        build_both(right(index), mid+1, R);

        // segment relation to its children
        tree_sum[index] = tree_sum[left(index)] + tree_sum[right(index)];
        tree_max[index] = max(tree_max[left(index)],tree_max[right(index)]);
    }
}
void update_replace(ll index, ll L, ll R, ll i,ll j, ll val) {

    if(lazy_replace[index] != 0) {
        tree_max[index] = val;
        tree_sum[index] += 
        if(L != R){

        }
    }

    if(lazy_gcd[index] != 0){

    }
    if(L == R) {
        // Leaf node
        A[idx] = val;
        tree[index] += val;
    }
    else {
        ll mid = get_mid(L,R);
        if(L <= idx && idx <= mid) {
            update(left(index), L, mid, idx, val);
        }
        else{
            update(right(index), mid+1, R, idx, val);
        }
        // segment relation to its children
        tree[index] = tree[left(index)] + tree[right(index)];
    }
}
void update_gcd(ll index, ll L, ll R, ll idx, ll val) {
    if(L == R) {
        // Leaf node
        A[idx] += val;
        tree[index] += val;
    }
    else {
        ll mid = get_mid(L,R);
        if(L <= idx && idx <= mid) {
            update(left(index), L, mid, idx, val);
        }
        else{
            update(right(index), mid+1, R, idx, val);
        }
        // segment relation to its children
        tree[index] = tree[left(index)] + tree[right(index)];
    }
}
ll query(ll index, ll L, ll R, ll i, ll j) {   
    //1) complete overlap
    if(i <= L && R <= j) {
        return tree[index];
    }

    //2) no overlap
    if(j < L || R < i){
        return 0;
    }
    
    //3) partial overlap
    ll mid = get_mid(L,R);
    ll p1 = query(left(index), L, mid, i, j);
    ll p2 = query(right(index), mid+1, R, i, j);

    // segment relation to its children
    ll seg_ans = p1+p2;


    return seg_ans;
}

//################################
// ALERTTTTT
// THIS IS 0 INDEXED SEGMENT TREE SO THE ROOT SEGMET IS LABELLED 0
// AND CORRESPONDINGLY THE SUBSEQUENT LEFT AND RIGHT SEGMENT
// take care of query no and convert them to indexes
//################################

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //reset global trees
    
    return 0;
}