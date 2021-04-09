import com.sun.java_cup.internal.runtime.Scanner;

public class problem1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.next_int();
		int cnt = 1, ans = 0, datecnt = 0;
		for (int i = 0; i < n; i++) {
			datecnt++;
			ans += cnt;
			if (datecnt == cnt) {
				datecnt = 0;
				cnt++;
			}	
		}
		System.out.println(ans);
		return ;
	}
}