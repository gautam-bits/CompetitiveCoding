#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define MOD 1000000007
#define ll long long
#define int long long
#define float double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

ll mul(ll x, ll y)
{
  return (x * 1ll * y) % MOD;
}

ll binpow(ll x, ll y)
{
  ll ans = 1;
  while (y > 0)
  {
    if (y % 2 == 1)
      ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}

int32_t main()
{
  fast

    int t = 1;
    cin >> t;
    int n = 2e7 + 10;
    vi dp(n + 1, 0);
    vi dp2(n + 1, 0);
    vi dp3(n + 1, 0);
    dp[3] = 1;
    dp2[3] = 7;
    dp3[0]=1;
    dp3[1]=2;
    for(int i = 2 ; i <= n ; i++){
      dp3[i]=(dp3[i-1]*2)%MOD;
    }
    for (int i = 4; i <= n; i++)
    {
      dp[i] = (2 * dp[i - 1] + dp3[i-3]  + MOD) % MOD;
      dp2[i] = (dp3[i] - dp[i] + MOD) % MOD;
    }
    while(t--){
      int x;
      cin >> x;
      cout << dp2[x] << endl;
    }

  return 0;
}