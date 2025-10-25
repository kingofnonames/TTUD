#include <bits/stdc++.h>
using namespace std;

bool check_valid(int mid_, const vector<int>& X, int N, int C){
    int cnt = 1;
    int prev = X[1];
    for(int i = 2; i <= N; ++i){
        if(X[i] - prev >= mid_) {
            ++cnt;
            prev = X[i];
        }
        if(cnt >= C) return true;
    }
    return false;
}

int solve(vector<int>& X, int N, int C){
    sort(X.begin(), X.end());
    int right_ = X[N] - X[1], left_ = 0;
    int res = 0;
    while(left_ < right_){
        int mid_ = left_ + (right_ - left_) / 2;
        if(check_valid(mid_, X, N, C)){
            res = mid_;
            left_ = mid_ + 1;
        }else{
            right_ = mid_;
        }
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, C;
        cin >> N >> C;
        vector<int> X(N + 1);
        for(int i = 1; i <= N; ++i){
            cin >> X[i];
        }
        cout << solve(X, N, C) << endl;
    }
}