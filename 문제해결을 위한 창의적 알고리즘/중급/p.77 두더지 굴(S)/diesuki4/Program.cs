using System;
using System.Linq;

public class Program
{
	public static void Main(string[] args)
	{
		int n = int.Parse(Console.ReadLine());
		int[,] arr = new int[n, n];
		List<int> sizes = new List<int>();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i, j] = Console.Read() - '0';
				Console.Read();
			}	
			Console.Read();
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (arr[i, j] == 1)
					sizes.Add(OysterSize(arr, i, j));

		Console.WriteLine(sizes.Count());

		foreach (int size in sizes.OrderByDescending(x => x))
			Console.WriteLine(size);
	}

	public static int OysterSize(int[,] arr, int i, int j)
	{
		int n = arr.GetLength(0);

		if (i < 0 || n <= i || j < 0 || n <= j || arr[i, j] == 0)
			return 0;
		else
			arr[i, j] = 0;

		return 1 + OysterSize(arr, i-1, j) + OysterSize(arr, i+1, j) + OysterSize(arr, i, j-1) + OysterSize(arr, i, j+1);
	}
}
