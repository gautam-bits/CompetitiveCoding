
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<int> vi;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    } 
};

void fillHelp(vi& data,vi& answer_array,map<pair<int,int>,ll>& hash,int q,int m) {
    for(int i = 0 ; i < q ; i++){
        ll f;
        ll g;
        cin>>f>>g;

        f--;g--;


        //case1
        if(data[f] <= m) {
            answer_array[data[f]] += 1;
            answer_array[m+1] -= 1;

            if(data[g] <= m) {
                hash[make_pair(data[f],data[g])] ++;
            }
            
        }
    }
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

void fillHash(vi& answer_array,map<pair<int,int>,ll>& hash,int m) {
    auto itr = hash.begin();

    for(; itr != hash.end(); itr++){

        ll gautam = 2*(itr->first.first) + itr->first.second;

        answer_array[itr->first.first + itr->first.second] -= itr->second;
        answer_array[2*(itr->first.first) + itr->first.second] += itr->second;


        
        while(gautam + itr->first.second <= m) {
            gautam += itr->first.second;

            answer_array[gautam] -= itr->second;
            answer_array[gautam + itr->first.first] +=  itr->second;

            //update gautam

            gautam += itr->first.first;

        }
    }
}

ll A[(ll)1e5 + 5];
ll tree[(ll)2e6 + 20];

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





void solve() {
    int n;
    int m;
    int q;

    cin>>n>>q>>m;

    vector<int> data;
    vector<int> answer_array;
    map<pair<int,int>,ll> hash;

    data.assign(n + 10,0);
    answer_array.assign(3000005,0);

    for(int i = 0 ; i < n ; i++) {
        cin>>data[i];
    }



     fillHelp(data,answer_array,hash,q,m);

    fillHash(answer_array,hash,m);

    vector<int> preff;

    preff.assign(3000005,0);


    preff[0] = answer_array[0];
    for(int i = 1 ; i <= m ; i++) {
        preff[i] = preff[i-1] + answer_array[i];
    }

    int maxx = -1e9;

    for(int i = 1 ; i <= m ; i++) {
        maxx = max(maxx,preff[i]);
    }

    cout<<maxx<<endl;



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
    
    //cout<<5;


    int t;
    cin>>t;
    while(t-- > 0) {
        solve();
    }
    return 0;
}