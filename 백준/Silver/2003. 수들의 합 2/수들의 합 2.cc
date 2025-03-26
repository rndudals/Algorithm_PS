#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int N, M;
int sum[10001];
int arr[10001];
bool visited[10001];
vector<int> v;
int ans = 0;

void run(int idx){
    if(v.size()==2){
        if(sum[v[1]]-sum[v[0]]+arr[v[0]]==M){
            ans++;
        }
        return;
    }

    for(int i=idx+1;i<=N;i++){
        if(!visited[i]){
            v.push_back(i);
            visited[i] = true;
            run(i);
            visited[i] = false;
            v.pop_back();
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        if(arr[i]==M){ // 1개일 때
            ans++;
        }
        sum[i] = sum[i-1]+arr[i];
    }

    // 2개일 때
    run(0);

    
    cout<<ans<<'\n';
}
