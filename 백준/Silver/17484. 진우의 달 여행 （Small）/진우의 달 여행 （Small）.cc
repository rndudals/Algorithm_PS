#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, ans=600;
int map[6][6];

int dy[3] = {-1, 0, 1};

void run(int idx, int dir, int depth, int sum){
    if(depth==N-1) {
        ans = min(ans, sum);
        return;
    }

    for(int i=0;i<M;i++){
        int next_dir;
        int next_idx = i;

        if(idx-i==1) next_dir = 0;
        if(idx-i==0) next_dir = 1;
        if(idx-i==-1) next_dir = 2;

        if(abs(idx-i)<=1 && next_dir!=dir){
            run(i, next_dir, depth+1, sum+map[depth+1][i]);
        }    
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<M;i++){
        run(i, 3, 0, map[0][i]);
    }
    
    

    cout<<ans<<'\n';
    return 0;
}
