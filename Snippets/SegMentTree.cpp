//-------We can be heroes , just for one day!!.---------//
    
    #include <bits/stdc++.h>
    using namespace std;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ knowledge $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define ll long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<' '<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x )
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    
    typedef vector<ll> vi;
    typedef pair<ll,ll> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
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