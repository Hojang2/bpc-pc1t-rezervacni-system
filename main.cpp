// bpc-pc1t-rezervacni-system.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "zpracovani_kinosalu.h"
#include <time.h>

using namespace std;
// funkce pro projiti veskerych vstupenek a najiti volneho mista pro novou vstupenku
int najdi_volnou_vstupenku(int vstupenky[LSIZ * RSIZ][5]) { 
	for (int i = 0; i < RSIZ * LSIZ; i++) {
		if (vstupenky[i][0] == 0) {
			return i;
		}
	}
}
// funkce pro zmenu radku v seznamu filmu/casu
soubor zmena_hodnoty(soubor pole, int f) {
	char pole2[LSIZ];
	printf("Zadej novou hodnotu(musi byt 1 string): ");
	
	int vstup = scanf("%s", pole2);
	while (getchar() != '\n');
	if (vstup) {
		for (int i = 0; i < LSIZ; i++) {
			pole.line[f][i] = pole2[i];
		}
	}
	return pole;
}
// vypsani 2D pole sal
void vypsani_salu(soubor pole) {
	for (int i = 0; i < 8; i++)
	{
		printf(" %s\n", pole.line[i]);
	}
	printf("\n");
}
// vypis jedne konkretni vstupenky
void vypis_vstupenky(int vstupenky[LSIZ * RSIZ][5], int vstupenka, soubor filmy, soubor casy) {
	int film;
	int cas;
	int neexistuje = 1;
	for (int i = 0; i < RSIZ * LSIZ; i++) {
		if (vstupenky[i][0] == vstupenka && vstupenka != 0) {
			printf("*************************************************\n");
			printf("Vstupenka cislo: %d Pro radu: %d sedadlo: %d \n", vstupenky[i][0], vstupenky[i][1], vstupenky[i][2]);
			film = vstupenky[i][3];
			cas = vstupenky[i][4];
			printf("Pro film: %s v case %s\n", filmy.line[film], casy.line[cas]);
			printf("*************************************************\n");
			neexistuje = 0;
		}
	}
	if (neexistuje) {
		printf("Vstupenka cislo: %d neexistuje, nebo byla zrusena\n", vstupenka);
	}
}
// prochazeni vsech vstupenek a zavolani funkce vypis_vstupenk pro kazdou vstupenku
void vypis_vstupenek(int vstupenky[LSIZ * RSIZ][5], soubor filmy, soubor casy) {
	int last = 0;
	for (int i = 0; i < RSIZ * LSIZ; i++) {
		if (vstupenky[i][0] && vstupenky[i][0] != 0 && last != vstupenky[i][0]) {
			last = vstupenky[i][0];
			vypis_vstupenky(vstupenky, vstupenky[i][0], filmy, casy);
		}
	}
}
// funkce pro vypis filmu a vstup uzivatele s cislem filmu
int vyber_filmu(soubor filmy, int filmu) {
	int f = -1;

	printf("\nNabidka filmu: \n");
	for (int i = 0; i < filmu; i++) {
		printf("Film cislo %d: %s\n", i, filmy.line[i]);
	}

	while (f < 0 || f > filmu - 1) {


		printf("Vyber si cislo filmu: ");
		scanf("%d", &f);
		while (getchar() != '\n');
	}
	return f;
}
// kontrola pred zmenou nazvu filmu/casu
int potvrzeny_vyber(int zmena = 0) {
	printf("yes = 1\n");
	printf("no = 0\n");
	printf("Odpoved: ");
	scanf("%d", &zmena);
	while (getchar() != '\n');
	return zmena;
}

