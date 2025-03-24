#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int N;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>> N;
    string st;
    string input;
    cin>>st;
    map<int, int> a;
    for(int i=0;i<st.size();i++){
        a[st[i]-'A']++;
    }
    for(int i=0;i<N-1;i++){
        cin>>input;
        map<int, int> b;
        map<int, int> tmp;
        for(int j=0;j<input.size();j++){
            b[input[j]-'A']++;
        }
        
        int need = 0;
        int give = 0;
        for(int i=0;i<26;i++){
            tmp[i] = a[i] - b[i];
            if(a[i]>b[i]){
                need += (a[i] - b[i]);
            }else if(a[i]<b[i]){
                give += (b[i] - a[i]);
            }
        }
        
        if(abs(give) >1 || abs(need) >1) continue;;
        ans++;
    }
    cout<<ans<<'\n';
}
