#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "funkcje.h"


void gra(kwota_gry* head)
{
    wczytanie_pytan(head);
    int uzycie_pol_na_pol = 0;
    int uzycie_telefonu_do_przyjaciela = 0;
    int uzycie_publicznosci = 0;
    kwota_gry* zapamietanie_stanu = head;
    printf("Za chwile przejdziemy do pierwszego pytania, ktore rozpocznie twoja droge do miliona.\n Przed nim wazne zebys zapoznal/a sie ze sterowaniem:\n gdy nacisniesz klawisz 'r' i potwierdzisz enterem zrezygnujesz z gry.\n Jezeli wybierzesz klawisz 'k' pojawi sie mozliwosc uzycia kol ratunkowych. Pamietaj kazde kolo mozna uzyc tylko raz!\n Powodzenia!!\n Nacisnij przycisk enter aby kontynuowac\n");
    getchar(); getchar();
    int nagroda = 0;
    for (int i = 1; i < 13; i++)
    {
        system("cls");
        char odp;

        int uzycie_pol_na_pol_w_pytaniu = 0;
        pytanie* aktualne_pytanie = losowanie_pytania(head);
        if ((i == 2) || (i == 7))
            printf("Grasz o gwarantowane %d", head->kwota);
        else printf("Grasz o %d", head->kwota);
        printf("zl. Oto pytanie:\n");
        Sleep(750);
        wyswietlenie_pytania(aktualne_pytanie, 0);
        printf("Poprawna odpowiedz to: ");
        odp = getchar();
        odp = toupper(odp);
        if (odp == 'K')
        {
            int koniec_petli = 1;
            while (koniec_petli)
            {
                char kolo;
                if (!uzycie_pol_na_pol)
                    printf("1.50/50 \n ");
                
                if (!uzycie_telefonu_do_przyjaciela)
                    printf("2.Telefon do przyjaciela\n");

               
                if (!uzycie_publicznosci)
                    printf("3.Pytanie do publicznosci \n");
                if ((uzycie_publicznosci) & (uzycie_pol_na_pol) & (uzycie_telefonu_do_przyjaciela))
                    printf("Wszystkie kola ratunkowe zostały wykorzystane!\n");

                 printf ("4.Odpowiadam na pytanie lub rezygnuje ('r')\n");
                printf("Wybor: \n");
                kolo = getchar();

                switch (kolo)
                {
                case '1': if (!uzycie_pol_na_pol) { pol_na_pol(aktualne_pytanie, &uzycie_pol_na_pol_w_pytaniu); }
                      else  {wyswietlenie_pytania(aktualne_pytanie, 0);}
                      uzycie_pol_na_pol++; break;
                case '2':  if (!uzycie_telefonu_do_przyjaciela) { telefon_do_przyjaciela(aktualne_pytanie); }
                      else { wyswietlenie_pytania(aktualne_pytanie, 0); } 
                      uzycie_telefonu_do_przyjaciela++; break;
                case '3':   if (!uzycie_publicznosci) { pytanie_do_publicznosci(uzycie_pol_na_pol_w_pytaniu, aktualne_pytanie); }
                      else { wyswietlenie_pytania(aktualne_pytanie, 0); }
                      uzycie_publicznosci++; break;
                case '4': koniec_petli--; break;
                default: printf("wybierz jedna z opcji\n");  break;
                }
                getchar();
            }

            printf("Poprawna odpowiedz to: ");
            odp = getchar();
            odp = toupper(odp);

        }

        if (odp == 'R')
        {
            printf("Szkoda ze to juz koniec. Twoja wygrana to %d zl. Gratulacje!\n", nagroda);
            getchar(); getchar();
            head = zapamietanie_stanu;
            usuwanie_listy_pytan(head);

            return;
        }



        if (odp == aktualne_pytanie->poprawna)
        {
            if (i == 12)
                printf("Dobra odpowiedz!\n");
            else
            {
                printf("Dobra odpowiedz! Przechodzimy do kolejnego pytania. Twoja aktualna wygrana to %d zl!\n", head->kwota);
                nagroda = head->kwota;
            }
        }
        else
        {
            if (i < 3)

                printf("Niestety tym razem razem nie udalo Ci sie nic wygrac. Poprawna odpowiedz to %c . Sprobuj jeszcze raz!\n", aktualne_pytanie->poprawna);

            else if (i < 8)

                printf("Niestety twoja odpowiedz jest bledna! Poprawna odpowiedz to %c\nTwoja wygrane to gwarantowane 1000zl. Gratulacje!!\n", aktualne_pytanie->poprawna);

            else printf("Niestety twoja odpowiedz jest bledna! Poprawna odpowiedz to %c\n Twoja wygrane to gwarantowane 40000zl. Gratulacje!!\n", aktualne_pytanie->poprawna);
            printf("Nacisnij przycisk enter aby zakonczyc gre.\n");
            getchar(); getchar();
            head = zapamietanie_stanu;
            usuwanie_listy_pytan(head);

            return;
        }

        getchar(); getchar();

       
        head = head->next;
    }
    printf("Gratulacje wygrales okragly million zl!\n");
    getchar();
    head = zapamietanie_stanu;
    usuwanie_listy_pytan(head);
    return;

}
void opcje_dodatkowe(kwota_gry* head)
{
    char wybor;
    while (1)
    {
        printf("1.Wyswietlenie wszystkich pytan\n");
        printf("2.Powrot\n");
        getchar();
        wybor = getchar();

        switch (wybor)
        {
           

        case '1': wyswietlenie_wszystkich_pytan(head); break;

        case '2': return; break;

        default: break;

        }

    }



}
kwota_gry* szukanie_kwoty(kwota_gry* head, int szukane)
{
    kwota_gry* szukany_element = head;
    while (szukany_element)
    {
        if (szukany_element->kwota == szukane)
            return szukany_element;
        szukany_element = szukany_element->next;


    }
    return NULL;



}

