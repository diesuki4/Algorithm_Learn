using System;
using System.Linq;

public class Program
{
	public static void Main(string[] args)
	{
		int max = 0, index = 1;

		for (int i = 1; i <= 9; ++i)
		{
			int n = int.Parse(Console.ReadLine());

			if (max < n)
			{
				max = n;
				index = i;
			}
		}

		Console.WriteLine(max);
		Console.WriteLine(index);
	}
}
