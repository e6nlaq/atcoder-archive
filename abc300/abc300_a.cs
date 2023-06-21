/*---------------------------------------------------



	   Welcome to my program!

	　　∧＿∧        @x__0
	　 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	　　＼/　　　　 /  C# .Net 7.0
	　　　　￣￣￣￣￣
		   Let's write Code!


---------------------------------------------------*/

using System;

namespace atcoder
{
	internal class Program
	{
		static void Main()
		{
			int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
			int N = input[0], A = input[1], B = input[2];

			int[] C = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

			for (int i = 0; i < N; i++)
			{
				if (C[i] == A + B)
				{
					Console.WriteLine(i + 1);
					return;
				}
			}
		}
	}
}