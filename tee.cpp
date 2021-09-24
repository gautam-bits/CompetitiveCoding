
    
    #include <bits/stdc++.h>
    using namespace std;
    


int cccc(vector<int> vec) {
    int n = vec.size();
    vector<long long> cnt(32,0);

    for(int x : vec) {
        for(int i = 0 ; i < 32 ; i++) {
            cnt[i] += ((long long int)x>>i)&1;
        }
    } 
    long long ans = 0;

    for(int i  = 1 ; i < 32 ; i++) ans = (ans + cnt[i]*(cnt[i]-1)*(1<<i))%(1000000007);

    return ans;
    
}
    
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<cccc(3,{"11","10","00",},{"11"});
    
    
    return 0;
}