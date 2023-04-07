using System;

class Program
{
    static void Main(string[] args)
    {
        // 整数の入力
        int n = int.Parse(Console.ReadLine());

        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans = ans * 2;
        }

        Console.WriteLine(ans);

    }
}