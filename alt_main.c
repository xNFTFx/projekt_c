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

int nowa_rezerwacja(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {

    Rezerwacja nowa;
    nowa.id = liczba_rezerwacji + 1;

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

void usun_rezerwacje_z_pliku(const char* nazwa_pliku, int id_rez) {
    FILE* plik = fopen(nazwa_pliku, "r");
    FILE* tmp = fopen("tmp.txt", "w");
    if (plik != NULL && tmp != NULL) {
        char linia[256];
        while (fgets(linia, sizeof(linia), plik)) {
            int rez_id, sala_id, dzien, godzina;
            if (sscanf(linia, "%d %d %d %d/n",
                       &rez_id, &sala_id, &dzien, &godzina) == 4) {
                if (!(rez_id == id_rez)) {
                    fputs(linia, tmp);
                }
            }
        }
        fclose(plik);
        fclose(tmp);
        remove(nazwa_pliku);
        rename("tmp.txt", nazwa_pliku);
        printf("Usunięto rezerwację z pliku %s\n", nazwa_pliku);
    } else {
        printf("Błąd przy usuwaniu rezerwacji z pliku\n");
    }
}


int anuluj_rezerwacje(Rezerwacja *rezerwacje, int liczba_rezerwacji) {
    int id_rez = 0;
    printf("Podaj id rezerwacji ktora chcesz usunac: ");
    scanf("%d", &id_rez);
    printf("\n");
    for (int i = 0; i < liczba_rezerwacji; i++) {
        if (rezerwacje[i].id == id_rez) {
            for (int j = i; j < liczba_rezerwacji - 1; j++) {
                rezerwacje[j] = rezerwacje[j + 1];
            }
            liczba_rezerwacji--;
            
            // Dodatkowo usuwamy rezerwację z pliku
            usun_rezerwacje_z_pliku("rezerwacje.txt", id_rez);
            
            break;
        }
    }
    return liczba_rezerwacji;
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
        printf("0. Wyjdz\n\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);
        printf("\n");

        if (wybor == 1) {
            liczba_rezerwacji = nowa_rezerwacja(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == 2) {
            anuluj_rezerwacje(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == 3) {
            pokaz_wszystkie_rezerwacje(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == 4) {
            pokaz_rezerwacje_z_dnia(lista_rezerwacji, liczba_rezerwacji);
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


