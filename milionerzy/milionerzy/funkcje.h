/** @file */
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
/** Glowna funkcja odpowiadajaca za przebieg rozgrywki.
@param glowa wskaznik na poczatek listy, przechowywujacej wartosci o ktore gracz bedzie gral
*/
void gra(kwota_gry* head);

/** Funkcja wczytujaca pytania oraz odpowiedzi z pliku, dodaj¹c elementy listy podwieszanej lub tworzac ja.
@param head wskaznik element listy, przechowywujacej wartosci o ktore gracz bedzie gral
*/
void wczytanie_pytan(kwota_gry* head);

/** Funkcja wyswietlajaca dodatkowe opcje
@param head wskaznik element listy, przechowywujacej wartosci o ktore gracz bedzie gral
*/
void opcje_dodatkowe(kwota_gry* head);

/** Funkcja wyswietlajaca wszystkie pytania wystepujace w grze
@param head wskaznik element listy, przechowywujacej wartosci o ktore gracz bedzie gral
*/
void wyswietlenie_wszystkich_pytan(kwota_gry* head);

/** Funkcja wyswietlajaca pytanie wraz z odpowiedziami na ekranie
@param head wskaznik na pytanie, ktore ma byc wyswietlone
@param czy_wszystkie_pytania zmienna odpowiadajaca czy funkcja czysci ekran przed wyswietleniem pytania
*/
void wyswietlenie_pytania(pytanie* head, int czy_wszystkie_pytania);

/** Funkcja usuwajaca dwie bledne odpowiedzi
@param head wskaznik na aktualne pytanie
@param uzycie_pol_na_pol_w_pytaniu zmienna odpowiadajaca czy funkcja zostala uzyta w tym pytaniu
*/
void pol_na_pol(pytanie* head, int* uzycie_pol_na_pol_w_pytaniu);

/** Funkcja symulujaca wskazania publicznosci
@param  uzycie_pol_na_pol_w_pytaniu zmienna, ktora mowi czy funcja pol_na_pol zostala uzyta przy aktualnym pytaniu

@param head wskaznik na aktualne pytanie
*/
void pytanie_do_publicznosci(int uzycie_pol_na_pol_w_pytaniu, pytanie* head);

/** Funkcja symulujaca i wyswietlajaca prawdopodobna odpowiedz
@param head wskaznik na aktualne pytanie
*/
void telefon_do_przyjaciela(pytanie* head);
/** Funkcja losujaca pytanie do wyswietlenia
@param wskaznik na element zawierajacy liste z pytaniami
@return funckja zwraca wskaznik na pytanie
*/
pytanie* losowanie_pytania(kwota_gry* head);

/** Funkcja tworzy liste przechowywujaca wartosci, o ktore gracz bedzie gral
@param head wskaznik na liste
@param wartosc_pytania wartosc, o ktora gracz bedzie gral
@return funkcja zwraca wskaznik na liste
*/
kwota_gry* utworzenie_listy(kwota_gry* head, int wartosc_pytania);

/** Funkcja szukajaca elementu liczby glownej po jej wartosci
@param head wskaznik na liste, w ktorej szukamy elementu
@param szukane wartosc szukana
@return funkcja zwraca wskaznik na element lub NULL gdy on nie istnieje
*/
kwota_gry* szukanie_kwoty(kwota_gry* head, int szukane);

/** Funkcja usuwajaca liste glowna
@param head wskaznik na liste
*/
void usuwanie_listy_pierwotnej(kwota_gry* head);

/** Funkcja usuwajaca liste podwieszana danym elemencie listy glownej
@param head wskaznik na element listy glownej
*/
void usuwanie_listy_pytan(kwota_gry * head);
