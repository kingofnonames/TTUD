#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
struct Compare{
    bool operator()(const iii& a, const iii& b){
        return a.second.first > b.second.first;
    }
};
int n, m;
const int MAX = 5e3 + 7;
int C[MAX], D[MAX];
vector<vector<int>> adjs;
int res = INT_MAX;
vector<vector<int>> dists;
priority_queue<iii, vector<iii>, Compare> pq;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> C[i] >> D[i];
    }
    adjs.resize(n + 1);
    dists.resize(n + 1, vector<int>(107, INT_MAX));
    while(m--){
        int i, j;
        cin >> i >> j;
        adjs[i].push_back(j);
        adjs[j].push_back(i);
    }
}

void solve(){
    dists[1][D[1]] = C[1];
    pq.push(make_pair(1, make_pair(C[1], D[1])));
    while(!pq.empty()){
        iii t = pq.top();
        pq.pop();
        int tmp_city = t.first;
        int tmp_cost = t.second.first;
        int tmp_remaining = t.second.second;
        if(tmp_city == n) {
            res = tmp_cost;
            break;
        }
        // if (tmp_cost > dists[tmp_city][tmp_remaining]) continue;
        for(int nex : adjs[tmp_city]){
            if(tmp_remaining - 1 >= 0){
                if(dists[nex][tmp_remaining - 1] > tmp_cost){
                    dists[nex][tmp_remaining - 1] = tmp_cost;
                    pq.push(make_pair(nex, make_pair(tmp_cost, tmp_remaining - 1)));
                }
            }
            int new_cost = tmp_cost + C[nex];
            int new_remaining = D[nex];
            if(new_remaining < dists[nex][new_remaining]){
                pq.push(make_pair(nex, make_pair(new_cost, new_remaining)));
            }
        }
    }
    cout << res;
}
int main(){
    input();
    solve();
}
