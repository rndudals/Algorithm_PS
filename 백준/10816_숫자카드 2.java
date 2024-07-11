import java.util.*;

class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();

		int arr[] = new int[500000];

		int N = sc.nextInt();

		for (int i = 0; i < N; i++) {
			int x = sc.nextInt();
			if (m.containsKey(x)) {
				int cnt = m.get(x);
				m.put(x, cnt + 1);
			} else {
				m.put(x, 1);
			}
		}

		int M = sc.nextInt();
		for (int i = 0; i < M; i++) {
			int x = sc.nextInt();
			if (m.get(x) == null) {
				sb.append(0).append(' ');
			} else {
				sb.append(m.get(x)).append(' ');
			}
		}

		System.out.println(sb);
	}
}
