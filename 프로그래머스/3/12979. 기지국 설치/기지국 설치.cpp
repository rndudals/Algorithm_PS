#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> emp;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int size = stations.size();
    int camera = 2*w+1;
    
    for(int i=0;i<size;i++){
        v.push_back({stations[i]-w, stations[i]+w});
    }

    if(v[0].first>1){
        emp.push_back({1, v[0].first-1});
    }
    
    for(int i=0;i<size-1;i++){
        emp.push_back({v[i].second+1, v[i+1].first-1});
    }
    
    if(v[size-1].second<n){
        emp.push_back({v[stations.size()-1].second+1, n});
    }
    
    
    vector<int> emp2;
    for(int i=0;i<emp.size();i++){
        int t = emp[i].second - emp[i].first + 1;
        
        int a = t/camera;
        int b = t%camera;
        if(b>0){
            answer+=1;
        }
        answer+=a;
    }
    
    return answer;
}