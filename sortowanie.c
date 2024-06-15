#include "struktury.h"

void sortuj_rezerwacje(Rezerwacja rezerwacje[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (rezerwacje[j].data_rezerwacji.dzien > rezerwacje[j + 1].data_rezerwacji.dzien ||
                (rezerwacje[j].data_rezerwacji.dzien == rezerwacje[j + 1].data_rezerwacji.dzien &&
                 rezerwacje[j].data_rezerwacji.h > rezerwacje[j + 1].data_rezerwacji.h)) {
                // Zamiana miejscami
                Rezerwacja temp = rezerwacje[j];
                rezerwacje[j] = rezerwacje[j + 1];
                rezerwacje[j + 1] = temp;
            }
        }
    }
}
