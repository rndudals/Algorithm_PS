#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int N, x;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if(pq.empty()){
                cout<<"0"<<'\n';
            }else{
                int top = pq.top().first;
                int k = pq.top().second;
                pq.pop();
                cout<<top*k<<'\n';
            }
        }else{
            int k;
            if(x>0){
                k = 1;
            }else{
                k = -1;
            }
            pq.push({abs(x), k});
        }
    }
}
