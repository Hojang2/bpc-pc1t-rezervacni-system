// bpc-pc1t-rezervacni-system.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

int main()
{
	int t = 1;

	while (t != 3)
	{
		printf("Zadejte číslo jedné z možností : \n");
		printf("1. VÝBĚR MÍSTA \n");
		printf("2. ZRUŠENÍ VSTUPENKY \n");
		printf("3. UKONČENÍ PROGRAMU \n");
		scanf_s("%d", & t);
		if (t == 1)
		{
			//Funkce pro vyber mista
		}
		else if (t == 2)
		{
			//Funkce pro zruseni vstupenky
		}
	}
	return 0;
	//Zde se ukonci program v pripade inputu "3"
}
