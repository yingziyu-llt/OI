import com.sun.java_cup.internal.runtime.Scanner;
import com.sun.java_cup.internal.runtime.Symbol;

public class fib {
	public fib()
	{
		this.ans = 0;
	}
	public int calc(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		int ans = 0;
		ans = calc(n - 1) + calc(n - 2);
		return ans;
	}
}

public class problem2 {
	public static void main() {
		Scanner input = new Scanner();
		int n = input.next_int();
		fib tmp = new fib();
		int ans = tmp.calc(n);
		System.out.println(ans);
		return ;
	}
}