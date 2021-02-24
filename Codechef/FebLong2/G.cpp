
    
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

const int N = 3000;
typedef vector<int> vi;

vector<vector<int>> grid;
vector<int> potential;;

int nnn;

vi fact;
vi invNo;
vi invFactNo;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    } 
};

int trav(int a,int b) {
    if(grid[a].size() == 0) return b;

    if(b % grid[a].size() == 0) {
        //trav
        int gg = 0;

        for(int xx  = 0 ; xx < grid[a].size() ; xx++){
            gg += trav(grid[a][xx],b/grid[a].size());
        }

        return gg;
    }

    else return 0;
}

////////////////////////////////////////////////////////////////
//functions taken from gfg
ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll Bin(ll N, ll R)
{
    ll ans = mul(mul(fact[N],invFactNo[R]),invFactNo[N-R]);
    return ans;
}
void afac() {
    for(ll i = 2 ; i < N + 2 ; i++) {
        fact[i] = mul(i,fact[i-1]);
    }
}

void ainvfac() {
    for(ll i = 2 ; i < N + 2 ; i++){
        invNo[i] = invNo[MOD%i]*(MOD - MOD/i)%MOD;
    }
}

void aInvFactNo(){
    for(ll i = 2 ; i < N + 2 ; i++) {
        invFactNo[i] = mul(invNo[i], invFactNo[i-1]);
    }
}
/////////////////////////////////////////////////////////////////////

