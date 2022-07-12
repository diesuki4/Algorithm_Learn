using System;
using System.Linq;

public class Program
{
	public static void Main(string[] args)
	{
		int n = int.Parse(Console.ReadLine());
		int netSize = int.Parse(Console.ReadLine());
		int[] fishes = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

		Console.WriteLine(fishes.Where((x, i) => i <= n-netSize).Select((x, i) => fishes[i] + fishes[i+1] + fishes[i+2]).Max());
	}
}
