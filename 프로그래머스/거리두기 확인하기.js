let check
let dx = [1, -1, 0, 0]
let dy = [0, 0, -1, 1]

function solution(places) {
    var answer = [];
    for(let T=0;T<places.length;T++){
        check = 1;
       for(let i=0;i<places[T].length;i++){
           for(let j=0;j<places[T].length;j++){
              if(places[T][i][j] === 'P'){
                  let visited = new Array(5).fill(0).map(e => new Array(5).fill(0))
                  dfs(i, j, 0, visited, places, T)
              }
           }
           
       }
        answer.push(check)
    }
    
    return answer;
}

function dfs(x, y, cnt, visited, places, T){
    if(places[T][x][y]==='P' && cnt !==0) {
        check = 0
        return
    }
    if(cnt === 2 ){
        return
    }
    
    visited[x][y] = true
    for(let i=0;i<4;i++){
        let nx = dx[i]+x
        let ny = dy[i]+y
        if(nx<0 || ny<0 || nx>=5 || ny>=5) continue
        if(visited[nx][ny]) continue
        if(places[T][nx][ny]==='X') continue
        
        dfs(nx, ny, cnt+1, visited, places, T)
        
    }
}