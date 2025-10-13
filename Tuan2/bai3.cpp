#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int m, n;
vector<int> loads;
unordered_map<int, unordered_map<int, bool>> preferences;
vector<vector<int>> conflicts;
int res = INT_MAX;
bool flag = true;
vector<int> assigns;
void init(){
    cin >> m >> n;
    assigns.resize(n + 1, -1);
    loads.resize(m + 1, 0);
    conflicts.resize(n + 1);
    for(int i = 1; i <= m; ++i){
        int k;
        cin >> k;
        while(k--){
            int course;
            cin >> course;
            preferences[i][course] = true;
        }
    }
    int k;
    cin >> k;
    while(k--){
        int u, v;
        cin >> u >> v;
        conflicts[u].push_back(v);
        conflicts[v].push_back(u);
    }
}

void TRY(int course){
    if(course > n){
        int tmp_load = *max_element(loads.begin(), loads.end());
        res = min(tmp_load, res);
        flag = false;
        return;
    }
    for(int teacher = 1; teacher <= m; ++teacher){
        if(preferences[teacher][course]){
            bool confl = false;
            for(int cf: conflicts[course]){
                if(assigns[cf] == teacher){
                    confl = true;
                    break;
                };
            }
            if(confl) continue;
            assigns[course] = teacher;
            loads[teacher] += 1;
            if(loads[teacher] < res){
                TRY(course + 1);
            }
            assigns[course] = -1;
            loads[teacher] -= 1;
        }
    }
}
int main(){
    init();
    TRY(1);
    cout << (flag ? -1 : res);
}