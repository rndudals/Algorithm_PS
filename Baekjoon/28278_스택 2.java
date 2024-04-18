import java.util.*;

class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		Stack<Integer> s = new Stack<Integer>();

		int x, y, n;
		n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			x = sc.nextInt();
			if (x == 1) {
				y = sc.nextInt();
				s.add(y);
			} else if (x == 2) {
				if (s.empty()) {
					sb.append(-1).append('\n');
				} else {
					sb.append(s.peek()).append('\n');
					s.pop();
				}

			} else if (x == 3) {
				sb.append(s.size()).append('\n');
			} else if (x == 4) {
				if (s.empty()) {
					sb.append(1).append('\n');
				} else {
					sb.append(0).append('\n');
				}
			} else if (x == 5) {
				if (s.empty()) {
					sb.append(-1).append('\n');
				} else {
					sb.append(s.peek()).append('\n');
				}
			}
		}

		System.out.println(sb);
	}
}
