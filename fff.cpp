#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int age;
    Node* left;
    Node* right;

    Node(int aa) {
        age = aa;
    }
};


double calculate(Node* root) {
    if(root == NULL) return 0.0;
    
    map<int,vector<int>> mp; 
    
    
    queue<pair<Node*,int>> q;

    q.push({root,0});


    while(!q.empty()) {
        pair<Node*,int> curr = q.front();
        q.pop();
        mp[curr.second].push_back(curr.first->age);

        if(curr.first->left) {
            q.push({curr.first->left,curr.second+1});
        }
        if(curr.first->right) {
            q.push({curr.first->right,curr.second+1});
        }
    }

    vector<int> mm;

    


    for(auto x : mp) {
        vector<int> te = x.second;
        int sz = te.size();
        int mn = *min_element(te.begin(),te.end());
        if(te[0] == mn) mm.push_back(te[0]);
        else if(te[sz-1] == mn) mm.push_back(te[sz-1]);
        else return -1.0;
    }

    double ans = 0.0;

    for(int x : mm) ans += x;

    int sss = mm.size();

    ans = ans/sss;

    ans = ans*10;

    int bbb = (int)(ans + 0.5);

    double a2 = ((double)bbb)/10.0;

    return a2;

    
    
    
}


int circularArray(int n, vector<int> endNode) {
    int m = endNode.size();
    map<int, int> count;
    int start = endNode[0], end = endNode[m - 1];

    for (int i = 0 ; i < m ; i++)
        count[endNode[i]]++;

    for (pair<int,int> x: count) {
        int k = x.first;
        if (k >= end) {
            count[k]--;
        }
        if (k > start) {
            count[k]++;
        }
    }

    int max = 0; 
    int freq; = 1;
    for (pair<int,int> x : count) {
        int v = x.second;
        int k = x.first;
        if (max < v) {
            max = v;
            freq = k;
        }
        if (max == v && freq > k) {
            max = v;
            freq = k;
        }
    }
    return freq;
}


int main()
{


    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

    cout<<calculate(root);
}
