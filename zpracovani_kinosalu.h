#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 40 // definice promenne pro maximalni pocet znaku na radku
#define RSIZ 8 // definice promenne pro maximalni pocet radku souboru

typedef struct // definice struktury pro nacitani souboru
{
	char line[8][40];
	
}soubor;


soubor nacteni_souboru(char* cesta_k_souboru, soubor x) {
	FILE* fptr = fopen(cesta_k_souboru, "rt"); // otevreni souboru v modu cteni
	if (fptr == NULL) { // zkouska, jestli se soubor povedlo otevrit
		printf("Chyba pri otevreni souboru.");
		exit(1);
	}

	soubor line2;
	char line[RSIZ][LSIZ];
	
	int i = 0;
	int tot = 0;

	while (fgets(line[i], LSIZ, fptr)) // prendani hodnot z pointeru do 2D pole line
	{
		line[i][strlen(line[i]) - 1] = '\0';
		
		i++;
	}
	fclose(fptr); // zavreni souboru
	
	tot = i;
	for (i = 0; i < tot; i++) // predani hodnot z 2D pole line do struktury soubor
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
	FILE* fptr = fopen(cesta_k_souboru, "w+"); // otevreni souboru a smazani veskereho obsahu
	if (fptr == NULL) {
		printf("Chyba pri otevreni souboru.");
		exit(1);
	}

	
	for (int i = 0; i < pocet_radku; i++) {
		// pridani konce radku k jednotlivim radkum
		char result[LSIZ];
		strcpy(result, x.line[i]);
		strcat(result, "\n");
		fputs(result, fptr); // ulozeni radku
		
	}
	fclose(fptr); // ukonceni souboru
}