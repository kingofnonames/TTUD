#include<bits/stdc++.h>
using namespace std;
const int Q = 1e9 + 7;
const int MAX = 1e6 + 7;
int cnt = 0;
int a[MAX];

void merge(int a[], int l, int r){
    int m = l + (r - l) / 2;
    int tmp[r - l + 2];
    int k = 0;
    int st = l, en = m + 1;
    while(st < en && st <= m && en <= r){
        if(a[st] > a[en]){
            tmp[k] = a[en];
            ++en;
            cnt = (cnt + (m - st + 1)) % Q;
        }else{
            tmp[k] = a[st];
            ++st;
        }
        ++k;
    }
    while(st <= m){
        tmp[k] = a[st];
        ++k;
        ++st;
    }
    while(en <= r){
        tmp[k] = a[en];
        ++en;
        ++k;
    }
    for(int i = 0; i < k; ++i){
        a[i + l] = tmp[i];
    }
}

void mergeSort(int a[], int l, int r){
    int m = l + (r - l) / 2;
    if(l < r){
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, r);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    cout << cnt;
}