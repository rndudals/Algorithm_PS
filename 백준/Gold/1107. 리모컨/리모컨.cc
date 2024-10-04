#include<iostream>
#include<vector>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int N, M;
map<int, int> no;
vector<int> v;
int ans = 2000000000;

void init(){
    ans = min(ans, abs(N-100));

    for(int i=0;i<10;i++){
        if(no[i]!=1){
            v.push_back(i);
        }
    }
}

void input(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x;
        cin >> x;
        no[x]++;
    }
    init();
}


void printAnswer(){
   cout<<ans<<'\n';
    
}



void run(int n){
    if(n>1000000){return;}
    int n_size = to_string(n).size();
    ans = min(ans, abs(N-n) + n_size);
    for(int i=0;i<v.size();i++){
        run(10*n+v[i]);
    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            run(v[i]);
        }
        else{
            ans = min(ans, N+1);
        }
    }
    printAnswer();
}