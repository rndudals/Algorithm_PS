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
 
int BinarySearch(int end) { // ������ ��ũ�ð��� ��ġ�� ã���ִ� �Լ�
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
            nodes[i+1].sum = nodes[i].sum+nodes[i].end - nodes[i].start; // node[i+1].sum : node[i]������ peek�ð��� ������
        }
        for (int i = 0; i < N; i++) {
            int ans = 0;
            int idx=BinarySearch(nodes[i].start+L);
            if (nodes[i].start + L >= nodes[idx].end) { // ����ð��� ������ ��ũ�ð� ������ �ð����� �� ��
                ans = nodes[idx].sum - nodes[i].sum + nodes[idx].end - nodes[idx].start; // �������� + ������ ��ũ�ð��� �ð�
            }
            else { // ����ð��� ������ ��ũ�ð� ������ �ð����� ���� ��
                ans = nodes[idx].sum - nodes[i].sum + nodes[i].start+L - nodes[idx].start; // �������� + ������ ����ð� - ������ ��ũ�ð��� �����ϴ� �ð�
            }
            m = max(m, ans);
        }
     
        cout << "#" << test_case << " "<<m << '\n';
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}