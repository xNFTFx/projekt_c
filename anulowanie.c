#include <stdio.h>
#include "struktury.h"

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


void anuluj_rezerwacje(Rezerwacja *rezerwacje, int liczba_rezerwacji) {
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
}
