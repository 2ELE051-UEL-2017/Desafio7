int numMultiplicacoes;

double produto(double a, double b)
{
	numMultiplicacoes++;
	return a*b;
}

double potencia(double base, int expoente)
{
	double res = 1.0;
	int i;

	for (i = 0; i < expoente; i++)
		res = produto(res, base);

	return res;
}
