#include<iostream>
#include<cstring>
using namespace std;
 
int dp[101][1001]; // dp테이블 생성
int N, K;
int V[101], C[101]; // 부피배열 V와 가치 배열 C
 
int run(int idx, int v) {
    if (dp[idx][v] != 0)return dp[idx][v]; // 방문한 적 있으면 리턴
    if (idx == N) { return 0; } // 범위를 넘어가면 종료
    int a = 0, b = 0;
    if (V[idx] + v <= K) { // 넣을 때
        a = C[idx] + run(idx + 1, V[idx] + v);
    }
    b = run(idx + 1, v); // 안넣을 때
    dp[idx][v] = max(a, b); // 최댓값 기억하기
 
    return dp[idx][v]; // 최댓값 리턴
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> V[i] >> C[i];
        }
        cout << "#" << test_case << " " << run(0, 0) << '\n';
        memset(dp, 0, sizeof(dp)); // dp테이블 초기화
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}