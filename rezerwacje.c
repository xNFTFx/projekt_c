#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struktury.h"

// int wolne_sale(FILE *plik, int h, int dzien){
//     Rezerwacja rezerwacje[10];
//     int n = 0;
//     while (!feof(plik))
//     {
//         fscanf(plik, "%d %d %d %d", rezerwacje[n].id_rezerwacji, rezerwacje[n].sala_rezerwowana.nr_sali, rezerwacje[n].data_rezerwacji.dzien, rezerwacje[n].data_rezerwacji.h);
//         n++;
//     }
//     return rezerwacje;
// }


void zapis_rezerwacji_do_pliku_txt(Rezerwacja *rezerwacje, const char* nazwa_pliku, int liczba_rezerwacji) {
    FILE* plik = fopen(nazwa_pliku, "a"); // Otwórz plik w trybie dodawania (append)
    if (plik != NULL) {
        for (int i = 0; i < liczba_rezerwacji; i++) {
            fprintf(plik, "ID Rezerwacji: %d, ID Sali: %d, Data: %02d-%02d-%04d, Nazwisko: %s\n",
                rezerwacje[i].id, rezerwacje[i].sala_rezerwowana.nr_sali, rezerwacje[i].data_rezerwacji.dzien, rezerwacje[i].data_rezerwacji.h);
        }
        fclose(plik);
        printf("Zapisano rezerwacje do pliku %s\n", nazwa_pliku);
    } else {
        printf("Błąd przy zapisie do pliku\n");
    }
}

void nowa_rezerwacja(){
    Rezerwacja nowa;
    // funkcja nowy_numer potrzebna, ktora bd okreslala nr id nowej rezerwacji
    printf("Podaj dzien, kiedy chcesz zarezerwowac sale: ");
    if(scanf("%d", &nowa.data_rezerwacji.dzien) !=1 || nowa.data_rezerwacji.dzien > 30 || nowa.data_rezerwacji.dzien <1){
        printf("zla data\n\n");
        return;
    }
    printf("Podaj godzine, kiedy chcesz zarezerwowac sale: ");
    if(scanf("%d", &nowa.data_rezerwacji.h) !=1 || nowa.data_rezerwacji.h > 16 || nowa.data_rezerwacji.h <10){
        printf("zla godzina\\nn");
        return;
    }
    printf("Wybierz ktora z podanych sal chcesz zarezerwowac: ");
    // funkcja wolne_sale(), ktora bedzie wyswietlala wolne sale i zwracala tabele wolnych sal
    if(scanf("%d", &nowa.sala_rezerwowana.nr_sali) !=1 )//trzeba dopisac warunek na sprawdzenie czy sala jest zawarta w wolnych salach
    {
        printf("Nie ma mozliwosci wybrania tej sali\n\n");
        return;
    }
    printf("Zarezerwowales sale: %d, dnia %d, o godzinie %d", nowa.sala_rezerwowana.nr_sali, nowa.data_rezerwacji.dzien, nowa.data_rezerwacji.h); //dodac nr rezerwacji trza
    //trzeba dopisac wypisanie pliku z potwierdzeniem rezerwacji
}


//czesc testowa
int main(){
    nowa_rezerwacja();
}