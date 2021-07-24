    #include <bits/stdc++.h>
    using namespace std;
    

    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
	int p;
    cin>>n;
	cin>>p;
    set<int> points;
    map<int,int> idx;

    vector<int> a(n),b(n),c(n);

    for(int i = 0 ; i < n ; i++) {
        cin>>a[i]>>b[i]>>c[i];
        b[i]++;
        points.insert(a[i]);
        points.insert(b[i]);
    }

    int curr = 0;

    for(int x : points) {
        idx[x] = curr;
        curr++;
    }

    int sz = curr;

    vector<vector<pair<int,int>>> proj(sz);
    for(int i = 0 ; i < n ; i++) {
        proj[idx[b[i]]].push_back({idx[a[i]],c[i]});
    }

    vector<vector<long long>> dp(sz,vector<long long> (p+1,INT_MIN));


	for(int i = 0 ; i < sz ; i++) dp[i][0] = 0;
	

	for(int i = 0 ; i < sz ; i++) {
		for(int x = 1 ; x < p + 1 ; x++) {
			if(i > 0) dp[i][x] = dp[i-1][x];
			for(auto pr : proj[i]) {
				dp[i][x] = max(dp[i][x],dp[pr.first][x-1] + pr.second);
			}
		}
	}  

	if(dp[sz-1][p] < 0 ) {
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

    cout<<dp[sz-1][p]<<endl;

    
    return 0;
}


