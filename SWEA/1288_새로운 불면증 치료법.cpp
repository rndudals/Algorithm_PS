#include<iostream>
 
using namespace std;

//한글 테스트
int N,tmp;
bool arr[10];
int e = 0;
int cnt;
int main(int argc, char** argv)
{
 
    int test_case;
    int T;
     
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        while (1) {
            cnt++;
            tmp = cnt*N;
            while (tmp != 0) {
                if (arr[tmp % 10] == false) {
                    arr[tmp % 10] = true;
                    e++;
                    if (e == 10) { break; }
                }
                tmp = tmp / 10;
            }
             
            if (e == 10) { break; }
        }
        cout << "#" << test_case << " " << cnt*N << '\n';
        e = 0;
        cnt = 0;
        for (int i = 0; i < 10; i++) {
            arr[i] = false;
        }
 
 
    }
    return 0;
}