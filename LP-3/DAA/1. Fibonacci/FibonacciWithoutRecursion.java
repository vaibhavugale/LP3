// fibonacci without recursion

class Fibonacci {
	public static void main(String[] args) {
		int n = 8;

		int a = 0;
		int b = 1;

		int i = 1; 

		while(i != n) {
			// System.out.print(a + " ");
			int c = a + b;
			a = b;
			b = c;
			i++;
		}
		System.out.println(a);
	}
}
