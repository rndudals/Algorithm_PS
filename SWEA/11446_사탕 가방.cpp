#include<iostream>
using namespace std;
 
long long arr[100];
 
 
long long N, M;
long long p_search() {
    long long low = 1;
    long long high = 1000000000000000001;
    while (low != high) {
        long long mid = low + (high - low) / 2;
        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += arr[i] / mid;
        }
        if (cnt >= M) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
 
    }
    return high-1;
 
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    //freopen("input.txt", "r", stdin);
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
        for (int i = 0; i < N;i++) {
            cin >> arr[i];
        }
        cout << "#" << test_case << " " <<p_search() << '\n';
 
    }
    return 0;
}