import java.util.Scanner;

public class Fib
{
	public static void main(String args[])
	{
		Scanner kb = new Scanner(System.in);
		int num = kb.nextInt();
		System.out.println(fib(num));
	}
	public static int fib(int n)
	{
		if(n == 0)
		return 0;
		else if (n == 1)
		return 1;
		else
		{
			return(fib(n-1) + fib(n-2));
		}
	}
}