int main()
{
	const int POCET_FILMU = 6; // pocet filmu v souboru 1 - 8
	const int POCET_CASU = 5; // pocet casu v souboru 1 - 8
	// definice cest k souborum
	char* cesta_k_salu = "sal_1.txt";
	char* cesta_k_casum = "casy.txt";
	char* cesta_k_filmum= "filmy.txt";
	int t = 4; // promenna, ktera meni mod programu
	int f;
	int vstupenka;
	int cislo_vstupenky;
	int vstupenky[LSIZ * RSIZ][5] = { 0 }; // 2D pole, ktere obsahuje data o vstupenkach
	srand(time(NULL)); // inicializace pro generovani nahodneho cisla
	// nasteni obsahu souboru
	soubor sal1 = { 0 };
	soubor pole = nacteni_souboru(cesta_k_salu, sal1);
	soubor filmy = nacteni_souboru(cesta_k_filmum, sal1);
	soubor casy = nacteni_souboru(cesta_k_casum, sal1);
	int sedadel;
	int x, y, i, orig;
	
	
	while (t) { // hlavni cyklus, bezi dokud uzivatel nezada 0
		if (t == 1) {

			f = vyber_filmu(filmy, POCET_FILMU);


			vypsani_salu(pole);


			int sedadla[RSIZ * LSIZ][3]; // 2D pole, kam se budou ukladat pozice obsazenych sedadel

			printf("Zadej pocet sedadel:");
			scanf("%d", &sedadel);
			while (getchar() != '\n');

			
			
			if (sedadel <= 0) {
				continue;
			}
			i = 0;
			while (i < sedadel) {
				printf("Zadej radu a cislo sedadla ve formatu [rada sedadlo]:");
				scanf("%d %d", &x, &y);
				while (getchar() != '\n');
				if ((x >= 0 && x < 15) && (y >= 0 && y < 8)) { // zmena z 0 na X, v danem sedadle


					if (pole.line[x][y] != 'X') {
						sedadla[i][0] = 1;
						sedadla[i][1] = x;
						sedadla[i][2] = y;
						pole.line[y][x] = 'X';
						i++;
					}
				}
			}
			vypsani_salu(pole);

			orig = 1;
			while (1){
				vstupenka = rand(); // generace nahodneho cisla
				for (int i = 0; i < RSIZ * LSIZ; i++) { // kontrola unikatnosti vygenerovaneho cisla
					if (vstupenka == vstupenky[i][0]) {
						orig = 0;
					}
				}
				if (orig) {
					break;
				}
			}
			cislo_vstupenky = najdi_volnou_vstupenku(vstupenky); // nalezeni pozice na vstupenku
			
			for (int i = 0; i < sedadel; i++) {
				if (sedadla[i][0]) {
					vstupenky[cislo_vstupenky][0] = vstupenka;
					vstupenky[cislo_vstupenky][1] = sedadla[i][1];
					vstupenky[cislo_vstupenky][2] = sedadla[i][2];
					vstupenky[cislo_vstupenky][3] = f;
					vstupenky[cislo_vstupenky][4] = f;
					if (vstupenky[cislo_vstupenky + 1][0]) { // pri obsazeni vice sedadel, vyhledani dalsi mozne vstupenky
						cislo_vstupenky = najdi_volnou_vstupenku(vstupenky);
					}
					cislo_vstupenky++;
				}
				
			}
			
			vypis_vstupenky(vstupenky, vstupenka, filmy, casy);

			t = 4;

		} else if (t == 2) {
			system("cls");
			vypis_vstupenek(vstupenky, filmy, casy);
			vstupenka = -1;
			printf("Zadej cislo vstupenky: ");
			scanf("%d", &vstupenka);
			while (getchar() != '\n');

			
			for (int i = 0; i < RSIZ * LSIZ; i++) { // vynulovani hodnot vstupenky
				if (vstupenky[i][0] == vstupenka) {
					x = vstupenky[i][1];
					y = vstupenky[i][2];
					pole.line[x][y] = '0';
					vstupenky[i][0] = 0;
					vstupenky[i][1] = 0;
					vstupenky[i][2] = 0;
					vstupenky[i][3] = 0;
					vstupenky[i][4] = 0;
					printf("Vstupenka zrusena\n");
					vypis_vstupenky(vstupenky, vstupenka, filmy, casy);
					
				}
				
			}
			vypis_vstupenek(vstupenky, filmy, casy);
			vypsani_salu(pole);
			t = 4;

		}
		else if (t == 3) {
			f = vyber_filmu(filmy, POCET_FILMU);
			printf("Zmenit nazev filmu?\n");
			if (potvrzeny_vyber()) {
				filmy = zmena_hodnoty(filmy, f);
				printf("Nabidka filmu: \n");
				for (int i = 0; i < POCET_FILMU; i++) {
					printf("Film cislo %d: %s\n", i, filmy.line[i]);
				}
			}
			printf("Zmenit cas filmu?\n");
			for (int i = 0; i < POCET_CASU; i++) {
				printf("Cas cislo %d: %s\n", i, casy.line[i]);
			}
			if (potvrzeny_vyber()) {
				casy = zmena_hodnoty(casy, f);
				printf("Nabidka casu: \n");
				for (int i = 0; i < POCET_CASU; i++) {
					printf("Cas cislo %d: %s\n", i, casy.line[i]);
				}
			}

			t = 4;
			

		} else {
			// zakladni menu
			printf("\nZadejte cislo jedne z moznosti : \n");
			printf("0. ukonceni programu \n");
			printf("1. vyber filmu \n");
			printf("2. zruseni vstupenky \n");
			printf("3. zmena jmena nebo casu filmu \n");
			printf("Zadej volbu: ");
			scanf("%d", &t);
			while (getchar() != '\n');
			system("cls");
		}
	}
	// ulozeni zmen
	printf("Ukladam zmeny\n");
	ulozeni_souboru("sal_1.txt", pole, RSIZ);
	ulozeni_souboru("filmy.txt", filmy, POCET_FILMU);
	ulozeni_souboru("casy.txt", casy, POCET_CASU);

	return 0;
}
