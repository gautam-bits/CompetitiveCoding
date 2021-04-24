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
 
vi parent;
vi rank_element;
vi sz_set;
int noOfDisSets;
 
int findSet(int i)
{
  if (i == parent[i])
    return i;
  parent[i] = findSet(parent[i]);
  return parent[i];
}
 
bool isSameSet(int i, int j)
{
  return findSet(i) == findSet(j);
}
 
void unionSet(int i, int j)
{
  if (!isSameSet(i, j))
  {
    int x = findSet(i);
    int y = findSet(j);
 
    noOfDisSets--;
 
    if (rank_element[x] > rank_element[y])
    {
      parent[y] = x;
      sz_set[x] += sz_set[y];
    }
    else
    {
      parent[x] = y;
      sz_set[y] += sz_set[x];
      if (rank_element[x] == rank_element[y])
        rank_element[y]++;
    }
  }
}
 
int sizeOfSet(int i)
{
  int x = findSet(i);
  return sz_set[x];
}
 
int noOfDisjointSets()
{
  return noOfDisSets;
}
 
int32_t main()
{
  fast
 
      int t = 1;

  while (t--)
  {
    int n;
    cin >> n;
    parent.assign(n, 0);
    rank_element.assign(n, 0);
    sz_set.assign(n, 1);
    noOfDisSets = n;
    rep(i, n) parent[i] = i;
 
    map<vector<int>,int> idxmp;
    vector<vector<int>> edges; // w u v


    vector<vector<int>> points(n);

    for(int i = 0 ; i < n ; i ++) {
        int u,v;
        cin>>u>>v;
        points[i] = {u,v};
        idxmp[{u,v}] = i;
    }

    vector<vector<int>> temppoints(n);

    for(int i = 0 ; i < n ; i ++) temppoints[i] = points[i];

    sort(temppoints.begin(),temppoints.end());



    for(int i = 1 ; i < n ; i ++) {
        edges.pb({temppoints[i][0]-temppoints[i-1][0],idxmp[temppoints[i]],idxmp[temppoints[i-1]]});
    }


    for(int i = 0 ; i < n ; i ++) {
        temppoints[i] = {points[i][1],points[i][0]};
    }

    sort(temppoints.begin(),temppoints.end());

    for(int i = 1 ; i < n ; i ++) {
        edges.pb({temppoints[i][0]-temppoints[i-1][0],idxmp[{temppoints[i][1],temppoints[i][0]}],idxmp[{temppoints[i-1][1],temppoints[i-1][0]}]});
    }


    sort(edges.begin(),edges.end());


    int ans = 0;

    for(vector<int>& edge : edges) {
        if(!isSameSet(edge[1],edge[2])) {
            ans += edge[0];
            unionSet(edge[1],edge[2]);
        }
    }


    cout<<ans<<endl;




  }
  return 0;
}