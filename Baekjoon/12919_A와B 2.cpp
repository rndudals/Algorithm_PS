#include <bits/stdc++.h>
using namespace std;

string A, B;
int ans;

void go(string st) {
	//Á¾·á
	if (st == A) {
		ans = 1;
	}
	if (st.size() < A.size()) return;
	if (st[st.size() - 1] == 'A') {
		st.pop_back();
		go(st);
		st += 'A';
	}

	if (st[0] == 'B') {
		reverse(st.begin(), st.end());
		st.pop_back();
		go(st);
		st += 'B';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string st="";
	cin >> A >> B;
	go(B);
	cout << ans;
	return 0;
}