#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX = 1e6 + 7;
int a[MAX];
int f[MAX];
int main(){
    int n, L1, L2;
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int res = 0;
    priority_queue<ii, vector<ii>> pq;
    for(int i = 1; i <= n; ++i){
        while(!pq.empty() && i - pq.top().second > L2) pq.pop();
        f[i] = a[i];
        if(i - L1 > 0) pq.push({f[i - L1], i - L1});
        if (!pq.empty()){
            f[i] = max(f[i], a[i] + pq.top().first);
        }
        res = max(res, f[i]);
    }
    cout << res;
}