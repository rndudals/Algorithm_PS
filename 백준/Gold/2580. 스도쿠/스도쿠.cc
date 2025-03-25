#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int arr[9][9];
bool visited[9][9];

vector<pair<int,int>> empties;

void input(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){
                empties.push_back({i, j});
            }
        }
    }
}

bool checkRec(int x, int y, int k){
    int sx = (x/3)*3;
    int sy = (y/3)*3;
    int x_val = x%3;
    int y_val = y%3;

    arr[x][y] = k;
    

    bool check[10] = {0, };
    bool a = true;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(arr[i][j]==0) continue;
            if(!check[arr[i][j]]){
                check[arr[i][j]] = true;
            }else{
                a=false;
            }
        }
    }
    arr[x][y] = 0;

    return a;
}

bool checkRowCol(int x, int y, int k){
    bool checkRow[10] = {0, };
    bool a = true;
    arr[x][y] = k;
    for(int i=0;i<9;i++){
        if(arr[i][y]==0) continue;
        if(!checkRow[arr[i][y]]){
            checkRow[arr[i][y]] = true;
        }else{
            a=false;
        }
    }

    bool checkCol[10] = {0, };
    bool b = true;
    for(int j=0;j<9;j++){
        if(arr[x][j]==0) continue;
        if(!checkCol[arr[x][j]]){
            checkCol[arr[x][j]] = true;
        }else{
            b=false;
        }
    }
    arr[x][y] = 0;
    return a&&b;
}

void printArr(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void run(int idx){

    if(idx == empties.size()){
        printArr();
        exit(0); 
    }
    
    int x = empties[idx].first;
    int y = empties[idx].second;

    for(int k=1; k<=9; k++){
        if(!checkRec(x, y, k)) continue;
        if(!checkRowCol(x, y, k)) continue;

        arr[x][y] = k;
        run(idx+1);
        arr[x][y] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    run(0);
}
