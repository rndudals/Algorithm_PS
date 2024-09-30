#include<iostream>
#include<vector>
using namespace std;

int N, T;
vector<int> v;
vector<pair<int, int>> student;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cin>>T;
    for(int i=0;i<T;i++){
        int a, b;
        cin>>a >> b;
        student.push_back({a, b});
    }
}

void clickSwitch(int idx){
    v[idx] = ((v[idx]==1) ? 0:1);
}

void boy(int idx){
    for(int i=idx-1;i<N;i=i+idx){
        clickSwitch(i);
    }
}

void girl(int idx){
    clickSwitch(idx-1);
    for(int i=1;i<N;i++){
        int l = idx - 1 - i;
        int r = idx - 1 + i;
        if(l<0 || r>=N) continue;
        if(v[l]==v[r]){
            clickSwitch(l);
            clickSwitch(r);
        }
        else{
            break;
        }
    }
}


void run(){
    for(int i=0;i<T;i++){
        if(student[i].first==1){
            boy(student[i].second);
        }
        else{
            girl(student[i].second);
        }
        
    }
}

void printAnswer(){
    int cnt = 0;
    for(int num:v){   
        cnt++;
        cout<<num<<" ";
        if(cnt==20){
            cout<<'\n';
            cnt=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    run();
    printAnswer();
}