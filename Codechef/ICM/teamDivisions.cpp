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
    #define EPS 1e-15
    
    
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

ll k;




// assume a is base
double area(double a,double b, double c) {
    double s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double altitude(double a, double b, double c) {  //(a)(b,c)
    return (2*area(a,b,c))/a;
}

double hor(double a, double b, double c, double h) {
    double alt = altitude(a,b,c);
    
    return a*((alt-h)/alt);
}

double area_rect(double a, double b, double c, double h) {
    return h*hor(a,b,c,h);
}

double rati(double a, double b, double c, double h) {
    double alt = altitude(a,b,c);

    double ans = (alt - h)/alt;

    return ans*ans;
}


double func(double a, double b, double c, double h) {

    double rat = rati(a,b,c,h);
    double ans = area_rect(a,b,c,h);

    double ans2 = 1.0 - pow(rat,k);
    ans2 /= (1.0 - rat);

    return ans*ans2;


}

double deri(double a, double b, double c, double h) {
    
    if(h - EPS < 0) {
        return (func(a,b,c,h+EPS)- func(a,b,c,h))/EPS;
    }

    else {
        return (func(a,b,c,h)- func(a,b,c,h-EPS))/EPS;
    }
}


double bisection(double a,double b,double c, double x,double y) {
    x += EPS;
    y -= EPS;
    double x2 = x;

    while(y - x >= EPS) {

        x2 = (x + y)/2;

        //csp(x);csp(y);cnl(func(a,b,c,x2));

        if(deri(a,b,c,x2) == 0.0) break;

        else if(deri(a,b,c,x2)*deri(a,b,c,x)  > 0.0) {
            y = x2;
        }
        else {
            x = x2;
        }
    }


    return x2;
}


    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll x,y,z;

        read(x);read(y);read(z);read(k);

        deci(8);

        double mx = 0.0;

        mx = max(mx,func(x,y,z,bisection(x,y,z,0.0,altitude(x,y,z))));

        mx = max(mx,func(y,x,z,bisection(y,x,z,0.0,altitude(y,x,z))));

        mx = max(mx,func(z,y,x,bisection(z,y,x,0.0,altitude(z,y,x))));

        //cnl(func(3,4,5,2));

        cnl(mx);




    
    }
    return 0;
}