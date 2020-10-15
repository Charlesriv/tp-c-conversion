#include <stdio.h>
#include "conversion.h"



int main()
{
	printf("Conversion de 11101 en decimal : %d\n", bintodec("11101"));
	printf("Conversion de 0xAF en décimal %d\n", hexatodec("AF"));
	printf("Conversion de 45 vers hexa : %s\n", dectohexa(45));
	printf("Conversion de 12 vers binaire : %s\n", dectobin_v1(12));
	printf("Conversion de 12 vers binaire v2 : %s\n", dectobin_v2(12));
	printf("Conversion de 22 vers binaire v3 : %s\n", dectobin_v3(22));
	printf("Conversion de 156 vers hexa v2 : %s\n", dectohexa_v2(156));
	return (0);
}

//tar zcvf  TP1-NOMFAMILLE.tgz conversion (TP1)