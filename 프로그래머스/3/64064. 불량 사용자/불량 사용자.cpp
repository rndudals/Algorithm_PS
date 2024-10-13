#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool b_visited[8];
bool u_visited[8];
int answer = 0;
vector<string> ans_v[10000];
int ans_v_size = -1;
vector<string> tmp;


bool checking(string st, string target){
    if(st.size()!=target.size()) return false;
    
    bool ret = true;
    for(int i=0;i<st.size();i++){
        if(target[i]!='*'){
            if(st[i]!=target[i]){
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int finding(string st, vector<string> banned_id){
    for(int i=0;i<banned_id.size();i++){
        if(checking(st, banned_id[i]) && !b_visited[i]){
            return i;
        }
    }
    return -1;
}

bool checkingDuplicate(){
    ans_v_size++;
    vector<string> sorted_v;
    for(int i=0;i<tmp.size();i++){
        sorted_v.push_back(tmp[i]);
    }
    sort(sorted_v.begin(), sorted_v.end());

    for(int i=0;i<=ans_v_size;i++){
        if(ans_v[i]==sorted_v){
            return false;
        }
    }
    ans_v[ans_v_size]=sorted_v;
    return true;
}

void printing(vector<string> banned_id){
    for(int i=0;i<banned_id.size();i++){
        if(checking(tmp[i], banned_id[i])==false){
            return ;
        }
    }
    if(checkingDuplicate()){
        answer++;
    }
}

void run(int cnt, vector<string> user_id, vector<string> banned_id){
    if(cnt==banned_id.size()){
        printing(banned_id);
        return;
    }
    for(int i=0;i<user_id.size();i++){
        if(!u_visited[i]){
            int findIdx = finding(user_id[i], banned_id);
            if(findIdx !=-1){
                b_visited[findIdx] = true;
                u_visited[i]=true;
                tmp.push_back(user_id[i]);
                run(cnt+1, user_id, banned_id);
                tmp.pop_back();
                u_visited[i]=false;
                b_visited[findIdx] = false;
            };
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    
    run(0, user_id, banned_id); // cnt
    return answer;
}