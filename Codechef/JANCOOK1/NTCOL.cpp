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
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n,m,r,g,b;
        read(n);
        read(m);
        read(r);
        read(g);
        read(b);

        vector<pair<int,char>> ff;
        vector<vector<char>> grid(n,vector<char> (m));
        
        vector<vector<bool>> red(n,vector<bool> (m,0));
        vector<vector<bool>> green(n,vector<bool> (m,0));
        vector<vector<bool>> blue(n,vector<bool> (m,0));

        fo(i,0,n){
            fo(j,0,m){

                if(i == 0) {
                    if(j == 0){
                        if(r > 0) {
                            grid[i][j] = 'R';
                            r--;
                        }
                        else if(g > 0) {
                            grid[i][j] = 'G';
                            g--;
                        }
                        else {
                            grid[i][j] = 'B';
                            b--;
                        }
                    }
                    else {
                        ll cnt = 0;
                        if(red[i][j-1]) cnt++;
                        if(green[i][j-1]) cnt++;
                        if(blue[i][j-1]) cnt++;

                        if(cnt <= 1){   //exploit
                            if(red[i][j-1]){
                                if(g > 0) {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }
                            else if(green[i][j-1]){
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }
                            else {
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }

                            //cross add
                            if(grid[i][j] == 'R') red[i][j-1] = 1;
                            if(grid[i][j] == 'G') green[i][j-1] = 1;
                            if(grid[i][j] == 'B') blue[i][j-1] = 1;

                            if(grid[i][j-1] == 'R') red[i][j] = 1;
                            if(grid[i][j-1] == 'G') green[i][j] = 1;
                            if(grid[i][j-1] == 'B') blue[i][j] = 1;

                        }

                        else {    // control

                            if(red[i][j-1] && green[i][j-1]){
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }
                            else if(green[i][j-1] && blue[i][j-1]){
                                if(b > 0) {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }
                            else {
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }

                            //cross add
                            if(grid[i][j] == 'R') red[i-1][j] = 1;
                            if(grid[i][j] == 'G') green[i-1][j] = 1;
                            if(grid[i][j] == 'B') blue[i-1][j] = 1;

                            if(grid[i-1][j] == 'R') red[i][j] = 1;
                            if(grid[i-1][j] == 'G') green[i][j] = 1;
                            if(grid[i-1][j] == 'B') blue[i][j] = 1;

                        }
                    }


                }

                else{
                    if(j == 0){
                        if(r > 0) {
                            grid[i][j] = 'R';
                            r--;
                        }
                        else if(g > 0) {
                            grid[i][j] = 'G';
                            g--;
                        }
                        else {
                            grid[i][j] = 'B';
                            b--;
                        }
                    }
                    else {
                        ll cnt = 0;
                        if(red[i][j-1]) cnt++;
                        if(green[i][j-1]) cnt++;
                        if(blue[i][j-1]) cnt++;

                        if(cnt <= 1){   //exploit
                            if(red[i][j-1]){
                                if(g > 0) {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }
                            else if(green[i][j-1]){
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }
                            else {
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }

                            //cross add
                            if(grid[i][j] == 'R') red[i][j-1] = 1;
                            if(grid[i][j] == 'G') green[i][j-1] = 1;
                            if(grid[i][j] == 'B') blue[i][j-1] = 1;

                            if(grid[i][j-1] == 'R') red[i][j] = 1;
                            if(grid[i][j-1] == 'G') green[i][j] = 1;
                            if(grid[i][j-1] == 'B') blue[i][j] = 1;

                        }

                        else {    // control

                            if(red[i][j-1] && green[i][j-1]){
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }
                            else if(green[i][j-1] && blue[i][j-1]){
                                if(b > 0) {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                                else {
                                    grid[i][j] = 'G';
                                    g--;
                                }
                            }
                            else {
                                if(r > 0) {
                                    grid[i][j] = 'R';
                                    r--;
                                }
                                else {
                                    grid[i][j] = 'B';
                                    b--;
                                }
                            }

                            //cross add
                            if(grid[i][j] == 'R') red[i-1][j] = 1;
                            if(grid[i][j] == 'G') green[i-1][j] = 1;
                            if(grid[i][j] == 'B') blue[i-1][j] = 1;

                            if(grid[i-1][j] == 'R') red[i][j] = 1;
                            if(grid[i-1][j] == 'G') green[i][j] = 1;
                            if(grid[i-1][j] == 'B') blue[i][j] = 1;

                        }
                    }
                }



            }
        }

            
    }
    return 0;
}