#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;


int n;
map<string, int> m;
set<string> s;
stack<string> sta;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++){
        string st1;
        string st2;
        cin>>st1>>st2;

        if(st2=="enter"){
            m[st1] = 1;
        }else{
            m[st1] = 0;
        }
    }
    for(auto e: m){
        if(e.second==1){
            s.insert(e.first);
        }
    }
    
    for(auto e:s){
        sta.push(e);
    }
    while(!sta.empty()){
        cout<<sta.top()<<'\n';
        sta.pop();
    }
}
