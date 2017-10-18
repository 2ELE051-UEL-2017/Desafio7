#include "CppUTest/TestHarness.h"
#include <math.h>

#define TESTA_EFICIENCIA

extern "C" {
	int numMultiplicacoes;
	double potencia(double base, int expoente);
}

TEST_GROUP(potencia)
{
	void setup()
	{
		numMultiplicacoes = 0;
	}
};

void testaEficiencia(int expoente)
{
#ifdef TESTA_EFICIENCIA
	double log2e = ceil(log2(expoente));
	CHECK_TEXT(numMultiplicacoes >= log2e, "Quantidade de multiplicacoes muito pequena: provavelmente voce esta' usando o operador * ao inves da funcao produto()");
	CHECK_TEXT(numMultiplicacoes <= 2.0*log2e, "Quantidade de multiplicacoes muito grande: seu algoritmo nao esta' tao eficiente quanto possivel");
#endif // TESTA_EFICIENCIA
}

TEST(potencia, DoisElevadoAUm)
{
	DOUBLES_EQUAL(2.0, potencia(2.0, 1), 1e-6);
	testaEficiencia(1);
}

TEST(potencia, TresElevadoAUm)
{
	DOUBLES_EQUAL(3.0, potencia(3.0, 1), 1e-6);
	testaEficiencia(1);
}

TEST(potencia, DoisElevadoADez)
{
	DOUBLES_EQUAL(1024.0, potencia(2.0, 10), 1e-6);
	testaEficiencia(10);
}

TEST(potencia, DoisElevadoAZero)
{
	DOUBLES_EQUAL(1.0, potencia(2.0, 0), 1e-6);
	testaEficiencia(1);
}

TEST(potencia, ZeroElevadoAZero)
{
	DOUBLES_EQUAL(1.0, potencia(0.0, 0), 1e-6);
	testaEficiencia(1);
}

TEST(potencia, ZeroElevadoADois)
{
	DOUBLES_EQUAL(0.0, potencia(0.0, 2), 1e-6);
	testaEficiencia(2);
}

TEST(potencia, MenosDoisElevadoATres)
{
	DOUBLES_EQUAL(-8.0, potencia(-2.0, 3), 1e-6);
	testaEficiencia(3);
}

TEST(potencia, MenosDoisElevadoADois)
{
	DOUBLES_EQUAL(4.0, potencia(-2.0, 2), 1e-6);
	testaEficiencia(2);
}

TEST(potencia, DoisElevadoAMenosUm)
{
	DOUBLES_EQUAL(0.5, potencia(2.0, -1), 1e-6);
	testaEficiencia(1);
}

TEST(potencia, NoveOitavosElevadoATrezentosESeis)
{
	DOUBLES_EQUAL(4494401521690882.1, potencia(1.125, 306), 10);
	testaEficiencia(306);
}

TEST(potencia, CincoQuartosElevadoACentoESessentaEUm)
{
	DOUBLES_EQUAL(4004166190366201.8, potencia(1.25, 161), 10);
	testaEficiencia(161);
}

TEST(potencia, TresMeiosElevadoAOitentaEOito)
{
	DOUBLES_EQUAL(3133507921263586.4, potencia(1.5, 88), 10);
	testaEficiencia(88);
}


TEST(potencia, DoisElevadoACinquentaEDois)
{
	DOUBLES_EQUAL(4503599627370496.0, potencia(2.0, 52), 1e-6);
	testaEficiencia(52);
}

TEST(potencia, DoisEMeioElevadoATrintaENove)
{
	DOUBLES_EQUAL(3308722450212110.7, potencia(2.5, 39), 1);
	testaEficiencia(52);
}


TEST(potencia, TresElevadoATrintaETres)
{
	DOUBLES_EQUAL(5559060566555523.0, potencia(3.0, 33), 1e-6);
	testaEficiencia(33);
}

TEST(potencia, CincoElevadoAVinteEDois)
{
	DOUBLES_EQUAL(2384185791015625.0, potencia(5.0, 22), 1e-6);
	testaEficiencia(22);
}

TEST(potencia, seisElevadoAVinte)
{
	DOUBLES_EQUAL(3656158440062976.0, potencia(6.0, 20), 1e-6);
	testaEficiencia(20);
}

TEST(potencia, seteElevadoADezoito)
{
	DOUBLES_EQUAL(1628413597910449.0, potencia(7.0, 18), 1e-6);
	testaEficiencia(18);
}

TEST(potencia, dezElevadoAQuinze)
{
	DOUBLES_EQUAL(1000000000000000.0, potencia(10.0, 15), 1e-6);
	testaEficiencia(15);
}

TEST(potencia, dozeElevadoAQuatorze)
{
	DOUBLES_EQUAL(1283918464548864.0, potencia(12.0, 14), 1e-6);
	testaEficiencia(14);
}

TEST(potencia, dezenoveElevadoADoze)
{
	DOUBLES_EQUAL(2213314919066161.0, potencia(19.0, 12), 1e-6);
	testaEficiencia(12);
}

TEST(potencia, DoisElevadoADoisAteTrinta)
{
	int i;
	for (i = 2; i <= 30; i++)
	{
		numMultiplicacoes = 0;
		DOUBLES_EQUAL(1 << i, potencia(2.0, i), 1e-6);
		testaEficiencia(i);
	}
}