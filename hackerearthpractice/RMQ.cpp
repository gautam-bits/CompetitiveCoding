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
    vi st;
    ll n;
    ll left (ll p) {return p << 1 ;}
    ll right (ll p) { return (p << 1) + 1 ;}

    void build(ll p,ll L,ll R,vi& A) {   //O(n) builds the tree recursively
        if(L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R)/2,A);
            build(right(p), (L + R)/2 + 1, R,A);
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;        //for min
            //st[p] = (A[p1] >= A[p2]) ? p1 : p2;      //for max
        }
    }

    ll rmq(ll p, ll L,ll R,ll i, ll j,vi& A) {      //O(logn) gives the min from i,j;
        if(i > R || j < L) return -1; //current segment outside query range
        if(L >= i &&  R <= j) return st[p]; //current segment insode query range

        ll p1 = rmq(left(p),L,(L+R)/2,i,j,A);
        ll p2 = rmq(right(p),(L+R)/2 + 1,R,i,j,A);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void update(ll index, ll val,ll p, ll L,ll R,vi& A) {   //O(logn) updates the segment tree;
        
        if(L == R ){
            //if(L == index)  
            st[p] = L;
            return;
        }

        if(index > R || index < L) return;

        
        //cout<<"dfmkfd"<<endl;
        //st[p] = ( val <  A[st[p]]) ? index : st[p];

        //st[p] = ( val <= A[st[p]] ) ? index : st[p] ;

        update(index,val,left(p),L,(L + R)/2,A);
        update(index,val,right(p),(L + R)/2 + 1,R,A);

        ll p1 = st[left(p)], p2 = st[right(p)];
        // ll temp = st[p];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2; 
        //if(st[p] != temp)cout<<p<<" "<<temp<<" "<<st[p]<<endl;

        // ll p1 = st[left(p)], p2 = st[right(p)];
        // st[p] = (A[p1] <= A[p2]) ? p1 : p2; 

    }

public:
    SegmentTree(vi& A) {
        //A = &_A;
        //copy(_A.begin(), _A.end(), A.begin());
        //fo(i,0,_A.size())A.pb(_A[i]);
        
        n = (ll)A.size();
        st.assign(4*n,0);
        build(1,0,n-1,A);
        // fo(i,0,4*n)cout<<st[i];
        // cout<<endl;
    }
    ll rmq(ll i, ll j,vi& A) { return rmq(1,0,n -1,i,j,A); }  //O(logn)//overload

    ll update(ll index, ll val,vi& A){                //O(logn)//overload
        A[index] = val;
        //fo(i,0,A.size())cout<<A[i]<<" ";
        // fo(i,0,15)cout<<A[i]<<" ";
        //cout<<endl;
        update(index,val,1,0,n - 1,A);
        // fo(i,0,4*n)cout<<st[i];
        // cout<<endl;
        //arr = A;

    }
};



int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    //cin>>t;
    t = 1;
    while(t--)
    {

        ll n,q;
        cin>>n>>q;

        vi arr(n,0);

        fo(i,0,n) cin>>arr[i];

        SegmentTree st_rmq(arr);

        char temp;
        ll x,y;

        fo(i,0,q){
            cin>>temp>>x>>y;

            if(temp == 'q'){
                cout<<arr[st_rmq.rmq(x-1,y-1,arr)]<<endl;
            }
            else {
                st_rmq.update(x-1,y,arr);
            }
        }



    
    
    }
    return 0;
}