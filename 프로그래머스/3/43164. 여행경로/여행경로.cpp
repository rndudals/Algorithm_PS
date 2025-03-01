#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector<string> answer;
bool visited[10001];
int on = 0;

void run(string start, int cnt, vector<vector<string>> tickets){
    answer.push_back(start);
    if(cnt == tickets.size()){
        on = 1;
        return ;
    }
    for(int i=0;i<tickets.size();i++){
        if(!visited[i] && tickets[i][0] == start){
            visited[i] = true;
            run(tickets[i][1], cnt+1, tickets);
            if(on==0){
                answer.pop_back();
                visited[i] = false;
            }
        }
        
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    
    run("ICN", 0, tickets);
    
    return answer;
}