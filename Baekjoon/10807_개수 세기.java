import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int ans = 0;
		
		int N = scanner.nextInt();
		
		int[] arr = new int[N];
		
		for(int i = 0; i < N; i++) {
			arr[i] = scanner.nextInt();
		}
		
		int target = scanner.nextInt();
		
		for(int i = 0 ; i < N ; i++) {
			if(arr[i] == target) {
				ans++;
			}
		}
		
		System.out.println(ans);
	}

}
