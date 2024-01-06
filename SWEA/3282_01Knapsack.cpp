#include<iostream>
#include<cstring>
using namespace std;
 
int dp[101][1001]; // dp���̺� ����
int N, K;
int V[101], C[101]; // ���ǹ迭 V�� ��ġ �迭 C
 
int run(int idx, int v) {
    if (dp[idx][v] != 0)return dp[idx][v]; // �湮�� �� ������ ����
    if (idx == N) { return 0; } // ������ �Ѿ�� ����
    int a = 0, b = 0;
    if (V[idx] + v <= K) { // ���� ��
        a = C[idx] + run(idx + 1, V[idx] + v);
    }
    b = run(idx + 1, v); // �ȳ��� ��
    dp[idx][v] = max(a, b); // �ִ� ����ϱ�
 
    return dp[idx][v]; // �ִ� ����
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
        memset(dp, 0, sizeof(dp)); // dp���̺� �ʱ�ȭ
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}