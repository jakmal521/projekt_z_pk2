#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "funkcje.h"



int main()

{
    FILE* plik = fopen("pytania_do_milionerow.txt", "r");
    if (plik)
    {
        fclose(plik);
        kwota_gry* head = NULL; char wybor;



             head = utworzenie_listy(head, 500); break;
             head = utworzenie_listy(head, 1000); break;
             head = utworzenie_listy(head, 2000); break;
             head = utworzenie_listy(head, 5000); break;
             head = utworzenie_listy(head, 10000); break;
             head = utworzenie_listy(head, 20000); break;
             head = utworzenie_listy(head, 40000); break;
             head = utworzenie_listy(head, 75000); break;
             head = utworzenie_listy(head, 125000); break;
             head = utworzenie_listy(head, 250000); break;
             head = utworzenie_listy(head, 500000); break;
             head = utworzenie_listy(head, 1000000); break;

            

        

        while (1)
        {

            printf("Witamy przyszlego milionera!\n");
            printf("Ktora opcje chcesz wybrac?\n 1. Nowa gra \n 2. Opcje\n 3. Wyjscie\n");
            wybor = getchar();

            switch (wybor)
            {
            case '1': gra(head); break;

            case '2': opcje_dodatkowe(head); break;

            case '3': usuwanie_listy_pierwotnej(head); head = NULL; return 0;

            default: break;


            }
            system("cls");
        }




    }
    else
    {
        printf("Brak pliku z pytaniami. Dolacz plik i uruchom program jeszcze raz");
        return 0;
    }
}


