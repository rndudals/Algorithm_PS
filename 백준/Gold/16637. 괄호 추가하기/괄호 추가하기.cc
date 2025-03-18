#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
vector<int> v;
vector<char> oper;
string input;
vector<int> sel;
bool visited[11];
long long ans = -1000000000000000000;

long long calculate(int a, char op, int b){
    int ret;
    if(op=='+'){
        ret = a+b;
    }
    if(op=='-'){
        ret = a-b;
    }
    if(op=='*'){
        ret = a*b;
    }
    return ret;
}

void calculateAnswer(){
    vector<int> tmp_v;
    vector<char> tmp_oper;
    tmp_v.push_back(v[0]);
    for(int i=0;i<oper.size();i++){
        if(visited[i]){
            long long lastVal = tmp_v.back();
            tmp_v.pop_back();
            long long val = calculate(lastVal, oper[i], v[i+1]);
            tmp_v.push_back(val);
        }else{
            tmp_v.push_back(v[i+1]);
            tmp_oper.push_back(oper[i]);
        }
    }
    long long tmp = tmp_v[0];
    for(int i=0;i<tmp_oper.size();i++){
        tmp = calculate(tmp, tmp_oper[i],tmp_v[i+1]);
    }
    
    
    ans = max(tmp, ans);
}

void run(int idx){
    if(idx>=oper.size()){
        calculateAnswer();
        return;
    }

    // 치지 않았을 때
    run(idx+1);

    // 괄호를 쳤을 때
    visited[idx] = true;
    run(idx+2);
    visited[idx] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    cin>>input;

    for(int i=0;i<input.size();i++){
        if(i%2==0){ // 숫자
            v.push_back(input[i]-'0');
        }else{
            oper.push_back(input[i]);
        }
    }

    run(0);

    cout<<ans<<'\n';
    return 0;
}
