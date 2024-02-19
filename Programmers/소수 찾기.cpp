#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
set<int> s;
bool visited[7];
string st;

void func(string numbers, int size, int cur_size){
    if(size==cur_size){return;}
    for(int i=0;i<numbers.size();i++){
        if(!visited[i]){
            visited[i]=true;
            st+=numbers[i];
            s.insert(stoi(st));
            
            func(numbers, size, cur_size+1);
            
            visited[i]=false;
            string tmp=st; st="";
            for(int i=0;i<tmp.size()-1;i++){
                st+=tmp[i];
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    for(int i=1;i<=numbers.size();i++){
        st="";
        func(numbers, i , 0);
    }
    for(auto x : s){
        int cnt=0;
        for(int i=2;i<=x;i++){
            if(x%i==0){
                cnt++;
            }
        }
        if(cnt==1){answer++;}
    }
    return answer;
}