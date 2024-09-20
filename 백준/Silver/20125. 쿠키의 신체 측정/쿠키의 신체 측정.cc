#include<iostream>

using namespace std;

int N;
char map[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};
int hx;
int hy;

void input(){
    for(int i=0;i<N;i++){
        string st;
        cin >> st;
        for(int j=0;j<N;j++){
            map[i][j]=st[j];
        }
    }
}
bool checkHeart(int c){
    if(c == 4){
        return true;
    }
    return false;
}


void findHeart(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                
                if(nx <0 || nx>=N || ny <0 || ny>=N) continue;
                if(map[nx][ny]=='*'){
                    cnt++;
                }
                if(cnt == 4){
                    hx = i+1;
                    hy = j+1;
                    cout<<i+1<<" "<<j+1<<'\n';
                    return;
                }
            }
        }
    }
}


// 0 : 아래
// 1 : 위쪽
// 2 : 오른쪽
// 3 : 왼쪽
int countLength(int x, int y, int dir){
    int cnt = 1;
    while(1){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(nx <0 || nx>=N || ny <0 || ny>=N) break;
        if(map[nx][ny]=='*'){
            x=nx;
            y=ny;
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}

int main(){
    cin >> N;
    
    input();
    
    findHeart();

    // 왼쪽 팔
    cout<<countLength(hx-1, hy-2, 3)<<" ";
    
    // 오른쪽 팔
    cout<<countLength(hx-1, hy, 2)<<" ";

    // 허리
    int p = countLength(hx, hy-1, 0);
    cout<<p<<" ";
    
    // 왼쪽 다리
    cout<<countLength(hx+p, hy-2, 0)<<" ";
    
    // 오른쪽 다리
    cout<<countLength(hx+p, hy, 0)<<" ";
}