void wczytanie_pytan(kwota_gry* head)
{
    FILE* plik = fopen("pytania_do_milionerow.txt", "r");
   
        char kwota_pytania[9];
        long int kwota_pytania_2;

        while (fgets(kwota_pytania, 9, plik))
        {


            kwota_pytania_2 = atoi(kwota_pytania);
            kwota_gry* szukana_wartosc = szukanie_kwoty(head, kwota_pytania_2);
            if (szukana_wartosc != NULL)
            {
                szukana_wartosc->ilosc_pytan++;
                char pomocnicza[3];
                pytanie* nowy = malloc(sizeof(pytanie));
                fgets(nowy->tresc_pytania, 300, plik);
                fgets(nowy->odpa, 30, plik);
                fgets(nowy->odpb, 30, plik);
                fgets(nowy->odpc, 30, plik);
                fgets(nowy->odpd, 30, plik);
                fgets(pomocnicza, 3, plik);
                nowy->poprawna = pomocnicza[0];
                nowy->nastepne = szukana_wartosc->wskaznik_na_pytanie;
                szukana_wartosc->wskaznik_na_pytanie = nowy;
            }
        }

        fclose(plik);
    
}

void wyswietlenie_pytania(pytanie* head ,int czy_wszystkie_pytania)
{
    if (head == NULL) return;
    if (czy_wszystkie_pytania != 1)
    system("cls");
    printf("%s\n", head->tresc_pytania);
    printf("%s\n", head->odpa);
    printf("%s\n", head->odpb);
    printf("%s\n", head->odpc);
    printf("%s\n", head->odpd);



}
void pol_na_pol(pytanie* head, int* uzycie_pol_na_pol_w_pytaniu)
{
    
        int i = 2;
        while (i)
        {
            srand((unsigned int)time(NULL));
            int pomocnicza = rand() % 4;
            if ((pomocnicza == 0) & (strlen(head->odpa) != 0) & (head->odpa[0] != head->poprawna))
            {
                strcpy_s(head->odpa, 1, "");
                i--;
            }
            if ((pomocnicza == 1) & (strlen(head->odpb) != 0) & (head->odpb[0] != head->poprawna))
            {
                strcpy(head->odpb, "");
                i--;
            }
            if ((pomocnicza == 2) & (strlen(head->odpc) != 0) & (head->odpc[0] != head->poprawna))
            {

                strcpy(head->odpc, "");
                i--;
            }
            if ((pomocnicza == 3) & (strlen(head->odpd) != 0) & (head->odpd[0] != head->poprawna))
            {
                strcpy(head->odpd, "");
                i--;
            }


        }
        *uzycie_pol_na_pol_w_pytaniu = 1;
        wyswietlenie_pytania(head,0); return;
    
   

}
void telefon_do_przyjaciela(pytanie* head)
{
    wyswietlenie_pytania(head,0);
    

        srand((unsigned int)time(NULL));
        char odp = '-';
        int pomocnicza;
        while (1)
        {

            pomocnicza = rand() % 4;

            if ((pomocnicza == 0) & (strlen(head->odpa) != 0))
            {
                odp = 'A'; break;
            }
            if ((pomocnicza == 1) & (strlen(head->odpb) != 0))
            {
                odp = 'B'; break;
            }
            if ((pomocnicza == 2) & (strlen(head->odpc) != 0))
            {
                odp = 'C'; break;
            }
            if ((pomocnicza == 3) & (strlen(head->odpd) != 0))
            {
                odp = 'D'; break;
            }

        }
        printf("Hmmm....wydadaje mi sie ze poprawna odpowiedz to %c", odp);
        printf("  ale glowy za to nie dam.\n");
    
    return;

}
void pytanie_do_publicznosci(int uzycie_pol_na_pol_w_pytaniu, pytanie* head)
{
    wyswietlenie_pytania(head,0);
   
        srand((unsigned int)time(NULL));
        if (uzycie_pol_na_pol_w_pytaniu == 1)
        {

            int odp_1 = rand() % 100;
            int odp_2 = 100 - odp_1;
            int pomocnicza = odp_1;
            if (strlen(head->odpa) != 0)
            {
                printf("A: %d%%\n", pomocnicza);
                pomocnicza = odp_2;

            }
            if (strlen(head->odpb) != 0)
            {
                printf("B: %d%%\n", pomocnicza);
                pomocnicza = odp_2;

            }
            if (strlen(head->odpc) != 0)
            {
                printf("C: %d%%\n", pomocnicza);
                pomocnicza = odp_2;

            }
            if (strlen(head->odpd) != 0)
            {
                printf("D: %d%%\n", pomocnicza);
                pomocnicza = odp_2;

            }

        }
        else
        {
            int odp_a = 100 - rand() % 100;
            int odp_b, odp_c, odp_d;
            if (odp_a != 100)
            {
                odp_b = 100 - odp_a - rand() % (100 - odp_a);
                if (odp_a + odp_b != 100)
                {
                    odp_c = 100 - odp_a - odp_b - rand() % (100 - odp_a - odp_b);
                }
                else
                {
                    odp_c = 0;
                }
                odp_d = 100 - odp_a - odp_b - odp_c;
            }
            else
            {
                odp_b = 0;
                odp_c = 0;
                odp_d = 0;


            }
            printf("A: %d%%\n", odp_a);
            printf("B: %d%%\n", odp_b);
            printf("C: %d%%\n", odp_c);
            printf("D: %d%%\n", odp_d);
        }
   
    return;



}
pytanie* losowanie_pytania(kwota_gry* head)

