#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 40
#define RSIZ 8 

typedef struct 
{
	char line[8][40];
	
}soubor;


soubor nacteni_souboru(char* cesta_k_souboru, soubor x) {
	FILE* fptr = fopen(cesta_k_souboru, "rt");
	if (fptr == NULL) {
		printf("Chyba pri otevreni souboru.");
		exit(1);
	}

	soubor line2;
	char line[RSIZ][LSIZ];
	
	int i = 0;
	int tot = 0;

	while (fgets(line[i], LSIZ, fptr))
	{
		line[i][strlen(line[i]) - 1] = '\0';
		
		i++;
	}
	fclose(fptr);
	
	tot = i;
	for (i = 0; i < tot; i++)
	{	
		if(strlen(line[i]) > 0){
			for (int ii = 0; ii < LSIZ; ii++) {
				x.line[i][ii] = line[i][ii];
			
			}
		}
	}
	
	return x;
}

void ulozeni_souboru(char* cesta_k_souboru, soubor x, int pocet_radku) {
	FILE* fptr = fopen(cesta_k_souboru, "w+");
	if (fptr == NULL) {
		printf("Chyba pri otevreni souboru.");
		exit(1);
	}

	
	for (int i = 0; i < pocet_radku; i++) {
		char result[LSIZ];
		strcpy(result, x.line[i]);
		strcat(result, "\n");
		fputs(result, fptr);
		
	}
	fclose(fptr);
}