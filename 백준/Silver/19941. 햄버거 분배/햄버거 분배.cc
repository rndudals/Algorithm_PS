#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, ans;
string st;
bool visited[20000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    cin>>st;

    for(int i=0;i<st.size();i++){
        if(st[i]=='P'){
            for(int j=-K;j<=K;j++){
                if(st[i+j]=='H' && !visited[i+j]){
                    visited[i+j]=true;
                    ans++;
                    break;
                }
                
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
