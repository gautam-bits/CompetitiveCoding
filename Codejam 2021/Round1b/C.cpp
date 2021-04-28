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
    #define ctc(x) cout << "Case #"<<x<<": "
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
bool check(ll an,ll bn,ll cn,vi& vec) {

    ll aaa,bbb,ccc;

    bool poss = 0;

    an /= (ll)1e9;
    bn /= (ll)12e9;
    cn /= (ll)72e10;

    ll ss = cn;
    ll mm = (bn - ss);
    ll hh = an - mm - ss;

    if(mm % (ll)60 == 0 && hh % (ll)3600 == 0) {
        mm /= 60;
        hh /= 3600;

        if(ss >=0 && ss < 60 && mm >= 0 && mm < 60 && hh >=0 && hh < 12) {
            aaa = ss;
            bbb = mm;
            ccc = hh;
            poss = 1;

        }
    }

    if(poss == 0) return 0;
    else {
        vec[0] = aaa;
        vec[1] = bbb;
        vec[2] = ccc;

        csp(an*(ll)1e9);csp(bn*(ll)12e9);cnl(cn*(ll)72e10);
        return 1;
    }

}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll MD = 360 * 12 * 1e10;
    
    test(t){     // tno[1..t]
    
        ll a,b,c;

        read(a);
        read(b);
        read(c);


        ll x;

        ll aaa = -1;
        ll bbb = -1;
        ll ccc = -1;

        ll kk;
        fo(k,0,360*12*10 + 1) {
            ll tot = k*1e9;

            kk = k;
            x = tot - a;

            if(x >= 0 && (b+x)%(ll)1e9 == 0 && (c+x)%(ll)1e9 == 0) {

                if(k == 5400) cnl(x);
                
                ll an = (a + x)%MD;
                ll bn = (b + x)%MD;
                ll cn = (c + x)%MD;



                vi vec(3);

                if(check(an,bn,cn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    
                    break;
                }
                if(check(an,cn,bn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(bn,an,cn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(bn,cn,an,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(cn,bn,an,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(cn,an,bn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
            }

        }

        if(ccc != -1) {
            cnl(kk);
            ctc(tno);csp(ccc);csp(bbb);csp(aaa);cnl(0);
            continue;
        }

        fo(k,0,360*12*10 + 1) {
            ll tot = k*1e9 + MD;

            x = tot - a;

            if(x >= 0 && (b+x)%(ll)1e9 == 0 && (c+x)%(ll)1e9 == 0) {
                ll an = (a + x)%MD;
                ll bn = (b + x)%MD;
                ll cn = (c + x)%MD;

                vi vec(3);

                if(check(an,bn,cn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(an,cn,bn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(bn,an,cn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(bn,cn,an,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(cn,bn,an,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
                if(check(cn,an,bn,vec)) {
                    aaa = vec[0];
                    bbb = vec[1];
                    ccc = vec[2];
                    break;
                }
            }

        }

        if(ccc != -1) {
            ctc(tno);csp(ccc);csp(bbb);csp(aaa);cnl(0);
            continue;
        }
    
    }
    return 0;
}