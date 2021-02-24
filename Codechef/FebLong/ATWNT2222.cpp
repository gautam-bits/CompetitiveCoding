#include <bits/stdc++.h>
using namespace std;

int recurss(int xx,int yy,vector<vector<int>>& graph,vector<int>& answer);
int main() 
{
    
    
    int n;
    int queries;
    int xx,yy;
    cin>>n;

    vector<vector<int>> graph(n+1);
    vector<int> answer(n+1,0);

    //fill the list

    for(int i = 1 ; i < n ; i++){
        int res = i + 1;
        int yo;
        cin>>yo;

        graph[yo].push_back(res);
        answer[yo]++;
    }

    cin>>queries;

    while(queries--){
        cin>>xx>>yy;

        int ans = recurss(xx,yy,graph,answer);
        cout<<yy - ans<<endl;
    }


    return 0;
}

int recurss(int xx,int yy,vector<vector<int>>& graph,vector<int>& answer){
    int len = graph[xx].size();

    if(len == 0) {
        return yy;
    }
    else if(yy % len != 0) {
        return 0;
    }
    else {
        int wtf = 0;

        for(int i = 0 ; i < len ; i++) {
            int tem = graph[xx][i];
            wtf += recurss(tem,yy/len,graph,answer);
        }

        return wtf;
    }

}