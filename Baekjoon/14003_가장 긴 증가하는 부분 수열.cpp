#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int N;
int arr[1000001];
int cnt=1;
int tmp[1000001];
stack<int> s;

vector <pair<int, int >> v;
int binarySearch(int lo, int hi, int target) { // 이분탐색
	while (lo!=hi) {
		int mid = lo + (hi - lo) / 2;
		if (tmp[mid] >= target) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	tmp[0] = arr[0];
	int tmp_idx =0;
	v.push_back({ arr[0], 0 });
	for (int i = 1; i < N; i++) {
		if (tmp[tmp_idx] < arr[i]) { // 다음 배열의 값이 tmp배열의 마지막 보다 클 경우
			tmp_idx++;
			cnt++;
			tmp[tmp_idx] = arr[i]; // tmp 배열에 추가
			v.push_back({ arr[i], tmp_idx});

		}
		else { // 다음 배열의 값이 tmp배열의 마지막 보다 작거나 같을 경우
			int idx = binarySearch(0, tmp_idx, arr[i]); 
			tmp[idx] = arr[i]; // 교체를 해줍니다
			v.push_back({ arr[i], idx });

		}
		
	}
	cout << cnt<<'\n'; // 길이 출력

	int l = tmp_idx;

	for (int i = v.size() - 1; i >= 0; i--) { // v 맨 뒤에서 부터 크기 순서대로 스택에 넣는다.
		if (v[i].second == l) {
			s.push(v[i].first);
			l--;
		}
	}
	while (!s.empty()) { // 스택을 차례로 출력하면 정답
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}