ll npow(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}
class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int Parent(int i) { return (i-1)/2; }

  int LeftChild(int i) { return (i<<1) + 1; }

  int RightChild(int i) { return (i<<1) + 2; } 

  void ShiftUp(int i) {              //O(logn)
    if(i > 0 && data_[Parent(i)] > data_[i]) {
      swap(data_[Parent(i)],data_[i]);
      ShiftUp(Parent(i));
    }
  }

  void ShiftDown(int i) {          //O(logn)  //with print overload
    int minidx = i;

    int l = LeftChild(i);
    int r = RightChild(i);

    if(l < data_.size() && data_[l] < data_[minidx] ){
      minidx = l;
    }

    if(r < data_.size() && data_[r] < data_[minidx] ){
      minidx = r;
    }

    if(i != minidx){
      swap(data_[i],data_[minidx]);
      swaps_.push_back(make_pair(i,minidx));
      ShiftDown(minidx);

    }


  }

  void GenerateSwaps() {
    swaps_.clear();

    int n = data_.size();

    for(int i = n/2 - 1; i >=0;i--){
      ShiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};


ll A[(ll)1e5 + 5];
ll tree[(ll)2e6 + 20];

void fillData() {
    for(int x = 1 ; x < nnn ; x++){
        int temp;
        cin>>temp;

        grid[temp].push_back(x + 1);
        potential[temp] += 1;

    }
}

int get_mid(int x,int y) {
    return x + (y-x)/2;
}

int left(int x) {      //0 - indexed
    return (x << 1) + 1;
}

int right(int x) {      //0 - indexed
    return (x << 1) + 2;
}


void build(ll index, ll L, ll R) {
    if(L == R) {
        tree[index] = A[L];
    }
    else {
        ll mid = get_mid(L,R);

        build(left(index), L, mid);
        build(right(index), mid+1, R);

        // segment relation to its children
        tree[index] = tree[left(index)] + tree[right(index)];
    }
}
void update(ll index, ll L, ll R, ll idx, ll val) {
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


void doquery() {
    int q;
    cin>>q;

    for(int i = 0 ; i < q; i++){
        int a;
        int b;
        cin>>a>>b;

        cout<<b - trav(a,b)<<endl;
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

void queryyy(vector<ll>& ans) {
    int q;
    cin>>q;

    while(q--) {
        ll te;
        cin>>te;

        cout<<ans[te]<<endl;
    }
}

void fillbitss(vector<ll>& numbers,vector<ll>& bitss) {
    for(ll no : numbers){
        ll idx = 0;
        ll te = no;

        while(te > 0){
            if(te&1){
                bitss[idx] ++;
            }
            te >>= 1;
            idx++;
        }
    }
}

void solve3() {
    ll nn;
    cin>>nn;

    vector<ll> numbers(nn);

    for(int i = 0 ; i < nn ; i++) {
        cin>>numbers[i];
    }

    ll maxx = 0 ;

    for(ll x : numbers){
        maxx = max(maxx,(ll) log2(x) + 2);
    }

    vector<ll> bitss(maxx+1,0);

    fillbitss(numbers,bitss);

    vector<ll> ans(nn + 1,0);

    for(int i = 1 ; i < nn + 1; i++) {

        for(int hh = 0 ; hh < maxx ; hh++){
            
            for(int it = 1 ; it <= bitss[hh] ; it += 2) {
                if(i - it >= 0 && (nn - bitss[hh]) >= (i - it)){
                    ll yoyo = mul(Bin(bitss[hh],it),mul(Bin(nn - bitss[hh],i-it),npow(2,hh)));
                    ans[i] = (ans[i] + yoyo)%MOD;
                }
            }
        }
    }

    for(int i = 1 ; i <= nn ; i++){
        ans[i] = (ans[i] + ans[i-1])%MOD;
    }

    queryyy(ans);
}
class SegmentTree {
private:
    vi st,A;
    ll n;
    ll left (ll p) {return p << 1 ;}
    ll right (ll p) { return (p << 1) + 1 ;}

    void build(ll p,ll L,ll R) {   //O(n) builds the tree recursively
        if(L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R)/2);
            build(right(p), (L + R)/2 + 1, R);
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;        //for min
            //st[p] = (A[p1] >= A[p2]) ? p1 : p2;      //for max
        }
    }

    ll rmq(ll p, ll L,ll R,ll i, ll j) {      //O(logn) gives the min from i,j;
        if(i > R || j < L) return -1;         //current segment outside query range
        if(L >= i &&  R <= j) return st[p];   //current segment insode query range

        ll p1 = rmq(left(p),L,(L+R)/2,i,j);
        ll p2 = rmq(right(p),(L+R)/2 + 1,R,i,j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void update(ll index, ll val,ll p, ll L,ll R) {   //O(logn) updates the segment tree;
        
        if(L == R ){ 
            st[p] = L;
            return;
        }

        if(index > R || index < L) return;


        update(index,val,left(p),L,(L + R)/2);
        update(index,val,right(p),(L + R)/2 + 1,R);

        ll p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2; 


    }

public:
    SegmentTree(vi& _A) {
        A = _A;
        
        n = (ll)A.size();
        st.assign(4*n,0);
        build(1,0,n-1);

    }
    ll rmq(ll i, ll j) { return rmq(1,0,n -1,i,j); }  //O(logn)//overload

    ll update(ll index, ll val,vi& A){                //O(logn)//overload
        A[index] = val;

        update(index,val,1,0,n - 1);
    }
};




void solve2() {
    fact.assign(N+2,1);
    invNo.assign(N+2,1);
    invFactNo.assign(N+2,1);

    afac();
    ainvfac();
    aInvFactNo();

    solve3();

}

void solve() {

    int q;
    cin>>nnn;

    grid.resize(nnn+1);
    potential.assign(nnn+1,0);

    fillData();

    doquery();

}

vi parent ;
vi rank_element;
vi sz_set;
ll noOfDisSets;

ll findSet(ll i) {              // find the representative element of i in the forest
    if(i == parent[i]) {
        return i;
    }
    parent[i] = findSet(parent[i]);
    return parent[i];
}

bool isSameSet(ll i,ll j){
    return findSet(i) == findSet(j);
}

void unionSet(ll i, ll j) {    // merging sets containing i and j
    if(!isSameSet(i,j)) {
        ll x = findSet(i);
        ll y = findSet(j);

        noOfDisSets--; // if we are merging 2 different sets

        if(rank_element[x] > rank_element[y]){
            parent[y] = x;
            sz_set[x] += sz_set[y];  //increasing the size
        }
        else {
            parent[x] = y;
            sz_set[y] += sz_set[x];  //increasing the size
            if(rank_element[x] == rank_element[y]) rank_element[y]++;
        }

    }
}

ll sizeOfSet(ll i) {    // returns size of set that currently contains i
    ll x = findSet(i);
    return sz_set[x];
}

ll noOfDisjointSets() {
    return noOfDisSets;
}


//////////////////////////////////////////////////////////////////////////
// Start here
////////////////////////////////////////////////////////////////////////


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--) {
        solve2();
    }
    
    return 0;
}