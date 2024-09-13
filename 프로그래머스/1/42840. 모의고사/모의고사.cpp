#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr1[5]={1,2,3,4,5};
int arr2[8]={2,1,2,3,2,4,2,5};
int arr3[10]={3,3,1,1,2,2,4,4,5,5};
int score[4];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size1=5, size2=8, size3=10, M=0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == arr1[i%size1]) score[1]++;
        if(answers[i] == arr2[i%size2]) score[2]++;
        if(answers[i] == arr3[i%size3]) score[3]++;
    }
    
    for(int i=1;i<=3;i++) M = max(M, score[i]);
    for(int i=1;i<=3;i++) if(score[i]==M)answer.push_back(i);
    
    return answer;
}