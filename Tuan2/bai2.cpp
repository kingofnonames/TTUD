#include <bits/stdc++.h>
using namespace std;
const int MAX = 23;
int x[MAX], c[MAX][MAX];
int tmp_f = 0;
int f = INT_MAX;
int n, load;
int c_min = INT_MAX;
bool visited[MAX];
int tmp_load = 0;
void init(){
    cin >> n >> load;
    for(int i = 0; i <= 2 * n; ++i){
        for(int j = 0; j <= 2 * n; ++j){
            cin >> c[i][j];
            if(i != j){
                c_min = min(c_min, c[i][j]);
            }
        }
    }
    fill(visited, visited + MAX, false);
}

bool check_valid(int city){
    if(visited[city]) return false;
    if(city > n) return visited[city - n];
    return (tmp_load + 1 <= load);
}
void TRY(int k){
    for(int i = 1; i <= 2 * n; ++i){
        if(check_valid(i)){
            visited[i] = true;
            tmp_f += c[x[k - 1]][i];
            tmp_load += (i > n ? -1 : 1);
            x[k] = i;
            if(k == 2 * n){
                f = min(f, tmp_f + c[i][0]);
            }else{
                if(tmp_f + c_min * (2 * n + 1 - k) < f){
                    TRY(k + 1);
                }
            }
            visited[i] = false;
            tmp_f -= c[x[k - 1]][i];
            tmp_load -= (i > n ? -1 : 1);

        }
    }
}
int main(){
    init();
    x[0] = 0;
    TRY(1);
    cout << f;
}