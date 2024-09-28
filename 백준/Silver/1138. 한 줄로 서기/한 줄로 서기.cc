#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> v;
vector<int> ans;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
}

void printAnswer(){
    for(int num:ans){   
        cout<<num<<" ";
    }
}

void run(){
    ans.push_back(v.size());
    for(int i=v.size()-2 ;i>=0 ;i--){
        auto it = ans.begin() + v[i];
        ans.insert(it, i+1);
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    run();
    printAnswer();
}