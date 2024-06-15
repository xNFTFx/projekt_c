#include <stdio.h>
#include "struktury.h"

int sala_istnieje(int nr_sali){
    printf("dupa");
    FILE *baza_sal;
    Sala lista_sal[10];
    int istnieje = 0;
    baza_sal = fopen("sale.txt", "r");
    int i = 0;
    while (!feof(baza_sal))
    {
        fscanf("%d", &lista_sal[i].nr_sali);
        printf("%d\n", lista_sal[i].nr_sali);
        if(nr_sali == lista_sal[i].nr_sali){
            istnieje = 1;
            break;
        }
        i++;
    }
    return istnieje;
}

int main(){
    Rezerwacja nowa;
    nowa.id = 1;
    nowa.data_rezerwacji.dzien = 12;
    nowa.data_rezerwacji.h = 12;
    nowa.sala_rezerwowana.nr_sali = 102;

    printf("%d", sala_istnieje(102));
}