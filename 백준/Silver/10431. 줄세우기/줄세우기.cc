#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int P, ans, T;
int arr[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>P;
    while(P--){
        ans = 0;
        cin>>T;

        for(int i=0;i<20;i++){
            cin>>arr[i];
        }
        
        for(int i=0;i<20;i++){
            for(int j=i+1;j<20;j++){
                if(arr[i]>arr[j]){
                    ans++;
                }
            }
        }
        cout<<T<<" "<<ans<<'\n';
    }
    return 0;
}
