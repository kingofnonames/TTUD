#include <bits/stdc++.h>
using namespace std;
#define MAX 1007
struct Treasure
{
    int xi, yi, ci;
    Treasure() : xi(0), yi(0), ci(0) {}
    Treasure(int x, int y, int c) : xi(x), yi(y), ci(c) {}
};

int main()
{
    int n;
    cin >> n;
    vector<Treasure> treasures(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        Treasure t(x, y, c);
        treasures[i] = t;
    }
    sort(treasures.begin() + 1, treasures.end(), [](const Treasure &a, const Treasure &b)
         {
        if(a.xi == b.xi){
            if(a.yi == b.yi) return a.ci > b.ci;
            return a.yi < b.yi;
        } 
        return a.xi < b.xi; });
    long long f[MAX];
    long long res = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        f[i] = treasures[i].ci;
        for (int j = 1; j < i; ++j)
        {
            if (treasures[j].yi <= treasures[i].yi)
            {
                f[i] = max(f[i], f[j] + treasures[i].ci);
            }
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
}
