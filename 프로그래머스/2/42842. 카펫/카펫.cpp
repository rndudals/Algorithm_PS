#include <string>
#include <vector>

using namespace std;
int yr, yc, br, bc;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=yellow;i++){
        if(yellow%i==0){
            yr=i;
            yc=yellow/yr;
            
            br=yr+1;
            bc=yc+1;
            if(2*br + 2*bc==brown){
                break;
            }
        }
    }
    if(br > bc){swap(br,bc);}
    answer.push_back(bc+1);
    answer.push_back(br+1);
        
    
    
    
    return answer;
}