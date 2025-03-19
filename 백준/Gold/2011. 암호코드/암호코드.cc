#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string st;
vector<int> v;
int Size;
long long ans;
int dp[5000];

void run(){
    // 0) 첫 글자 해석 불가능 여부 체크
    //    첫 글자가 '0'이면 어떤 해석도 불가
    if(v[0] == 0) {
        dp[0] = 0; 
    } else {
        dp[0] = 1;
    }

    // 1) 두 번째 글자 초기화 (Size>1일 때만)
    if(Size > 1){
        dp[1] = 0;
        // 두 번째 글자 한 자리 해석 가능
        if(v[1] != 0) {
            dp[1] += dp[0];
        }

        // 첫 두 글자가 10~26이면 두 자리 해석도 가능
        int tmp = v[0]*10 + v[1];
        if(tmp >= 10 && tmp <= 26){
            dp[1]++;
        }
    }

    for(int i=2;i<Size;i++){
        dp[i] = 0;
        if(v[i]!=0){
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        }
        
        int temp = v[i-1]*10+v[i];
        if(temp>=10&&temp<=26){
             dp[i] = (dp[i] + dp[i-2]) % 1000000;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>>st;
    Size = st.size();
    for(int i=0;i<Size;i++){
        int x = st[i] -'0';
        v.push_back(x);
    }
    

    run();
    cout<<dp[Size-1]<<'\n';

    return 0;
}
