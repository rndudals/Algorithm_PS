#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;

class K{
public:
    int a;
    int b;
};

K arr[46];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin>>K;

    arr[0] = {1,0};
    for(int i=1;i<=K;i++){
        arr[i].a = arr[i-1].a;
        arr[i].b = arr[i-1].b;

        int a = arr[i-1].a;
        int b = arr[i-1].b;

        while(a--){
            arr[i].a--;
            arr[i].b++;
        }

        while(b--){
            arr[i].a++;
        }
    }
    cout<<arr[K].a<<" "<<arr[K].b<<'\n';
    return 0;
}
