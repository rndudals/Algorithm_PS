#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans =0 ;
void dfs(vector<int> & numbers, int & target, int idx, int sum){
    if(idx==numbers.size()-1){
        if(sum==target){
            ans++;
        }
        return ;
    }
    dfs(numbers, target, idx+1, sum + numbers[idx+1]);
    dfs(numbers, target, idx+1, sum - numbers[idx+1]);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, -1, 0);
    answer = ans;
    return answer;
}