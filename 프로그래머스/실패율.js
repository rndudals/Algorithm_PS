function solution(N, stages) {
    var answer = [];
    arr = []
    
    for(let i=1;i<=N;i++){
        let fail=0
        let ent = 0
        for(let j=0;j<stages.length;j++){
            if(stages[j]===i){
                fail++
            }
            if(stages[j] >= i){
                ent++
            }
        }
        arr.push([fail/ent, i])
    }
    arr = arr.sort((a, b)=> b[0]-a[0])
    
    for(let i=0;i<arr.length;i++){
        answer.push(arr[i][1])
    }
    return answer;
}