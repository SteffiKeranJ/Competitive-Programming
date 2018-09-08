import java.util.Scanner;
class CharacterPattern {
	public static void main(String args[]) throws Exception {
		Scanner sc= new Scanner(System.in);
		int T = sc.nextInt(); // number of test cases
		for (int tc = 1; tc <= T; tc++) {
			int r = sc.nextInt(); // number of rows
			int c = sc.nextInt(); // number of columns
			for (int i = 0; i < r; i++) {
				for (int j = 0; j<c; j++) {
					System.out.print((i+j)%2 == 0?"*":".");
				}
				System.out.println();
			}
			System.out.println();
		}
		sc.close();
	}
}
