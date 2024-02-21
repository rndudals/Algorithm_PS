#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int w=0, h=0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<sizes[i][1]){
            swap(sizes[i][0], sizes[i][1]);
        }
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]);
    }
    return w*h;
}