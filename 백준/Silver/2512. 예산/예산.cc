#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
vector<int> v;
long long sum;
long long cur_sum;


void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
        cur_sum +=x;
    }
    cin>> sum;

    sort(v.begin(), v.end(), greater<int>());
    
}

void run(){
    int cnt = 0;
    int line = v[0];
    int idx = 0;
    while(cur_sum > sum){
        if(line == v[idx]){
            cnt++;
            idx++;
            line++;
            cur_sum += cnt;
        }
        cur_sum -= cnt;
        line--;
    }
    cout<<line;
}


int main(){
    input();
    run();
}