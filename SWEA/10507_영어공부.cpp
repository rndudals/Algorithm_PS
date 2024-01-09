#include<iostream>
#include<cstring>
 
using namespace std;
 
bool arr[1000001];
 
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
        memset(arr, 0, sizeof(arr));
        int n = 0, p = 0;
        int M = 0;
        int x = 0;
        cin >> n >> p;
        M = p + 1; // �ּڰ� ���� n�� �ּڰ��� 1�̹Ƿ� p+1
        for (int i = 1; i <= n; i++) {
            cin >> x;
            arr[x] = true;
        }
        int start = 1, end = 1;
 
        while (end < x + 1) { // �迭�� true�� �ε����� ���� ū���� x�̴�.
            if (arr[end] == true) { // �迭�� true�̸�
                end++; // end�� �÷��ݴϴ�.
                if (end - start > M) { M = end - start; } // �ִ� ����
            }
            else { // �迭�� false �̸�
                if (p == 0) { // ��ŷ�� ���� ��
                    if (arr[start]==false) { p++; } // �տ� ��ŷ�� ����մϴ�.
                    start++; // arr[start]==true�϶� start�� �ø��ϴ�.
                }
                else { // ��ŷ ������ ��
                    p--; // ��ŷ
                    end++; // end�� �÷��ݴϴ�.
                    if (end - start > M) { M = end - start; } // �ִ밪 ����
                }
            }
        }
        cout << "#" << test_case << ' ' << M << '\n';
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}