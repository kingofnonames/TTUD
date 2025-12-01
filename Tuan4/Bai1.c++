#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 7;
long long presum[MAX];
int main(){
    int n;
    cin >> n;
    presum[0] = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
    }
    ll res = -1e18;
    ll f_odd = 1e18;
    ll f_even = 0;
    for(int i = 1; i <= n; ++i){
        if (abs(presum[i]) % 2){
            if(f_odd == -1e18){
                f_odd = presum[i];
            }else{
                res = max(res, presum[i] - f_odd);
                f_odd = min(f_odd, presum[i]);
            }
        }else{
            res = max(res, presum[i] - f_even);
            f_even = min(f_even, presum[i]);
        }
    }
    if (res == -1e18) cout << "NOT_FOUND";
    else
        cout << res << endl;

}