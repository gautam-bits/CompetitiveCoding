#include<bits/stdc++.h>
using namespace std;

bool isConsonent(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return false;
    return true;
}

bool allSame(string s) {
    int x = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        if(isConsonent(s[i])) x++;
    }
    if(x == 0 || x == s.size()) return true;
}

int32_t main()
{
    
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin >> t;
        
    for(int cases = 1 ; cases <= t ; cases++)
    {
        
        string s;
        cin>>s;
        int minima = INT_MAX;
        for(int i = 0 ; i < (int)s.size() ; i++) {
            int count = 0;
            for(int j = 0 ; j < s.size() ; j++) {
                if(s[i] == s[j]) continue;
                else if(isConsonent(s[i]) ^ isConsonent(s[j])) count += 1;
                else count += 2; 
            }
            minima = min(minima, count);
        }
        if(allSame(s))minima = min(minima, (int)s.size());
        cout << "Case #" << cases << ": " << minima << endl;
    }
    return 0;
}