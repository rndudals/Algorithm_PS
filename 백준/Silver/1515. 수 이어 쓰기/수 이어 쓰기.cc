#include<iostream>
using namespace std;


string st;
int N;

int main(){
    cin>>st;

    int ptr = 0;
    while(1){
        N++;
        string st_N = to_string(N);
        for(int j=0;j<st_N.size();j++){
            if(st_N[j]== st[ptr]){
                ptr++;
            }
            if(ptr==st.size()){
                cout<<N<<'\n';
                return 0;
            }
        }
    }
}