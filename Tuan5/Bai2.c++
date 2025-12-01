#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX = 1e6 + 7;
vector<vector<int>> X;
int num[MAX], low[MAX], cnt = 0;
int countBridges = 0, countArticulaions = 0;
int numChild[MAX];
bool isArticulation[MAX];
int n, m;
vector<ii> edges;
bool visited[MAX];
void input(){
    cin >> n >> m;
    X.resize(n + 1);
    edges.resize(m + 1);
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        X[a].push_back(i);
        X[b].push_back(i);
    }
}
void solve(int u){
    num[u] = low[u] = ++cnt;
    for(int &x : X[u]){
        if(!visited[x]){
            visited[x] = true;
            int v = edges[x].first + edges[x].second - u;
            if(num[v]){
                low[u] = min(num[v], low[u]);
            }else{
                numChild[u]++;
                solve(v);
                low[u] = min(low[u], low[v]);
                if(num[u] < low[v]){
                    countBridges++;
                }
                if(num[u] <= low[v]){
                    isArticulation[u] = true;
                }
            }
        }
    }
}
int main(){
    input();
    for(int i = 1; i <= n; ++i){
        if(!num[i]){
            solve(i);
            if(numChild[i] < 2) isArticulation[i] = false;
        }
        if(isArticulation[i]) countArticulaions++;
    }
    cout << countArticulaions << " " << countBridges;
}
