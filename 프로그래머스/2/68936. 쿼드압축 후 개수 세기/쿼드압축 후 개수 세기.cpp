#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a, b;

bool check(int size, vector<vector<int>> &arr, int x, int y){
    int cnt = 0;
    int k = arr[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(k==arr[i][j]){
                cnt++;
            }
        }
    }
    if(cnt==(size*size)){
        return true;
    }else{
        return false;
    }
}

void countAnswer(vector<vector<int>> &arr, int x, int y){
    if(arr[x][y]==1){
        b++;
    }
    else{
        a++;
    }
}

void func(int size, vector<vector<int>> &arr, int x, int y){
    // 종료 조건
    if(size==1){
        countAnswer(arr, x, y);
        return ;
    }
    
    if(check(size, arr, x, y)){
        countAnswer(arr, x, y);
    }
    else{
        func(size/2, arr, x, y);
        func(size/2, arr, x, y+size/2);
        func(size/2, arr, x+size/2, y);
        func(size/2, arr, x+size/2, y+size/2);
    }
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    func(arr.size(), arr, 0, 0);
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}