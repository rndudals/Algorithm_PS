#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int N, M, B;
int arr[500][500];
int ans_time = 987654321;
int ans_len;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    for(int len=0;len<=256;len++){
        int inven = B;
        int time = 0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] < len){
                    time = time + (len - arr[i][j]);
                    inven = inven - (len - arr[i][j]);
                }else if(arr[i][j] > len){
                    time = time + 2*(arr[i][j] - len);
                    inven = inven + (arr[i][j] - len);
                }
            }
        }
        if(inven < 0) continue;
        if(ans_time>=time){
            ans_time = time;
            ans_len = len;
        }
    }
    cout<<ans_time<<" "<<ans_len<<'\n';
}
