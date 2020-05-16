#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "funkcje.h"



int main()

{
    kwota_gry* head = NULL; char wybor;



    for (int i = 1; i < 13; i++)
    {
        switch (i)
        {
        case 1: head = utworzenie_listy(head, 500); break;
        case 2: head = utworzenie_listy(head, 1000); break;
        case 3: head = utworzenie_listy(head, 2000); break;
        case 4: head = utworzenie_listy(head, 5000); break;
        case 5: head = utworzenie_listy(head, 10000); break;
        case 6: head = utworzenie_listy(head, 20000); break;
        case 7: head = utworzenie_listy(head, 40000); break;
        case 8: head = utworzenie_listy(head, 75000); break;
        case 9: head = utworzenie_listy(head, 125000); break;
        case 10: head = utworzenie_listy(head, 250000); break;
        case 11: head = utworzenie_listy(head, 500000); break;
        case 12: head = utworzenie_listy(head, 1000000); break;

        }

    }
     wyswietlenie_wszystkich_pytan(head);
    return 0;

    while (1)
    {

        printf("Witamy przyszlego milionera!\n");
        printf("Ktora opcje chcesz wybrac?\n 1. Nowa gra \n 2. Opcje\n 3. Wyjscie\n");
        wybor = getchar();

        switch (wybor)
        {
        case '1': gra(head); break;

        case '2': opcje_dodatkowe(head); break;

        case '3': usuwanie_listy_pierwotnej(head); head = NULL; _CrtDumpMemoryLeaks(); return 0;

        default: printf("Wybierz 1,2 lub 3 \n"); Sleep(1000);


        }
        system("cls");
    }





}


