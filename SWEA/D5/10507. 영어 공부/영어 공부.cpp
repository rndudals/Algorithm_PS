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
		M = p + 1; // 최솟값 설정 n의 최솟값이 1이므로 p+1
		for (int i = 1; i <= n; i++) {
			cin >> x;
			arr[x] = true;
		}
		int start = 1, end = 1;

		while (end < x + 1) { // 배열이 true인 인덱스중 가장 큰값이 x이다.
			if (arr[end] == true) { // 배열이 true이면
				end++; // end를 올려줍니다.
				if (end - start > M) { M = end - start; } // 최댓값 갱신
			}
			else { // 배열이 false 이면
				if (p == 0) { // 해킹을 못할 때
					if (arr[start]==false) { p++; } // 앞에 해킹을 취소합니다.
					start++;
				}
				else { // 해킹 가능할 때
					p--; // 해킹
					end++; // end를 올려줍니다.
					if (end - start > M) { M = end - start; } // 최대값 갱신
				}
			}
		}
		cout << "#" << test_case << ' ' << M << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}