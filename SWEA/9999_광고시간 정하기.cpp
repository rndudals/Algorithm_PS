#include<iostream>
#include <cstring>
#include<vector>
 
using namespace std;
 
struct Node {
    int start;
    int end;
    int sum;
};
Node nodes[100001];
int N, L;
 
int BinarySearch(int end) { // 마지막 피크시간의 위치를 찾아주는 함수
    int l = 0; int r = N;
    while (l != r) {
        int m = l + (r - l) / 2;
        end > nodes[m].start ? l = m + 1:r = m;
    }
    return l-1;
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
        int m = 0;
        cin >> L >> N;
        for (int i = 0; i < N; i++) {
            cin >> nodes[i].start >> nodes[i].end;
            nodes[i+1].sum = nodes[i].sum+nodes[i].end - nodes[i].start; // node[i+1].sum : node[i]까지의 peek시간의 누적합
        }
        for (int i = 0; i < N; i++) {
            int ans = 0;
            int idx=BinarySearch(nodes[i].start+L);
            if (nodes[i].start + L >= nodes[idx].end) { // 광고시간이 마지막 피크시간 끝나는 시간보다 길 때
                ans = nodes[idx].sum - nodes[i].sum + nodes[idx].end - nodes[idx].start; // 누적합을 + 마지막 피크시간의 시간
            }
            else { // 광고시간이 마지막 피크시간 끝나는 시간보다 작을 때
                ans = nodes[idx].sum - nodes[i].sum + nodes[i].start+L - nodes[idx].start; // 누적합을 + 마지막 광고시간 - 마지막 피크시간이 시작하는 시간
            }
            m = max(m, ans);
        }
     
        cout << "#" << test_case << " "<<m << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}