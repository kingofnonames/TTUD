#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
int n, M;
int a[MAX];
long long pre_sum[MAX];
int tmp = 0;
int cnt = 0;
void init(){
    cin >> n >> M;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
}

void TRY(int k){
    int x_max = (M - tmp - (pre_sum[n] - pre_sum[k])) / a[k];
    for(int x = 1; x <= x_max; ++x){
        tmp += x * a[k];
        if(k == n){
            if(tmp == M) ++cnt;
        }else{
            TRY(k + 1);
        }
        tmp -= x * a[k];
    } 
}
int main(){
    init();
    TRY(1);
    cout << cnt;
}