
import java.util.Scanner;

class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int ans = 0;
		char arr[][] = new char[5][15];

		for (int i = 0; i < 5; i++) {
			String st = sc.next();
			for (int j = 0; j < st.length(); j++) {
				arr[i][j] = st.charAt(j);
			}
		}
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[j][i] != '\u0000') {
					System.out.print(arr[j][i]);
				}
			}
		}
	}
}
