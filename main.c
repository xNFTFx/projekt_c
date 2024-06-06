int main() {
    int wybor;
    do {
        printf("\nSystem rezerwacji sal\n");
        printf("1. Dodaj sale\n");
        printf("2. Pokaz sale\n");
        printf("3. Dodaj rezerwacje\n");
        printf("4. Anuluj rezerwacje\n");
        printf("5. Pokaz wszystkie rezerwacje\n");
        printf("6. Zapisz rezerwacje do pliku\n");
        printf("0. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf_s("%d", &wybor);

        if (wybor == 1) {
            // kod do dodawania sali
        } else if (wybor == 2) {
            // kod do pokazywania sal
        } else if (wybor == 3) {
            // kod do dodawania rezerwacji
        } else if (wybor == 4) {
            // kod do anulowania rezerwacji
        } else if (wybor == 5) {
            // kod do pokazywania wszystkich rezerwacji
        } else if (wybor == 6) {
            char nazwa_pliku[50]; /////// zapis pliku
            printf("Podaj nazwe pliku do zapisu: ");
            scanf_s("%49s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));
            zapis_rezerwacji_do_pliku_txt(nazwa_pliku);
        }
    } while (wybor != 0);

    return 0;
}

