#include<iostream>
#include<vector>
using namespace std;


int N, X;
vector<int> v;

void input(){
    cin>>N>>X;
    for(int i=0;i<N;i++){
        int tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
}

int init(){
    int sum = 0;
    for(int i=0;i<X;i++){
        sum+=v[i];
    }
    return sum;
}

pair<int, int> run(int sum){
    int m = sum;
    int cnt = 1;
    for(int i=X;i<N;i++){
        sum+=v[i];
        sum-=v[i-X];
        if(m < sum){
            m = sum;
            cnt = 1;
        }else if(m == sum){
            cnt++;
        }
    }
    return {cnt, m};
}

void printAnswer(int cnt, int m){
    if(m==0){
        cout<<"SAD"<<'\n';
    }else{
        cout<<m<<'\n';
        cout<<cnt<<'\n';
    }  
}
int main(){
    input();
    
    int sum = init();
    
    pair<int, int> p =run(sum);
    
    printAnswer(p.first, p.second);
}