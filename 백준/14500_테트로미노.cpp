#include <iostream>
#include <vector>
using namespace std;


int N, M;
int map[501][501];
bool visited[501][501];
int on;
int tmp;
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void func_1(int x, int y, int depth) {
    // 종료조건
   if (depth == 4) {
       if (ans < tmp) {
           ans = tmp;
       }
       return;
   }

   for (int i = 0; i < 4; i++) {
       int next_x = x + dx[i];
       int next_y = y + dy[i];

       if (next_x > 0 && next_y > 0 && next_x <= N && next_y <= M) {
           if (!visited[next_x][next_y]) {
               visited[next_x][next_y] = true;
               tmp += map[next_x][next_y];
               func_1(next_x, next_y, depth + 1);
               visited[next_x][next_y] = false;
               tmp -= map[next_x][next_y];
           }
       }
   }

}


int func_2(int x, int y) {
    int m=0;
    if (x + 1 <= N && y - 1 >= 1 && y + 1 <= M) { // ㅜ
        m = max(m, map[x + 1][y] + map[x][y - 1] + map[x][y + 1] + map[x][y]);
    }
    if (x - 1 >=1 && y - 1 >= 1 && y + 1 <= M) { // ㅗ
        m = max(m, map[x - 1][y] + map[x][y - 1] + map[x][y + 1] + map[x][y]);
    }
    if (x + 1 <= N && x - 1 >= 1 && y + 1 <= M) { // ㅏ
        m = max(m, map[x + 1][y] + map[x-1][y] + map[x][y + 1] + map[x][y]);
    }
    if (x + 1 <= N && x - 1 >= 1 && y - 1 >= 1) { // ㅓ
        m = max(m, map[x + 1][y] + map[x - 1][y] + map[x][y - 1] + map[x][y]);
    }

    return m;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= N; i++) { // ㅜ 제외하면 백트래킹으로 해결 가능
        for (int j = 1; j <= M; j++) {
            visited[i][j] = true;
            tmp += map[i][j];
            func_1(i,j,1);
            visited[i][j] = false;
            tmp -= map[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans=max(ans,func_2(i,j)); // ㅜ 해결하는 함수
        }
    }
    cout << ans;
    return 0;
}