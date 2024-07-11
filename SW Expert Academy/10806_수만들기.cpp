#include<iostream>
#include <queue>
using namespace std;
 
int K;
int N;
int num[10];
 
int run(int cnt, int k) {
    priority_queue<pair<int, int>>pq;
    pq.push({ cnt,k });
    while (pq.top().second) {
        int first = -pq.top().first;
        int second = pq.top().second;
        pq.pop();
 
        for (int i = 0; i < N; i++) {
            pq.push({ -(first + second % num[i]), second / num[i] });
        }
    }
    return -pq.top().first;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        cin >> K;
        cout << "#" << test_case << " "<<run(0,K) << '\n';
 
    }
    return 0;
}