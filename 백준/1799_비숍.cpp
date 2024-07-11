#include<iostream>
#include <map>
#include <queue>
using namespace std;

bool l_visited[50]; // ���ʾƷ��� ���� �밢��
bool r_visited[50]; // ������ �Ʒ��� ���� �밢��
int arr[11][11];
int N;
int ans;
int bishop[2];

void func(int x, int y, int cnt, int color) {
	if (x>N) {
		if (bishop[color] < cnt) { // �ִ� ����
			bishop[color] = cnt;
		}
		return;
	}
	if (y > N) {
		x++;
		if (y % 2 == 1) y = 2; // Ȧ���� ¦���� �ٲ��ֱ�
		else y = 1; // ¦���� Ȧ���� �ٲ��ֱ�
	}
	//���� ���� �� ���� ��
	if (arr[x][y] && !l_visited[x + y] && !r_visited[x - y + 10]) {
		l_visited[x + y] = 1;
		r_visited[x - y + 10] = 1;
		func(x, y+2, cnt+1, color); // ���� ���� ���
		l_visited[x + y] = 0;
		r_visited[x - y + 10] = 0;
	}
	func(x, y+2, cnt, color); // ���� �ȳ��� ���
	// *���� ������ ���� ���� �� ���� ��쵵 ��� �ؾ� ��
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	func(1, 1, 0, 0); // ����
	func(1, 2, 0, 1); // ���

	
	cout << bishop[0] + bishop[1];
	
	return 0;
}