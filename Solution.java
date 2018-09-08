import java.util.Scanner;
public class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt(); // number of test cases
		for (int tc = 1; tc <= T; tc++) {
			String s = sc.next();
			String p = s.substring(0, s.length()/2);
			for (int i = 0; i<s.length()/2;) {
				System.out.print(p.charAt(i));
				i=i+2;
			}
			System.out.println();
		}
		sc.close();
	}
}
