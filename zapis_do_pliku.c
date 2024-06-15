#include <stdio.h>
#include "struktury.h"

void zapis_rezerwacji_do_pliku_txt(Rezerwacja *rezerwacje, const char* nazwa_pliku, int liczba_rezerwacji) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik != NULL) {
        for (int i = 0; i < liczba_rezerwacji; i++) {
            fprintf(plik, "%d %d %d %d\n",
                rezerwacje[i].id, rezerwacje[i].sala_rezerwowana.nr_sali, rezerwacje[i].data_rezerwacji.dzien, rezerwacje[i].data_rezerwacji.h);
        }
        fclose(plik);
        printf("Zapisano rezerwacje do pliku %s\n", nazwa_pliku);
    } else {
        printf("Błąd przy zapisie do pliku\n");
    }
}