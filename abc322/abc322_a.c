/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

	　　∧＿∧        AtCoder / Codeforces
	　 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	　　＼/　　　　 /  C++ GCC 11.4.0
	　　　　￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>

#pragma GCC optimize("O3")

int main()
{
	int N;
	char S[101];
	scanf("%ld\n%s", &N, &S);

	for (int i = 0; i < N - 2; ++i)
	{
		if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C')
		{
			printf("%d", i + 1);
			return 0;
		}
	}

	printf("-1");

	return 0;
}
