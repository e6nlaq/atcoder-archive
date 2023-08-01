#include <stdio.h>
#include <stdbool.h>

#define swap(type, a, b) ({ \
	type tmp = (a);         \
	(a) = (b);              \
	(b) = (tmp);            \
})

int main()
{
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);

	printf("%d", N - A + B);

	return 0;
}
