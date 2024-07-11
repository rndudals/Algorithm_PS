#include <iostream>
#include <queue>
using namespace std;

string st;
int ans = 1000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> st;
	
	int window = 0;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == 'a') window++;
	}

	for (int i = 0; i < st.size(); i++) {
		int b = 0;
		for (int j = i; j < i + window; j++) {
			if (st[j%st.size()] == 'b') b++;
		}
		ans = min(ans, b);
	}
	
	cout << ans;
	return 0;
}
