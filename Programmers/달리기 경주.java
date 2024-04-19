import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        Map<String, Integer> m = new HashMap<String, Integer>();
        for(int j=0;j<players.length;j++){
                m.put(players[j], j);
            }
        for(int i=0;i<callings.length;i++){
            int rank = m.get(callings[i]);
            
            players[rank] = players[rank-1];
            players[rank-1] = callings[i];
            
            m.put(players[rank], rank);
            m.put(players[rank-1], rank-1);
        }
        return players;
    }
    
    public void swap(String a, String b, String[] players, int j){
    players[j] = b;
    players[j-1] = a;
    }
}