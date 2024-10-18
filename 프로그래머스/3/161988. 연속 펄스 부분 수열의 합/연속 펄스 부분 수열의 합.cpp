#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long pulse1[500000];
long long pulse2[500000];

long long dp1[500000];
long long dp2[500000];


void init(int size, vector<int> sequence){
    int start = 1;
    for(int i=0;i<size;i++){
        pulse1[i] = start*sequence[i];
        pulse2[i] = -start*sequence[i];
        start *= -1;
    }
}

long long findMax(int size){
    long long ret = -50000000000;
    
    for(int i=0;i<size;i++){
        ret = max(ret, dp1[i]);
    }
    
    for(int i=0;i<size;i++){
        ret = max(ret, dp2[i]);
    }
    return ret;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    int size = sequence.size();
    init(size, sequence);
    
    dp1[0] = pulse1[0];
    dp2[0] = pulse2[0];
    for(int i=1;i<size;i++){
        dp1[i] = max(dp1[i-1]+pulse1[i], pulse1[i]);
        dp2[i] = max(dp2[i-1]+pulse2[i], pulse2[i]);
    }
    
    answer = findMax(size);
    return answer;
}