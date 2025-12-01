#include <bits/stdc++.h>
using namespace std;
vector<int> match;
vector<vector<int>> adj;
vector<bool> visited;
int n, m;
int cnt = 0;
void input()
{
    cin >> n >> m;
    adj.resize(n + 1);
    match.resize(m + 1, -1);
    visited.resize(m + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int b = 0;
            cin >> b;
            adj[i].push_back(b);
        }
    }
}
bool dfs(int task)
{
    for (int &staff : adj[task])
    {
        if (!visited[staff])
        {
            visited[staff] = true;
            if (match[staff] == -1 || dfs(match[staff]))
            {
                match[staff] = task;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (dfs(i))
            cnt++;
        visited.assign(m + 1, false);
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
