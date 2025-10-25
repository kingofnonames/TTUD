#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
int segmentTree[4 * MAX];
const int Q = 1e9 + 7;
void updateTree(int id, int l, int r, int u, int val){
    if(u < l || u > r) return;
    if(l == r){
        segmentTree[id] += val;
        return;
    }
    int m = l + (r - l) / 2;
    updateTree(2 * id, l, m, u, val);
    updateTree(2 * id + 1, m + 1, r, u, val);
    segmentTree[id] = segmentTree[2 * id] + segmentTree[2 * id + 1];
}

int getTree(int id, int l, int r, int u, int v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r) return segmentTree[id];
    int m = l + (r - l) / 2;
    return getTree(2 * id, l, m, u, v) + getTree(2 * id + 1, m + 1, r, u, v);
}

int lower_bound(const vector<int>& a_unique, int val){
    int r = a_unique.size() - 1;
    int l = 0;
    while(l < r){
        int m = l + (r - l) / 2;
        if (a_unique[m] < val){
            l = m + 1;
        }else{
            r = m;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> a_sorted = a;
    sort(a_sorted.begin(), a_sorted.end());
    vector<int> a_unique;
    int val_tmp = a_sorted[0];
    a_unique.push_back(val_tmp);
    for(int i = 1; i < n; ++i){
        if(val_tmp == a_sorted[i]) continue;
        val_tmp = a_sorted[i];
        a_unique.push_back(val_tmp);
    }
    long long cnt = 0;
    for(int i = n - 1; i >= 0; --i){
        int key = lower_bound(a_unique, a[i]) + 1;
        int val = getTree(1, 1, n, 1, key - 1);
        updateTree(1, 1, n, key, 1);
        cnt = (cnt + val) % Q;
    }
    cout << cnt;
}