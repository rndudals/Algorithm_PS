#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int N;
int M;
vector<int> input;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 가장 긴 길이 찾기
    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }

    // 양 끝 예외처리
    v.push_back(abs(0-input[0]));
    for(int i=0;i<input.size()-1;i++){
        int val = input[i+1]-input[i];
        v.push_back((val%2==1)?(val/2+1):val/2);
    }
    v.push_back(abs((N)-input[input.size()-1]));

    int m=0;
    for(int i=0;i<v.size();i++){
        m = max(m, v[i]);
    }
    cout<<m<<'\n';

    return 0;
}
