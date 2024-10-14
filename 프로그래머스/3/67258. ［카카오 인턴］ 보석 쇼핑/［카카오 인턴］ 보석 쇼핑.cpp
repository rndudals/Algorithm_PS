#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

unordered_map<string, int> m;
unordered_map<string, int> tmp;
vector<int> answer;
int M = INT_MAX;

void update(int cnt, int size, int f, int r){
    if(cnt == size){
        if(M > r - f){
            answer.clear();
            M = r - f;
            answer.push_back(f + 1);
            answer.push_back(r + 1);
        } else if(M == r - f && answer[0] > f + 1){
            answer.clear();
            answer.push_back(f + 1);
            answer.push_back(r + 1);
        }
    }
}

vector<int> solution(vector<string> gems) {
    int size = 0;
    for(auto& e: gems){
        if(m[e] == 0){
            size++;
        }
        m[e]++;
    }

    int f = 0;
    int r = 0;
    int cnt = 0;
    tmp[gems[0]]++;
    cnt = 1;
    answer.push_back(1);
    answer.push_back(gems.size());

    while(f <= r){
        update(cnt, size, f, r);

        if(cnt == size){
            tmp[gems[f]]--;
            if(tmp[gems[f]] == 0){
                cnt--;
            }
            f++;
        } else {
            r++;
            if(r == gems.size()) break;
            tmp[gems[r]]++;
            if(tmp[gems[r]] == 1){
                cnt++;
            }
        }
    }
    return answer;
}
