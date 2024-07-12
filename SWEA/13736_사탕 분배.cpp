#include<iostream>
 
using namespace std;
 
 
unsigned long long A, B, K;
 
unsigned long long power(unsigned long long x, unsigned long long p) {
    if (p == 0)return 1;
    unsigned long long res = power(x, p / 2);
    res = (res*res)%(A+B);
    if (p & 1) res = (res*x)%(A+B); // p가 홀수면 x를 따로 한 번 곱해준다.
    return res%(A+B);
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    //freopen("input.txt", "r", stdin);
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> A >> B >> K;
        unsigned long long a = A*power(2 , K)%(A+B);
        cout << "#" << test_case << " " <<min(a,(A+B)-a) << '\n';
    }
    return 0;
}