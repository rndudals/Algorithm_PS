#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
vector<string> v;

bool compare(string a, string b){
    return a+b>b+a;
}


string solution(vector<int> numbers) {
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), compare);
    
    string answer = "";
    
    if(v[0]=="0") return "0";
    for(auto x:v){
        answer+=x;
    }
    
    return answer;
}