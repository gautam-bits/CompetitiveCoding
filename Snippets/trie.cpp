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

const int ALPHABET_SIZE = 26; 

struct node {
	node *p[ALPHABET_SIZE];
	int count;
    bool isEndOfWord;
	node() {
		count=0;
        isEndOfWord = 0;
		fo(i,0,ALPHABET_SIZE) p[i] = NULL;
	}
};

class trie {
    
public:

    node *root;
	
    trie(){
        root = new node();
    }

    void insert(string s){
        node *x = root;
        int length = s.size();
        for (int i = 0; i < length; i++) {
            if (x->p[s[i] - 'A'] == NULL) {
                x->p[s[i] - 'A'] = new node();
            }
            x = x->p[s[i] - 'A'];
        }
        x->count++;
    }
	
    void erase(string s){
        node *x = root;
        int length = s.size();
        for (int i = 0; i < length; i++) {
            x = x->p[s[i] - 'A'];
        }
        x->count--;
    }

    // int dfs(node* curr,int k,int depth,int& ans) {

    //     for(int i = 0 ; i < ALPHABET_SIZE ; i++) {
    //         if(curr->p[i] != NULL) {
    //             curr->count += dfs(curr->p[i],k,depth + 1,ans);
    //         }
    //     }

    //     int temp = (curr->count)/k;
    //     ans += depth*temp;

    //     return curr->count - k*temp;
    // }
	
};


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]

        trie*tr = new trie();




    
    }
    return 0;
}