#include <stdio.h>
#include "struktury.h"

void usun_rezerwacje_z_pliku(const char* nazwa_pliku, int id_rez, Data data) {
    FILE* plik = fopen(nazwa_pliku, "r");
    FILE* tmp = fopen("tmp.txt", "w");
    if (plik != NULL && tmp != NULL) {
        char linia[256];
        while (fgets(linia, sizeof(linia), plik)) {
            int rez_id, sala_id, dzien, miesiac, rok, godzina;
            char nazwisko[50];
            if (sscanf(linia, "ID Rezerwacji: %d, ID Sali: %d, Data: %02d-%02d-%04d %02d:00, Nazwisko: %49s\n",
                       &rez_id, &sala_id, &dzien, &miesiac, &rok, &godzina, nazwisko) == 7) {
                if (!(rez_id == id_rez && dzien == data.dzien && godzina == data.h)) {
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


void anuluj_rezerwacje(Rezerwacja *rezerwacje, int id_rez, Data data, int liczba_rezerwacji) {
    for (int i = 0; i < liczba_rezerwacji; i++) {
        if (rezerwacje[i].id== id_rez && rezerwacje[i].data_rezerwacji.dzien == data.dzien &&
            rezerwacje[i].data_rezerwacji.h == data.h) {
            for (int j = i; j < liczba_rezerwacji - 1; j++) {
                rezerwacje[j] = rezerwacje[j + 1];
            }
            liczba_rezerwacji--;
            
            // Dodatkowo usuwamy rezerwację z pliku
            usun_rezerwacje_z_pliku("rezerwacje.txt", id_rez, data);
            
            break;
        }
    }
}
