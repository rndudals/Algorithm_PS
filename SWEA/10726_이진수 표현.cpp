#include<iostream>
using namespace std;

int N, M;
string ans;
int sum=1;

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
std::cout.tie(nullptr);
std::ios_base::sync_with_stdio(false);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			if ((M & ((1 << (i)) - 1))==sum) {
				if (i == N) {
					ans = "ON";
				}
			}
			else {
				ans = "OFF";
				break;
			}
			sum += (1<< i);
		}
		cout << "#" << test_case << " " << ans << '\n';
		sum = 1;
	}
	return 0;
}