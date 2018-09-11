import java.util.Scanner;
public class Fctrl {

	public static void main (String args[]) throws Exception {
		int T; // number of test cases
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc<=T; tc++) {
			int count = 0;
			int n = sc.nextInt();
			while(n>=5) {
				count +=n/5;
				n/=5;
			}
			System.out.println(count);
		}
		sc.close();
	}
}
