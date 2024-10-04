#include<iostream>
using namespace std;

int N, r, c;
long long ans;

void input(){
    cin >> N >> r >> c;
}

void printAnswer(){
    cout << ans << '\n';
    exit(0);
}

void go(int x, int y, int size){
    if(size == 1){
        if(x == r && y == c){
            printAnswer();
        }
        ans++;
        return;
    }

    int half = size / 2;
    int area = half * half;

    // 현재 영역을 4분할하여 각 영역에 대해 재귀 호출

    // 왼쪽 위
    if(r < x + half && c < y + half){
        go(x, y, half);
    } else {
        ans += area;
    }

    // 오른쪽 위
    if(r < x + half && c >= y + half){
        go(x, y + half, half);
    } else {
        ans += area;
    }

    // 왼쪽 아래
    if(r >= x + half && c < y + half){
        go(x + half, y, half);
    } else {
        ans += area;
    }

    // 오른쪽 아래
    if(r >= x + half && c >= y + half){
        go(x + half, y + half, half);
    } else {
        ans += area;
    }
}

void run(){
    int size = 1 << N;
    go(0, 0, size);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    run();
}
