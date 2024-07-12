#include<iostream>
#include <cstring>
using namespace std;
 
long long dp[10000][16]; // dp[day][ABCD������ ��� ���]
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    string st;
    //freopen("input.txt", "r", stdin);
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(dp, 0, sizeof(dp));
        cin >> st;
        int size = st.size();
        for (int i = 0; i < size; i++) {
            int manager = 1 << (st[i] - 'A'); // �Ŵ��� ���ϱ�
            for (int j = 1; j < 16; j++) {
                if (i == 0) { // ù �� �ʱ�ȭ���ֱ�
                    if ((manager & j) != 0 && (j & 1) != 0) { // managet�� A�� ������
                        dp[i][j] = 1;
                    }
                }
                else { // ������ ����
                    if (dp[i - 1][j] != 0) { // ������ ����� ���� ������
                        for (int k = 1; k < 16; k++) { // ��� ����� ���� ����.
                            if ((k & j) != 0 && (manager & k) != 0) { // k : ����, j : ���� 
                            // ���� ���� ����� �������� �־���
                            // ���� ���� ����� manager�� ���� ���
                                dp[i][k] += dp[i - 1][j];
                                dp[i][k] = dp[i][k] % 1000000007;
                            }
                        }
                    }
                }
            }
        }
        long long cnt=0;
        for (int i = 1; i < 16; i++) {
            cnt += dp[size - 1][i];
            cnt %= 1000000007;
        }
 
        cout << "#" << test_case << " "<<cnt << '\n';
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}