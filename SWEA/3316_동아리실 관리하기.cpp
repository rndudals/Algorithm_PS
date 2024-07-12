#include<iostream>
#include <cstring>
using namespace std;
 
long long dp[10000][16]; // dp[day][ABCD존재의 모든 경우]
 
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
            int manager = 1 << (st[i] - 'A'); // 매니저 정하기
            for (int j = 1; j < 16; j++) {
                if (i == 0) { // 첫 날 초기화해주기
                    if ((manager & j) != 0 && (j & 1) != 0) { // managet와 A가 있으면
                        dp[i][j] = 1;
                    }
                }
                else { // 나머지 날에
                    if (dp[i - 1][j] != 0) { // 전날에 경우의 수가 있으면
                        for (int k = 1; k < 16; k++) { // 모든 경우의 수를 본다.
                            if ((k & j) != 0 && (manager & k) != 0) { // k : 오늘, j : 전날 
                            // 오늘 나온 사람이 전날에도 있었고
                            // 오늘 나온 사람이 manager가 있을 경우
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
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}