#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>


typedef struct pytanie_do_milionerow
{

    char tresc_pytania[300];
    char odpa[30];
    char odpb[30];
    char odpc[30];
    char odpd[30];
    char poprawna;
    struct pytanie_do_milionerow* nastepne;




}pytanie;
typedef struct baza_pytan
{
    int kwota;
    int ilosc_pytan;
    struct baza_pytan* next;
    struct pytanie_do_milionerow* wskaznik_na_pytanie;


}kwota_gry;

void gra(kwota_gry* glowa);
void wczytanie_pytan(kwota_gry* head);
void opcje_dodatkowe(kwota_gry* head);
void dodanie_pytania();
void wyswietlenie_wszystkich_pytan(kwota_gry* head);
void wyswietlenie_pytania(pytanie* head);
void pol_na_pol(pytanie* head, int flaga_aktualne_kolo, int* uzycie_pol_na_pol_w_pytaniu);
void pytanie_do_publicznosci(int uzycie_pol_na_pol_w_pytaniu, int flaga_aktualne_kolo, pytanie* head);
void telefon_do_przyjaciela(pytanie* head, int flaga_aktualne_kolo);
pytanie* losowanie_pytania(kwota_gry* head);
kwota_gry* utworzenie_listy(kwota_gry* head, int wartosc_pytania);
void tworzenie_pytania(kwota_gry* head, FILE* plik);
kwota_gry* szukanie_kwoty(kwota_gry* head, int szukane);
void usuwanie_listy_pierwotnej(kwota_gry* head);
void usuwanie_listy_pytan(kwota_gry * head);
