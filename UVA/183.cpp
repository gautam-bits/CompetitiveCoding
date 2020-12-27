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
    
    
    typedef vector<int> vi;
    typedef pair<int,int> pi;
    
    const int MOD =  1000000007 ;
    const int MAX = 2e4 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ intelligence $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
string convBtoD(ll r0,ll c0,ll r1,ll c1,vector<vector<char>>& bform){   // invoke by(0,0,n-1,m-1,bform)
    ll cnt = 0;                                                        // O(nmlog(nm))  improve this
    fo(i,r0,r1+1){
        fo(j,c0,c1+1){
            if(bform[i][j] == '1') cnt++;
        }
    }
    
    if(r1 < r0 || c1 < c0) return "";
    if(cnt == 0) return "0";
    if(cnt == (c1 - c0 + 1)*(r1 - r0 + 1)) return "1";
    string s = "D";

    s += convBtoD(r0,c0,(r0+r1)/2,(c0+c1)/2,bform);
    s += convBtoD(r0,(c0+c1)/2 + 1,(r0+r1)/2,c1,bform);
    s += convBtoD((r0+r1)/2 + 1,c0,r1,(c0+c1)/2,bform);
    s += convBtoD((r0+r1)/2 + 1,(c0+c1)/2 + 1,r1,c1,bform);
    //cout<<cnt<<endl;
    return s;
}

void convDtoB(ll r0,ll c0,ll r1,ll c1,ll& idx,string& dform,vector<vector<char>>& bformFinal) {   //O(mn)
    if(r1 < r0 || c1 < c0) return ;
    if(dform[idx] == '1') {
        fo(i,r0,r1+1){
            fo(j,c0,c1+1){
                bformFinal[i][j] = '1';
            }
        }
        idx++;
        return;
    }
    if(dform[idx] == '0') {
        fo(i,r0,r1+1){
            fo(j,c0,c1+1){
                bformFinal[i][j] = '0';
            }
        }
        idx++;
        return;
    }
    idx++;

    convDtoB(r0,c0,(r0+r1)/2,(c0+c1)/2,idx,dform,bformFinal);
    convDtoB(r0,(c0+c1)/2 + 1,(r0+r1)/2,c1,idx,dform,bformFinal);
    convDtoB((r0+r1)/2 + 1,c0,r1,(c0+c1)/2,idx,dform,bformFinal);
    convDtoB((r0+r1)/2 + 1,(c0+c1)/2 + 1,r1,c1,idx,dform,bformFinal);
    // end of each operation do idx++
}

string convDtoBUtil(ll n, ll m, string& raw_dform) {
    vector<vector<char>> bformFinal (n,vector<char> (m,'.'));
    ll idx = 0;
    convDtoB(0,0,n-1,m-1,idx,raw_dform,bformFinal);
    string bform = "";
    fo(i,0,n){
        fo(j,0,m){
            bform += bformFinal[i][j];
        }
    }
    return bform;

}


string convBtoDUtil(ll n, ll m, string raw_bform){
    vector<vector<char>> bform (n,vector<char> (m,'.'));
    ll idx = 0;
    fo(i,0,n){
        fo(j,0,m){
            bform[i][j] = raw_bform[idx];
            idx++;
        }
    }
    
    return convBtoD(0,0,n-1,m-1,bform);
}


int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> input;
    string temp;
    vi indexes;

    while(cin>>temp && temp != "#"){
        input.pb(temp);
    }
    //for(string  x : input)cout<<x<<endl;
    fo(i,0,input.size()){
        if(input[i] == "D" || input[i] == "B") indexes.pb(i);
    }
    indexes.pb(input.size());

    fo(i,0,indexes.size()-1){
        ll n,m;
        n = stoi(input[indexes[i]+1]);
        m = stoi(input[indexes[i]+2]);
        string form = "";
        fo(j,indexes[i]+3,indexes[i+1]){
            form += input[j];
        }
        if(input[indexes[i]] == "B") {
            string nn = "",mm = "";
            if(n == 0) nn = "   0";
            else {
                ll tem = (ll)log10(n) + 1;
                tem = 4 - tem;
                fo(k,0,tem) nn += " ";
                nn += to_string(n);
            }
            if(m == 0) mm = "   0";
            else {
                ll tem = (ll)log10(m) + 1;
                tem = 4 - tem;
                fo(k,0,tem) mm += " ";
                mm += to_string(m);
            }
            cout<<"D"<<nn<<mm<<endl;
            string ans = convBtoDUtil(n,m,form);
            ll n = (ans.length() + 49)/50;
            fo(i,0,n-1) cout<<ans.substr(50*i,50)<<endl;;
            cout<<ans.substr(50*(n-1))<<endl;
        }
        else if(input[indexes[i]] == "D") {
            string nn = "",mm = "";
            if(n == 0) nn = "   0";
            else {
                ll tem = (ll)log10(n) + 1;
                tem = 4 - tem;
                fo(k,0,tem) nn += " ";
                nn += to_string(n);
            }
            if(m == 0) mm = "   0";
            else {
                ll tem = (ll)log10(m) + 1;
                tem = 4 - tem;
                fo(k,0,tem) mm += " ";
                mm += to_string(m);
            }
            cout<<"B"<<nn<<mm<<endl;
            string ans = convDtoBUtil(n,m,form);
            ll n = (ans.length() + 49)/50;
            fo(i,0,n-1) cout<<ans.substr(50*i,50)<<endl;;
            cout<<ans.substr(50*(n-1))<<endl;
        }
    }


    //test here
    // string str ="DD10111";
    // cout<<convDtoBUtil(2,3,str);
    return 0;
}