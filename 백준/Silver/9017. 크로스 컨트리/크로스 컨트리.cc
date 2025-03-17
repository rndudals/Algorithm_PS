#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int N;
int arr[1000][2];
int team_cnt[201];  
int score[201][2];     
int f[201];          
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--){
        memset(team_cnt, 0, sizeof(team_cnt));
        memset(score, 0, sizeof(score));
        memset(f, 0, sizeof(f));
        ans = 0;

        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i][0];  
        }

        // 1. 팀별 주자 수 확인 
        for(int i = 0; i < N; i++){
            team_cnt[arr[i][0]]++;
        }

        // 2. 순위 매기기
        int rank = 1;
        for(int i = 0; i < N; i++){
            if(team_cnt[arr[i][0]] == 6){
                arr[i][1] = rank++;
            } else {
                arr[i][1] = 0; 
            }
        }

        // 3. 점수 계산
        for(int i = 0; i < N; i++){
            int t = arr[i][0];
            int r = arr[i][1];
            
            if(team_cnt[t] == 6){
                if(f[t] < 4) {
                    f[t]++;
                    score[t][0] += r; 
                }
               
                else if(f[t] == 4) {
                    score[t][1] = r;  
                    f[t]++;
                }
            }
        }

        // 4. 최소 점수
        int best_score = 987654321;
        for(int i = 1; i <= 200; i++){
            if(team_cnt[i] == 6 && score[i][0] < best_score){
                best_score = score[i][0];
            }
        }

        // 5. 최소 점수를 가진 팀이 몇 개인지 확인
        int cnt = 0;
        for(int i = 1; i <= 200; i++){
            if(team_cnt[i] == 6 && score[i][0] == best_score){
                cnt++;
            }
        }

        // 6. 우승 팀 결정
        if(cnt == 1){
            for(int i = 1; i <= 200; i++){
                if(team_cnt[i] == 6 && score[i][0] == best_score){
                    ans = i;
                    break;
                }
            }
        } else {
            vector<pair<int,int>> v; 
            for(int i = 1; i <= 200; i++){
                if(team_cnt[i] == 6 && score[i][0] == best_score){
                    v.push_back({score[i][1], i});
                }
            }
            sort(v.begin(), v.end()); 
            ans = v[0].second;
        }

        cout << ans << "\n";
    }

    return 0;
}
