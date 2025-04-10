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


string st;
int zero, one;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='0'){
            zero++;
        }else{
            one++;
        }
    }
    one = one/2;
    zero = zero/2;
    
    string ans = "";
    while(zero--){
        ans+='0';
    }

    while(one--){
        ans+='1';
    }
    cout<<ans<<'\n';
    return 0;
}
