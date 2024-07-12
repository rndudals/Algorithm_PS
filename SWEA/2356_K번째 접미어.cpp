#include<iostream>
#include <set>
using namespace std;
 
set<string>s;
set<string>::iterator it;
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
        int K = 0;
        string st, tmp = "";
        cin >> K;
        cin >> st;
        int size = st.size();
        for (int i = size-1; i >= 0; i--) {
            tmp = st[i] + tmp;
            s.insert(tmp);
        }
 
        it = s.begin();
        for (int i = 0; i < K-1; i++) { it++; }
 
        cout << "#" << test_case <<" "<<*it  << '\n';
 
        s.clear();
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}