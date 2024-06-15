#include <stdio.h>
#include "struktury.h"

//WCZYTYWANIE DANYCH

int wczytanie_z_pliku(char* src_file, Rezerwacja *lista_rezerwacji){
    FILE *plik;
    plik = fopen(src_file, "r");
    int i =0;
    while (!feof(plik))
    {
        fscanf(plik, "%d %d %d %d", &lista_rezerwacji[i].id, &lista_rezerwacji[i].sala_rezerwowana.nr_sali, &lista_rezerwacji[i].data_rezerwacji.dzien, &lista_rezerwacji[i].data_rezerwacji.h);
        i++;
    }
    fclose(plik);
    return i;
}

//1. REZERWOWANIE SALI

int wolna_sala(Rezerwacja nowa,  Rezerwacja *rezerwacje, int liczba_rezerwacji){
    for(int i = 0; i<liczba_rezerwacji; i++){
        if(nowa.data_rezerwacji.dzien == rezerwacje[i].data_rezerwacji.dzien && nowa.data_rezerwacji.h == rezerwacje[i].data_rezerwacji.h && nowa.sala_rezerwowana.nr_sali == rezerwacje[i].sala_rezerwowana.nr_sali){
            printf("Ta sala jest juz zarezerwowana o tej godzinie\n");
            return 0;
        }
    }
    return 1;
}

int sala_istnieje(Rezerwacja nowa){
    FILE *baza_sal;
    Sala lista_sal[10];
    int istnieje = 0;
    baza_sal = fopen("sale.txt", "r");
    int i = 0;
    while (!feof(baza_sal))
    {
        fscanf(baza_sal, "%d", &lista_sal[i].nr_sali);
        if(nowa.sala_rezerwowana.nr_sali == lista_sal[i].nr_sali){
            istnieje = 1;
            break;
        }
        i++;
    }
    return istnieje;
}

void drukowanie_rezerwacji(Rezerwacja nowa){
    FILE *plik;
    plik = fopen("paragon.txt", "w");
    fprintf(plik, "*************\n");
    fprintf(plik, "Rezerwacja %2d\n", nowa.id);
    fprintf(plik, "  Sala: %3d\n", nowa.sala_rezerwowana.nr_sali);
    fprintf(plik, "  Dzień: %2d\n", nowa.data_rezerwacji.dzien);
    fprintf(plik, " Godzina: %2d\n", nowa.data_rezerwacji.h);
    fprintf(plik, "*************\n");
    fclose(plik);
}

int nowa_rezerwacja(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {

    Rezerwacja nowa;
    nowa.id = lista_rezerwacji[liczba_rezerwacji-1].id + 1;

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
        printf("\nNie ma mozliwosci wybrania tej sali\n\n");
        return liczba_rezerwacji;
    }
    
    if(wolna_sala(nowa, lista_rezerwacji, liczba_rezerwacji) == 0){
        return liczba_rezerwacji;
    }
    if (sala_istnieje(nowa) == 0){
        printf("\nPodana sala nie istnieje\n");
        return liczba_rezerwacji;
    }
    

    lista_rezerwacji[liczba_rezerwacji] = nowa;
    liczba_rezerwacji++;
  
    printf("\nID rezerwacji: %d\nZarezerwowales sale: %d, dnia %d, o godzinie %d\n",nowa.id, nowa.sala_rezerwowana.nr_sali, nowa.data_rezerwacji.dzien, nowa.data_rezerwacji.h);

    drukowanie_rezerwacji(nowa);
    return liczba_rezerwacji;
}

//2. ANULOWANIE REZERWACJI

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
            
            break;
        }
    }
    return liczba_rezerwacji;
}

//3. POKAŻ WSZYSTKIE REZERWACJE

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

//4. POKAŻ REZERWACJE Z DANEGO DNIA

void pokaz_rezerwacje_z_dnia(Rezerwacja *lista_rezerwacji, int liczba_rezerwacji) {
    int dzien;
    printf("Podaj dzien, dla ktorego chcesz zobaczyc rezerwacje: ");
    if (scanf("%d", &dzien) != 1 || dzien < 1 || dzien > 30) {
        printf("Zla data\n");
        return;
    }

    int znaleziono = 0;
    printf("\nRezerwacje z dnia %d:\n", dzien);
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

// ZAPIS DO PLIKU

void zapis_rezerwacji_do_pliku_txt(Rezerwacja *rezerwacje, const char* nazwa_pliku, int liczba_rezerwacji) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik != NULL) {
        for (int i = 0; i < liczba_rezerwacji; i++) {
            fprintf(plik, "\n%d %d %d %d",
                rezerwacje[i].id, rezerwacje[i].sala_rezerwowana.nr_sali, rezerwacje[i].data_rezerwacji.dzien, rezerwacje[i].data_rezerwacji.h);
        }
        fclose(plik);
        printf("Zapisano rezerwacje do pliku %s\n", nazwa_pliku);
    } else {
        printf("Błąd przy zapisie do pliku\n");
    }
    fclose(plik);
}

//MENU

int main() {
    char wybor;

    Rezerwacja lista_rezerwacji[1000];

    int liczba_rezerwacji =    wczytanie_z_pliku("src.txt", lista_rezerwacji);

    do {
        printf("\nSystem rezerwacji sal\n");
        printf("1. Dodaj rezerwacje\n");
        printf("2. Anuluj rezerwacje\n");
        printf("3. Pokaz wszystkie rezerwacje\n");
        printf("4. Pokaz rezerwacje z konkretnego dnia\n");
        printf("0. Wyjdz\n\n");
        printf("Wybierz opcje: ");
        scanf("%c", &wybor);
        printf("\n");

        if (wybor == '1') {
            liczba_rezerwacji = nowa_rezerwacja(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == '2') {
            liczba_rezerwacji=anuluj_rezerwacje(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == '3') {
            pokaz_wszystkie_rezerwacje(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor == '4') {
            pokaz_rezerwacje_z_dnia(lista_rezerwacji, liczba_rezerwacji);
        } else if (wybor != '0') {
            printf("Podales zla wartosc\n");
        }
    } while (wybor != '0');

    zapis_rezerwacji_do_pliku_txt(lista_rezerwacji, "src.txt", liczba_rezerwacji);

    return 0;
}


