#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
int num[MAX], low[MAX], cnt = 0;
int n, m, res = 0;
stack<int> st;
vector<vector<int>> edges;
void input(){
    cin >> n >> m;
    edges.resize(n + 1);
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
}
void solve(int u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for(int edge : edges[u]){
        if(num[edge]){
            low[u] = min(low[u], num[edge]);
        }
        else{
            solve(edge);
            low[u] = min(low[u], low[edge]);
        }
    }
    if(num[u] == low[u]){
        int v;
        do{
            v = st.top();
            st.pop();
            num[v] = low[v] = INT_MAX;
        }while(v != u);
        res++;
    }
}
int main(){
    input();
    for(int i = 1; i <= n; ++i){
        if(!num[i]) solve(i);
    }
    cout << res << endl;
}
