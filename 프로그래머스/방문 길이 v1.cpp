#include <string>
#include <iostream>
using namespace std;

int map[11][11];

bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int x=5, y=5;
    
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            if(x-1>=0){
                if(!visited[x][y][x-1][y]){
                    visited[x][y][x-1][y] = 1;
                    visited[x-1][y][x][y] = 1;
                    answer++;
                }
                x=x-1;
            }
        }
        else if(dirs[i]=='L'){
            if(y-1>=0){
                if(!visited[x][y][x][y-1]){
                    visited[x][y][x][y-1] = 1;
                    visited[x][y-1][x][y] = 1;
                    answer++;
                }
                y=y-1;
            }
        }
        else if(dirs[i]=='R'){
            if(y+1<=10){
                if(!visited[x][y][x][y+1]){
                    visited[x][y][x][y+1] = 1;
                    visited[x][y+1][x][y] = 1;
                    answer++;
                }
                y=y+1;
            }
        }
        else if(dirs[i]=='D'){
            if(x+1<=10){
                if(!visited[x][y][x+1][y]){
                    visited[x][y][x+1][y] = 1;
                    visited[x+1][y][x][y] = 1;
                    answer++;
                }
                x=x+1;
            }
        }
    }
    return answer;
}