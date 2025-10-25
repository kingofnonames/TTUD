#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main(){
    int n;
    vector<ii> segments;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        segments.push_back(make_pair(a, b));
    }
    sort(segments.begin(), segments.end(), [](const ii &a, const ii &b){
        return a.second < b.second;
    });
    int cnt = 1;
    int endTime = segments[0].second;
    for(int i = 1; i < n; ++i){
        if(segments[i].first > endTime){
            ++cnt;
            endTime = segments[i].second;
        }
    } 
    cout << cnt << endl;
}