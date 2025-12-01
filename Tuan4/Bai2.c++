#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    int N, K1, K2;
    cin >> N >> K1 >> K2;
    int cnt = 0;
    int f[10007][2];
    f[0][0] = f[0][1] = 1;
    for(int i = 1; i <= N; ++i){
        f[i][0] = f[i - 1][1] % MOD;
        for(int k = K1; k <= K2 && i >= k; ++k){
            f[i][1] = (f[i][1] + f[i - k][0]) % MOD;
        }
    }
    cout << (f[N][0] + f[N][1]) % MOD;
}