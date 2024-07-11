#include<iostream>
#include <unordered_set>
 
using namespace std;
 
int N, M;
unordered_set<string>s;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string x;
            cin >> x;
            s.insert(x);
        }
        for (int i = 0; i < M; i++) {
            string x;
            cin >> x;
            s.insert(x);
        }
        cout << "#" << test_case <<' '<< M + N - s.size() << '\n';
        s.clear();
 
 
    }
    return 0;
}