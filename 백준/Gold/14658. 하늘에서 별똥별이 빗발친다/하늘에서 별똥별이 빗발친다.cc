#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
#include <unordered_map>
#include <sstream>
using namespace std;


int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

int N, M, L, K;
int ans = 100000;
vector<pair<int, int>> v; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>L>>K;
    for(int i=0;i<K;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {          // ★ (1) dir → j 루프로 변경
        int cx = v[i].first;              
        int cy = v[j].second;             // ★ (2) y는 v[j].second 를 사용

        int cnt = 0;
        int nx = cx + L;                  // ★ (3) dx,dy 대신 +L 만 하면 됨
        int ny = cy + L;

        int lx = min(cx, nx), rx = max(cx, nx);
        int ly = min(cy, ny), ry = max(cy, ny);

        for (int t = 0; t < K; t++) {
            int tx = v[t].first;
            int ty = v[t].second;
            if (lx <= tx && tx <= rx && ly <= ty && ty <= ry) ++cnt;
        }
        ans = min(ans, K - cnt);
    }
}

cout << ans << '\n';
    return 0;
}
