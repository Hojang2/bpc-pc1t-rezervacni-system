// bpc-pc1t-rezervacni-system.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "zpracovani_kinosalu.h"
#include <time.h>

using namespace std;
int najdi_cislo_vstupenky(int vstupenky[LSIZ * RSIZ][3]) {
	for (int i = 0; i < RSIZ * LSIZ; i++) {
		if (vstupenky[i][0] == 0) {
			return i;
		}
	}
}
	

int main()
{
	const int POCET_FILMU = 5;
	const int POCET_CASU = 5;
	char* cesta_k_salu = "sal_1.txt";
	char* cesta_k_casum = "casy.txt";
	char* cesta_k_filmum= "filmy.txt";
	int t = 3;
	int f;
	int c;
	int vstupenka;
	int cislo_vstupenky;
	int vstupenky[LSIZ * RSIZ][3] = { 0 };
	srand(time(NULL));
	//char filmy[POCET_FILMU][20] = { "james bond", "avatar", "ready player one", "star wars", "duna" };
	//char casy[POCET_CASU][20] = { "9:00 - 11:00", "11:00 - 13:00", "13:00 - 15:00", "15:00 - 17:00", "17:00 - 19:00" };
	soubor sal1 = { 0 };
	soubor pole = nacteni_souboru(cesta_k_salu, sal1);
	soubor filmy = nacteni_souboru(cesta_k_filmum, sal1);
	soubor casy = nacteni_souboru(cesta_k_casum, sal1);
	int sedadel;
	int x, y, i, orig;
	
	
	while (t) {
		if (t == 1) {
			printf("\nNabidka filmu: \n");
			for (int i = 0; i < POCET_FILMU; i++) {
				printf("Film cislo %d: %s\n", i, filmy.line[i]);
			}

			printf("Vyber si cislo filmu: ");
			scanf_s("%d", &f);
			if (f < 0 || f > POCET_FILMU-1) {
				printf("Spatne vybrany film \n");
				continue;
			}


			printf("\nNabidka casu: \n");
			for (int i = 0; i < POCET_CASU; i++) {
				printf("Cas cislo %d: %s\n", i, casy.line[i]);
			}

			printf("Vyber si cislo casu filmu: ");
			scanf_s("%d", &c);

			if (c < 0 || c > POCET_CASU-1) {
				printf("Spatne vybrany cas \n");
				continue;
			}

			

			for (int i = 0; i < 8; i++)
			{
				printf(" %s\n", pole.line[i]);
			}
			printf("\n");


			
			printf("Zadej pocet sedadel:");
			scanf("%d", &sedadel);
			printf("\n");

			//int sedadla[sedadel];
			int sedadla[RSIZ * LSIZ][3];
			
			if (sedadel <= 0) {
				continue;
			}
			i = 0;
			while (i < sedadel) {
				printf("Zadej radu a cislo sedadla ve formatu [rada sedadlo]:");
				scanf("%d %d", &x, &y);
				if ((x >= 0 && x < 15) && (y >= 0 && y < 8)) {


					if (pole.line[x][y] != 'X') {
						sedadla[i][0] = 1;
						sedadla[i][1] = x;
						sedadla[i][2] = y;
						pole.line[y][x] = 'X';
						i++;
					}
				}
			}
			for (int i = 0; i < 8; i++)
			{
				printf(" %s\n", pole.line[i]);
			}
			printf("\n");

			orig = 1;
			while (1){
				vstupenka = rand();
				for (int i = 0; i < RSIZ * LSIZ; i++) {
					if (vstupenka == vstupenky[i][0]) {
						orig = 0;
					}
				}
				if (orig) {
					break;
				}
			}
			cislo_vstupenky = najdi_cislo_vstupenky(vstupenky);
			
			for (int i = 0; i < sedadel; i++) {
				if (sedadla[i][0]) {
					vstupenky[cislo_vstupenky][0] = vstupenka;
					vstupenky[cislo_vstupenky][1] = sedadla[i][1];
					vstupenky[cislo_vstupenky][2] = sedadla[i][2];
					if (vstupenky[cislo_vstupenky + 1][0]) {
						cislo_vstupenky = najdi_cislo_vstupenky(vstupenky);
					}
					cislo_vstupenky++;
				}
				
			}
			for (int i = 0; i < sedadel; i++) {
				if (sedadla[i][0]) {
					printf("%d %d\n", sedadla[i][0], sedadla[i][1], sedadla[i][2]);
				}
			}

			for (int i = 0; i < RSIZ * LSIZ; i++) {
				if (vstupenky[i][0]) {
					printf("%d %d %d \n", vstupenky[i][0], vstupenky[i][1], vstupenky[i][2]);
				}
			}

			
			
			

			
			
			
			
			t = 3;
		}
		if (t == 2) {
			printf("Zadej kod vstupenky: ");
		} else {
			printf("Zadejte cislo jedne z moznosti : \n");
			printf("0. ukonceni programu \n");
			printf("1. vyber filmu \n");
			printf("2. zruseni vstupenky \n");
			printf("Zadej volbu: ");
			scanf_s("%d", &t);
		}
	}
		
	return 0;
}
