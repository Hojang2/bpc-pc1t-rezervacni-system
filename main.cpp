// bpc-pc1t-rezervacni-system.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

int main()
{
	const int POCET_FILMU = 5;
	const int POCET_CASU = 5;
	int t = 3;
	int f;
	int c;
	
	char filmy[POCET_FILMU][20] = { "james bond", "avatar", "ready player one", "star wars", "duna" };
	char casy[POCET_CASU][20] = { "9:00 - 11:00", "11:00 - 13:00", "13:00 - 15:00", "15:00 - 17:00", "17:00 - 19:00" };
	
	while (t) {
		if (t == 1) {
			printf("\nNabidka filmu: \n");
			for (int i = 0; i < POCET_FILMU; i++) {
				printf("Film cislo %d: %s\n", i, filmy[i]);
			}

			printf("Vyber si cislo filmu: ");
			scanf_s("%d", &f);
			if (f < 0 || f > POCET_FILMU-1) {
				printf("Spatne vybrany film \n");
				continue;
			}


			printf("\nNabidka casu: \n");
			for (int i = 0; i < POCET_CASU; i++) {
				printf("Cas cislo %d: %s\n", i, casy[i]);
			}

			printf("Vyber si cislo casu filmu: ");
			scanf_s("%d", &c);

			if (c < 0 || c > POCET_CASU-1) {
				printf("Spatne vybrany cas \n");
				continue;
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
