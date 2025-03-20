#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int M, N, K;

class A{
public:
    int x1;
    int y1;
    int x2;
    int y2;
};

vector<A> v;
bool map[100][100];

void input(){
    cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        v.push_back({a,b,c,d});
    }
}

void makeRec(int x1, int y1, int x2, int y2){
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            map[i][j] = 1;
        }
    }
}

int bfs(int x, int y){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x,y});
    map[x][y] =true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();


        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0 || ny<0 ||nx>=N || ny>=M) continue;
            if(map[nx][ny]) continue;
            map[nx][ny]=true;
            cnt++;
            q.push({nx, ny});
        }
    }
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    // 직사각형 방문처리
    for(int i=0;i<v.size();i++){
        makeRec(v[i].x1, v[i].y1, v[i].x2, v[i].y2);
    }
    


    // bfs로 칸수 세기
    vector<int> cnt_v;
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!map[i][j]){
                ans++;
                cnt_v.push_back(bfs(i, j));
                
            }
        }
    }
    cout<<ans<<'\n';
    sort(cnt_v.begin(), cnt_v.end());
    for(auto e: cnt_v){
        cout<<e<<" ";
    }
}
