#include<iostream>
#include <queue>
using namespace std;

priority_queue<int> M;
priority_queue<int> m;
long long sum;
int N;
int A;
int x;
int Ms,ms;
int main(int argc, char** argv)

{
    ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> N >> A;
		M.push(A);
		Ms++;
		for (int i = 0; i < N; i++) {
			for (int i = 0; i < 2; i++) {
				cin >> x;
				if (M.top() < x) { m.push(-x); ms++; }
				else { M.push(x); Ms++; }
			}
			if (Ms - ms == 3) { m.push(-M.top()); M.pop(); Ms--; ms++; }
			else if (ms - Ms == 1) { M.push(-m.top()); m.pop(); Ms++; ms--; }
			sum = (sum + M.top()) % 20171109;
		}
		
		cout << "#" << test_case << " " <<sum << '\n';
		sum = 0;
		while (!M.empty()) { M.pop(); }
		while (!m.empty()) { m.pop(); }
		Ms = 0;
		ms = 0;
	

	}
	return 0;
}