//kod na wyswietlanie listy wszystkich rezerwacji + wyswietlanie rezerwacji z danego dnia + nowe tworzenie rezerwacji pod kątem tego kodu + jak do maina zapisac 
//trzeba wycignac to co nas interesuje i reszte usunac bo to tylko po to zeby skosultowac nowe tworzenie rezerwacji bo jest do tych dwoch kodow kompatybilne 

#include <stdio.h>
#include "struktury.h"

void pokaz_wszystkie_rezerwacje(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {
    if (liczba_rezerwacji == 0) {
        printf("Brak rezerwacji.\n");
        return;
    }

    printf("Lista wszystkich rezerwacji:\n");
    for (int i = 0; i < liczba_rezerwacji; i++) {
        printf("ID Rezerwacji: %d, Sala: %d, Dzien: %d, Godzina: %d\n", 
               lista_rezerwacji[i].id, 
               lista_rezerwacji[i].sala_rezerwowana.nr_sali, 
               lista_rezerwacji[i].data_rezerwacji.dzien, 
               lista_rezerwacji[i].data_rezerwacji.h);
    }
}

void pokaz_rezerwacje_z_dnia(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {
    int dzien;
    printf("Podaj dzien, dla ktorego chcesz zobaczyc rezerwacje: ");
    if (scanf("%d", &dzien) != 1 || dzien < 1 || dzien > 30) {
        printf("Zla data\n");
        return;
    }

    int znaleziono = 0;
    printf("Rezerwacje z dnia %d:\n", dzien);
    for (int i = 0; i < liczba_rezerwacji; i++) {
        if (lista_rezerwacji[i].data_rezerwacji.dzien == dzien) {
            printf("ID Rezerwacji: %d, Sala: %d, Godzina: %d\n", 
                   lista_rezerwacji[i].id, 
                   lista_rezerwacji[i].sala_rezerwowana.nr_sali, 
                   lista_rezerwacji[i].data_rezerwacji.h);
            znaleziono = 1;
        }
    }

    if (!znaleziono) {
        printf("Brak rezerwacji w tym dniu.\n");
    }
}


int main() {
    int wybor;

    //funkcja odczytujaca plik

    Rezerwacja lista_rezerwacji[1000];
    int liczba_rezerwacji = 0;


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
        printf("\n");

        if (wybor == 1) {

        } else if (wybor == 2) {
            // kod do anulowania rezerwacji
        } else if (wybor == 3) {
            pokaz_wszystkie_rezerwacje(lista_rezerwacji, liczba_rezerwacji);
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



