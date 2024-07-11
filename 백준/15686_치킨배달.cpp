#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int arr[51][51];
int N, M;
bool check[51][51];
bool visited[51][51];
int dist[51][51];
vector<pair<int, int>> v;
int ans = 1000000000;


void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    dist[x][y] = 0;
    q.push({ x,y });
    while (!q.empty()) {
        int c_x = q.front().first;
        int c_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];
            if (n_x >= 1 && n_y >= 1 && n_x <= N && n_y <= N) {
                if (!visited[n_x][n_y]) {
                    dist[n_x][n_y] = dist[c_x][c_y] + 1;
                    visited[n_x][n_y] = true;
                    q.push({ n_x, n_y });
                }
                else {
                    if (dist[n_x][n_y] > dist[c_x][c_y] + 1) {
                        dist[n_x][n_y] = dist[c_x][c_y] + 1;
                        q.push({ n_x, n_y });
                    }
                }
            }

        }
    }

}

int calc() {
    int m = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) {
                m += dist[i][j];
            }
        }
    }
    return m;
}


void pick(int depth, int x, int y) {
    if (depth == M) {
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < v.size(); i++) {
            bfs(v[i].first, v[i].second);

        }
        ans = min(ans, calc());

        return;
    }
    for (int i = x; i <= N; i++) {
        for (int j = y; j <= N; j++) {
            if (arr[i][j] == 2 && !check[i][j]) {
                check[i][j] = true;
                v.push_back({ i,j });
                pick(depth + 1,i,j);
                v.pop_back();
                check[i][j] = false;
            }
        }
        y = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    pick(0,1,1);
    cout << ans;
    return 0;
}
