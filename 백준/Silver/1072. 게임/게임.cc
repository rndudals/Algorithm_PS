#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int x, y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>x>>y;

    // 기존 승률 계산
    long long a = (long long) y * 100 / x;

    // 승률이 이미 99 이상이면, 절대 변하지 않으므로 -1
    if(a >= 99){
        cout << -1 << "\n";
        return 0;
    }

    long long start = x;
    long long diff = x-y;
    long long end = x+1000000000;
    long long mid=0;
    while(start<end){
        mid = (end - start)/2+start;

        long long win = mid - diff;

        long long val = win*100/mid;
        if(a<val){
            end = mid;            
        }
        else{
            start = mid+1;
        }
    }
    if(start > 2000000000){
        cout << -1 << "\n";
    } else {
        cout << (start - x) << "\n";
    }
    return 0;
}
