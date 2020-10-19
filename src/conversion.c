#include "conversion.h"
#include <math.h>
#include <string.h>
// int powerCalc(int base, unsigned int exp)
// {

// 	if (exp == 0)
// 		return 1;
// 	int temp = powerCalc(base, exp / 2);
// 	if (exp % 2 == 0)
// 		return temp * temp;
// 	else
// 		return base * temp * temp;
// }

int bintodec(char *val)
{
	int result = 0;
	while (*val)
	{
		result <<= 1;
		result += *val == '1';
		val++;
	}
	return result;
	// int nb = 0;
	// for (int i = 0; i <= strlen(val) - 1; i++)
	// {
	//  nb += (int)(val[strlen(val) - 1 - i] - '0') * powerCalc(2, i);
	// }
	// return nb;
}

int hexatodec(char *val)
{
	int nb = 0;
	while (*val)
	{
		nb <<= 4;
		if (*val >= '0' && *val <= '9')
			nb += *val++ - '0';
		if (*val >= 'A' && *val <= 'F')
			nb += *val++ - 'A' + 10;
		if (*val >= 'a' && *val <= 'f')
			nb += *val++ - 'a' + 10;
	}
	return nb;
	// for (int i = 0; i <= strlen(val) - 1; i++)
	// {
	// 	int temp;
	// 	char curr = val[strlen(val) - 1 - i];
	// 	if (curr >= '0' && curr <= '9')
	// 		temp = curr - '0';
	// 	if (curr >= 'A' && curr <= 'F')
	// 		temp = curr - 'A' + 10;
	// 	if (curr >= 'a' && curr <= 'f')
	// 		temp = curr - 'a' + 10;
	// 	nb += temp << (4 * i);
	// }
}

char *dectohexa(unsigned int val)
{
	char *result = malloc(100);
	char *hex = malloc(10);
	int cpt = -1;
	char dictionnary[15] = "0123456789ABCDEF";
	while (val != 0)
	{
		cpt++;
		int reste = val & 0xF;
		hex[cpt] = dictionnary[reste];
		val >>= 4;
	}
	int k = 0;
	for (int j = cpt; j >= 0; j--)
	{
		result[k++] = hex[j];
	}
	return result;

	// char *result = malloc(100);
	// char hex[10];
	// int cpt = -1;
	// int reste = 0;
	// while (val != 0)
	// {
	// 	reste = val % 16;
	// 	if (reste < 10)
	// 		reste += 48;
	// 	else
	// 		reste += 55;
	// 	val >>= 4;
	// 	cpt++;
	// 	hex[cpt] = reste;
	// }
	// int k = 0;
	// for (int j = cpt; j >= 0; j--)
	// {
	// 	result[k++] = hex[j];
	// }
	// result[strlen(result) - 1] = '\0';
	// return result;
}

char *dectobin_v1(unsigned int val)
{
	int power = 1;
	char *result = malloc(100);
	while (power < val)
	{
		power <<= 1;
	}
	for (power >>= 1; power > 0; power >>= 1)
	{
		if ((int)(val - power) >= 0)
		{
			val -= power;
			strcat(result, "1");
		}
		else
		{
			strcat(result, "0");
		}
	}
	return result;
}

char *dectobin_v2(unsigned int val)
{
	int tab[10];
	char *result = malloc(100);
	char append[1];
	int i;
	for (i = 0; val > 0; i++)
	{
		tab[i] = val % 2;
		val >>= 1;
	}
	for (i = i - 1; i >= 0; i--)
	{
		sprintf(append, "%d", tab[i]);
		strcat(result, append);
	}
	return result;
}

char *dectobin_v3(unsigned int val)
{
	// const INT_SIZE = sizeof(int) * 4;
	// int index = INT_SIZE - 1;
	// int bin[INT_SIZE];
	// unsigned int range = 0b1000000000000000;
	// char *result = malloc(100);
	// char append[2];
	// while (range > 0)
	// {
	// 	bin[index--] = (val & range) ? 1 : 0;
	// 	range >>= 1;
	// }
	// for (int i = INT_SIZE - 1; i >= 0; i--)
	// {
	// 	sprintf(append, "%d", bin[i]);
	// 	strcat(result, append);
	// }
	// return result;

	const INT_SIZE = sizeof(int) * 4;
	char *res = malloc(100);
	int bin[INT_SIZE];
	int cpt = 0;
	char append[1];
	while (val > 0)
	{
		bin[cpt++] = (val & 1);
		val >>= 1;
	}
	for (int i = cpt - 1; i >= 0; i--)
	{
		sprintf(append, "%d", bin[i]);
		strcat(res, append);
	}
	return res;
}

char *dectohexa_v2(unsigned int val)
{
	char *res = malloc(sizeof(int) * 4);
	strcpy(res, "0x0000");
	const char reg[] = "0123456789ABCDEF";
	int index = 6;
	while (val > 0)
	{
		res[index--] = reg[(val & 0xF)];
		val >>= 4;
	}
	return res;
}
