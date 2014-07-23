#include <stdio.h>
#include <stdlib.h>

void nqsort(int *array, int n)
{
	int i, t, c;
	if (n < 2)
		return;
	c = 0;
	t = array[0];
	for (i = 1; i < n; i++)
	{
		if (array[i] < t)
		{

			array[c] = array[i];
			array[i] = array[++c];
		}
	}
	array[c] = t;
	nqsort(array, c);
	nqsort(array + c + 1, n - c - 1);
}

int nbsearch(int *array, int n, int ob)
{
	int np = 0;
	while (n > 0)
	{
		if (ob > array[n / 2])
		{
			array = array + n / 2 + 1;
			np += n / 2 + 1;
			n = n - n / 2 - 1;
		}
		else
		{
			n = n / 2;
		}
	}

	return np;
}

int main()
{

	int n, m;
	int *marbles;
	int ncase = 1, i, ob, np;
	while (scanf("%d %d", &n, &m) != EOF)
	{

		if (n == 0 && m == 0)
			return 0;
		printf("CASE# %d:\n", ncase++);
		marbles = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &marbles[i]);
		}
		nqsort(marbles, n);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &ob);
			np = nbsearch(marbles, n, ob);
			if (np == n || marbles[np] != ob)
				printf("%d not found\n", ob);
			else
				printf("%d found at %d\n", ob, np + 1);
		}
		free(marbles);
	}

	return 0;
}