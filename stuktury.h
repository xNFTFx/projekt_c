#pragma once

typedef struct Data{
    int dzien;
    int h;
} Data;

typedef struct Sala{
    char nr_sali;
}Sala;

typedef struct Rezerwacja{
    int id_rezerwacji;
    Sala sala_rezerwowana;
    Data data_rezerwacji;
}Rezerwacja;
