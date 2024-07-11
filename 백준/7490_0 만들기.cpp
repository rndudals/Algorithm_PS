#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, N;
vector<char> v;

void go(int cnt, int sum) {
	if (cnt == N) {
		if (sum == 0) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << '\n';
		}
		return;
	}
	if (v.size() > 2) {
		int idx = v.size() - 2;
		if (v[idx] == '+') {
			v.push_back(' ');
			v.push_back((cnt + 1) + '0');
			go(cnt + 1, sum - cnt + (cnt * 10 + cnt + 1));
			v.pop_back();
			v.pop_back();
		}
		else if (v[idx] == '-') {
			v.push_back(' ');
			v.push_back((cnt + 1) + '0');
			go(cnt + 1, sum + cnt - (cnt * 10 + cnt + 1));
			v.pop_back();
			v.pop_back();
		}
	}
	else {
		v.push_back(' ');
		v.push_back((cnt + 1) + '0');
		go(cnt + 1, sum - cnt + (cnt * 10 + cnt + 1));
		v.pop_back();
		v.pop_back();
	}
	// +
	if (cnt / 10 == 0) {
		v.push_back('+');
		v.push_back((cnt + 1) + '0');
		go(cnt + 1, sum + cnt + 1);
		v.pop_back();
		v.pop_back();

		// -
		v.push_back('-');
		v.push_back((cnt + 1) + '0');
		go(cnt + 1, sum - (cnt + 1));
		v.pop_back();
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		v.push_back('1');
		go(1, 1);
		v.pop_back();
		cout << '\n';
	}
	return 0;
}
