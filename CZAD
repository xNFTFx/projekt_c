#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SALE 100
#define MAX_REZERWACJE 100

typedef struct {
    int dzien;
    int miesiac;
    int rok;
} Data;

typedef struct {
    int id_sali;
    char nazwa[50];
    int liczba_miejsc;
} Sala;

typedef struct {
    int id_rezerwacji;
    int id_sali;
    Data data;
    char nazwisko[50];
} Rezerwacja;

Sala sale[MAX_SALE];
Rezerwacja rezerwacje[MAX_REZERWACJE];
int liczba_sal = 0;
int liczba_rezerwacji = 0;

void dodaj_sala(int id, const char* nazwa, int liczba_miejsc) {
    Sala sala;
    sala.id_sali = id;
    strcpy_s(sala.nazwa, sizeof(sala.nazwa), nazwa);
    sala.liczba_miejsc = liczba_miejsc;
    sale[liczba_sal++] = sala;
}

void pokaz_sale() {
    printf("Dostępne sale:\n");
    for (int i = 0; i < liczba_sal; i++) {
        printf("ID: %d, Nazwa: %s, Liczba miejsc: %d\n", sale[i].id_sali, sale[i].nazwa, sale[i].liczba_miejsc);
    }
}

void dodaj_rezerwacje(int id_rez, int id_sali, Data data, const char* nazwisko) {
    Rezerwacja rezerwacja;
    rezerwacja.id_rezerwacji = id_rez;
    rezerwacja.id_sali = id_sali;
    rezerwacja.data = data;
    strcpy_s(rezerwacja.nazwisko, sizeof(rezerwacja.nazwisko), nazwisko);
    rezerwacje[liczba_rezerwacji++] = rezerwacja;
}

void anuluj_rezerwacje(int id_rez) {
    for (int i = 0; i < liczba_rezerwacji; i++) {
        if (rezerwacje[i].id_rezerwacji == id_rez) {
            for (int j = i; j < liczba_rezerwacji - 1; j++) {
                rezerwacje[j] = rezerwacje[j + 1];
            }
            liczba_rezerwacji--;
            break;
        }
    }
}

void pokaz_rezerwacje() {
    printf("Wszystkie rezerwacje:\n");
    for (int i = 0; i < liczba_rezerwacji; i++) {
        printf("ID Rezerwacji: %d, ID Sali: %d, Data: %02d-%02d-%04d, Nazwisko: %s\n",
            rezerwacje[i].id_rezerwacji, rezerwacje[i].id_sali, rezerwacje[i].data.dzien,
            rezerwacje[i].data.miesiac, rezerwacje[i].data.rok, rezerwacje[i].nazwisko);
    }
}

void zapis_do_pliku(const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "wb");
    if (plik != NULL) {
        fwrite(&liczba_sal, sizeof(int), 1, plik);
        fwrite(sale, sizeof(Sala), liczba_sal, plik);
        fwrite(&liczba_rezerwacji, sizeof(int), 1, plik);
        fwrite(rezerwacje, sizeof(Rezerwacja), liczba_rezerwacji, plik);
        fclose(plik);
        printf("Zapisano dane do pliku %s\n", nazwa_pliku);
    }
    else {
        printf("Błąd przy zapisie do pliku\n");
    }
}

void odczyt_z_pliku(const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "rb");
    if (plik != NULL) {
        fread(&liczba_sal, sizeof(int), 1, plik);
        fread(sale, sizeof(Sala), liczba_sal, plik);
        fread(&liczba_rezerwacji, sizeof(int), 1, plik);
        fread(rezerwacje, sizeof(Rezerwacja), liczba_rezerwacji, plik);
        fclose(plik);
        printf("Wczytano dane z pliku %s\n", nazwa_pliku);
    }
    else {
        printf("Błąd przy odczycie z pliku\n");
    }
}

void drukuj_rezerwacje_do_pliku(const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik != NULL) {
        for (int i = 0; i < liczba_rezerwacji; i++) {
            fprintf(plik, "ID Rezerwacji: %d, ID Sali: %d, Data: %02d-%02d-%04d, Nazwisko: %s\n",
                rezerwacje[i].id_rezerwacji, rezerwacje[i].id_sali, rezerwacje[i].data.dzien,
                rezerwacje[i].data.miesiac, rezerwacje[i].data.rok, rezerwacje[i].nazwisko);
        }
        fclose(plik);
        printf("Wydrukowano rezerwacje do pliku %s\n", nazwa_pliku);
    }
    else {
        printf("Błąd przy drukowaniu do pliku\n");
    }
}

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
        printf("7. Odczytaj rezerwacje z pliku\n");
        printf("8. Drukuj rezerwacje do pliku\n");
        printf("0. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf_s("%d", &wybor);

        if (wybor == 1) {
            int id;
            char nazwa[50];
            int liczba_miejsc;
            printf("Podaj ID sali: ");
            scanf_s("%d", &id);
            printf("Podaj nazwe sali: ");
            scanf_s("%49s", nazwa, (unsigned)_countof(nazwa));
            printf("Podaj liczbe miejsc: ");
            scanf_s("%d", &liczba_miejsc);
            dodaj_sala(id, nazwa, liczba_miejsc);
        }
        else if (wybor == 2) {
            pokaz_sale();
        }
        else if (wybor == 3) {
            int id_rez, id_sali;
            Data data;
            char nazwisko[50];
            printf("Podaj ID rezerwacji: ");
            scanf_s("%d", &id_rez);
            printf("Podaj ID sali: ");
            scanf_s("%d", &id_sali);
            printf("Podaj dzien: ");
            scanf_s("%d", &data.dzien);
            printf("Podaj miesiac: ");
            scanf_s("%d", &data.miesiac);
            printf("Podaj rok: ");
            scanf_s("%d", &data.rok);
            printf("Podaj nazwisko rezerwujacego: ");
            scanf_s("%49s", nazwisko, (unsigned)_countof(nazwisko));
            dodaj_rezerwacje(id_rez, id_sali, data, nazwisko);
        }
        else if (wybor == 4) {
            int id_rez;
            printf("Podaj ID rezerwacji do anulowania: ");
            scanf_s("%d", &id_rez);
            anuluj_rezerwacje(id_rez);
        }
        else if (wybor == 5) {
            pokaz_rezerwacje();
        }
        else if (wybor == 6) {
            char nazwa_pliku[50];
            printf("Podaj nazwe pliku do zapisu: ");
            scanf_s("%49s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));
            zapis_do_pliku(nazwa_pliku);
        }
        else if (wybor == 7) {
            char nazwa_pliku[50];
            printf("Podaj nazwe pliku do odczytu: ");
            scanf_s("%49s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));
            odczyt_z_pliku(nazwa_pliku);
        }
        else if (wybor == 8) {
            char nazwa_pliku[50];
            printf("Podaj nazwe pliku do druku: ");
            scanf_s("%49s", nazwa_pliku, (unsigned)_countof(nazwa_pliku));
            drukuj_rezerwacje_do_pliku(nazwa_pliku);
        }
    } while (wybor != 0);

    return 0;
}
