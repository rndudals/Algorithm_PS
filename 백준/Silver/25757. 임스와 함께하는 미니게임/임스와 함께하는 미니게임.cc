#include<iostream>
#include<map>
#include<vector>
using namespace std;


int N;
char game;
map<string, int> m;
vector<string> v;
map<char, int> number;
int ans = 0;

void init(){
    number['Y'] = 2;
    number['F'] = 3;
    number['O'] = 4;
}

void input(){
    init();
    cin >> N >> game;
    for(int i=0;i<N;i++){
        string input;
        cin>> input;
        v.push_back(input);
    }
}

void run(){
    int cnt = 1;
    for(int i=0;i<v.size();i++){
        if(m[v[i]]==0){
            m[v[i]] = 1;
            cnt++;
            if(cnt==number[game]){
                ans++;
                cnt = 1;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    input();
    run();
}