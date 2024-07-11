#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int m = 1000000;
    int f = 0, e = 0;
    int sum = sequence[0];
    int ans_x = 0, ans_y = 0;
    
    while(f<=e && f<sequence.size() &&e<sequence.size()){
        if(sum > k){
            sum -= sequence[f];
            f++;
        }
        else{
            if(k == sum){
                if(e-f < m){
                    m = e-f;
                    ans_x = f;
                    ans_y = e;
                }
            }
            e++;
            sum += sequence[e];
        }
    }
    answer.push_back(ans_x);
    answer.push_back(ans_y);
    return answer;
}