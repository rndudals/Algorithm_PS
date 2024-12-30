#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int ans = 0;
    
    while (storey != 0) {
        int n = storey % 10;         
        int next = (storey / 10) % 10; 

       
        if (n > 5 || (n == 5 && next >= 5)) {
            ans += (10 - n);
            storey += (10 - n);
        } else {
            ans += n;
        }

        storey /= 10;
    }
    
    return ans;
}
