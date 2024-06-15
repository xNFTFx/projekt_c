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




int nowa_rezerwacja(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {

    Rezerwacja nowa;
    printf("%d - %d\n", liczba_rezerwacji, lista_rezerwacji[liczba_rezerwacji].id);
    nowa.id = lista_rezerwacji[liczba_rezerwacji].id + 1;

    printf("Podaj dzien, kiedy chcesz zarezerwowac sale: ");
    if (scanf("%d", &nowa.data_rezerwacji.dzien) != 1 || nowa.data_rezerwacji.dzien > 30 || nowa.data_rezerwacji.dzien < 1) {
        printf("Zla data\n\n");
        return liczba_rezerwacji;
    }

    printf("Podaj godzine, kiedy chcesz zarezerwowac sale: ");
    if (scanf("%d", &nowa.data_rezerwacji.h) != 1 || nowa.data_rezerwacji.h > 16 || nowa.data_rezerwacji.h < 10) {
        printf("Zla godzina\n\n");
        return liczba_rezerwacji;
    }

    printf("Podaj numer sali, ktora chcesz zarezerwowac: ");
    if (scanf("%d", &nowa.sala_rezerwowana.nr_sali) != 1) {
        printf("Nie ma mozliwosci wybrania tej sali\n\n");
        return liczba_rezerwacji;
    }
    
    //dodaj weryfikacje tego czy sala nie byla juz zarezerwowana

    lista_rezerwacji[liczba_rezerwacji] = nowa;
    liczba_rezerwacji++;
  


    printf("ID rezerwacji: %d\nZarezerwowales sale: %d, dnia %d, o godzinie %d\n",nowa.id, nowa.sala_rezerwowana.nr_sali, nowa.data_rezerwacji.dzien, nowa.data_rezerwacji.h);

    return liczba_rezerwacji;
}


//czesc testowa
int main(){
    Rezerwacja lista_rezerwacji[1000];
    int liczba_rezerwacji = 0;
    liczba_rezerwacji = nowa_rezerwacja(lista_rezerwacji, liczba_rezerwacji);
    liczba_rezerwacji = nowa_rezerwacja(lista_rezerwacji, liczba_rezerwacji);
    liczba_rezerwacji = nowa_rezerwacja(lista_rezerwacji, liczba_rezerwacji);
    for(int i = 0; i<3; i++){
        printf("%d %d %d %d\n", lista_rezerwacji[i].id, lista_rezerwacji[i].sala_rezerwowana, lista_rezerwacji[i].data_rezerwacji.dzien, lista_rezerwacji[i].data_rezerwacji.h);
    }
}