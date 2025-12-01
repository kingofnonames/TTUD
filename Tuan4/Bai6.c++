#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1, INT_MAX);
    b[0] = INT_MIN;
    int res = 1;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i){
        int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        b[k] = a[i];
        res = max(res, k);
    }
    cout << res;
}
