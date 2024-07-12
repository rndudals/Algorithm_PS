#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
 
int M, N, c1, c2;
int cow[500001];
int horse;
 
bool f(int idx) {
    if (cow[idx] < horse) {
        return true;
    }
    else return false;
}
 
int binarySearch(int start, int end) {
    int l = start, r = end + 1;
    while (l != r) {
        int mid = l + (r - l) / 2;
        f(mid) ? l = mid + 1 : r = mid;
    }
    return l;
}
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
 
    //freopen("input.txt", "r", stdin);
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(cow, 0, sizeof(cow));
        int cnt = 0;
        int MIN = 2147483647;
        cin >> N >> M;
        cin >> c1 >> c2;
        for (int i = 0; i < N; i++) {
            cin >> cow[i];
        }
        sort(cow, cow + N);
        for (int i = 0; i < M; i++) {
            cin >> horse;
            int idx = binarySearch(0, N - 1);
            //cout << "idx : " << idx<<'\n';
            int m;
            if (idx == N) {
                m = abs(horse - cow[idx-1]);
                if (m < MIN) {
                    MIN = m;
                    cnt = 1;
                }
                else if (m == MIN) {
                    cnt++;
                }
            }
            else {
                m = abs(horse - cow[idx]);
                if (m < MIN) {
                    MIN = m;
                    cnt = 1;
                }
                else if (m == MIN) {
                    cnt++;
                }
                if (idx > 0 && horse !=cow[idx]) {
                    m = abs(horse - cow[idx - 1]);
                    if (m < MIN) {
                        MIN = m;
                        cnt = 1;
                    }
                    else if (m == MIN) {
                        cnt++;
                    }
                }
            }
             
 
        }
        cout << "#" << test_case << ' ' << MIN + abs(c1 - c2) << ' ' << cnt << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}