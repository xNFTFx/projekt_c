#include <stdio.h>


int main() {
    int wybor;
    do {
        printf("\nSystem rezerwacji sal\n");
        printf("1. Dodaj rezerwacje\n");
        printf("2. Anuluj rezerwacje\n");
        printf("3. Pokaz wszystkie rezerwacje\n");
        printf("4. Pokaz rezerwacje z danego dnia\n");
        printf("0. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        if (wybor == 1) {
            // kod do dodawania rezerwacji
        } else if (wybor == 2) {
            // kod do anulowania rezerwacji
        } else if (wybor == 3) {
            // kod do pokazywania wszystkich rezerwacji
        } else if (wybor == 4) {
            //
        } else if (wybor == 5) {
            //
        } else if (wybor == 6) {
            char nazwa_pliku[50]; /////// zapis pliku
            printf("Podaj nazwe pliku do zapisu: ");
            // scanf("%49s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));
            // zapis_rezerwacji_do_pliku_txt(nazwa_pliku);
        }
        else{
            printf("Podales zla wartosc\n\n");
        }
    } while (wybor != 0);

    return 0;
}

