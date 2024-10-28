#include <string>
#include <vector>
#include <iostream>
using namespace std;


pair<int, int> arr[1000000];

void init(vector<int> a){
    
    for(int i=0;i<1000000;i++){
        arr[i].first=1000000000;
        arr[i].second=1000000000;
    }
    
    arr[0].first = a[0];
    int m_a=a[0];
    for(int i=0;i<a.size()-1;i++){
        
        if(m_a>a[i]){
            m_a=a[i];
        }
        arr[i+1].first = m_a;
    }
    
    int size = a.size();
    arr[size-1].first = a[size-1];
    int m_b=a[size-1];
    for(int i=size-1;i>0;i--){
        if(m_b>a[i]){
            m_b=a[i];
        }
        arr[i-1].second = m_b;
    }
}

int solution(vector<int> a) {
    int answer = 0;
    init(a);
    
    for(int i=0;i<a.size();i++){
        if(i==0 || i == (a.size()-1)){
            answer++;
        }else{
            if(!(arr[i].first<a[i] && arr[i].second<a[i])){
                answer++;
            }
        }
    }
    return answer;
}