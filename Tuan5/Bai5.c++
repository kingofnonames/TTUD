#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> edges[MAX];
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    vector<int> in(n + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        ++in[v];
    }
    queue<int> q;
    vector<int> time_start(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0)
            q.push(i);
    }
    int res = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int time_complete = time_start[u] + d[u];
        res = max(res, time_complete);
        for (const int &v : edges[u])
        {
            time_start[v] = max(time_start[v], time_complete);
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    cout << res << endl;
}
