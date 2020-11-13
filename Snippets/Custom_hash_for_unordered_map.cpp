// unordered map can easily be hacked by introducing multiole collisions
//https://codeforces.com/blog/entry/62393

#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    } 
};
int main() {
    unordered_map<long long, int, custom_hash> safe_map;
    return 0;
}
