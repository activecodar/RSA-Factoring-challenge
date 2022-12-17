#include "main.h"

/**
 *get_factors - get factors of an int
 *@n: int in question
 *@factors: factors of int n
 */
void get_factors(long long n, int factors[MAX_FACTORS][2])
{
	int num_factors = 0;

	for (int i = 1; i <= sqrt(n) && num_factors < MAX_FACTORS; i++)
	{
	if (n % i == 0)
	{
		factors[num_factors][0] = i;
		factors[num_factors][1] = n / i;
		num_factors++;
		if (num_factors == 2)
		{
			printf("%lld=%lld*%d\n", n, n / i, i);
		}
	}
	}
}

/**
 *main - entrypoint
 *@argc: arguments count
 *@argv: arguments array
 *Return: f1 if success
 */

int main(int argc, char *argv[])
{
	char *input_file;
	FILE *fp;
	long long n;

	input_file = argv[1];
	fp = fopen(input_file, "r");
	while (fscanf(fp, "%lld", &n) == 1)
	{
		int factors[MAX_FACTORS][2];

		get_factors(n, factors);
	}
	fclose(fp);
	return (0);
}
