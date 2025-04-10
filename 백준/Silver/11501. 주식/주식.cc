#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <math.h>
#include <unordered_map>
#include <sstream>
using namespace std;

int T, N;
int arr[1000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> T;
    while(T--){
        cin>>N;
        long long ans = 0;
        memset(arr, 0, sizeof(arr));

        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        int value = arr[N-1];
        for(int i=N-2;i>=0;i--){
            if(arr[i]<value){
                ans+=(value-arr[i]);
            }else if(arr[i]>value){
                value = arr[i];
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