{
    srand((unsigned int)time(NULL));
    pytanie* wybrane_pytanie = head->wskaznik_na_pytanie;
    int ktore_pytanie = rand() % (head->ilosc_pytan);

    for (int i = 0; i < ktore_pytanie; i++)
        wybrane_pytanie = wybrane_pytanie->nastepne;
    return wybrane_pytanie;



}

kwota_gry* utworzenie_listy(kwota_gry* head, int wartosc_pytania)
{
    if (head == NULL)
    {
        head = malloc(sizeof(kwota_gry));

        head->kwota = wartosc_pytania;
        head->wskaznik_na_pytanie = NULL;
        head->ilosc_pytan = 0;
        head->next = NULL;
    }
    else
    {
        kwota_gry* aktualny = head;
        while (aktualny->next != NULL)
            aktualny = aktualny->next;

        kwota_gry* nowy = (kwota_gry*)malloc(sizeof(kwota_gry));
        nowy->ilosc_pytan = 0;
        nowy->next = NULL;
        nowy->kwota = wartosc_pytania;
        nowy->wskaznik_na_pytanie = NULL;
        nowy->next = NULL;
        aktualny->next = nowy;
    }

    return head;
}

void wyswietlenie_wszystkich_pytan(kwota_gry* head)
{
    wczytanie_pytan(head);
    if (head)
    {
        kwota_gry* pomocnicza = head;
        while (pomocnicza)

        {
            pytanie* aktualne_pytanie = pomocnicza->wskaznik_na_pytanie;
           if (aktualne_pytanie)
            {
                printf(" Pytania za %d\n", pomocnicza->kwota);
                
               while (aktualne_pytanie)
                {
                    wyswietlenie_pytania(aktualne_pytanie ,1);
                    aktualne_pytanie = aktualne_pytanie->nastepne;
                }
                free(aktualne_pytanie);
               pomocnicza = pomocnicza->next;
            }
        }
        usuwanie_listy_pytan(head);
        
        return;
        
    }

    else printf("Brak pytan\n");
}

void usuwanie_listy_pytan(kwota_gry* head)
{
    if (head)
    {
        kwota_gry* pomocnicza = head;
        while (pomocnicza)
        {
            pytanie* aktualne = pomocnicza->wskaznik_na_pytanie;
            pytanie* nastepne;
            while (aktualne)
            {
                nastepne = aktualne->nastepne;
                free(aktualne);
                aktualne = nastepne;
            }
            pomocnicza->wskaznik_na_pytanie = NULL;
            pomocnicza->ilosc_pytan = 0;
            pomocnicza = pomocnicza->next;
        }
    }
    return;


}
void usuwanie_listy_pierwotnej(kwota_gry* head)
{

    if (head)
    {
        kwota_gry* aktualna = head;
        kwota_gry* nastepna;
        {
            while (aktualna->next)
            {
                nastepna = aktualna->next;
                free(aktualna);
                aktualna = nastepna;
            }

        }

    }

    return;

}
