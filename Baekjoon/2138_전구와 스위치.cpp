#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAX 987654321
using namespace std;


int N;

string target;
int ans = MAX;
int cnt = 0;

void change(int i, string& st) {
	cnt++;

	if (i - 1 >= 0) {
		if (st[i-1] == '1') { st[i-1] = '0'; }
		else { st[i-1] = '1'; }
	}

	if (st[i] == '1') { st[i] = '0'; }
	else { st[i] = '1'; }
	
	if (i + 1 < N) {
		if (st[i + 1] == '1') { st[i + 1] = '0'; }
		else { st[i + 1] = '1'; }
	}
}
void run(string st, int start) {
	cnt = 0;

	if (start == 1) {
		change(0, st);
	}

	for (int i = 1; i < N; i++) {
		if (st[i - 1] != target[i - 1]) {
			change(i, st);
		}
		if (st == target) {
			ans = min(cnt, ans);
			break;
		}
	}

	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string st;

	cin >> N;
	cin >> st;
	cin >> target;
	
	run(st, 0);
	run(st, 1);

	if (ans != MAX) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}
