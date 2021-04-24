#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
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




int32_t main()
{
  fast

      int t = 1;

  while (t--)
  {
    int n;
    cin >> n;
    
    vector<vector<int>> adjList(n);

    int u,v;

    rep(i,n-1) {
        cin>>u>>v;
        u--;
        v--;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n,0);


    //bfs // node int 

    queue<pair<int,bool>> q; //  1-> babi 0->geeta


    bool winner = 1 ; // 1-> babi 0->geeta


    q.push({0,0});
    visited[0] = 1;

    q.push({n-1,1});
    visited[n-1] = 1;


    while(!q.empty()) {

        pair<int,bool> curr = q.front();
        q.pop();


        for(int node : adjList[curr.first]) if(!visited[node]) {
            visited[node] = 1;
            winner = curr.second;
            q.push({node,curr.second});

        } 
    }

    if(winner) cout<<"Babita"<<endl;
    else cout<<"Geeta"<<endl;

    // if(winner) cout<<"1 1 1"<<endl;
    // else cout<<"0 0 0"<<endl;

    
  }
  return 0;
}