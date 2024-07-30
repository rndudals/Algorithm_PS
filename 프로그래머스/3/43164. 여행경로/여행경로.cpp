#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool visited[10000];
int on;

void func(string start, int cnt, vector<vector<string>> tickets){
    answer.push_back(start);
    if(cnt==tickets.size()){
        on=1;
        return;
    }
    
    for(int i=0;i<tickets.size() ;i++){
        if(!visited[i] && tickets[i][0]==start){
            visited[i]=true;
            func(tickets[i][1] ,cnt+1, tickets);
            if(on==0){
                answer.pop_back();
                visited[i]=false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    func("ICN", 0, tickets);
   
    return answer;
}