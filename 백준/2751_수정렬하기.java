import java.util.*;

class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		ArrayList <Integer> list = new ArrayList<>();
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			list.add(sc.nextInt());
		}
		
		Collections.sort(list);
		
		for(int ans : list) {
			sb.append(ans).append("\n");
		}
		System.out.println(sb);
	}
}
