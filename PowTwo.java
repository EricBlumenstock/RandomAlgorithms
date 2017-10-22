import java.util.Scanner;

public class PowTwo
{
	public static void main(String args[])
	{
		Scanner kb = new Scanner(System.in);
		double x = kb.nextDouble();
		int num = kb.nextInt();
		System.out.println(pow(x, num));
	}
	public static double pow(double x, int n)
	{
		if(n == 0)
		return 0;
		else if (n == 1)
		return x;
		else if (x == 1)
		return x;
		else
		{
			return(pow(x, n/2) * pow(x, (n+1)/2));
		}
	}
}