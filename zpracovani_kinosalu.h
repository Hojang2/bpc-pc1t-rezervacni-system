#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LSIZ 20
#define RSIZ 8 

typedef struct 
{
	char line[8][20];
	
}sal;


sal nacteni_kinosalu(char* cesta_k_souboru, sal x) {
	FILE* fptr = fopen(cesta_k_souboru, "rt");
	if (fptr == NULL) {
		printf("Chyba pri otevreni souboru.");
		exit(1);
	}

	sal line2;
	char line[RSIZ][LSIZ];
	
	int i = 0;
	int tot = 0;

	while (fgets(line[i], LSIZ, fptr))
	{
		if (i != RSIZ - 1) {
			line[i][strlen(line[i]) - 1] = '\0';
		}
		i++;
	}
	fclose(fptr);
	
	tot = i;
	for (i = 0; i < tot; i++)
	{	
		for (int ii = 0; ii < 20; ii++) {
			x.line[i][ii] = line[i][ii];
			
		}
	}
	
	return x;
}