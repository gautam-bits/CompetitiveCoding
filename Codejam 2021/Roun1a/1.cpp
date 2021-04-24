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
    //#define endl "\n" 
    
    
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



string removeZero(string& str)
{
    int i = 0;
    while (str[i] == '0')
       i++;

    str.erase(0, i);
  
    return str;
}

ll topdigit(ll n) {
    ll ans = 0;
    ll rtrn = 0;
    while(n > 0) {
        rtrn = n%10;
        n /= 10;
        ans++;
    }

    return rtrn;
}

string addBigNumbers(string number1, string number2) {
   if (number1.length() > number2.length())
    swap(number1, number2);
   string sum = "";
   int len1 = number1.length();
   int len2 = number2.length();
   int digitDiff = len2 - len1;
   int carry = 0;
   int intSum;
   for (int i=len1-1; i>=0; i--) {
      intSum = ((number1[i]-'0') + (number2[i+digitDiff]- '0') + carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   for (int i=digitDiff-1; i>=0; i--) {
      intSum = ((number2[i]-'0')+carry);
      sum.push_back(intSum%10 + '0');
      carry = intSum/10;
   }
   if (carry)
    sum.push_back(carry+'0');
   reverse(sum.begin(), sum.end());
   return sum;
}

int compare(string a, string b) {
  int l1, l2, p1, p2, n;

  // Checking if any of the numbers is negative

  if (a[0] == '-')
    p1 = 0;
  else
    p1 = 1;

  if (b[0] == '-')
    p2 = 0;
  else
    p2 = 1;

  // Calculating length of strings

  l1 = a.size();
  l2 = b.size();

  // Both numbers positive

  if (p1 == 1 && p2 == 1) {
    if (l1 > l2)
      return 1;
    else if (l2 > l1)
      return 2;
    else {
      for (n = 0; n < l1; n++) {
        if (a[n] > b[n])
          return 1;
        if (b[n] > a[n])
          return 2;
      }
      if (n == l1)  // Can be removed (optional)
        return 0;
    }
  }

  // If one number is positive and other is negative

  if (p1 == 1 && p2 == 0) // 1st no positive
    return 1;
  if (p1 == 0 && p2 == 1) // 2nd no positive
    return 2;

  // If both numbers negative

  if (l1 < l2)
    return 1;
  if (l2 < l1)
    return 2;

  for (n = 1; n < l1; n++) {
    if (a[n] < b[n])
      return 1;
    if (b[n] < a[n])
      return 2;
  }

  return 0; // Both numbers (-ve) are same.
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    test(t){     // tno[1..t]
    
        ll n;
        read(n);

        vector<string> arr(n);
        

        string temp;

        fo(i,0,n) {
            read(temp);
            temp = removeZero(temp);
            arr[i] = temp;
            //cnl(temp);
        }

        ll ans = 0;

        fo(i,1,n) {
            if(compare(arr[i],arr[i-1]) == 1) {
                //cnl(i);
                continue;
            }

            else if(arr[i].size() == arr[i-1].size()) {
                ans++;
                arr[i] += '0';
            }

            

            else {

                //csp(i);cnl("lund");
                //csp(arr[i]);cnl(arr[i-1]);
                // csp(arr[i].size());cnl(arr[i-1].size());
                
                if(arr[i-1].size() < arr[i].size()) assert(0);
                string temp = arr[i];

                fo(j,0,arr[i-1].size() - arr[i].size()) temp += '9';
                //cnl(temp);

                if(compare(temp,arr[i-1]) != 1) {
                    ans += arr[i-1].size() - arr[i].size() + 1;
                    ll tv = arr[i-1].size() - arr[i].size() + 1;
                    fo(j,0,tv) arr[i] += '0';
                    
                }

                else {
                    //cnl(i);
                    ans += arr[i-1].size() - arr[i].size();
                    ll tv = arr[i-1].size() - arr[i].size();
                    ll uu = arr[i].size();
                    ll vv = arr[i-1].size();
                    fo(j,uu,vv) arr[i] += arr[i-1][j];
                    arr[i] = addBigNumbers(arr[i],"1");
                    
                }
            }

            //vshow1d(arr);
        }

        //cnl(compare("799","100"));
        //vshow1d(arr);
        cout<<"Case #"<<tno<<": "<<ans<<endl;

        //vshow1d(arr);


    
    }
    return 0;
}