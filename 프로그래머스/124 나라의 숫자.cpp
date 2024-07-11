#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


string solution(int n) {
    string answer = "";
    int num = n;
    while(num!=0){
        int remain = num%3;
        num = num/3;
        
        if(remain==1){
            answer = "1" + answer;
        }
        else if(remain==2){
            answer = "2" + answer;
        }
        else{
            answer = "4" + answer;
            num--;
        }
       
    }
    return answer;
}