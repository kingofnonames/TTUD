#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, T, D;
    cin >> N >> T >> D;
    int a[1007], t[1007];
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> t[i];
    }
    int res = INT_MIN;
    int f[1007][1007];
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= T; ++j)
        {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = t[i]; j <= T; ++j)
        {
            f[i][j] = a[i];
            for (int k = i - D; k < i; ++k)
            {
                if (k > 0)
                    f[i][j] = max(f[i][j], f[k][j - t[i]] + a[i]);
            }
            res = max(res, f[i][T]);
        }
    }
    cout << res << endl;
}
