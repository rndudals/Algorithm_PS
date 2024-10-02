#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(auto a: clothes){
        m[a[1]]++;
    }
    for(auto a:m){
        answer *= (a.second + 1);
    }
    return answer - 1;
}