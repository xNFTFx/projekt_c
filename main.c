#include <stdio.h>
#include "struktury.h"
#include "rezerwacje.h"
#include "lista_rezerwacji.h"
#include "test.h"


int main() {
    int wybor;

    //funkcja odczytujaca plik

    Rezerwacja lista_rezerwacji[1000];
    int liczba_rezerwacji = 0;

    Dupa();

    do {
        printf("\nSystem rezerwacji sal\n");
        printf("1. Dodaj rezerwacje\n");
        printf("2. Anuluj rezerwacje\n");
        printf("3. Pokaz wszystkie rezerwacje\n");
        printf("4. Pokaz rezerwacje z konkretnego dnia\n");
        printf("6. Zapisz rezerwacje do pliku\n");
        printf("0. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        if (wybor == 1) {

        } else if (wybor == 2) {
            // kod do anulowania rezerwacji
        } else if (wybor == 3) {
        } else if (wybor == 4) {

        } else if (wybor == 6) {
            char nazwa_pliku[50];
            printf("Podaj nazwe pliku do zapisu: ");
            scanf("%49s", nazwa_pliku);
            // zapis_rezerwacji_do_pliku_txt(nazwa_pliku);
        } else if (wybor != 0) {
            printf("Podales zla wartosc\n");
        }
    } while (wybor != 0);

    return 0;
}


