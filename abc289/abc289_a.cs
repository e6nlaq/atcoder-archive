/*---------------------------------------------------



	   Welcome to my program!

	縲縲竏ｧ?ｼｿ竏ｧ        @x__0
	縲 ( 縲?ｽ･ﾏ会ｽ･)
	?ｼｿ(__縺､/?ｿ｣?ｿ｣?ｿ｣ /  MIT License
	縲縲?ｼｼ/縲縲縲縲 /  C# .Net 7.0
	縲縲縲縲?ｿ｣?ｿ｣?ｿ｣?ｿ｣?ｿ｣
		   Let's write Code!


---------------------------------------------------*/

using System;

namespace atcoder
{
	internal class Program
	{
		static void Main()
		{
			string? s = Console.ReadLine();
			char[] S = s.ToCharArray();
			for (int i = 0; i < s.Length; i++)
			{
				if (S[i] == '0') S[i] = '1';
				else S[i] = '0';
			}

			Console.WriteLine(S);
		}
	}
}