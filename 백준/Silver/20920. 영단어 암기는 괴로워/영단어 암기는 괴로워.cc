#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


int N, len;
map<string, int> m;
vector<string> v;
map<char, int> number;


void makeVector(){
    for(auto & element : m){
        v.push_back(element.first);
    }
}

void input(){
    cin >> N >> len;
    for(int i=0;i<N;i++){
        string input;
        cin>> input;
        if(len<=input.size()){
            m[input]++;
        }
    }
    makeVector();
}

bool compare(string &a, string& b){
    if(m[b]==m[a]){
        if(a.size()==b.size()){
            return a < b;
        }
        else{
            return a.size() > b.size();
        }
    }
    else{
        return m[a] > m[b];
    }
}

void sortVector(){
    sort(v.begin(), v.end(), compare);
}

void printAnswer(){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
    }
}

void run(){
    sortVector();
    printAnswer();
}

int main(){
    input();
    run();
}