#include <iostream>
#include <cstring>
#include<queue>
#include <math.h>
using namespace std;

int N;
int map[21][21];
bool visited[21][21];
int shark=2;
int stack;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int X, Y;
int wX, wY;
int ans;
int dist[21][21];
int min_dist=999999;

void eat() {
    stack++;
    if (stack == shark) {
        stack = 0;
        shark++;
    }
}

void time(int x, int y) {
    ans += dist[wX][wY];
}

bool bfs() {
    bool ret = false;
    queue<pair<int, int>> q;
    visited[X][Y] = true;
    q.push({ X,Y });
    dist[X][Y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visited[nx][ny] || map[nx][ny] > shark)continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            if (shark > map[nx][ny] && map[nx][ny] != 0) { // 먹을 수 있을 경우
                if (min_dist > dist[nx][ny]) {
                    wX = nx;
                    wY = ny;
                    min_dist = dist[nx][ny];
                }
                else if (min_dist == dist[nx][ny]) {
                    if (wX == nx) {
                        if (wY > ny) {
                            wX = nx;
                            wY = ny;
                        }
                    }
                    else if (wX > nx) {
                        wX = nx;
                        wY = ny;
                    }

                }
                ret = true;
            }
            
            q.push({ nx,ny });
            visited[nx][ny] = true;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                map[i][j] = 0;
                X = i;
                Y = j;
            }
        }
    }
    
    while (bfs()) {
        map[wX][wY] = 0;
        time(X, Y);
        eat();
        //cout <<"(" << X << ", " <<Y << ") -> "<<"("<< wX << ", " << wY <<") "<<"ans : "<<ans << '\n';
        X = wX;
        Y = wY;
        min_dist = 999999;
        
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
    }
    cout << ans;
}
